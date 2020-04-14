#include<bits/stdc++.h>
using namespace std;
#define balabalo freopen("giun.inp","r",stdin) , freopen("giun.out","w",stdout);
int n , ma = INT_MIN ;
string st , ans , t;
map< string , int > meo;

int main()
{
    //balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> st;
    for (int i = 0 ; i < n - 1 ; i++)
    {
        t = "";
        t.push_back(st[i]);
        t.push_back(st[i+1]);
        meo[t]++;
    if ( meo[t]  > ma ) ma = meo[t], ans = t;
    }
    cout << ans ;
    return 0;
}

