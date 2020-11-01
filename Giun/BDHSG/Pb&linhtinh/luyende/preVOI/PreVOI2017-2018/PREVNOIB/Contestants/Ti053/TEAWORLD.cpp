#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define NMAX 1000000
ll n,m,k;
ll dx[2*NMAX];
ll sumR[2*NMAX],sumL[2*NMAX];
struct ht{
    int x,r;
};
struct point{
    int x,val;
};
ht h[NMAX];
point a[20];
bool cmp(const point &x,const point &y){
    return x.x<y.x;
}
void enter(){
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        ll x,y,z,r;
        cin>>x>>y>>z>>r;
        h[i].x=x+NMAX,h[i].r=r;
        dx[h[i].x+r+1]++;
        dx[h[i].x-r-1]++;
    }
    for(int i=1;i<=n;i++){
        int x,y,z,e;
        cin>>x>>y>>z>>e;
        a[i].x=x+NMAX,a[i].val=e;
    }
    int zxcv,zxvc,start;
    cin>>start>>zxcv>>zxvc;
    start+=NMAX;
    for(int i=start+1;i<2*NMAX;i++){
        sumR[i]=sumR[i-1]+dx[i];
    }
    for(int i=start-1;i>=0;i--){
        sumL[i]=sumL[i+1]+dx[i];
    }
    sort(a+1,a+n+1,cmp);
    ll res=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ll cur=0;
            if(a[i].x<=NMAX&&a[j].x<=NMAX){
                cur=sumL[a[i].x];
            }
            if(a[i].x>=NMAX){
                cur=sumR[a[j].x];
            }
            if(a[i].x<=NMAX&&a[j].x>=NMAX){
                cur=sumL[a[i].x]+sumR[a[j].x];
            }
         //   cout<<i<<" "<<j<<" "<<cur<<'\n';
            if(cur<=k){
                ll sum=0;
                for(int t=i;t<=j;t++){
                    sum+=a[t].val;
                }
             //   cout<<sum<<'\n';
                res=max(res,sum);
            }
        }
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    enter();
}
