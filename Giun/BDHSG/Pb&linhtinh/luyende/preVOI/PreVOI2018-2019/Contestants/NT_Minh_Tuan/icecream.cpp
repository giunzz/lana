#include<bits/stdc++.h>
#define ii pair<int,int>
#define iii pair<ii,int>
#define fi first
#define se second
#define pqd priority_queue<int>
#define pqi priority_queue<int,vector<int>,greater<int> >
using namespace std;
	int n,mmax,ans;
	struct element{
		int m50,m1,m2;
		int m(){
			return m50+m1+m2;
		}
	};
	set<vector<int> > s;
	void buy(int d,element sta,vector<int> a){
		if(d>n){
			//ans+=s.insert(a).se;
			if(s.insert(a).se){
				ans++;
				/*for(int i=1;i<=n;i++){
					cout<<a[i]<<" ";
				}
				cout<<"\n";*/
			}
			return;
		}
		if(sta.m50+1<=mmax){
			a[d]=50;
			sta.m50++;
			buy(d+1,sta,a);
			a[d]=0;
			sta.m50--;
		}
		if(sta.m50>0 && sta.m1+1<=mmax){
			a[d]=1;
			sta.m50--;
			sta.m1++;
			buy(d+1,sta,a);
			a[d]=0;
			sta.m50++;
			sta.m1--;
		}
		if(sta.m1>0 && sta.m50>0 && sta.m2+1<=mmax){
			a[d]=2;
			sta.m50--;
			sta.m1--;
			sta.m2++;
			buy(d+1,sta,a);
			sta.m50++;
			sta.m1++;
			sta.m2--;
			a[d]=0;
		}
		else if(sta.m50>=3 && sta.m2+1<=mmax){
			a[d]=2;
			sta.m50-=3;
			sta.m2++;
			buy(d+1,sta,a);
			sta.m50+=3;
			sta.m2--;
			a[d]=0;
		}
	}
	int main(){
		freopen("icecream.inp","r",stdin);/*input file*/
		freopen("icecream.out","w",stdout);/*output file*/
		ans=0;
		cin>>n>>mmax;
		element ori;
		cin>>ori.m50>>ori.m1>>ori.m2;
		vector <int> a(n+1);
		for(int i=0;i<=n;i++) a[i]=0;
		//memset(a,0,sizeof(a));
		buy(1,ori,a);
		cout<<ans;
		//cerr<<"\nTime: "<<clock()<<" ms";
		//set<int> ss;
		//cout<<ss.insert(1).se;
		return 0;
	}
