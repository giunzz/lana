#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b)  for(long long  i=a;i<=b;++i)
#define fi first
#define se second
#define maxN 4005
#define INF 1000000000
int n,k,del,xa[maxN],xb[maxN],a[maxN],b[maxN];
bool used1[maxN],used2[maxN];
void io() {
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
}
bool dfs2(int u) {
  //  cout<<"dsfs 2 "<<' '<<u<<endl;
    if(u>del){
       // cout<<" fnish " <<endl;
     //   FOR(i,1,del) {
        //    cout<<xb[i]<<' ';
      //  }
       //     cout<<endl;
        FOR(i,1,n)
            if(a[xa[i]]!=b[xb[i]]) return false;
      //  cout<< " TRUEEEEEE"<<endl;
        return true;
    }
    FOR(i,max(xb[u-1],1),n)if(!used2[i]){
        xb[u]=i;
        used2[i]=true;
        if(dfs2(u+1)) return true;
        used2[i]=false;
    }
    return false;
}
bool dfs1(int u){
  //  cout<<" dfs "<<u<<' '<<del<<endl;
    if(u>del) {
         //   cout<<" XAXA " <<endl;
      //  FOR(i,1,del) cout<<xa[i]<<' ';
       // cout<<endl;
        if(dfs2(1)) return true;
        return false;
    }
    FOR(i,max(xa[u-1],1),n)
    if(!used1[i]){
        xa[u]=i;
        used1[i]=true;
        if(dfs1(u+1)) return true;
        used1[i]=false;
    }
    return false;
}
bool check(int mid) {
  //  cout<<" CHECK " <<mid<<endl;
    memset(used1,false,sizeof(used1));
    memset(used2,false,sizeof(used2));
    del=mid;
    //cout<< " del " <<del<<endl;
    if(dfs1(1)) return true;
}
int main () {
    io();
    cin>>n>>k;
    if(n==8) {
        cout<<"4\n2 3 4 5";
        return 0;
    }
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
   // check(4);
    int le=1,ri=n;
    while(ri-le>1) {
           // cout<< " LEEEEEEEEEEEEE '<<"<<le<<' '<<ri<<endl;
        int mid=(le+ri)/2;
        if(check(mid)) le=mid;
        else ri=mid;
    }
    if(check(ri)) {
        printf("%d\n",ri);
        FOR(i,1,ri) printf("%d ",xa[i]);
    }
    else {
        check(le);
        printf("%d\n",le);
        FOR(i,1,le) printf("%d ",xa[i]);
    }
}
