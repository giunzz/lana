#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
long long oo = 1e15;
int n,k;
int a[maxn];
long long s[maxn];
long long t[maxn];
long long d[maxn],c[maxn];
long long res =oo;
int main()
{
    freopen("gifts.inp","r",stdin);
    freopen("gifts.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];


    for(int i=1;i<=n-k+1;i++) t[i]=s[i+k-1]-s[i-1];

    for(int i=k;i<=n;i++) d[i]=max(d[i-1],t[i-k+1]);
    for(int i=n-k+1;i>=1;i--) c[i]=max(c[i+1],t[i]);
    for(int i=1;i<=n-k+1;i++)
        res=min(res,max(d[i-1],c[i+k]));
        cout<<res;
}
