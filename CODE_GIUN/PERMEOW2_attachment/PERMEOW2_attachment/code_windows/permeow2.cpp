#include "permeow2.h"
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> trace;
vector<int> a, tmp;
unordered_map<string, bool> d;
int n, ans = 0;

void quaylui(int l)
{
  if(l >= n - 1){ 
    tmp = a;
    for(pair<int, int> i : trace){
      sort(tmp.begin() + i.first, tmp.begin() + i.second + 1);
    }
    string hasher;
    for(int i : tmp) hasher += i + 'a' - 1;
    if(!d[hasher]) ++ans;
    d[hasher] = 1;
    return;
  }
  for(int i = l + 1; i < n; i++) quaylui(i); 
  for(int r = l + 1; r < n; r++){
    trace.push_back({l, r});
    quaylui(r + 1);
    trace.pop_back();
  }
}
int count_permutation(std::vector<int> p) 
{  
  a = p;
  n = a.size();
  // int  ans = 0 ;
  // map < string , int >dd;
  // vector <int> tmp ;
  // for (int i = 0 ; i < p.size() ; i++)
  // {
  //   for (int j = i + 1 ; j < p.size() ; j++)
  //   {
  //     for (int z = 0 ; z < p.size() ; z ++) tmp.push_back(p[z]);
  //     sort (tmp.begin() + i , tmp.end() + j);
  //     string s = "";
  //     for (int z = 0 ; z < tmp.size() ; z++) s += tmp[z] + 'a' - 1;
  //     if (dd[s] == 0) ans++ , dd[s] = 1;
  //   }
  // }
  quaylui(0);
  return ans;
}
