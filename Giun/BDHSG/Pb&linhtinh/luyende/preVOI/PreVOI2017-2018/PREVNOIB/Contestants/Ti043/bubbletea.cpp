#include <bits/stdc++.h>
using namespace std;
ifstream fin("bubbletea.inp");
ofstream fo("bubbletea.out");
#define cin fin
#define cout fo
#define mp make_pair
#define fi first
#define se second
#define pb push_back
int n,k,u,v,c;
int a[50007],mark[50007],par[50007],vis[50007],ok,prep[50007],st[50007];
long long dis[50007],cr;
vector < pair <int,int> > edge[50007];
bool cmp(int x,int y){
	return (dis[x]<dis[y] || (dis[x]==dis[y] && x<y));
}
void dfs(int u){
	int cnt=0;
	if(mark[u]==1) cnt++;
	prep[u]++;
	for(int i=0;i<(int)edge[u].size();i++){
		int v=edge[u][i].fi;
		long long c=edge[u][i].se;
		if(par[u]==v) continue;
		par[v]=u;
		dis[v]=dis[u]+c;
		dfs(v);
		if(prep[v]%2==1) cnt++;
		prep[u]+=prep[v];
	}
	if(cnt>=2) st[u]=1;
}
int dfs2(int u,long long x){
	if(ok==0) return 0;
	vector <int> cur;
	for(int i=0;i<(int)edge[u].size();i++){
		int v=edge[u][i].fi;
		if(par[u]==v) continue;
		int cl=dfs2(v,x);
		if(cl!=0) cur.pb(cl);
	}
	if(mark[u]==1) cur.pb(u);
	if((int)cur.size()>=2){
		sort(cur.begin(),cur.end(),cmp);
		for(int i=0;i<(int)cur.size();i++) vis[i]=0;
		if(dis[cur[0]]+dis[cur[1]]-2LL*dis[u]>x){
			ok=0;
			return 0;
		}
		int cnt=(int)cur.size()/2,l=(int)cur.size()-2;
		for(int i=(int)cur.size()-1;i>=0;i--){
			if(vis[i]==1) continue;
			if(cnt==0) break;
			vis[i]=1;
			while(l>=i) l--;
			while(l<i-1 && dis[cur[i]]+dis[cur[l+1]]-2LL*dis[u]<=x){
				l++;
			}
			while(l>=0 && (dis[cur[i]]+dis[cur[l]]-2LL*dis[u]>x || vis[l]==1)){
				l--;
			}
			if(vis[l]==0 && l>=0){
				vis[l]=1;
				cnt--;
			}
			else{
				ok=0;
				return 0;
			}
		}
		if((int)cur.size()%2==1){
			int sv=0;
			for(int i=0;i<(int)cur.size();i++){
				if(vis[i]==0){
					return cur[i];
				}
			}
		}
		else return 0;
	}
	else if((int)cur.size()==1) return cur[0];
	else return 0;
}
bool check(long long x){
	ok=1;
	dfs2(1,x);
	//cout<<ok<<endl;
	return (ok==1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		mark[a[i]]=1;
	}
	for(int i=1;i<n;i++){
		cin>>u>>v>>c;
		edge[u].pb(mp(v,c));
		edge[v].pb(mp(u,c));
	}
	dfs(1);
	//for(int i=1;i<=n;i++) cout<<st[i]<<endl;
	long long l=1,r=1e16,mid=(l+r)/2;
	if(check(r)==false){
		cout<<-1;
		return 0;
	}
	while(l!=mid && r!=mid){
		if(check(mid)) r=mid;
		else l=mid+1;
		mid=(l+r)/2LL;
	}
	for(long long i=r;i>=l;i--){
		if(check(i)==1){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}
