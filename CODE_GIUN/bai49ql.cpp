#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("bai49ql.inp","r",stdin);
    freopen("bai49ql.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string res;
    int count=0;
    do 
    {
        count++;
        res+=s;
        res+='\n';
    } 
    while(next_permutation(s.begin(), s.end()));
    cout << res << endl;
}