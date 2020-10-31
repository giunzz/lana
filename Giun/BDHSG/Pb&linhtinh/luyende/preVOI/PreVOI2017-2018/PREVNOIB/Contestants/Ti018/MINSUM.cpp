#include <bits/stdc++.h>
#define taskname "MINSUM"
#define FORU(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define el '\n'
using namespace std;
typedef pair<int,int> ii;
int A,B;
vector <bool> isprime(1LL*1000007,true);
vector <int> prime(1LL*1000007,0);
int cnt=0;
int GCD(int a,int b)
{
    int r;
    while(b!=0){r=a%b;a=b;b=r;}
    return a;
}
int _pow(int a,int b)
{
    int c=1;
    for(;b;b/=2,a*=a)
        if(b&1) c*=a;
    return c;
}
int _find(int a,int b)
{
    int res=0;
    while(a%b==0) {a/=b;++res;};
    return res;
}
void snto(int u)
{
    for(int i=2;i*i<=u;++i)
        if(isprime[i])
                for(int j=i*i;j<=u;j+=i)
                    isprime[j]=false;
    FORU(i,2,u)
        if(isprime[i]) prime[++cnt]=i;
}
vector <ii> _fp(int u)
{
    vector <ii> res;
    for(int i=1;prime[i]*prime[i]<=u;++i)
    {
        int c=_find(u,prime[i]);
        if(c>0)
        {
            u/=_pow(prime[i],c);
            res.pb(mp(prime[i],c));
        }
    }
    if(u>1) res.pb(mp(u,1));
    return res;
}
void process()
{
    vector <ii> fpA;
    vector <ii> fpB;
    int tmp=GCD(A,B);
    A/=tmp;B/=tmp;
    if(A>B)
    {
        fpA=_fp(A);
        FORD(i,fpA.size()-1,0)
        {
            A/=_pow(fpA[i].fi,fpA[i].se-(fpA[i].se%2));
            fpA[i].se%=2;
        }
        if(B>1)
        {
            fpB=_fp(B);
            FORD(i,fpB.size()-1,0)
            {
                B/=_pow(fpB[i].fi,fpB[i].se-(fpB[i].se%2));
                fpB[i].se%=2;
            }
        }
        FORU(i,0,fpA.size()-1)
            if(fpA[i].se>0)
               if(B < A/fpA[i].fi)
               {
                   B*=fpA[i].fi;
                   A/=fpA[i].fi;
                   --fpA[i].se;
               }
    }
    else
    {
        fpB=_fp(B);
        FORD(i,fpB.size()-1,0)
        {
            B/=_pow(fpB[i].fi,fpB[i].se-(fpB[i].se%2));
            fpB[i].se%=2;
        }
        if(A>1)
        {
            fpA=_fp(A);
            FORD(i,fpA.size()-1,0)
            {
                A/=_pow(fpA[i].fi,fpA[i].se-(fpA[i].se%2));
                fpA[i].se%=2;
            }
        }
        FORU(i,0,fpB.size()-1)
           if(fpB[i].se>0)
               if(A < B/fpB[i].fi)
               {
                   A*=fpB[i].fi;
                   B/=fpB[i].fi;
                   --fpB[i].se;
               }
    }
    cout << A << " " << B << el;
}
void input()
{
    snto(100000);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> A >> B;
        process();
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    input();
    return 0;
}
