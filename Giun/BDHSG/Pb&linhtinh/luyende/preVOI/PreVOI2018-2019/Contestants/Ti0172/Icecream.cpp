#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

int n, mmax, m50, m1, m2, a[20], res; 

void tinh(){
    int n50=m50, n1=m1, n2=m2, j=0;
    for (int i=1; i<=n; i++){
        if(a[i]==1) {
            if (n50<mmax) n50++;
            else break;
        }
        if (a[i]==2){ 
            if (n1<mmax){
                n1++;
                if (n50>0) n50--;
                else    break;
            }
            else break;
        }
        if (a[i]==3) {
            if (n2<mmax){
                n2++;
                if (n50>0 && n1>0)
                    n50--, n1--;
                else   
                    if (n50>=3)
                        n50-=3;
                else    break;
            }
            else break;
        }
        j=i;
    }
        
    if (j==n) res++;

}

void sinh(int i){
    for(int j=1;j<=3;j++)
    {
        a[i]=j;
        if(i==n)   
            tinh();
        else
            sinh(i+1); 
    }
}

int main()
{
    freopen("Icecream.inp", "r", stdin);
    freopen("Icecream.out", "w", stdout);
    cin>>n>>mmax;
    cin>>m50>>m1>>m2;
    res=0;
    sinh(1);
    cout<<res;
}