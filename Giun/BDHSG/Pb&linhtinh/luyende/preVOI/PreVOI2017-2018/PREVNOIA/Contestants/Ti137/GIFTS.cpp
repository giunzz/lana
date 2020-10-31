#include <iostream>
#include <cstdio>
#include <vector>
#define NAME "GIFTS."
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;

#define maxn (1000000+5)
int n,k;
int a[maxn];
ll s[maxn];
ll res=1e17;

void input(){
//    cin>>n>>k;
//    FOR(i,1,n) cin>>a[i];
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    s[0]=0;
    FOR(i,1,n) s[i]=s[i-1]+(ll)a[i];
//    FOR(i,1,n) cout<<s[i]<<" ";
}

void Xuli(){
    vector<ll> MAX1(n-k+5), MAX2(n-k+5);
    MAX1[0]=0;
    FOR(i,1,n-k+1) MAX1[i]=max(MAX1[i-1],s[i+k-1]-s[i-1]);
    MAX2[n-k+2]=0;
    for(int i=n-k+1;i>=1;i--) MAX2[i]=max(MAX2[i+1],s[i+k-1]-s[i-1]);

    ll r1,r2,sum;
    FOR(i,1,n-k+1){
        sum=s[i+k-1]-s[i-1];
        if (i>=k+1) r1=MAX1[i-k]; else r1=0;
        if (i<=n-(2*k)+1) r2=MAX2[i+k]; else r2=0;
        if (sum>=r1 && sum>=r2) res=min(res,sum);
    }
    cout<<res;
}


int main()
{
    freopen(NAME"inp","r",stdin);
    freopen(NAME"out","w",stdout);
    iostream::sync_with_stdio(0);
    input();
    Xuli();
}
