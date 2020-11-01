#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <int> prime, lst;
ll mid;
ll _back(int pos,ll val){
	if (val > mid) return -1;
	ll res = val;
	if (pos == (int)prime.size()) return res;
	return max(res, max(_back(pos+1,val), _back(pos+1,val*prime[pos])));
}
int main(){
	freopen("minsum.inp","r",stdin);
	freopen("minsum.out","w",stdout);
	int test;
	scanf("%d",&test);
	while(test--){
		int a,b;
		scanf("%d %d",&a,&b);
		lst.clear();
		for(int i=2;i<=(int)sqrt(a);i++){
			while(a%i==0){
				lst.push_back(i);
				a /= i;
			}
		}
		if (a > 1) lst.push_back(a);
		for(int i=2;i<=(int)sqrt(b);i++){
			while(b%i==0){
				lst.push_back(i);
				b /= i;
			}
		}
		if (b > 1) lst.push_back(b);
		
		prime.clear();
		sort(lst.begin(),lst.end());
		for(int i=0;i<(int)lst.size();i++){
			int pivot = i;
			for(;pivot<(int)lst.size();pivot++)	if (lst[pivot] != lst[i]) break; --pivot;
			if ((pivot - i) % 2 == 0) prime.push_back(lst[i]);
			i = pivot;
		}
		// end of preprocess
		// prime size small
		if (prime.size() == 0){
			printf("1 1\n");
			continue;
		}
		
		ll product = 1;
		for(int i=0;i<(int)prime.size();i++) product *= prime[i];
		mid = sqrt(product);
		ll ta = _back(0,1);
		ll tb = product / ta;
		printf("%lld %lld\n", min(ta,tb), max(ta,tb));
	}
}
