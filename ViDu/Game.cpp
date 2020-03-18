#include <iostream>
#include <cmath>

const long maxn =1e6+5;
long A[maxn], T[maxn], n;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	freopen("GAME.INP","r",stdin);
	freopen("GAME.OUT","w",stdout);
	std::cin >> n;
	char ch;
	for (long i=1;i<=n;i++){
		std::cin >> ch >> A[i];
		if (ch=='L') A[i]=0-A[i];
	}
	T[1]=A[1];
	for (long i=2; i<=n; i++){
		T[i] = std::max(T[i-1]+A[i], A[i]);
	}
	long r=1, l,tmax=0;
	for (long i=2;i<=n;i++){
		if (T[i]>T[r]) r=i;
	}
	l=r;
	long s=A[r];
	for (long i=r-1;i>=1;i--){
		s=s+A[i];
		if (s>tmax){
			tmax=s;
			l=i;
		}
	}
	std::cout << tmax << std::endl;
	std::cout << l << " " << r;
	return 0;
}
