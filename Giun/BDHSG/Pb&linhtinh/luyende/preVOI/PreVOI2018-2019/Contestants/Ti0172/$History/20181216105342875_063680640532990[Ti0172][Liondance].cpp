#include <bits/stdc++.h>
//#include <iostream>

using namespace std;

int n, delta, l[4001], r[4002], res[4002];
static int f[4002][4002], a[4002][4002], d[102][102];

int main()
{
    freopen("Liondance.inp", "r", stdin);
    freopen("Liondance.out", "w", stdout);
    cin>>n>>delta;
    
    for (int i=1; i<=n; i++)
        cin>>l[i];
    for (int i=1; i<=n; i++)
        cin>>r[i];
    if (n<=100){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (l[i]==r[j]){
                a[0][0]=l[i];
                for (int u=0; u<=i-1; u++)
                    for (int v=0; v<=j-1; v++)
                        if (abs(a[u][v]-l[i])<=delta)
                                f[i][j]=max(f[i][j], f[u][v]+1);
                a[i][j]=r[i];
            }
        else {  
            if (f[i][j-1]>f[i-1][j]){
                f[i][j]=f[i][j-1];
                a[i][j]=a[i][j-1];
            }
            if (f[i][j-1]<f[i-1][j]){
                f[i][j]=f[i-1][j];
                a[i][j]=a[i-1][j];
            }
            if (f[i][j-1]==f[i-1][j]){
                f[i][j]=f[i][j-1];
                a[i][j]=max(a[i-1][j], a[i][j-1]);
            }
        }
        //cout<<f[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<f[n][n]<<endl;
    int cnt=0, i, j;
    i=n; j=n;
    while (cnt<f[n][n]){
        //cout<<i<<" "<<j<<endl;
        if (l[i]==r[j]) {
            cnt++;
            res[cnt]=a[i][j];
            i--;
            j--;
        }
        else {
            if (f[i][j-1]>f[i-1][j])
                j--;
            else
            if (f[i][j-1]<f[i-1][j])
                i--;
            else
            if (f[i][j-1]==f[i-1][j]){
                //cout<<i<<" "<<j<<a[i][j-1]<<endl;
                if (a[i][j-1]>a[i-1][j]){ 
                    
                    if (abs(a[i][j-1]-res[cnt])<=delta)
                    j--;
                }
                else    
                    if (abs(a[i-1][j]-res[cnt])<=delta) i--; 
                
                else i--, j--;
            }
        }
    }
    for (int i=cnt; i>=1; i--)
        cout<<res[i]<<" ";
    }
    if (n>100){
        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++){
            if (l[i]==r[j]){
                if (abs(a[i-1][j-1]-l[i])<=delta || a[i-1][j-1]==0 )
                    f[i][j]=f[i-1][j-1]+1,
                    a[i][j]=l[i];
            }
        else {  
            if (f[i][j-1]>f[i-1][j]){
                f[i][j]=f[i][j-1];
                a[i][j]=a[i][j-1];
            }
            if (f[i][j-1]<f[i-1][j]){
                f[i][j]=f[i-1][j];
                a[i][j]=a[i-1][j];
            }
            if (f[i][j-1]==f[i-1][j]){
                f[i][j]=f[i][j-1];
                a[i][j]=max(a[i-1][j], a[i][j-1]);
            }
        }
        cout<<f[i][j]<<" ";
        }
    cout<<f[n][n]<<endl;
    int cnt=0, i, j;
    i=n; j=n;
    while (cnt<f[n][n]){
        //cout<<i<<" "<<j<<endl;
        if (l[i]==r[j]) {
            cnt++;
            res[cnt]=l[i];
            i--;
            j--;
        }
        else {
            if (f[i][j-1]>f[i-1][j])
                j--;
            else
            if (f[i][j-1]<f[i-1][j])
                i--;
            else
            if (f[i][j-1]==f[i-1][j]){
                if (a[i][j-1]<a[i-1][j])
                    j--;
                else    i--;
            }
        }
    }
    for (int i=cnt; i>=1; i--)
        cout<<res[i]<<" ";
    } 
}