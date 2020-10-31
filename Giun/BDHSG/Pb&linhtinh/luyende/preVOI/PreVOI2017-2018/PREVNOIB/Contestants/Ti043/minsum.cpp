#include <bits/stdc++.h>
using namespace std;
ifstream fin("minsum.inp");
ofstream fo("minsum.out");
#define cin fin
#define cout fo
#define mp make_pair
#define fi first
#define se second
#define pb push_back
int test;
int a,b;
vector < pair<int,int> > x,y;
vector < long long > last;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>test;
	while(test--){
		cin>>a>>b;
		int sv=a;
		x.clear();
		y.clear();
		last.clear();
		for(int i=2;i*i<=a;i++){
			if(sv==1) break;
			int cnt=0;
			while(sv%i==0){
				cnt++;
				sv/=i;
			}
			if(cnt>0) x.pb(mp(i,cnt));
		}
		if(sv>1) x.pb(mp(sv,1));
		sv=b;
		for(int i=2;i*i<=b;i++){
			if(sv==1) break;
			int cnt=0;
			while(sv%i==0){
				cnt++;
				sv/=i;
			}
			if(cnt>0) y.pb(mp(i,cnt));
		}
		if(sv>1) y.pb(mp(sv,1));
		int cur=0;
		for(int i=0;i<(int)x.size();i++){
			int sa=x[i].fi,val=x[i].se%2;
			while(cur<(int)y.size() && y[cur].fi<sa) cur++;
			if(y[cur].fi==sa) val=(val+y[cur].se)%2,cur++;
			if(val==1) last.pb(sa);
		}
		while(cur<(int)y.size()){
			if(y[cur].se==1) last.pb(y[cur].fi);
			cur++;
		}
		int n=(int)last.size();
		long long product=1,sum=2e18,ans1=0,ans2=0;
		for(int i=0;i<n;i++){
			product*=last[i];
		}
		for(int mask=0;mask<(1<<n);mask++){
			long long cr=1;
			for(int i=0;i<n;i++){
				if(mask&(1<<i)) cr=cr*last[i];
			}
			if(cr+product/cr<sum){
				sum=cr+product/cr;
				ans1=cr;
				ans2=product/cr;
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
}
