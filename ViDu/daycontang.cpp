#include <iostream>
using namespace std;
const int maxn=1e6+5;
int n,A[maxn],B[maxn],Tr[maxn];

void TaoBang(){
	B[1]=1;
	int bmax, v;
	for (int i=2;i<=n;i++){
		bmax=0;
		v=0;
		for (int j=i-1;j>=1;j--){
			if (A[i]>=A[j] && B[j]>bmax){
				bmax=B[j];
				v=j;
			}
		}
		B[i]=B[v]+1;
		Tr[i]=v;
	}
}
void InRa(int i){
	if (Tr[i]==0){
		cout << A[i] << " ";
		return;
	}
	else {
		InRa(Tr[i]);
		cout << A[i] << " ";
	}
}
int main(){
	freopen("DAYCONTANG2.INP","r",stdin);
	freopen("DAYCONTANG2.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> A[i];
	TaoBang();
	int vmax = n;
	for (int i=n-1;i>=1;i--){
		if (B[i]>B[vmax]) vmax=i;
	}
	InRa(vmax);
	return 0;
}
