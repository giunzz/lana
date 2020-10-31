#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define pii pair<int,int >
#define F first
#define S second
#define mp make_pair
#define maxn 3050
#define int long long
#define pb push_back
using namespace std;
const int oo=1e15+7;
int n,k;
int dd[maxn];
pii a[maxn];
int re[maxn],res=0,kq[maxn];
void dq(int x)
{
    if(x>n)
    {
        int dem=0;
        int ch=0;
        FOR(i,1,n)
        {
            if(dd[i]&&a[i].F==a[i].S)
            {
                re[++dem]=a[i].F;
                ch=0;
            }
            else if(dd[i]&&ch==0)
            {
                ch=i;
            }
            else if(dd[i]&&ch)
            {
                int ma=0;
                if(a[i].S==a[ch].F&&abs(a[i].S-re[dem])<=k)
                    ma=max(ma,a[i].S);
                if(a[i].S==a[ch].S&&abs(a[i].S-re[dem])<=k)
                    ma=max(ma,a[i].S);
                if(a[i].F==a[ch].F&&abs(a[i].F-re[dem])<=k)
                    ma=max(ma,a[i].F);
                if(a[i].F==a[ch].S&&abs(a[i].F-re[dem])<=k)
                    ma=max(ma,a[i].F);
                if(ma>0) re[++dem]=ma;
                ch=0;
            }
        }
//        cout<<dem<<endl;
//        FOR(i,1,dem)
//        {
//            cout<<re[i]<<" ";
//        }
//        cout<<endl;
        if(dem>res)
        {
            res=dem;
            FOR(i,1,dem)
            {
                kq[i]=re[i];
            }
//            cout<<endl;
        }
        else if(dem==res)
        {
            FOR(i,1,dem)
            {
                if(kq[i]<re[i])
                {
                    FOR(j,i,dem)
                    {
                        kq[j]=re[j];
                    }
                    break;
                }
            }

        }
    }
    else
    {
        FORD(i,1,0)
        {
            dd[x]=i;
            dq(x+1);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n)
    {
        cin>>a[i].F;
    }
    FOR(i,1,n)
    {
        cin>>a[i].S;
    }
    if(n<=22)
        dq(1);
    FOR(i,1,res) cout<<kq[i]<<" ";
}
