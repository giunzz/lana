#include <bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair

using namespace std;

void pool(){
    freopen("BUBBLETEA.INP","r",stdin);
    freopen("BUBBLETEA.OUT","w",stdout);
    return;
}

const int MAXN=50005;
int n,k,vt[MAXN];
vector<PII> g[MAXN];
int f[MAXN];

void ip(){
    cin>>n>>k;
    for (int i=1;i<=k;i++) cin>>vt[i];
    for (int i=1;i<=n-1;i++){
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back(mp(v,c));
        g[v].push_back(mp(u,c));
        f[i]=c;
    }

    return;
}

bool okkt[MAXN];
long long maxx,minx=1e9+7;

/*void NIX(){
    for (int i=1;i<=k/2;i++){
        for (int j1=1;j1<=k;j1++)
        if (okkt[j1]==0){
            okkt[j1]=1;
            for (int j2=1;j2<=k;j2++)
            if (okkt[j2]==0){
                okkt[j2]=1;
                maxx=0;
                if (!DFS(j1))
                okkt[j2]=0;
            }
            okkt[j1]=0;
        }
    }

    return;
}*/

int main()
{
    pool();
    ip();
    sort(f+1,f+n);
    if (k==n) cout<<f[k/2];//NIX();
    else cout<<-1;

    return 0;
}
