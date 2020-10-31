#include <bits/stdc++.h>
#define int long long
#define MAXN 66
#define MOD 1000000007
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int n,a,b,k,moda[66],modb[66];
unsigned long long luy2[64];
map<int,pp> trace[MAXN];
// c/so se lay + trang thai
vector <int> ans;
int mul(int x,int so){
	x%=luy2[n];
	int i,j,val=x;
	for (i=2;i<=so;i++){
		j=x;
		if (val>=luy2[n]-j){
			val-=luy2[n-1];
			if (val>=luy2[n]-j){
				j-=luy2[n-1]; val+=j;
			}
			else{
				val+=j; val-=luy2[n-1];
			}
		}
		else val+=j;
	}
	return val;
}
int add(int x,int y){
	if (x<y) swap(x,y);
	if (x>=luy2[n]-y){
		x-=luy2[n-1];
		if (x>=luy2[n]-y){
			y-=luy2[n-1];
			return x+y;
		}
		else{
			x+=y; x-=luy2[n-1];
			return x;
		}
	}
	return x+y;
}
int total=0;
void init(){
	int i,j,x,val;
	luy2[0]=1;
	for (i=1;i<64;i++) luy2[i]=luy2[i-1]*2;
	moda[0]=a%luy2[n];
	for (i=1;i<64;i++){
		//moda[i]=(moda[i-1]*10)%luy2[n];
		moda[i]=mul(moda[i-1],10);
	}
	modb[0]=b%luy2[n];
	for (i=1;i<64;i++){
		//modb[i]=(modb[i-1]*10)%luy2[n];
		modb[i]=mul(modb[i-1],10);
	}
	queue<int> q; int dem=0,dem2;
	if (a%2==k%2){
		q.push(a%luy2[n]); trace[0][a%luy2[n]]=mp(-1,1); dem++;
		if (n==1) ans.pb(a%2);
	}
	if (b%2==k%2){
		q.push(b%luy2[n]); trace[0][b%luy2[n]]=mp(-1,2); dem++;
		if (n==1) ans.pb(b%2);
	}
	//cout<<moda[1]<<' '<<modb[1]; exit(0);
	for (i=1;i<n;i++){
		dem2=0; total+=dem;
		if (q.empty()){
			cout<<-1; exit(0);
		}
		for (j=0;j<dem;j++){
			if (q.empty()){
				cout<<-1; exit(0);
			}
			x=q.front(); q.pop();
			val=add(x,moda[i]); val%=luy2[n];
			if (val%luy2[i+1]==k%luy2[i+1]){
				dem2++; q.push(val); trace[i][val]=mp(x,1);
				if (i==n-1&&val==k) ans.pb(val);
			}
			val=add(x,modb[i]); val%=luy2[n];
			if (val%luy2[i+1]==k%luy2[i+1]){
				dem2++; q.push(val); trace[i][val]=mp(x,2);
				if (i==n-1&&val==k) ans.pb(val);
			}
		}
		dem=dem2;
	}
}
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	freopen("MODULO.INP","r",stdin); freopen("MODULO.OUT","w",stdout);
	cin>>a>>b>>n>>k; int i,j,val;
	init();
	if (ans.empty()){
		cout<<-1; return 0;
	}
	pp p=trace[n-1][k]; string s;
	char c1=a+48,c2=b+48; i=n-1; val=k;
	while (p.first!=-1){
		if (p.second==1) s=s+c1;
		else s=s+c2;
		i--; val=p.first;
		p=trace[i][val];
	}
	if (p.second==1) s=s+c1; else s=s+c2;
	//cout<<total<<'\n';
	cout<<s;
}
