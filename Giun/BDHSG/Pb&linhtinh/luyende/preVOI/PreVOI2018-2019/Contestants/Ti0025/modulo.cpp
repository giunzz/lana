#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define maxn 65
#define pll pair<long long ,long long  >
#define mp make_pair
#define F first
#define S second
#define int long long
using namespace std;
int a,b,n;
long long k;
int dd[maxn];
pll kq[1<<20+5];
int dem1=0;
void dq(int x)
{
    if(x>n)
    {
        long long sd=(1ll<<n);
        long long re=0;
        FOR(i,1,n)
        {
            if(dd[i])
            {
                re=(re*10ll+1ll*a)%sd;
            }
            else
                re=(re*10ll+1ll*b)%sd;
        }

        if(re==k)
        {
            FOR(i,1,n)
            {
                if(dd[i])
                    cout<<a;
                else
                    cout<<b;
            }
            exit(0);
        }
    }
    else
    {
        FORD(i,1,0)
        {
            dd[x]=i;
            dq(x+1);
        }
    }
}
void dq1(int x)
{
    if(x>20)
    {
        long long sd=(1ll<<n);
        long long re=0;
        int tv=0;
        FOR(i,1,20)
        {
            if(dd[i])
            {
                re=(re*10ll+1ll*a)%sd;
            }
            else
                re=(re*10ll+1ll*b)%sd;
        }
        FORD(i,20,1)
        {
            tv=tv*2ll+dd[i];
        }
        FOR(i,21,n)
        {
            re=re*10;
            re%=sd;
        }
        kq[++dem1].F=re;
//        cout<<re<<endl;
        kq[dem1].S=1ll*tv;

    }
    else
    {
        FORD(i,1,0)
        {
            dd[x]=i;
            dq1(x+1);
        }
    }
}
void dq2(int x)
{
    if(x>n)
    {
        long long sd=(1ll<<n);
        long long re=0;
        FOR(i,21,n)
        {
            if(dd[i])
            {
                re=(re*10l+1ll*a)%sd;
            }
            else
                re=(re*10l+1ll*b)%sd;
        }
        int vt=lower_bound(kq+1,kq+1+dem1,mp(sd-re,0ll))-kq;
//        cout<<vt<<endl;
        if(kq[vt].F==sd-re)
        {
            long long mot=kq[vt].S;
            int demd=0;
            while(mot)
            {
                if(mot%2) cout<<a;
                else cout<<b;
                mot/=2;
                demd++;
            }
            FOR(i,demd+1,20) cout<<b;
            FOR(i,21,n)
            {
                if(dd[i]) cout<<a;
                else cout<<b;
            }
            exit(0);
        }
    }
    else
    {
        FORD(i,1,0)
        {
            dd[x]=i;
            dq2(x+1);
        }
    }
}
void trau()
{
    dq(1);
    cout<<-1;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>a>>b>>n>>k;
    if(n<=20)
        trau();
    else if(n<=40)
    {
        dq1(1);
        sort(kq+1,kq+dem1+1);
        dq2(21);
        cout<<-1;
    }
    else cout<<-1;
}
