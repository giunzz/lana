#include<bits/stdc++.h>
#define ll long long 
#define cll const long long 
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
ll test , dp_cnt[17][10][2]; // pos , num  , ok  ,
ll dp_sol[17][10][2];
vector<ll> digit;

ll cnt (ll pos, ll num  , bool ok )
{
    if (pos == 16) return dp_cnt[pos][num][ok] = 1 ;
    if (~dp_cnt[pos][num][ok]) return dp[pos][num][ok];
    ll npos = 1 , res = 0 ;
    for (int nnum =  0 ; nnum <= 9 ; i++)
    {
        if (ok)
        {
            if (nnum < digit[num]) 
                res += cnt (npos, nnum , 0 );
            else if (nnum == digit[num]) res += cnt(npos, nnum, 1);
            else res += cnt(npos,nnum,ok);
        }
    }
    return dp_cnt[pos][num][ok] = res;
}
ll sol(ll pos, ll num , bool ok)
{
    if (pos == 16)
        return dp_sol[pos][num][ok] = num;
    if (~dp_cnt[pos][num][ok]) return  dp_cnt[pos][num][ok];
    ll npos = pos+1 , res = 0 ;
    for (int nnum =  0 ; nmun < 10 ; nnum++)
    {
        if (ok)
        {
            if (nnum <  digit[npos])
                res += sol (npos,nnum,0) + num * cnt(npos,nnum,0);
            else if (nnum == digit[npos])
                res += sol(npos,nnum,1) + num * cnt(npos,nnum,1);
            else res += sol(npos , nnum ,ok) + num * cnt(npos , nnum ,1);
        }
    }
    return dq_sol[pos][num][ok] = res;
}
ll cal (ll x)
{
    digit.clear();
    while (x) digit.push_back(x%10) , x /= 10 ;
    while (digit.size() < 16) digit.push_back(0);
    reverse(digit.begin() , digit.end());
    memset(dp_cnt, -1 , sizeof dp_cnt);
    memset(dp_sol, -1 , sizeof dp_sol);
    return sol(0,0,1);
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> test;
    while (test--)
    {
        ll l , r;
        cin >> l >> r;
        cout << cal(r) - cal(l-1) << endl;
    }
}

}