#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define ii pair<int, int>
#define mod 1e9+7;
#define HANH "ARRANGE"
using namespace std;
const int N=1e5+5;
int n, a[N], s1, s2, dau=N, cuoi=0, ss, sk;
long long s, kq;
priority_queue <ii> q;
void sub1()
{
    priority_queue <ii> su;
    for(int i=1; i<=n; ++i)
        if(a[i]>s1) su.push(mp(i, a[i]-s1));
    for(int i=n; i>0; --i)
    {
        if(!su.size()) break;
        if(a[i]<s1)
        {
        int k=s1-a[i];
        while(k && su.size())
            {
                int u=su.top().x;
                int v=su.top().y; su.pop();
                if(v>=k)
                {
                    kq+=1ll*k*abs(u-i);
                    v-=k;
                    a[u]-=k;
                    k=0;
                    if(v) su.push(mp(u, v));
                }
                else
                {
                    k-=v;
                    a[u]-=v;
                    kq+=1ll*v*abs(u-i);
                }
            }
        }
    }
    printf("%lld", kq);
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(HANH".inp", "r", stdin);
    freopen(HANH".out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), s+=a[i];
    s1=s/n;
    s2=s-1ll*s1*n;
    int s3=s2;
    if(s2==0) { sub1(); return 0; }
    int them=1;
    for(int i=1; i<=n; ++i) if(a[i]>s1+1) q.push(mp(i, a[i]-s1-1));
    for(int i=1; i<=n; ++i)
    {
        if(s2==0) --them;
        if(a[i]<s1 && a[i-1]>s1+them)
            {
                int k=a[i-1]-s1-them;
                a[i-1]=s1+1;
                --s2;
                a[i]+=k;
                kq+=k;
            }
        if(a[i]<s1)
        {
            int k=s1-a[i];
            a[i]=s1;
            a[i+1]-=k;
            kq+=k;
        }
    }
    if(s2==0) printf("%lld", kq);
    for(int i=1; i<=n; ++i) if(a[i]>s1+1) { dau=min(dau, i); cuoi=max(cuoi, i); }
    s2=n-s3;
    s2/=2;
    printf("%lld", kq);
}
