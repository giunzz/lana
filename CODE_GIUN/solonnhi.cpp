#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const long maxn=1e7+4;
int n,a[maxn],ma1,ma2,stt=1;
int main(){
  cin>>n;
  for (int i=1; i<=n; i++) cin>>a[i];
    ma1=a[1];
    for(int i=2;i<=n;i++) ma1=max(ma1,a[i]);
        ma2=-maxn;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>ma2 && a[i]!=ma1)
        {
            ma2=a[i];
            stt=i;
        }
       }
       cout << stt;
       return 0;
}
