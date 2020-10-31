#include<bits/stdc++.h>
#define maxn 2005
#define ll long long
#define db double
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
int n,m,k,dd[maxn];
struct data
{
        ll x,y,z,val;
        db dis;
};
ll res;
data C[maxn],a[maxn],S;
db dist(data a,data b)
{
        db x=a.x-b.x;
        db y=a.y-b.y;
        x=x*x;
        y=y*y;
        x=x+y;
        return (db)sqrt(x);
}
db dt(data a,data b,data c)
{
        db res=(db)a.x*(b.y-c.y)+(db)b.x*(c.y-a.y)+(db)c.x*(a.y-b.y);
        if (res<0) res=-res;
        return res;
}
void dfs(int now)
{
        if (now==n+1)
        {
                ll sum=0;
                vector<data >e;
                e.clear();
                for (int i=1;i<=n;++i)
                {
                        if (!dd[i]) continue;
                        e.push_back({a[i].x,a[i].y,a[i].z,0,dist(a[i],S)});
                        sum+=a[i].val;
                }
                int d=0;
                if (sum==105)
                {
                        int ok=1;
                }
                for (int i=1;i<=m;++i)
                {
                        for (int j=0;j<e.size();++j)
                        {
                                db D=dt(C[i],e[j],S);
                                db Q=e[j].dis;
                                D/=e[j].dis;
                                db disA=dist(S,C[i]);
                                db disB=dist(e[j],C[i]);
                                if (disA<=C[i].val&&disB<=C[i].val) continue;
                                if ((disA>C[i].val&&disB<=C[i].val)||(disA<=C[i].val&&disB>C[i].val))
                                {
                                        ++d;
                                        break;
                                }
                                if (D==0) continue;
                                D=max(D,min(disA,disB));
                                if (D<=C[i].val)
                                {
                                        ++d;
                                        break;
                                }

                        }
                        if (d>k) break;
                }
                if (d<=k) res=max(res,sum);
                return;
        }
        dfs(now+1);
        dd[now]=1;
        dfs(now+1);
        dd[now]=0;
}
int main()
{
        freopen("TEAWORLD.inp","r",stdin);
        freopen("TEAWORLD.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(m);read(n);read(k);
        for (int i=1;i<=m;++i)
        {
                //cin>>C[i].x>>C[i].y>>C[i].z>>C[i].val;
                read(C[i].x);
                read(C[i].y);
                read(C[i].z);
                read(C[i].val);
        }
        for (int i=1;i<=n;++i)
        {
                read(a[i].x);
                read(a[i].y);
                read(a[i].z);
                read(a[i].val);
        }
        read(S.x);read(S.y);read(S.z);
        dfs(1);
        write(res);
}
