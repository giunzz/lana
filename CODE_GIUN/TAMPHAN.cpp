#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const double oo = 1e9;
double X[maxn],Y[maxn], L[maxn][maxn]={{0}}, D[maxn][maxn]={{0}};
int n, G[maxn][maxn]={{0}};

double kc(int i, int j){
	return sqrt(pow(X[j]-X[i],2) + pow(Y[j]-Y[i],2));
}

void Trace(int d, int c){
	if (c-d<3) return;

	if (G[d][c]-d>=2) {
		cout << d << " " << G[d][c] << endl;
		Trace(d,G[d][c]);
	}

	if (c-G[d][c]>=2){
		cout << G[d][c] << " " << c << endl;
		Trace(G[d][c],c);
	}
}

int main(){
	
	freopen("TAMPHAN.INP","r",stdin);
	freopen("TAMPHAN.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> X[i] >> Y[i];
	}
	
	int i,j,k,v;
	//Tính D
	for (i=1; i<=n; i++){
		for (j=i; j<=n; j++){
			if (j-i > 1) {
				D[i][j]=D[j][i]=kc(i,j);
			}
			else {
				D[i][j]=D[j][i]=0;
			}
		}
	}
	//Tính L
	double minl = oo,t;
	for (i=n; i>=1; i--){
		for (j=i-1; j<=n; j++){
			if (j-i<3) L[i][j]=0;
			else {
				v=0;
				minl = oo;
				for (k=i+1;k<j; k++){
					t=L[i][k]+L[k][j] + D[i][k] + D[k][j];
					if (t > 0 && t < minl){
						minl = t;
						v=k;
					}
				}
				if (v!=0){
					L[i][j]=minl;
					G[i][j]=v;
				}
			}
		}
	}
	printf("%0.4f\n",L[1][n]);
	Trace(1,n);
	return 0;
}