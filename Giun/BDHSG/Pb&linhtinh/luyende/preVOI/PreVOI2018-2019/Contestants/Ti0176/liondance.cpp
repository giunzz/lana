#include <bits/stdc++.h>
using namespace std;

int n,delta;
int L[4000],R[4000];

void init(){
	freopen("liondance.inp","r",stdin);
	freopen("liondance.out","w",stdout);
}

void input(){
	scanf("%d%d",&n,&delta);
	for (int i = 1 ; i <= n ; i++)
		scanf("%d",&L[i]);
	for (int i = 1 ; i <= n ; i++)
		scanf("%d",&R[i]);
}

struct data{
	int val;
	int prevL;
	int prevR;
};

int maxL = 0;


void buffalo(){
	data f[102][102];
	
	
	L[n+1] = 0;
	R[n+1] = 0;
	
	for (int i = 0 ; i <= n+1 ; i++){
		for (int j = 0 ; j <= n+1 ; j++)
			f[i][j] = {0,0,0};
	}

	for (int i = n ; i > 0 ; i--)
		for (int j = n ; j > 0 ; j--){
			if (L[i] == R[j])
				for (int p1 = i+1 ; p1 <= n+1 ; p1++)
					for (int p2 = j+1 ; p2 <= n+1 ; p2++){
						if (L[p1] == R[p2] && (abs(L[p1]-L[i]) <= delta || p1 == n+1))
							if (f[i][j].val <= f[p1][p2].val+1){
								f[i][j] = {f[p1][p2].val+1,p1,p2};
//								cerr<<" f["<<i<<","<<j<<"] = "<<f[i][j].val<<endl;
	//							if (Dict.empty() || Dict[f[i][j].val][0] == L[i])
	//								Dict[f[i][j].val].push_back({L[i],i,j,p1,p2});
	//							else if (Dict[f[i][j].val][0] > L[i]){
	//								Dict[f[i][j].val].clear();
	//								Dict[f[i][j].val].push_back({L[i],i,j,p1,p2});
	//							}
		//						cerr<<i<<" "<<j<<" "<<p1<<" "<<p2<<" "<<f[p1][p2].val<<" "<<f[i][j].val<<endl;
								maxL = max(maxL,f[i][j].val);
		//						cerr<<"  "<<f[i][j].val<<endl;
							}				
					}
			}
	int Result[maxL+1];
	
	printf("%d\n",maxL);
	int p1 = 0 , p2 = 0,prevV = 0;
	while (maxL > 0){
		int maxV = 0;
		int op1 = p1 , op2 = p2;
		for (int i = op1+1 ; i <= n ; i++)
			for (int j = op2+1 ; j <= n ; j++){
//				cerr<<" "<<i<<","<<j<<" : "<<f[i][j].val<<endl;
				if (f[i][j].val == maxL && L[i] > maxV && (prevV==0 || abs(prevV-L[i]) <= delta)){
					maxV = L[i];
					p1 = i;
					p2 = j;
//					cerr<<f[i][j].val<<" = "<<maxL<<" "<<i<<","<<j<<endl;
				}
			}
		prevV = maxV;
//		cerr<<maxV<<" "<<p1<<" "<<p2<<" "<<maxL<<" "<<prevV<<endl;
		printf("%d ",maxV);
		maxL--;
	}
}

void compute(){
	if (n<=100){
		buffalo();
	}
}

void output(){
	
}

main(){
	init();
	input();
	compute();
}
