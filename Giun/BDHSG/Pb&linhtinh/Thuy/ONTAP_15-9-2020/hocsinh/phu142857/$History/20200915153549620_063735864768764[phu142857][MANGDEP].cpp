#include <bits/stdc++.h>

using namespace std;

int n,i,k,d,j,a[1000000];


int main()
{
    freopen("MANGDEP.inp","r",stdin);
    freopen("MANGDEP.out","w",stdout);


    cin >> n;

    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    if (n%6!=0) { cout << n;return 0;}

    else
    {
        d=0;k=0;
        for (i=1;i<n;i++)
            for (j=i+1;j<=n;j++)
        {
            if (a[i]<a[j]) {d++;a[i]=0;if (d=6) {break;a[j]=0;};k++;}
        }
    }
    cout << 0;

    /*if (d=n) {cout << 0;return 0;}
    else
    {
        while(k!=n)

    }
*/
    return 0;


}
