#include <bits/stdc++.h>
#define task "icecream"
#define int int64_t
using namespace std;
template <typename T> inline void R(T &x)
{
    bool neg=false;
    register int c;
    x=0;
    c=getchar();
    if (c=='-')
    {
        neg=true;
        c=getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        x=(x>>1)+(x>>3)+c-48;
    if (neg) x=-x;
}
const int base=1e9+9;
const int N=305;
int n,mx,m50,m1,m2,cnt[3],res,x[N];
void cn()
{
    bool ok=1;
    cnt[0]=m50;
    cnt[1]=m1;
    cnt[2]=m2;
    for (int i=1; i<=n; ++i) {
        //if (cnt[0]>mx || cnt[1]>mx || cnt[2]>mx)
           // break;
        if (!x[i])
        {
            if (cnt[0]<mx)
                cnt[0]++;
            else
            {
                ok=0; break;
            }
        }
        if (x[i]==1)
        {
            if (cnt[0]>0 && cnt[0]<=mx && cnt[1]<mx)
            {
                cnt[0]--;
                cnt[1]++;
            }
            else
            {
                ok=0;
                break;
            }
        }
        if (x[i]==2)
        {
            if (cnt[1]>0 && cnt[1]<=mx && cnt[0]>0 && cnt[0]<=mx && cnt[2]<mx)
            {
                cnt[1]--;
                cnt[0]--;
                cnt[2]++;
                continue;
            }
            else
                if (cnt[0]>=3 && cnt[0]<=mx && cnt[2]<mx)
                {
                    cnt[0]-=3;
                    cnt[2]++;
                }
            else
            {
                ok=0; break;
            }
        }
    }
    if (ok)
    {
        /*for (int i=1; i<=n; ++i)
            cout<<x[i]<<" ";
        cout<<endl;*/
        res=(res+1)%base;
    }
}
void Try(int i)
{
    for (int j=0; j<=2; ++j)
    {
        x[i]=j;
        if (i==n) cn();
        else Try(i+1);
    }
}
void sub1()
{
    Try(1);
    cout<<res;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>mx>>m50>>m1>>m2;
    if (n<=15) sub1();
    return 0;
}
