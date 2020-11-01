#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define For(i,a,b) for(int i=a;i<=b;i++)
int n,d;
int l[4001],r[4001];
map<int,int> p2;
void input(){
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
    cin>>n>>d;
    For(i,1,n){
        scanf("%d",&l[i]);
        }
    For(i,1,n){
        scanf("%d",&r[i]);
        p2[r[i]]++;
    }
}
int x[4001];
bool v[22];
vector<int> kq;
void dfs(int i,int k){
    if(i>k){
        map<int,int> p1;
        for(int j=1;j<=k;j++){
            p1[l[x[j]]]++;
        }
        for(int j=1;j<=k;j++)
            if(p1[l[x[j]]]>p2[l[x[j]]]) return;
        vector<int> tmp;
        for(int j=1;j<=k;j++)
            tmp.push_back(l[x[j]]);
        if(tmp>kq){
            kq=tmp;
        }
        return;
    }
    for(int j=1;j<=n;j++){
        if(j>x[i-1]&&abs(l[j]-l[x[i-1]])<=d){
            x[i]=j;
            dfs(i+1,k);
        }
    }
}
void work(){
    for(int k=4;k<=n;k++){
        x[0]=0;
        dfs(1,k);
        if(kq.size()!=0) break;
    }
    cout<<kq.size()<<endl;
    for(int i=0;i<kq.size()-1;i++)
        cout<<kq[i]<<' ';
    cout<<kq[kq.size()-1];
}
int main(){
    input();
    work();
}
