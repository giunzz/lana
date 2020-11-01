#include <bits/stdc++.h>
#define maxn 5000
using namespace std;
int n,tang=1;
long long ans=0;
int s[maxn],d[maxn],pra[maxn],con[maxn];
vector<int> a[maxn],c[maxn];
vector<int> topo;
void dfs(int u){
    for(int i=0;i<a[u].size();i++){
        int v = a[u][i];
        if(pra[u]!= v){
            d[v]=d[u]+1;
            tang=max(tang,d[v]);
            pra[v]=u;
            con[u]++;
            c[u].push_back(v);
            dfs(v);
        }
    }
    topo.push_back(u);
}
int main()
{
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>s[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    pra[1]=1;
    d[1]=1;
    dfs(1);
    for(int i=1;i<=n;i++){
        if(con[i]==0){
            if(s[i]>1){
                ans+=s[i]-1;
                s[i]=1;
            }
            else if(s[i]==0){
                s[i]=1;
                ans++;
            }
        }
    }
    tang--;
    while(tang>0){
        for(int i=1;i<=n;i++){
            if(d[i]==tang){
                int su=0;
                if(!c[i].empty()){
                    for(int j=0;j<c[i].size();j++){
                        int x= c[i][j];
                        su+=s[c[i][j]];
                    }
                    ans+= abs(su-s[i]);
                    s[i]=su;
                }
            }
        }
        tang--;
    }
    cout<<ans;
    return 0;
}

