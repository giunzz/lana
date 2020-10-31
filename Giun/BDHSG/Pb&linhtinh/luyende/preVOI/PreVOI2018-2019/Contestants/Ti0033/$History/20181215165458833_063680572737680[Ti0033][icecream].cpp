#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+9;
long long m,n,d,mmax,m50,m1,m2,a[10005],f1[500],f2[500],f3[500],f[500];
void Try(int i)
{
    if (i>n)
        {
            //for (int j=1;j<=n;j++) cout<<a[j]<<" ";cout<<"\n";
            d++;return;
        }
    if (m50<mmax) {m50++;Try(i+1);m50--;}
    if (m1<mmax && m50>=1) {m50--;m1++;Try(i+1);m50++;m1--;}
    if (m2<mmax)
    {
        if (m1>=1 && m50>=1) {m1--;m50--;m2++;Try(i+1);m1++;m50++;m2--;}
        else
            if (m50>=3) {m50-=3;m2++;Try(i+1);m50+=3;m2--;}
    }
}
/*void solve()
{
    f1[0]=m50;
    f2[0]=m1;
    f3[0]=m2;
    for (int i=1;i<=n;i++)
    {
        if (f[i-1]<mmax) f[i]++
    }
}*/
int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>mmax;
    cin>>m50>>m1>>m2;
    d=0;
    Try(1);
    cout<<d;
    return 0;
}
