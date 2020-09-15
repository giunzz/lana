/*#include <iostream>
using namespace std;
int b[90]
int main(){

	a[4]=1;
	a[8]=2;
	a[15]=3;
	a[16]=4;
	a[23]=5;
	a[42]=6;


	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> b[i];
		b[i]=a[b[i]];
	}
	for(int i=0;i<n;i++){
		if(b[i])
	}
	return 0;
}
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a[1000005];
int b[50];
using namespace std;
int main(){
	freopen("mangdep.inp","r",stdin);
	freopen("mangdep.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin >> a[i]; 
		b[a[i]]++;
		if(a[i]==8 && b[8]>b[4]){
			b[a[i]]--;
			a[i]=0;
		}
		else if(a[i]==15 && b[15]>b[8]){
			b[a[i]]--;
			a[i]=0;
		}
		else if(a[i]==16 && b[16]>b[15]){
			b[a[i]]--;
			a[i]=0;
		}
		else if(a[i]==23 && b[23]>b[16]){
			b[a[i]]--;
			a[i]=0;
		}
		else if(a[i]==42 && b[42]>b[23]){
			b[a[i]]--;
			a[i]=0;
		}
	}
	int dem=0;
	for(int i=0;i<n;i++){
		if(a[i]==0) dem++;
	}
	dem+= abs(b[42]*5-b[23]-b[16]-b[15]-b[8]-b[4]);
	if((n-dem)%6==0) cout << dem;
	else cout << n;
}