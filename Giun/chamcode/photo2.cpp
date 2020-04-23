#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;
const long maxn = 1e6+10;
long n,W[maxn],H[maxn],h1,h2;
ll w=0;
int main(){
	freopen("PHOTO.INP","r",stdin);
	freopen("PHOTO.OUT","w",stdout);
	scanf("%ld",&n);
	h1=1;
	for (long i=1;i<=n;i++){
		scanf("%ld%ld",&W[i],&H[i]);
		w+=W[i];
		if (H[i]>H[h1]){
			h1=i;
		}
	}

	h2=(h1==1)?2:1;
	for (long i=1;i<=n;i++)
		if (i!=h1 && H[i]>H[h2]) h2=i;
    //cerr << H[h1] << endl << H[h2];
	for (long i=1;i<=n;i++){
		(i==h1)?printf("%lld ",(w-W[i])*H[h2]):printf("%lld ",(w-W[i])*H[h1]);
	}
	return 0;
}
