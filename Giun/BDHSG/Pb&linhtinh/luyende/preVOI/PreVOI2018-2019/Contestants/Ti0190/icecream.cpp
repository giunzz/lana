#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define FRE freopen("icecream.inp","r",stdin),freopen("icecream.out","w",stdout)
using namespace std;
const int MOD=1e9+9;
int n,mmax,value[5],counter;
int dem;

void dfs(int j)
{
	if (j==n+1) {dem=(dem+1) % MOD;return ;}
	for (int i=1;i<=3;i++)
	{
		counter=0;
		value[i]++;
		if (value[i]>mmax) {
		value[i]--;
		continue;
		}
		if (i==2) {
		if (value[1]!=0) value[1]--;
		else {
		value[i]--;continue;
			}
		}
		else if (i==3) {
		if (value[2]!=0 && value[1]!=0) value[1]--,value[2]--;
		else if (value[1]>=3) value[1]-=3,counter=1;
		else {
		value[i]--;
		continue;
			}
		}
		dfs(j+1);
		value[i]--;
		if (i==2) {value[1]++;}
		else if (i==3) {
		if (counter==1) value[1]+=3;
		else value[1]++,value[2]++;
		} 
	}
}

int main()
{
	IOS;
	FRE;
	cin>>n>>mmax;
	for (int i=1;i<=3;i++) cin>>value[i];
	dfs(1);
	cout<<dem;
}
