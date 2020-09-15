#include <iostream>
#include <stdio.h>
using namespace std;
int d[50];
int a[1000009],n,dem=0,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("mangdep.inp","r",stdin);
	freopen("mangdep.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	  { 
        cin>>x;
        if (x==4||x==8||x==15||x==16||x==42||x==23) {
                                                       dem++;
                                                       a[dem]=x;
                                                    }
	  }
    for (int i=1;i<=dem;i++)
      {
        if (a[i]==4) d[4]++;
        if (a[i]==8&&d[4]!=0) {
                                d[8]++;
                                d[4]--;
                              }
        if (a[i]==15&&d[8]!=0) {
                                d[15]++;
                                d[8]--;
                              }
        if (a[i]==16&&d[15]!=0) {
                                  d[16]++;
                                  d[15]--;
                                }
        if (a[i]==23&&d[16]!=0) {
                                  d[23]++;
                                  d[16]--;
                                }
        if (a[i]==42&&d[23]!=0) {
                                  d[42]++;
                                  d[23]--;
                                }
      }
    cout<<n-d[42]*6;
  //  cout<<d[4]<<" "<<d[8]<<" "<<d[15]<<" "<<d[16]<<" "<<d[23]<<" "<<d[42];
	return 0;
}