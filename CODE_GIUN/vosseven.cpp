#include<iostream>
#include<string>
#include<cstdio>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
const ll maxn = 1e6 + 7;
using namespace std;
ll tmp = 0 , n , f[maxn] = {0};
string s ;
int main()
{
    giuncute;
    cin >> s ;
    for (char c : s)
    {
        if (c == '7')  f[++tmp]++ , n = max(n , tmp) ;
        else tmp = 0;
    }
    for (int i = n-1 ; i >= 1 ; i--) f[i] += f[i+1] ; //, cerr << i << " " << f[i] << endl;
    for (int i = 1 ; i <= n ; i++) printf("%d ", i), printf("%lld\n", f[i]);
}
