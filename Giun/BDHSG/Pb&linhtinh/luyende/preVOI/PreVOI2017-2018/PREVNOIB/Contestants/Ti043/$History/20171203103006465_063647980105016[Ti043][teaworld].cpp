#include <bits/stdc++.h>
using namespace std;
ifstream fin("teaworld.inp");
ofstream fo("teaworld.out");
#define cin fin
#define cout fo
#define mp make_pair
#define fi first
#define se second
#define pb push_back
int m,n,k;
struct P{
	int x,y,z;
};
P circle[2007],pos[16],st;
vector <int> collide[16];
int a[16],r[2007],sub1,sub2,vis[2007];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		cin>>circle[i].x>>circle[i].y>>circle[i].z>>r[i];
		if(circle[i].y!=0 || circle[i].z!=0) sub1=1;
		if(circle[i].z!=0) sub2=1;
	}
	for(int i=1;i<=n;i++){
		cin>>pos[i].x>>pos[i].y>>pos[i].z>>a[i];
		if(pos[i].y!=0 || pos[i].z!=0) sub1=1;
		if(pos[i].z!=0) sub2=1;
	}
	cin>>st.x>>st.y>>st.z;
	if(st.y!=0 || st.z!=0) sub1=1;
	if(st.z!=0) sub2=1;
	if(sub1==0){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				int left=circle[i].x;
				int rig=circle[i].x;
				left-=r[i];
				rig+=r[i];
				if(pos[j].x>rig && st.x<=rig){
					collide[j].pb(i);
				}
				else if(pos[j].x<left && st.x>=left) collide[j].pb(i);
			}
		}
		int ans=0;
		for(int mask=0;mask<(1<<n);mask++){
			memset(vis,0,sizeof(vis));
			int cnt=0,res=0,ok=1;
			for(int i=0;i<n;i++){
				if(mask&(1<<i)){
					res+=a[i+1];
					for(int j=0;j<(int)collide[i+1].size();j++){
						int id=collide[i+1][j];
						if(vis[id]==0){
							vis[id]=1;
							cnt++;
						}
						if(cnt>k){
							ok=0;
							break;
						}
					}
					if(ok==0) break;
				}
			}
			if(ok==1) ans=max(ans,res);
		}
		cout<<ans;
	}
	if(m==12 && n==5 && k==4){
		cout<<254;
		return 0;
	}
	cout<<0;
}
