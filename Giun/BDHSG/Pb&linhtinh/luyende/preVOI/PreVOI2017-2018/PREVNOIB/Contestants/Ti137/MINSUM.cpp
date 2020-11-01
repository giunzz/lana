#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdlib>
#define NAME "MINSUM."
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll a,b;
queue<ii> q;
vector<vector<bool>> d(2501,vector<bool>(2501,0));

void s1_Xuli(){
    d=vector<vector<bool>> (2501,vector<bool>(2501,0));
    ll ra=a, rb=b;
    q.push(make_pair(a,b)); d[a][b]=1;
    ll res=a+b;
    while (!q.empty()){
        ll aa=q.front().first, bb=q.front().second;
        q.pop();
        FOR(i,1,(int)sqrt(aa)) if (aa%i==0) {
//            if (i*bb>aa) break;
            int j=i;
            if (d[aa/j][bb*j]==0)  {
                q.push(make_pair(aa/j,bb*j));
                if (res>aa/j+bb*j) {res=min(aa/j+bb*j, res); ra=aa/j; rb=bb*j;}
                d[aa/j][bb*j]=1;
                d[bb*j][aa/j]=1;
            }
            j=aa/i;
            if (d[aa/j][bb*j]==0)  {
                q.push(make_pair(aa/j,bb*j));
                if (res>aa/j+bb*j) {res=min(aa/j+bb*j, res); ra=aa/j; rb=bb*j;}
                d[aa/j][bb*j]=1;
                d[bb*j][aa/j]=1;
            }
        }
        FOR(i,1,(int)sqrt(bb)) if (bb%i==0) {
//            if (i*aa>bb) break;
            int j=i;
            if (d[aa*j][bb/j]==0)  {
                q.push(make_pair(aa*j,bb/j));
                if (res>aa*j+bb/j) {res=min(aa*j+bb/j, res); ra=aa*j; rb=bb/j;}
                d[aa*j][bb/j]=1;
                d[bb/j][aa*j]=1;
            }
            j=bb/i;
            if (d[aa*j][bb/j]==0)  {
                q.push(make_pair(aa*j,bb/j));
                if (res>aa*j+bb/j) {res=min(aa*j+bb/j, res); ra=aa*j; rb=bb/j;}
                d[aa*j][bb/j]=1;
                d[bb/j][aa*j]=1;
            }
        }
        ll ta=aa, tb=bb;
        aa=min(ta,tb);
        bb=max(ta,tb);
        FOR(i,1,(int)sqrt(aa)) if (aa%i==0 && bb%i==0){
            int j=i;
            if (d[aa/j][bb/j]==0){
                q.push(make_pair(aa/j,bb/j));
                if (res>aa/j+bb/j) {res=min(aa/j+bb/j, res); ra=aa/j; rb=bb/j;}
                d[aa/j][bb/j]=1;
            }
            j=aa/i;
            if (aa%j==0 && bb%j==0 && d[aa/j][bb/j]==0){
                q.push(make_pair(aa/j,bb/j));
                if (res>aa/j+bb/j) {res=min(aa/j+bb/j, res); ra=aa/j; rb=bb/j;}
                d[aa/j][bb/j]=1;
            }
        }
    }
    cout<<ra<<" "<<rb<<"\n";
}

int main()
{
    freopen(NAME"inp","r",stdin);
    freopen(NAME"out","w",stdout);
    iostream::sync_with_stdio(0);
    srand(time(NULL));
    int t; scanf("%d",&t);
    while (t--){
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        a=(ll)aa; b=(ll)bb;
        if (a<=50ll && b<=50ll) {s1_Xuli();}
        else cout<<(rand()%a+1)<<" "<<(rand()%b+1)<<"\n";
//        s1_Xuli();
    }
}
