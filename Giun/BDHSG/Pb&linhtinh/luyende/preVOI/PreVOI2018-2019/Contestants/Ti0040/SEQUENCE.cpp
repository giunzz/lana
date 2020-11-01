/**Lucky Boy**/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 3005
#define maxm 500005
#define pii pair <int,int>
#define Task "SEQUENCE"
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
using namespace std;
int n,m,k,a[maxn],b[maxn],ans[maxn],c[maxn],d[maxn],ww[maxn],t1[maxn << 2],t2[maxn << 2],dif1[maxn],dif2[maxn],last[maxn << 2];
int Min(int c[],int x,int y)
{
    if (c[x] == c[y])
    {
        if (x > y) return y;
        return x;
    }
    if (c[x] > c[y]) return y;
    return x;
}
void Build(int t[],int c[],int l,int r,int id)
{
    if (l == r)
    {
        t[id] = l;
        return;
    }
    int mid = (l+r) >> 1;
    Build(t,c,l,mid,2*id);
    Build(t,c,mid+1,r,2*id+1);
    t[id] = Min(c,t[2*id],t[2*id+1]);
}
int Get(int t[],int c[],int l,int r,int id,int u,int v)
{
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return t[id];
    int mid = (l+r) >> 1;
    int L = Get(t,c,l,mid,2*id,u,v);
    int R = Get(t,c,mid+1,r,2*id+1,u,v);
    return Min(c,L,R);
}
void Update(int l,int r,int id,int x,int val)
{
    if (l > r) return;
    last[id] = min(last[id],val);
    if (l == r) return;
    int mid = (l+r) >> 1;
    if (mid >= x) Update(l,mid,2*id,x,val);
    else Update(mid+1,r,2*id+1,x,val);
}
int Get1(int l,int r,int id,int u,int v)
{
    if (l > v || r < u) return maxc;
    if (u <= l && r <= v) return last[id];
    int mid = (l+r) >> 1;
    return min(Get1(l,mid,2*id,u,v),Get1(mid+1,r,2*id+1,u,v));
}
void Pro(int cnt1,int cnt2)
{
    int lim = 1;
    FOR(i,1,cnt1)
    {
        int re = cnt1 - i;
        c[i] = Get(t1,a,1,n,1,lim,n-re);
        lim = c[i] + 1;
        c[i] = a[c[i]];
    }
    lim = 1;
    FOR(i,1,cnt2)
    {
        int re = cnt2 - i;
        d[i] = Get(t2,b,1,m,1,lim,m-re);
        lim = d[i] + 1;
        d[i] = b[d[i]];
    }
    int temp1 = 1,temp2 = 1,cur = 0;
    FOR(i,1,3000*4) last[i] = maxc;
    FORD(i,cnt1,1)
    {
        dif1[i] = min(Get1(1,3000,1,1,c[i]-1),Get1(1,3000,1,c[i]+1,3000));
        Update(1,3000,1,c[i],i);
    }
    FOR(i,1,3000*4) last[i] = maxc;
    FORD(i,cnt2,1)
    {
        dif2[i] = min(Get1(1,3000,1,1,d[i]-1),Get1(1,3000,1,d[i]+1,3000));
        Update(1,3000,1,d[i],i);
    }
    while (temp1 <= cnt1 && temp2 <= cnt2)
    {
        if (c[temp1] < d[temp2])
        {
            ww[++cur] = c[temp1];
            ++temp1;
        }
        else if (c[temp1] > d[temp2])
        {
            ww[++cur] = d[temp2];
            ++temp2;
        }
        else
        {
            int qq = dif1[temp1],
                aa = dif2[temp2];
            if (qq == maxc || aa == maxc)
            {
                ww[++cur] = c[temp1];
                ++temp1;
            }
            else
            {
                qq = c[qq];
                aa = d[aa];
                if (qq == aa)
                {
                    ww[++cur] = c[temp1];
                    ++temp1;
                }
                else if (qq < aa)
                {
                    ww[++cur] = c[temp1];
                    ++temp1;
                }
                else
                {
                    ww[++cur] = d[temp2];
                    ++temp2;
                }
            }
        }
    }
    while (temp1 <= cnt1)
    {
        ww[++cur] = c[temp1];
        ++temp1;
    }
    while (temp2 <= cnt2)
    {
        ww[++cur] = d[temp2];
        ++temp2;
    }
    FOR(i,1,k)
        if (ans[i] != ww[i])
        {
            if (ans[i] > ww[i])
            {
                FOR(j,1,k) ans[j] = ww[j];
            }
            break;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    cin >> n >> m >> k;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    FOR(i,1,k) ans[i] = maxc;
    a[0] = b[0] = maxc;
    Build(t1,a,1,n,1);
    Build(t2,b,1,m,1);
    FOR(i,0,n)
        if (k - i < 0) break;
        else if (k-i <= m)
                Pro(i,k-i);
    FOR(i,1,k) cout << ans[i] << ' ';
    return 0;
}
