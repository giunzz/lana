#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define ULL unsigned long long
#define pii pair<ULL,ULL>
#define F first
#define S second
using namespace std;

int n;
ULL a,b,k;
ULL mod;
bool ok;
vector<int> res;

void DFS(int x, int d)
{
    if (x==n+1)
    {
        if (d==k) ok=true;
        return;
    }

    ULL dd;

    dd=(d*10+a)%mod;
    DFS(x+1,dd);
    if (ok)
    {
        res.push_back(a);
        return;
    }

    dd=(d*10+b)%mod;
    DFS(x+1,dd);
    if (ok)
    {
        res.push_back(b);
        return;
    }

}

void sub1()
{
    DFS(1,0);
    if (res.size()!=0)
    {
        for(int i=res.size()-1; i>=0; i--)
            cout<<res[i];
    }
    else cout<<-1;
}

void print(ULL p1, ULL p2, int n1, int n2)
{
    if (p1!=-1)
    {
        FOR(i,0,n1-1)
            if ((p1>>i)&1) cout<<b;
            else cout<<a;
    }
    FOR(i,0,n2-1)
        if ((p2>>i)&1) cout<<b;
        else cout<<a;
    exit(0);
}

void sub2()
{
    vector<pii> f1,f2;
    vector<ULL> f3;
    ULL m1[65]={},m2[65]={};

    m1[n]=a; m2[n]=b;
    for(int i=n-1; i>=1; i--)
    {
        m1[i]=m1[i+1]*10%mod;
        m2[i]=m2[i+1]*10%mod;
    }

    int n1=n/2,n2=n-n1;
    if (n1==0) f1.push_back(pii(0,-1));
    else
    FOR(i,0,(1<<n1)-1)
    {
        ULL x=0;
        FOR(j,0,n1-1)
            if ((i>>j)&1) x=(x+m2[j+1])%mod;
            else x=(x+m1[j+1])%mod;
        f1.push_back(pii(x,i));
    }
    FOR(i,0,(1<<n2)-1)
    {
        ULL x=0;
        FOR(j,0,n2-1)
            if ((i>>j)&1) x=(x+m2[j+n1+1])%mod;
            else x=(x+m1[j+n1+1])%mod;
        f2.push_back(pii(x,i));
    }

    sort(f2.begin(),f2.end());
    FOR(i,0,f2.size()-1)
        f3.push_back(f2[i].F);

    FOR(i,0,f1.size()-1)
    {
        int vt;
        vt=lower_bound(f3.begin(),f3.end(),k-f1[i].F)-f3.begin();
        if (f2[vt].F==k-f1[i].F) print(f1[i].S,f2[vt].S,n1,n2);
        vt=lower_bound(f3.begin(),f3.end(),k+mod-f1[i].F)-f3.begin();
        if (f2[vt].F==k+mod-f1[i].F) print(f1[i].S,f2[vt].S,n1,n2);
    }

    cout<<-1;
}

int main()
{
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>a>>b>>n>>k;
    if (a>b) swap(a,b);

    mod=1;
    FOR(i,1,n) mod=mod*2;

    if (n<=20) sub1();
    if (20<n && n<=40) sub2();
    if (40<n) sub1();
}
