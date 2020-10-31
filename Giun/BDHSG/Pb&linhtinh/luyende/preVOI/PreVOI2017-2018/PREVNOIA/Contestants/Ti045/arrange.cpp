#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int n,m;
long long s=0,a[N],res=0;
vector<int> vt;
struct ii{
	long long x;int y;
	ii(){};
	ii(long long x, int y):x(x),y(y){};
};
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
void solve(){
	long long x=s/n;
	queue<ii> q1,q2;
	m=n-m;
	for(int i=1;i<=n;++i){
		if (a[i]>x) q1.push(ii(a[i],i));
		else if (a[i]!=x) q2.push(ii(a[i],i));
		else if (a[i]==x) m--;
		if (m==0){
			x++;
			m--;
		}
		while (!q1.empty()){
			ii tmp1=q1.front();q1.pop();
			if (q2.empty()){
				q1.push(tmp1);
				break;
			}
			while(!q2.empty()){
				ii tmp2=q2.front();
				if (tmp1.x+tmp2.x>=2*x){
					tmp1.x-=x-tmp2.x;
					res+=(x-tmp2.x)*abs(tmp1.y-tmp2.y);
					m--;
					if (m==0) x++;
					q2.pop();
				}
				else{
					tmp2.x-=tmp1.x-x;
					res+=(tmp1.x-x)*abs(tmp1.y-tmp2.y);
					tmp1.x=x;
					q2.push(tmp2);
					break;
				}
			}
			if (tmp1.x>x) q1.push(tmp1);
		}
	}
	cout<<res;
}
void sub1(){
	long long x=s/n;
	queue<ii> q1,q2;
	for(int i=1;i<=n;++i){
		if (a[i]>x) q1.push(ii(a[i],i));
		else if (a[i]!=x) q2.push(ii(a[i],i));
		while (!q1.empty()){
			ii tmp1=q1.front();q1.pop();
			if (q2.empty()){
				q1.push(tmp1);
				break;
			}
			while(!q2.empty()){
				ii tmp2=q2.front();
				if (tmp1.x+tmp2.x>=2*x){
					tmp1.x-=x-tmp2.x;
					res+=(x-tmp2.x)*abs(tmp1.y-tmp2.y);
					q2.pop();
				}
				else{
					tmp2.x-=tmp1.x-x;
					res+=(tmp1.x-x)*abs(tmp1.y-tmp2.y);
					tmp1.x=x;
					q2.push(tmp2);
					break;
				}
			}
			if (tmp1.x>x) q1.push(tmp1);
		}
	}
	cout<<res;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("arrange.inp","r",stdin);
	freopen("arrange.out","w",stdout);
	n=readInt();
	for(int i=1;i<=n;++i){
		a[i]=readInt();
		s=s+a[i];
	}
	m=s%n;
	if (m==0) sub1();
	else solve();
}
