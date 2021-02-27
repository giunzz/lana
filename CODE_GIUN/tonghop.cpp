
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1005;
int C[maxn][maxn];
int n,k;

int main(){
	cin >> n >> k;
	int i,j;
	for (i=0;i<=n;i++) C[i][0]=1;
	for (i=0;i<=n;i++) C[i][i]=1;
	for (i=2;i<=n;i++){
		for (j=1; j<=i-1;j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}
	cout << C[n][k];
	return 0;
}
