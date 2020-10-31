#include <bits/stdc++.h>
#define taskname "BUBBLETEA"
#define FORU(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const ll nmax=50000;
vector<int> vc(nmax+7,0);
vector <ii> tea(nmax+7);
vector<int> ctea(nmax+7,2);
bool visit[1007][1007];
int l[1007][1007];
bool t;
ll tl;
ll res=-1;
int st,ed;
vector<int> v[nmax];
int n,k;
void DFS(int u,int pre,int le)
{
    if(u==ed)
    {
        t=true;
        tl=le;
        return;
    }
    FORU(i,0,int(v[u].size())-1)
        if(v[u][i]!=pre && !visit[v[u][i]][u])
        {
            visit[v[u][i]][u]=true;
            visit[u][v[u][i]]=true;
            DFS(v[u][i],u,le+l[u][v[u][i]]);
            visit[v[u][i]][u]=false;
            visit[u][v[u][i]]=false;
        }
}
void xuli()
{
    ll tmp=0;
    FORU(i,1,k/2)
    {
        t=false;
        st=tea[i].fi;
        ed=tea[i].se;
        DFS(st,0,0);
        if(t) tmp=max(tmp,tl);
        else return;
    }
    if(res==-1) res=tmp;
    else res=min(res,tmp);
}
void sinh(int i)
{
    FORU(j,1,k/2)
        if(ctea[j]>0)
        {
            if(ctea[j]==1) tea[j].fi=vc[i];
            else tea[j].se=vc[i];
            --ctea[j];
            if(i==k) xuli();
            else sinh(i+1);
            ++ctea[j];
        }
}
void input()
{
    int tmp1,tmp2,tmp3;
    cin >> n >> k;
    FORU(i,1,k) cin >> vc[i];
    FORU(i,1,n-1)
    {
        cin >> tmp1 >> tmp2 >> tmp3;
        v[tmp1].pb(tmp2);
        v[tmp2].pb(tmp1);
        l[tmp1][tmp2]=tmp3;
        l[tmp2][tmp1]=tmp3;
    }
    sinh(1);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    #endif
    input();
    cout << res;
    return 0;
}
