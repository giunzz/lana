#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

long long ans=0,sum=0;
long long kq=1e18;

int n,m,k;
int u_min,v_min,u_max,v_max;
long long a[301][301];
pair<int ,int > tr[301][301];
pair<int ,int > tr_ans[301][301];

bool used[301][301];

const int DX[2]={0,1};
const int DY[2]={1,0};

void IO()
{
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
}

void read()
{
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);

}

void DFS(int i,int j)
{
    if(i==u_max&&j==v_max&&sum>=ans)
    {
        for(int pi=1;pi<=m;pi++)
            for(int yi=1;yi<=n;yi++)
            tr_ans[pi][yi]=tr[pi][yi];
        ans=sum;
    }

    for(int wi=0;wi<2;wi++)
    {
        int l = i+DX[wi];
        int r = j+DY[wi];
        if(used[l][r])continue;
        if(l<u_min||l>u_max||r<v_min||r>v_max)continue;
        tr[l][r]={i,j};
        sum+=a[l][r];
        DFS(l,r);
        sum-=a[l][r];
    }
}

void BFS(int i,int j)
{

    if(i==u_max&&j==v_max&&sum>ans)
        ans=sum;

    for(int wi=0;wi<2;wi++)
    {
        int l = i+DX[wi];
        int r = j+DY[wi];
        if(used[l][r])continue;
        if(l<u_min||l>u_max||r<v_min||r>v_max)continue;
        tr[l][r]={i,j};
        sum+=a[l][r];
        BFS(l,r);
        sum-=a[l][r];
    }
}

void solve()
{
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d%d",&u_min,&v_min,&u_max,&v_max);
        sum=0;
        DFS(u_min,v_min);
        tr_ans[u_min][v_min]={u_min,v_min};

        int petl=tr_ans[u_max][v_max].fi,petr=tr_ans[u_max][v_max].se;
        ans=0;
        while(true)
        {
            sum=0;
            used[petl][petr]=true;
            BFS(u_min,v_min);
            used[petl][petr]=false;
            int nhol=petl,nhor=petr;
            petl=tr_ans[nhol][nhor].fi,petr=tr_ans[nhol][nhor].se;
            if(petl==u_min&&petr==v_min)break;
            if(petl<u_min||petl>u_max||petr<v_min||petr>v_max)break;
            kq=min(ans,kq);

        }

        kq+=a[u_min][v_min];
        cout<<kq<<'\n';
    }
}

int main()
{
    IO();
    memset(used,false,sizeof(used));
    read();
    solve();
    return 0;
}
