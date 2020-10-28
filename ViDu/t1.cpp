#include<bits/stdc++.h>

using namespace std;

vector<int> a;
int main()
{
    a.push_back(80);
    a.push_back(80);
    a.push_back(10);
    a.push_back(10);
    a.push_back(20);
    a.push_back(40);
    a.push_back(30);
    set<int> b(a.begin(),a.end());
    for (set<int, greater<int> > :: iterator i = b.begin() ; i != b.end() ; i++ ) cout << *i << " ";
}