#include <bits/stdc++.h>
using namespace std;
const long long base=1e9+9;
long n,m,i,j,k,mx,m1,m2,m50;
long a[350],sl[55];
long long res=0;
void Try(long i)
{
    for(long j=1;j<=3;j++)
    {
        int tt=0;
        if(j==1)
        {
            if(m50<mx) m50++,tt=1;
            else continue;
        }
        else if(j==2)
        {
            if(m50>0&&m1<mx) m50--,m1++,tt=1;
            else continue;
        }
        else if(j==3)
        {
            if(m50>0&&m1>0&&m2<mx) m2++,m1--,m50--,tt=1;
            else if(m50>=3&&m2<mx) m2++,m50-=3,tt=2;
            else continue;
        }
        if(i==n) res=(res+1)%base;
        else Try(i+1);
        if(j==3)
        {
            if(tt==1) m2--,m1++,m50++;
            else if(tt==2) m2--,m50+=3;
        }
        else if(j==2)
        {
            if(tt==1) m50++,m1--;
        }
        else if(j==1)
        {
            if(tt==1) m50--;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin >> n >> mx;
    cin >> m50 >> m1 >> m2;
    Try(1);
    cout << res;
}
