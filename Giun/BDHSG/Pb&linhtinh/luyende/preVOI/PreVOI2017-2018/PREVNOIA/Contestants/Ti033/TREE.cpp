#include<bits/stdc++.h>
#define N 5003
using namespace std;
int n;
int in[N], numL[N];
vector<int> a[N];
int f[N][N];
void DFS(int u, int pre)
    {
        vector<int> child; child.clear();
        for (int i=0; i < a[u].size(); i++){
            int v=a[u][i];
            if (v != pre){
                child.push_back(v);
                DFS(v,u);
                numL[u]+=numL[v];
            }
        }
        int sl=int(child.size());
        if (sl == 0){
            numL[u]=1;
            f[u][0]=in[u];
            f[u][1]=abs(in[u]-1);
            return;
        }
        if (sl == 1){
            int v=child[0];
            for (int i=0; i <= numL[u]; i++)
                f[u][i]=f[v][i]+abs(in[u]-i);
            return;
        }
        if (sl != 2) return;
        int v1=child[0], v2=child[1];
        for (int i=0; i <= numL[u]; i++){
            int add=abs(in[u]-i);
            int st=max(0,i-numL[v2]);
            int en=min(i,numL[v1]);
            for (int j=st; j <= en; j++)
                f[u][i]=min(f[u][i],f[v1][j]+f[v2][i-j]+add);
        }
    }
int main()
{
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for (int i=1; i <= n; i++)
        cin>>in[i];
    for (int i=1; i < n; i++){
        int u,v; cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=0; i <= n+1; i++)
        for (int j=0; j <= n+1; j++)
            f[i][j]=n*n;
    DFS(1,0);
    int res=f[1][0];
    for (int i=1; i <= n; i++)
        res=min(res,f[1][i]);
    cout<<res;
    return 0;
}
