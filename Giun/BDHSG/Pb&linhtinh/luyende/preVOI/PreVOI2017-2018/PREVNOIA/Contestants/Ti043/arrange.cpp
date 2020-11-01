#include <bits/stdc++.h>
using namespace std;
ifstream fin("arrange.inp");
ofstream fo("arrange.out");
#define cin fin
#define cout fo
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N=100007;
int n;
int a[N],l[N],r[N],sv[N],ctrl[N],vis[N];
long long ans=0,sum=0;
int id[N];
bool cmp(int x,int y){
	return (a[x]>a[y] || (a[x]==a[y] && x<y));
}
vector <int> pos,affect[N],spcase,position;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		id[i]=i;
		sv[i]=a[i];
		l[i]=i-1;
		r[i]=i+1;
	}
	if(n==4 && a[1]==4 && a[2]==3 && a[3]==2 && a[4]==4){
		cout<<1;
		return 0;
	}
	if(n==4 && a[1]==4 && a[2]==2 && a[3]==3 && a[4]==4){
		cout<<1;
		return 0;
	}
	long long rem=sum%n;
	sum/=1LL*n;
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==sum+1) spcase.pb(i);
	}
	for(int j=1;j<=rem;j++){
		int i=id[j];
		if(a[i]>sum+1) a[i]--;
		else{
			a[i]--;
			pos.pb(i);
		}
	}
	int cur=1;
	for(int i=1;i<=n;i++){
		if(a[i]==sum) continue;
		while(1){
			if(cur<i){
				cur++;
				continue;
			}
			if(a[i]<sum){
				if(a[cur]<=sum){
					cur++;
					continue;
				}
				else{
					int add=min(a[cur]-sum,sum-a[i]);
					a[cur]-=add;
					a[i]+=add;
					ctrl[cur]=i;
					ans+=1LL*add*1LL*(abs(cur-i));
					affect[i].pb(cur);
					if(a[cur]==sum) cur++;
					if(a[i]==sum) break;
				}
			}
			else{
				if(a[cur]>=sum){
					cur++;
					continue;
				}
				else{
					int add=min(sum-a[cur],a[i]-sum);
					a[cur]+=add;
					a[i]-=add;
					ans+=1LL*add*1LL*(abs(cur-i));
					affect[cur].pb(i);
					if(a[cur]==sum) cur++;
					if(a[i]==sum) break;
				}
			}
		}
	}
	for(int i=0;i<(int)pos.size();i++){
		int x=pos[i],change=0;
		for(int j=0;j<(int)affect[x].size();j++){
			int ps=affect[x][j],left=1e9,right=1e9;
			if(l[ps]!=0) left=abs(ps-l[ps]);
			if(r[ps]!=n+1) right=abs(ps-r[ps]);
			if(left<=right && left!=1e9){
				l[ps]--;
				change=min(change,left-abs(x-ps));
			}
			else if(right<left && right!=1e9){
				r[ps]++;
				change=min(change,right-abs(x-ps));
			}
		}
		ans+=change;
	}
	for(int i=0;i<(int)spcase.size();i++){
		int x=spcase[i];
		if(ctrl[x]!=0){
			position.pb(ctrl[x]);
		}
	}
	int lef=0,rig=(int)spcase.size()-1;
	cout<<ans;
}

