#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define name "modulo"

using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
const ll oo = 1e18;
const int nmax = 1e6+5;
ll a,b,n,k,ok=0;
ll x,mod,nhan=1;
int kq=0;



void quaylui(int i)
{
    if(ok) return;
    {
        x=x*10+a;
        if(i==n) {if(x%mod == k) {ok=1;cout << x;exit;}}
        else  quaylui(i+1);
        x/=10;
    }
    {
        x=x*10+b;
        if(i==n) {if(x%mod == k) {ok=1;cout << x;exit;}}
        if(i<n) quaylui(i+1);
        x/=10;
    }
}

map <ll,ll> M;

void quaylui1(int i)
{
    if(ok) return;
    {
        x=x*10+a;
        if(i==n) {M[x%mod]=x;}
        else  quaylui1(i+1);
        x/=10;
    }
    {
        x=x*10+b;
        if(i==n) {M[x%mod]=x;}
        else quaylui1(i+1);
        x/=10;
    }
}


void quaylui2(int i)
{
    if(ok) return;
    {
        x=x*10+a;
        if(i==n)
            {
                ll tg=(x*nhan)%mod,tg2;
                if(tg<=k)
                    tg2=k-tg;
                else
                    tg2=k+mod-tg;
                if(M[tg2]!=0)
                {
                    //ll x=x*nhan+M[tg2];
                    //ll z=M[tg2];
                    {ok=1;cout << x<<M[tg2];exit;}
                }
            }
        else  quaylui2(i+1);
        x/=10;
    }
    {
        x=x*10+b;
        if(i==n)
            {
                ll tg=(x*nhan)%mod,tg2;
                if(tg<=k)
                    tg2=k-tg;
                else
                    tg2=k+mod-tg;
                if(M[tg2]!=0)
                {
                    {ok=1;cout << x;cout << M[tg2];exit;}
                }
            }
        else quaylui2(i+1);
        x/=10;
    }
}


void xuli1()
{
    for(int i=1;i<=20;i++) nhan=(nhan*10)%mod;
    x=0;int tg=n;
    n=20;
    quaylui1(1);
    x=0;
    n=tg-n;
    quaylui2(1);
    if(ok==0)
        cout << -1;
}

void xuli2()
{
    cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    cin >> a >> b >>n >>k;
    mod = (1<<(n));
    if(n<=20)
    {
        x=0;
        quaylui(1);
        if(!ok)
        cout << -1;
    }
    else if(n<=40 ) xuli1();
    else xuli2();
	return 0;
}
