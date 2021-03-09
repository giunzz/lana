#include<bits/stdc++.h>
using namespace std;
const int maxn=10007;
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0);
int A[maxn],L[maxn][maxn]={{0}},n,C[maxn],i,j;

int main()
{
    giuncute;
	freopen("DAYDX.INP","r",stdin);
	freopen("DAYDX.OUT","w",stdout);
	cin >> n;
	for(i=1;i<=n;i++) cin >> A[i];
	for(i=1;i<=n;i++) L[i][i]=1;
	for(i=n-1;i>=1;i--){
		for(j=i+1;j<=n;j++){
			if(A[i]==A[j]) L[i][j]=L[i+1][j-1]+2;
			else L[i][j]=max(L[i+1][j],L[i][j-1]);
		}
	}
	cout << L[1][n] << endl;
	i=1, j=n;
	do{
		if(A[i]==A[j])
        {
			C[i]=C[j]=true;
			i+=1;
			j-=1;
		} 
        else 
        {
			if(L[i][j-1]>L[i+1][j]) j-=1;
			else i+=1;
		}
	} while (i<=j);
	for (i=1;i<=n;i++)
		if(C[i]==true) cout << A[i] << " ";
return 0;
}