#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,ar1[3005],ar2[3005],min1[3005][20],min2[3005][20],now1[6005],ans[6005],sum2,sum1,now2[6005],cmp[6005],bar[6005];
int minn(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
int maxx(int a,int b){
	if(a<b){
		return b;
	}
	return a;
}
void make(){
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j<=n-(1<<i)+1;j++){
			min1[j][i]=minn(min1[j][i-1],min1[j+(1<<(i-1))][i-1]);;
		}
	}
	for(int i=1;(1<<i)<=m;i++){
		for(int j=1;j<=m-(1<<i)+1;j++){
			min2[j][i]=minn(min2[j][i-1],min2[j+(1<<(i-1))][i-1]);
		}
	}
}
int min_range1(int l,int r){
	int i=0;
	while((1<<i)<r-l+1){
		i++;
	}
	i--;
	return minn(min1[l][i],min1[r-(1<<i)+1][i]);
}
int min_range2(int l,int r){
	int i=0;
	while((1<<i)<r-l+1){
		i++;
	}
	i--;
	return minn(min2[l][i],min2[r-(1<<i)+1][i]);
}
void comparee(){
	bool cac=0;
	for(int i=1;i<=k;i++){
		if(cmp[i]<ans[i]){
			cac=1;
			break;
		}
		if(cmp[i]>ans[i]){
			break;
		}
	}
	if(cac){
		for(int i=1;i<=k;i++){
			ans[i]=cmp[i];
		}
	}
}
void get1(int l,int r){
	int i,j,num=0;
	bar[0]=l-1;
	j=min_range1(l,r);
	for(i=l;i<=r;i++){
		if(ar1[i]==j){
			num++;
			bar[num]=i;
			now1[sum1]=i;
			sum1--;
			if(sum1==0){
				return ;
			}
		}
	}
	num++;
	bar[num]=r+1;
	for(i=num;i>=1;i--){
		if(bar[i]-bar[i-1]-1<=sum1){
			for(j=bar[i-1]+1;j<bar[i];j++){
				now1[sum1]=j;
				sum1--;
			}
			if(sum1==0){
				return;
			}
		}
		else{
			get1(bar[i-1]+1,bar[i]-1);
			return ;
		}
	}
}
void get2(int l,int r){
	int i,j,num=0;
	bar[0]=l-1;
	j=min_range2(l,r);
	for(i=l;i<=r;i++){
		if(ar2[i]==j){
			num++;
			bar[num]=i;
			now2[sum2]=i;
			sum2--;
			if(sum2==0){
				return ;
			}
		}
	}
	num++;
	bar[num]=r+1;
	for(i=num;i>=1;i--){
		if(bar[i]-bar[i-1]-1<=sum2){
			for(j=bar[i-1]+1;j<bar[i];j++){
				now2[sum2]=j;
				sum2--;
			}
			if(sum2==0){
				return;
			}
		}
		else{
			get2(bar[i-1]+1,bar[i]-1);
			return ;
		}
	}
}
void mergee(int x,int y){
	int i=1,j=1;
	while(i<=x||j<=y){
		if(i==x+1){
			while(j<=y){
				cmp[i+j-1]=ar2[now2[j]];
				j++;
			}
			break;
		}
		if(j==y+1){
			while(i<=x){
				cmp[i+j-1]=ar1[now1[i]];
				i++;
			}
			break;
		}
		if(ar1[now1[i]]<ar2[now2[j]]){
			cmp[i+j-1]=ar1[now1[i]];
			i++;
		}
		else{
			cmp[i+j-1]=ar2[now2[j]];
			j++;
		}
	}
}
int main(){
	int i,j;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		cin>>ar1[i];
		min1[i][0]=ar1[i];
		ans[i]=3500;
	}
	for(i=1;i<=m;i++){
		cin>>ar2[i];
		min2[i][0]=ar2[i];
		ans[n+i]=3500;
	}
	make();
	for(i=minn(m,k);i>=maxx(0,k-n);i--){
		sum1=i;
		get1(1,n);
		sort(now1+1,now1+1+i);
		sum2=k-i;
		get2(1,m);
		sort(now2+1,now2+1+k-i);
		mergee(i,k-i);
		comparee();
	}
	for(i=1;i<=k;i++){
		cout<<ans[i]<<" ";
	}
}
/*7 4 9
1 2 1 3 1 2 1
1 2 3 1*/
