#include<bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
     freopen("mangdep.inp","r",stdin);
    freopen("mangdep.out","w",stdout);
    cin>>n;
    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
    for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x==4) c1++;
            if(x==8 &&c1) c1--,c2++;
            if(x==15 &&c2) c2--,c3++;
            if(x==16 &&c3) c3--,c4++;
            if(x==23 &&c4) c4--,c5++;
            if(x==42 &&c5) c5--,c6++;
        }
        cout<<n-c6*6;
        return 0;

}
