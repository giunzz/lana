#include <bits/stdc++.h>

using namespace std;
int n,k,dem;
const long long oo=10000000000000;
long long st[4000001];
int x[1000000];
long long a[1000000];

void setup()
{
        cin >> n >> k;
        int sum=0;
        for (int i=1;i<=n;++i)
        {
                cin >> x[i];
                sum+=x[i];
                if (i>=k)
                {
                        ++dem;
                        a[dem]=sum;
                        sum-=x[i-k+1];
                }
        }
}

void update(int id,int l,int r,int i,long long v)
{
        if (i<l||r<i)
        {
                return;
        }
        st[id]=max(st[id],v);
        if (l==r)
                return;
        int mid=(l+r)/2;
        update(id*2,l,mid,i,v);
        update(id*2+1,mid+1,r,i,v);
}

long long get(int id,int l,int r,int u,int v)
{
        if (v<l||r<u)
        {
                return -oo;
        }
        if (u<=l&&r<=v)
        {
                return(st[id]);
        }
        int mid=(l+r)/2;
        long long tg1=get(id*2,l,mid,u,v);
        long long tg2=get(id*2+1,mid+1,r,u,v);
        return max(tg1,tg2);

}

void solve()
{

        for (int i=1;i<=dem;++i)
                update(1,1,dem,i,a[i]);
        long long finalRes=oo;
        for (int i=1;i<=dem;++i)
        {
                long long res=-1;
                int left=i-k;
                int right=i+k;
                if (left>=1)
                        res=max(res,get(1,1,dem,1,left));
                if (right<=dem)
                        res=max(res,get(1,1,dem,right,dem));
                if (res!=-1)
                        {
                                finalRes=min(res,finalRes);
                        }

        }
        cout << finalRes;

}

int main()
{
    ios::sync_with_stdio(false);
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    setup();
    solve();
    return 0;
}
