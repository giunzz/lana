#include<bits/stdc++.h>
using namespace std;

long long S,S1=1;
int a[3],n,k,d[20];

void ql(int i)
{
    if(i>n)
    {
        if(S%S1==k)
        {
        for(int j = 1 ; j <= n ; j++)
            cout<<d[j];
        exit(0);
        }
    }
    else
    {
        for(int j = 1 ; j <= 2 ; j++)
        {
            d[i]=a[j];
            S=S*10+a[j];
            ql(i+1);
            S=S/10;
        }
    }
}

int main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>a[1]>>a[2];
    cin>>n>>k;
    if(n>=20)
        cout<<"-1";
    else
    {
        for(int i = 1 ; i <= n ; i++)
            S1*=2;
        ql(1);
        cout<<"-1";
    }
}
