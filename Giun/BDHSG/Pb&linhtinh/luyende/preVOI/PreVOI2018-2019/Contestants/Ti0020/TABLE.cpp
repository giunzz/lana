#include <bits/stdc++.h>
using namespace std;
#define maxn 310
typedef long long ll;
int m,n,k,u,v,p,q;
int a[maxn][maxn],b[maxn][maxn];
ll f[maxn][maxn],res,s[maxn][maxn];
typedef pair<int,int>ii;
#define fi first
#define se second
vector<ii>t;

//int cals(int x1,int y1,int x2,int y2){
//    return
//}
//int calle(int x1,int y1,int x2,int y2){
//    if(f[x1-1][y1]<=f[x1][y1-1]) return cals(x1,y1,x2,y2);
//    return cals(x1,y1,x2,y2)-a[x1-1][y1]+a[x1][y1-1];
//}
//int calup(int x1,int y1,int x2,int y2){
//    if(f[x1-1][y1]>=f[x1][y1-1]) return cals(x1,y1,x2,y2);
//    return cals(x1,y1,x2,y2)-a[x1][y1-1]+a[x1-1][y1];
//}

int main(){
    freopen("TABLE.INP","r",stdin);
    freopen("TABLE.OUT","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            s[i][j]=max(s[i-1][j],s[i][j-1])+a[i][j];
        }
    }
    while(k--){
        scanf("%d%d%d%d",&u,&v,&p,&q);
        for(int i=u;i<=p;i++) f[i][v-1]=b[i][v-1]=0;
        for(int j=v;j<=q;j++) f[u-1][j]=b[u-1][j]=0;
        for(int i=u;i<=p;i++){
            for(int j=v;j<=q;j++){
                b[i][j]=a[i][j];
                f[i][j]=max(f[i-1][j],f[i][j-1])+b[i][j];
            }
        }
        int x=p,y=q;res=f[p][q];
        for(int i=1;i<p+q-u-v;i++){
            if(f[x-1][y]==(f[x][y]-a[x][y])){
                x--;
                t.push_back(ii(x,y));
            }
            else{
                y--;
                t.push_back(ii(x,y));
            }
        }
        while(!t.empty()){
            x=t.back().fi;y=t.back().se;t.pop_back();
//            for(int i=x+1;i<=q;i++) res=min(res,cals(u,v,i,y-1)+calle(i,y,p,q));
//            for(int i=y+1;i<=q;i++) res=min(res,cals(u,v,x-1,i)+calup(x,i,p,q));
            b[x][y]=0;
            for(int i=u;i<=p;i++){
                for(int j=v;j<=q;j++){
                    f[i][j]=max(f[i-1][j],f[i][j-1])+b[i][j];
                }
            }
            res=min(res,f[p][q]);
            b[x][y]=a[x][y];
        }
        cout<<res<<"\n";
    }
    return 0;
}
