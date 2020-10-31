#include<bits/stdc++.h>
using namespace std;
int n,mmax,m50,m1,m2,res=0;
void dequy(int num, int so1, int so2 ,int so3)
{
    if (num==n+1) {res++; return;}
    if (so1+1<=mmax) dequy(num+1,so1+1,so2,so3);
    if (so2+1<=mmax && so1>=1) dequy(num+1,so1-1,so2+1,so3);
    if (so3+1<=mmax)
    {
        if (so1>=1 && so2>=1) dequy(num+1,so1-1,so2-1,so3+1);
        else if (so1>=3) dequy(num+1,so1-3,so2,so3+1);
    }
}
int main()
{
	freopen("ICECREAM.inp","r",stdin);
	freopen("ICECREAM.out","w",stdout);
    cin>>n>>mmax>>m50>>m1>>m2;
    dequy(1,m50,m1,m2);
    cout<<res;
	return 0;
}
