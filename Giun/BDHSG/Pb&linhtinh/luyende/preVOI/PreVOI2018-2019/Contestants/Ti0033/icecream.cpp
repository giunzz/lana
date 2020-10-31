#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+9;
long long m,n,d,mmax,m50,m1,m2;
void Try(int i)
{
    if (i>n)
        {
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
