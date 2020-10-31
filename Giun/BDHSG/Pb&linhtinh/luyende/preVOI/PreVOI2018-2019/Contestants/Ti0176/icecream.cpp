#include <bits/stdc++.h>
using namespace std;

int N,MMAX, M50,M1,M2;
int res;
int MOD = 1e9+9;

void init(){
	freopen("icecream.inp","r",stdin);
	freopen("icecream.out","w",stdout);
}

void input(){
	scanf("%d%d",&N,&MMAX);
	scanf("%d%d%d",&M50,&M1,&M2);
}

void dfs(int _pos, int money){
//	cerr<<"DFS "<<_pos<<" "<<money<<endl;
//	cerr<<" pre "<<M50<<" "<<M1<<" "<<M2<<endl;
	bool Type = 0;
	if (money == 50){
		if (M50 >= MMAX) 
			return;
		M50++;
	}
	else if (money == 1){
		if (M1 >= MMAX || M50 == 0) 
			return;
		M1++;
		M50--;
	}
	else if (money == 2){
		if (M2 >= MMAX || M50==0 || (M1==0 && M50 < 3) ){
//			cerr<<"    :( "<<M50<<" "<<M1<<" "<<M2<<endl;
			return;
		}
		M2++;
		if (M1 > 0){
			Type = 1;
			M1--;
			M50--;
		}
		else {
			M50-=3;
		}
	}
//		cerr<<" "<<M50<<" "<<M1<<" "<<M2<<endl;
	if (_pos == N){
		res++;
//		cerr<<"  ++"<<endl;
		if (money == 50) M50--;
		if (money == 1) {
			M1--;
			M50++;
		}
		if (money == 2) {
			M2--;
			if (Type){
				M1++;
				M50++;
			}
			else{
				M50+=3;
			}
		}
		return;
	}
	dfs(_pos+1,50);
	dfs(_pos+1,1);
	dfs(_pos+1,2);
	if (money == 50) M50--;
	if (money == 1) {
		M1--;
		M50++;
	}
	if (money == 2) {
		M2--;
		if (Type){
			M1++;
			M50++;
		}
		else{
			M50+=3;
		}
	}
}

void buffalo(){
	dfs(1,50);
	dfs(1,1);
	dfs(1,2);
	printf("%d",res);
}

int f[101][101][101][101];

void buffalo2(){
	f[0][M50][M1][M2] = 1;
	for (int i = 1 ; i <= N ; i++){
		for (int m50 = 0 ; m50 <= N ; m50++)
			for (int m1 = 0 ; m1 <= N ; m1++)
				for (int m2 = 0 ; m2 <= N ; m2++){
					int plus = 0;
					if (m50 > 0)
						plus = (plus+f[i-1][m50-1][m1][m2]) % MOD;
					if (m1 > 0){
						if(m50 < MMAX)
							plus = (plus + f[i-1][m50+1][m1-1][m2]) % MOD;
					}
					if (m2 > 0){
						if (m50 < MMAX && m1 < MMAX)
							plus = (plus+f[i-1][m50+1][m1+1][m2-1]) % MOD;
						if (m50+3 <= MMAX)
							plus = (plus+f[i-1][m50+3][m1][m2-1]) % MOD;
					}
					plus %= MOD;
					f[i][m50][m1][m2] = plus;
				}
	}
	
	for (int m50 = 0 ; m50 <= N ; m50++)
			for (int m1 = 0 ; m1 <= N ; m1++)
				for (int m2 = 0 ; m2 <= N ; m2++){
					if (m50 <= MMAX && m1 <= MMAX && m2 <= MMAX)
						res = (res+f[N][m50][m1][m2]) % MOD;
				}
	printf("%d",res);
}

void compute(){
	if (N <= 15 && MMAX <= 10){
		buffalo();
	}
	else if (N<=100){
		buffalo2();
	}
	else{
		buffalo();
	}
}

void output(){
	
}

main(){
	init();
	input();
	compute();
	output();
}
