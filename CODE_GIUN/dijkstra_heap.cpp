#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
#define pi pair<int,int>
const int MAXN = 1e5+7;
const ll oo = 1e9 + 7;
int N,M,u,v,w;
int visited[MAXN]={0} , MINF [MAXN] ={0}; 
int dd[MAXN]={0};
vector<pi>G[MAXN] ;

void DIJKSTRA ()
{
    priority_queue<pi, vector<pi> , greater<pi>> pq;
    for (int i = 1 ; i <= N ; i++) MINF[i] = oo ;
    MINF[1] = 1;
    pq.push(make_pair(1,0));
    while (pq.empty() == false)
    {
        u = pq.top().first ; // đỉnh u hiện tại đang thăm
        int dis_u = pq.top().second; // Dis_u là khoảng cách ngắn nhất từ 1 đến u lúc hiện tại
        pq.pop();
        for (pi v : G[u])
        {
            if (MINF[v.first] > dis_u + v.second ) 
                MINF[v.first] = dis_u + v.second;
            pq.push(make_pair(v.first,MINF[v.first]));
        }
        cerr << u << " " << v << endl;
    }
    

}
int main()
{
    priority_queue<pi, vector<pi> , greater<pi>> pq;
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> N >> M;
    for (int i = 1; i <= M ;  i++)
    {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
        pq.push(make_pair(v,w));
    }
    DIJKSTRA();
    cout << MINF[3] ;
        /*for (int i = 1; i <= N ;i++) 
    {
        for (int j = 1 ; j <= N ; j++) cerr << G[i][j].first << " " << G[i][j].second << "    ";
        cerr << endl; 
    }*/
}