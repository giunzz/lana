#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct ans{
	long long a,b,c;
};
long long A[2006][2006],N,dem;
ans B[(int)];
bool cmp(ans val1, ans val2){
	return val1.c<val2.c;

}
int main(){
	freopen("CHUYEN01.INP","r",stdin);
	freopen("CHUYEN01.OUT","w",stdout);
cin>>N;
for(long long i=1; i<=N; i++) 
	for(long long j=1; j<=N; j++)
		scanf("%ld", &A[i][j]);
for(long long i=1; i<=N; i++)
	for(long long j=i+1; j<=N; j++)
		if(A[i][j]!=0){
			dem+=1;
			B[dem].a=i;
			B[dem].b=j;
			B[dem].c=A[i][j];
		}
sort(B+1,B+dem+1,cmp);
cout<<dem<<endl;
for(long long i=1; i<=dem; i++){
	cout<<B[i].a<<" "<<B[i].b<<" "<<B[i].c<<endl;
}
return 0;
}