#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 2005
#define m_p make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
int n,m,k,demy;
int sum=0;
int xs,ys,zs;
bool danhdau[100000];
vector<pip> t,s;
vector<int> b;
int main()
{
    freopen("TEAWORLD.INP","r",stdin);
    freopen("TEAWORLD.OUT","w",stdout);
    cin>>m>>n>>k;
    b.resize(n);
    for(int i=0;i<m;i++){
        int u,v,z,r;
        cin>>u>>v>>z>>r;
        t.push_back(pip(u,pii(v,r)));
        if(v==0){
            demy++;
        }
    }
    for(int i=0;i<n;i++){
        int u,v,z,w;
        cin>>u>>v>>z>>w;
        s.pb(m_p(u,m_p(v,w)));
        if(v==0){
            demy++;
        }
    }
    cin>>xs>>ys>>zs;
    for(int i=0;i<s.size()/2;i++){
        sum+=s[i].second.second;
    }
    if(demy==n+m){
        sort(t.begin(),t.end());
        sort(s.begin(),s.end());
        for(int i=0;i<t.size();i++){
            cout<<t[i].first<<' ';

        }
    }
    else cout<<sum;
    return 0;
}
