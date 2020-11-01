#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,k,a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=m; i++) cin >> b[i];
    int x=0,y=0;
    while (k)
    {
        int resa=1e9+5, resb=1e9+5;
        int vta=-1, vtb=-1;
        for (int i=x+1; i<=n; i++)
        {
            if (n-i+m-y<k-1) break;
            if (resa>a[i])
            {
                resa=a[i];
                vta=i;
            }
        }
        for (int i=y+1; i<=m; i++)
        {
            if (n-x+m-i<k-1) break;
            if (resb>b[i])
            {
                resb=b[i];
                vtb=i;
            }
        }
        if (resa<=resb)
        {
            cout << resa << " ";
            x=vta;
        }
        else
        {
            cout << resb << " ";
            y=vtb;
        }
        k--;
    }
}
