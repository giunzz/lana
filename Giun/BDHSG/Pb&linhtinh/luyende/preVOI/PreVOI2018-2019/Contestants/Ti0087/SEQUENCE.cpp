#include <bits/stdc++.h>
#define int long long
#define MAXN 3005
#define MOD 1000000007
#define sz(a) static_cast<long long>(a.size())
#define INF 2000000000000000000
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pp;
int m,n,k,a[MAXN],b[MAXN],dpa[MAXN][MAXN],dpb[MAXN][MAXN];
bool upa[MAXN][MAXN],upb[MAXN][MAXN];
void tinh(){
	int i,j; a[0]=INF; b[0]=INF;
	for (i=0;i<MAXN;i++) dpa[0][i]=INF; dpa[0][0]=0;
	for (i=1;i<=m;i++){
		for (j=1;j<=m;j++){
			dpa[i][j]=dpa[i-1][j];
			if (j>0&&a[i]<dpa[i][j] && dpa[i-1][j-1]!=INF||j>0&&upa[i-1][j-1]){
				dpa[i][j]=a[i]; upa[i][j]=true;
			}
		}
	}
	for (i=0;i<MAXN;i++) dpb[0][i]=INF; dpb[0][0]=0;
	for (i=1;i<=n;i++){
		for( j=1;j<=n;j++){
			dpb[i][j]=dpb[i-1][j];
			if (j>0&&b[i]<dpb[i][j]&&dpb[i-1][j-1]!=INF||j>0&&upb[i-1][j-1]){
				dpb[i][j]=b[i]; upb[i][j]=true;
			}
		}
	}
}
int ara[MAXN],arb[MAXN],c[MAXN],ans[MAXN];
void Upd(){
	int i;
	for (i=1;i<=k;i++) ans[i]=c[i];
}
void thu(int x1,int x2){
	int r1=x1,r2=x2;
	int i,j,x; i=m; j=x1;
	while (i>0&&j>0){
		//cout<<dpa[i][j]<<' ';
		ara[r1--]=dpa[i][j];
		i--; j--;
		while (i>0&&dpa[i][j]==dpa[i-1][j]) i--;
	}
	i=n; j=x2;
	while (i>0&&j>0){
		arb[r2--]=dpb[i][j];
		i--; j--;
		while (i>0&&dpb[i][j]==dpb[i-1][j]) i--;
	}
	//for (i=1;i<=x1;i++) cout<<ara[i]<<' '; cout<<'\n';
	//for (i=1;i<=x2;i++) cout<<arb[i]<<' '; cout<<'\n';
	i=1; j=1;
	for (x=1;x<=k;x++){
		if (i>x1) c[x]=arb[j++];
		else if (j>x2) c[x]=ara[i++];
		else{
			if (ara[i]<=arb[j]) c[x]=ara[i++];
			else c[x]=arb[j++];
		}
	}
	for (i=1;i<=k;i++){
		if (ans[i]<c[i]) return;
		else if (ans[i]>c[i]) Upd();
	}
}
main(){
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	freopen("SEQUENCE.INP","r",stdin); freopen("SEQUENCE.OUT","w",stdout);
	cin>>m>>n>>k; int i,j;
	for (i=1;i<=m;i++){
		cin>>a[i];
	}
	for	(i=1;i<=n;i++){
		cin>>b[i];
	}
	tinh();
	ans[1]=INF;
	for (i=0;i<=k;i++){
		j=k-i;
		if (i<=m&&j<=n){
			thu(i,j);
		}
	}
	for (i=1;i<=k;i++) cout<<ans[i]<<' ';
	
}
