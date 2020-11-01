#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
int a[maxn];
ll b[maxn],le[maxn],ri[maxn];
int n,k;
ll res;
void solve()
{
        ll maxx=0;
        for (int i=k+1;i<=n;++i)
        {
                maxx=max(maxx,b[i-k]);
                le[i]=maxx;
        }
        maxx=0;
        for (int i=n-k;i>=1;--i)
        {
                maxx=max(maxx,b[i+1]);
                ri[i]=maxx;
        }
        res=1e18;
        for (int i=1;i<=n-k+1;++i)
        {
                ll tmp=max(le[i],ri[i+k-1]);
                res=min(res,tmp);
        }
        write(res);
}
void sub2()
{
        res=1e18;
        for (int i=1;i<=n-k+1;++i)
        {
                ll ans=0;
                for (int j=1;j<=i-k;++j)
                        ans=max(ans,b[j]);
                for (int j=i+k;j<=n-k+1;++j)
                        ans=max(ans,b[j]);
                res=min(res,ans);
        }
        write(res);
}
int main()
{
        freopen("GIFTS.inp","r",stdin);
        freopen("GIFTS.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(n);read(k);
        for (int i=1;i<=n;++i)
                read(a[i]);
        for (int i=1;i<=k;++i)
                b[1]+=a[i];
        for (int i=2;i<=n-k+1;++i)
                b[i]=b[i-1]-a[i-1]+a[i+k-1];
        if (n<=5000) sub2();
        else
                solve();
}
