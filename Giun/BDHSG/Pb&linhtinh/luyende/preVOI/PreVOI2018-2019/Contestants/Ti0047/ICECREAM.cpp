#include <bits/stdc++.h>
#define task "ICECREAM"
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
const ll M=1e9+7;
int n,mmax,m50,m1,m2;
ll res;
inline void _remain(ll &a) {if(a>=M) a-=M;}
void input()
{
    cin >>  n >> mmax >> m50 >> m1 >> m2;
}
void _try(int k,int _50,int _1,int _2)
{
    FOR(i,0,2)
    {
        if(!i)
        {
            if(_50==mmax) continue;
            if(k<n) _try(k+1,_50+1,_1,_2);
            else ++res;
        }
        else
            if(i&1)
            {
                if(_1==mmax) continue;
                if(_50>0)
                {
                    if(k<n) _try(k+1,_50-1,_1+1,_2);
                    else ++res;
                }
            }
            else
            {
                if(_2==mmax) continue;
                if(_50>0 && _1>0)
                {
                    if(k<n) _try(k+1,_50-1,_1-1,_2+1);
                    else ++res;
                }
                else
                    if(_50>2)
                    {
                        if(k<n) _try(k+1,_50-3,_1,_2+1);
                        else ++res;
                    }
            }
    }
    _remain(res);
}
void process()
{
    _try(1,m50,m1,m2);
    cout << res;
}
int main()
{
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    ios::sync_with_stdio(false);cin.tie(NULL);
    input();
    process();
    return 0;
}
