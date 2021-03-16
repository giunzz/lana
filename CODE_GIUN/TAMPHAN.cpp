#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const double oo = 1e9;
double X[maxn],Y[maxn], L[maxn][maxn]={{0}}, D[maxn][maxn]={{0}};
int n, G[maxn][maxn]={{0}};
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
double kc(int i, int j)
{
	return sqrt( (X[j]-X[i])*(X[j]-X[i]) + (Y[j]-Y[i])*(Y[j]- Y[i]) );
}
int main(){
	giuncute;
	freopen("tamphan.INP","r",stdin);
	freopen("tamphan.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> X[i] >> Y[i];	
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n; j++)
		{
			if (j-i > 1) D[i][j]=D[j][i]=kc(i,j);
			else D[i][j]=D[j][i]=0;
		}
	}
	double minl = oo,t;
	for (int i=n; i>=1; i--)
	{
		for (int j=i-1; j<=n; j++)
		{
			if (j-i<3) L[i][j]=0;
			else {
				int v=0;
				minl = oo;
				for (int k=i+1;k<j; k++)
				{
					t=L[i][k]+L[k][j] + D[i][k] + D[k][j];
					if (t > 0 && t < minl)
					{
						minl = t;
						v=k;
					}
				}
				if (v!=0)
				{
					L[i][j]=minl;
					G[i][j]=v;
				}
			}
		}
	}
	printf("%0.4f\n",L[1][n]);
	return 0;
}