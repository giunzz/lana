#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

int n, m ,k , a[3000], b[3000], c[3000], res[3000];

int main()
{
    freopen("Sequence.inp", "r", stdin);
    freopen("Sequence.inp", "w", stdout);
    cin>>m>>n>>k;
    for (int i=1; i<=k; i++)
        res[i]=1000000000;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        cin>>b[i];
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    for (int i=1; i<=min(k,n); i++){
        for (int j=1; j<=i; j++)
            c[j]=a[j];
        for (int j=i+1; j<=k; j++)
            c[j]=b[j-i]; 
        //for (int j=1; j<=k; j++)
            //cout<<c[j]<<" ";
        for (int j=1; j<=k; j++){
            if (c[j]>res[j])
                break;           
            if (c[j]<res[j]) 
                for (int v=1; v<=k; v++)
                    res[v]=c[v];
        }
         //cout<<endl;
    }
    for (int v=1; v<=k; v++)
        cout<<res[v]<<" ";   
}