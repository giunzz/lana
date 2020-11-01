#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first
#define se second
#define pqd priority_queue<int>
#define pqi priority_queue<int,vector<int>,greater<int> >
using namespace std;
	uint64_t A,B,N,K,ans,mod;
	bool ok=false;;
	void solve(int d,uint64_t T){
		if(d>N){
			//cout<<d<<" "<<ans<<"\n";
			if(ans%mod==K){
				cout<<ans;
				ok=true;
			}
			return;
		}
		ans*=10;
		ans+=T;
		//cout<<d<<" "<<ans<<"\n";
		if(d==1 && T==0) return;
		if(!ok) solve(d+1,A);
		else return;
		//ans/=10;
		if(!ok) solve(d+1,B);
		else return;
		ans/=10;
	}
	int main(){
		freopen("modulo.inp","r",stdin);/*input file*/
		freopen("modulo.out","w",stdout);/*output file*/
		ans=0;
		cin>>A>>B>>N>>K;
		mod=pow(2,N);
		//cout<<A<<" "<<B<<" "<<N<<" "<<K<<" "<<mod;
		solve(1,A);
		ans=0;
		if(!ok) solve(1,B);
		if(!ok) cout<<"-1";
		//cout<<"\n"<<77%8;
		//cerr<<"\nTime: "<<clock()<<" ms";
		return 0;
	}
