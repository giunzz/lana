#include <bits/stdc++.h>
using namespace std;
int n,ai[5001],x,y,res=500000000;
int f[5001][5001],dx[5001],lmt[5001];
vector <int> son[5001];
void setlmt(int a){
    if(son[a].empty())
        lmt[a]=1;
    else{
        int sum=0;
        for(int i=0;i<son[a].size();i++){
            if(lmt[son[a][i]]==0)
                setlmt(son[a][i]);
            sum+=lmt[son[a][i]];
        }
        lmt[a]=sum;
    }
}
void dfs(int a){
    if(son[a].empty()){
        f[a][0]=ai[a];
        f[a][1]=abs(ai[a]-1);
        dx[a]=1;
    }
    else{
        for(int i=0;i<son[a].size();i++)
            if(dx[son[a][i]]==0)
                dfs(son[a][i]);
        for(int i=0;i<=lmt[a];i++){
            if(son[a].size()==1)
                f[a][i]=f[son[a][0]][i]+abs(ai[a]-i);
            else{
                int add=1000000;
                for(int j=0;j<=i;j++)
                    if(j<=lmt[son[a][0]]&&i-j<=lmt[son[a][1]])
                        add=min(add,f[son[a][0]][j]+f[son[a][1]][i-j]);
                f[a][i]=abs(ai[a]-i)+add;
            }
        }
        dx[a]=1;
    }
}
int main(){
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> ai[i];
    for(int i=1;i<n;i++){
        cin >> x >> y;
        son[x].push_back(y);
    }
    setlmt(1);
    dfs(1);
    for(int i=1;i<=n;i++){
        cout << i << " : ";
        for(int j=0;j<=lmt[i];j++)
            cout << f[i][j] << " " ;
        cout << endl;
    }
    for(int i=0;i<=lmt[1];i++)
        res=min(res,f[1][i]);
    cout << res;
}
