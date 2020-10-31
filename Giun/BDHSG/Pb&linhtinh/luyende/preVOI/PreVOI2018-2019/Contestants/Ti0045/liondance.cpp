#include <bits/stdc++.h>
#define maxn 4005
#define maxc
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define DH "liondance"
using namespace std;
long n,k;
long a[maxn],b[maxn],F[maxn],c[maxn];
vector < long > v;
void nhap()
{
    cin >> n >> k;
    for(long i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(long i=1;i<=n;++i)
    {
        cin >> b[i];
    }
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+n);
}
void lam()
{
    for(long i=1;i<=n;++i)
    {
        memset(c,0,sizeof(c));
        for(long j=1;j<=n;++j)
        {
            c[j]=c[j-1];
            if(abs(a[i]-b[j])<=k)
            {
                c[j]=max(c[j],F[j]);
            }
        }
        for(long j=1;j<=n;++j)
        {
            if(a[i]==b[j])
            {
                F[j]=max(F[j],c[j-1]+1);
            }
        }
    }
    long x= *max_element(F+1,F+1+n);
    cout << x <<endl;
    vector < long > kq;
    kq.clear();
    long id;
    long gt=0;
    for(long i=1;i<=n;++i)
    {
        if(F[i]!=x) continue;
        if(b[i]>= gt)
        {
            id=i;
            gt=b[i];
        }
    }
    kq.PB(b[id]);
    while(1)
    {
        if(F[id]==1) break;
        long id1;
        gt=0;
        for(long i=1;i<id;++i)
        {
            if(abs(b[i]-b[id])<=k && F[i]+1==F[id])
            {
                if(b[i]>=gt)
                {
                    id1=i;
                    gt=b[i];
                }
            }
        };
        id=id1;
        kq.PB(b[id]);
    }
    for(auto hang:kq) cout << hang <<" ";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(DH".inp","r",stdin);
    freopen(DH".out","w",stdout);
    nhap();
    lam();
    return 0;
}
