#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
map <double,int> cnt ;
int x ,n;
int main()
{
    for (int i = 1 ; i <= n ; i++) cin >> x , cnt[x]++;
    for (map<double,int> :: iterator it = cnt.begin() ; it != cnt.end() ; it++)
    {
        cout << '\t' << it->first 
            << '\t' << it->second << '\n'; 
    }
}