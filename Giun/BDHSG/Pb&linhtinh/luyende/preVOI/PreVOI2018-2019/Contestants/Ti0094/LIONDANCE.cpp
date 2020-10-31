#include <bits/stdc++.h>
#define ll int
#define fort(i,a,b) for(ll i=(a);i<=(b);++i)
#define N 4005

using namespace std;

vector <ll> vc[N],vcc[N];
ll n,t,a[N],b[N],f[N][N],tmp;

ll lui(ll i,ll j){
    if (i>n || j>n) return 0;
    if (f[i][j]!=-1) return f[i][j];
    if (vc[i].size()==0 || vcc[j].size()==0) return f[i][j]=0;

    ll ans=0,n_i,n_j;


    fort(h,0,vc[i].size()-1){
        n_i=vc[i][h];
        fort(k,0,vcc[j].size()-1){
            n_j=vcc[j][k];
            if (a[n_i]!=b[n_j]) continue;
            ans=max(ans,lui(n_i,n_j)+1);
        }
    }

    return f[i][j]=ans;
}

void tv(ll i,ll j){
    if (i>n || j>n)  return;
    if (vc[i].size()==0 || vcc[j].size()==0) return;

    ll n_i,n_j,ii,jj,nh=-1;

    fort(h,0,vc[i].size()-1){
        n_i=vc[i][h];
        fort(k,0,vcc[j].size()-1){
            n_j=vcc[j][k];
            if (a[n_i] != b[n_j]) continue;
            if (tmp==lui(n_i,n_j)+1 && nh<a[n_i]){
                nh=a[n_i];
                ii=n_i;
                jj=n_j;
            }
        }
    }

    if (nh==-1) return;
    cout<<nh<<" ";
    tmp--;
    tv(ii,jj);
}

int main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);

    cin>>n>>t;
    fort(i,1,n){
        cin>>a[i];
        vc[0].push_back(i);
        vcc[0].push_back(i);
    }
    fort(i,1,n) cin>>b[i];

    fort(i,1,n) fort(j,i+1,n) if (abs(a[i]-a[j])<=t) vc[i].push_back(j);
    fort(i,1,n) fort(j,i+1,n) if (abs(b[i]-b[j])<=t) vcc[i].push_back(j);

    memset(f,-1,sizeof(f));
    tmp=lui(0,0);
    cout<<tmp<<"\n";
    tv(0,0);

    return 0;
}
