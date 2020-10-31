//#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int A, B, n, k, x[63], y[63], res;
static int p[5000000], tv[5000000];
static long long q[5000000];

int main()
{
    freopen("Modulo.inp", "r", stdin);
    freopen("Modulo.out", "w", stdout);
    cin>>A>>B>>n>>k;
    long long an=1;
    for (int i=1; i<=n; i++){
        an=an*2;
    }
    x[1]=A % an;
    y[1]=B % an;
    for (int i=2; i<=n; i++){
        x[i]=x[i-1]*10 % an;
        y[i]=y[i-1]*10 % an;
    }
    int l=1, r=2, r1;
    q[1]=A%an;
    p[1]=A;
    q[2]=B%an;
    p[2]=B;
    tv[1]=-1;
    tv[2]=-1;
    for (int i=2; i<=n; i++){
        r1=r;
        while (l<=r){
            int u=q[l];
            r1++;
            q[r1]=(u+x[i]) % an;
            p[r1]=A;
            tv[r1]=l;
            r1++;
            q[r1]=(u+y[i]) % an;
            p[r1]=B;
            tv[r1]=l;
            l++; 
        }
        l=r+1;
        r=r1;
        //<<l<<" "<<r<<" ";
    }
    res=-1;
    for (int i=l; i<=r; i++)
        if (q[i]==k){
            res=i;
            //cout<<B<<" ";
            break;
        }
    //for (int i=1; i<=r; i++)
      //  cout<<p[res]<<" ";
    //cout<<l<<" "<<r<<endl;
    if (res==-1) cout<<res;
    else{
        while (res>-1){
            cout<<p[res];
            res=tv[res];
        }
    }
    
}