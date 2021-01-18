#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 2e3+5;
int A[maxn][maxn], n, k, c=0; 
void LatNen(int y, int x, int l, int t){
	if (l==2){
		c+=1;
		A[y][x]=c;
		A[y][x+1]=c;
		A[y+1][x]=c;
		A[y+1][x+1]=c;
		if (t==1) A[y][x] = 0;
		else if (t==2) A[y][x+1] = 0;
		else if (t==3) A[y+1][x] = 0;
		else if (t==4) A[y+1][x+1] = 0;
	} else {
		if (t==1){
			LatNen(y,x+l/2,l/2,3);
			LatNen(y+l/2,x,l/2,2);
			LatNen(y+l/2,x+l/2,l/2,1);
			LatNen(y+l/4,x+l/4,l/2,1);
		}
		else if (t==2){
			LatNen(y,x,l/2,4);
			LatNen(y+l/2,x,l/2,2);
			LatNen(y+l/2,x+l/2,l/2,1);
			LatNen(y+l/4,x+l/4,l/2,2);
		} else if (t==3){
			LatNen(y,x,l/2,4);
			LatNen(y,x+l/2,l/2,3);
			LatNen(y+l/2,x+l/2,l/2,1);
			LatNen(y+l/4,x+l/4,l/2,3);
		} else if (t==4){
			LatNen(y,x,l/2,4);
			LatNen(y,x+l/2,l/2,3);
			LatNen(y+l/2,x,l/2,2);
			LatNen(y+l/4,x+l/4,l/2,4);
		}
		
	}
}
int main(){
	freopen("LATNEN.INP", "r", stdin);
	freopen("LATNEN.OUT", "w", stdout);
	scanf("%d", &k);
	n = pow(2,k);
	LatNen(1,1,n,2);
	for (int y=1; y<=n;y++){
		for (int x=1; x<=n;x++) printf("%d ",A[y][x]);
		printf("\n");
	}
	return 0;
}