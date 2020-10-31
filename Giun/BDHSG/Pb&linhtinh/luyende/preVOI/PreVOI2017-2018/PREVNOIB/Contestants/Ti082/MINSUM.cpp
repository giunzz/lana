#include<bits/stdc++.h>
#define ll long long
#define maxn 10005
using namespace std;
int a,b,dem,X[maxn],factor[maxn];
ll resA,resB;
void dfs(int i,ll A,ll B)
{
        if (i==dem+1)
        {
                if (A+B<resA+resB)
                {
                        resA=A;
                        resB=B;
                }
                return;
        }
        dfs(i+1,A*factor[i],B);
        dfs(i+1,A,B*factor[i]);
}
void solve()
{
        resA=1e18;
        resB=1e18;
        int x=__gcd(a,b);
        a/=x;b/=x;
        dem=0;
        if (a==b&&a==1)
        {
                cout<<a<<" "<<b<<"\n";
                return;
        }
        for (int i=2;i*i<=a;++i)
        {
                if (a%i) continue;
                int d=0;
                while(a%i==0)
                {
                        ++d;
                        a/=i;
                }
                if (d%2)factor[++dem]=i;
        }
        if (a!=1) factor[++dem]=a;
        for (int i=2;i*i<=b;++i)
        {
                if(b%i) continue;
                int d=0;
                while(b%i==0)
                {
                        ++d;
                        b/=i;
                }
                if (d%2)factor[++dem]=i;
        }
        if (b!=1) factor[++dem]=b;
        dfs(1,1,1);
        if(resA>resB) swap(resA,resB);
        cout<<resA<<" "<<resB<<"\n";
}
int main()
{
        freopen("MINSUM.inp","r",stdin);
        freopen("MINSUM.out","w",stdout);
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int test;
        cin>>test;
        while(test--)
        {
                cin>>a>>b;
                solve();
        }
}
