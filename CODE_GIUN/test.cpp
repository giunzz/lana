#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n;
char s[N];
bool check(int t) {
	int lt=0, rt=0;
	for (int i=1; i<=n; i++)
	if (s[i]=='*' && lt==0 && i>rt) lt=i;
	else
	if (s[i]=='P') {
		int tmp=lt>0?i-lt:0;
		//cout<<"lt= "<<lt<<" "<< "i= "<<i<<endl;
		if (tmp>t) return 0;
		rt=max((t-tmp)/2,t-2*tmp)+i;
		lt=0;
	}
	if (lt) return 0;
	return 1;
}

int main() {
	freopen("giun.inp","r",stdin);
	freopen("giun.out","w",stdout);
	scanf("%d", &n);
	scanf("%s", s+1);
	int l=1, r=2*n;
	while (l<r)
	{
	    	//cout<<"sdhgf"<<endl;
		int mid=(l+r)/2;
         cerr << l << " " << r << " " << mid << endl;
		int x=check(mid);
		//cout<<x<<endl;
		if (x) r=mid; else l=mid+1;
	}

	printf("%d",l);
	return 0;
}
