#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a,b_=b;i<=b_;++i)
#define ford(i,a,b) for(int i=a,b_=b;i>=b_;--i)
#define forv(i,a) for(auto &i:a)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ___ << "\n"
#define __ << " " <<
#define _ << " "
#define getbit(x,i) (((x)>>(i))&1)
#define onbit(x,i) ((x)|(1<<(i)))
#define INF 1000000000000000
using namespace std;

const int N=4005;
int n,k,a[N],b[N];
vector<int> tr[105][105];
int f[N][N];
pii d[N][N];

int tried[N],res,used[N],us;
vector<int> st;

bool CmpV(vector<int> &x, vector<int> &y)
{
    fori(i,0,x.size()-1) if(x[i]<y[i]) return true;
    else if(x[i]>y[i]) return false;
    return false;
}
void Check()
{
    int len=0,j,pos=0; us++;
    vector<int> vt;
    fori(i,1,n) if(tried[i]==1)
    {
        if(!vt.empty() && abs(vt.back()-a[i])>k) return;
        len++; j=1;
        while(j<=n && (a[i]!=b[j] || used[j]==us)) j++;
        if(j>n || j<=pos) return; pos=j;
        used[j]=us; vt.pb(a[i]);
    }
    if(len==0) return;
    if(res==len)
    {
        if(CmpV(st,vt)) swap(st,vt);
    }
    if(res<len) res=len, swap(st,vt);
}
void Att(int i)
{
    if(i>n) Check();
    else
    {
        fori(j,0,1)
        {
            tried[i]=j; Att(i+1);
        }
    }
}
void Apps1()
{
    st.pb(0);
    Att(1);
    cout << res ___;
    fori(i,0,res-1) cout << st[i] _;
}
bool Cmp(int i, int j)
{
    int ss=f[i][j-1];
    if(ss==0) return 0; /// i,j-1;
    fori(x,0,ss-1)
    {
        if(tr[i][j-1][x]>tr[i-1][j][x]) return 0;
        else if(tr[i][j-1][x]<tr[i-1][j][x]) return 1; /// i-1,j
    }
    return 0;
}
void Apps2()
{
    fori(i,1,n) fori(j,1,n)
    {
        if(a[i]==b[j])
        {
            if(f[i-1][j-1]>0)
            {
                if(abs(tr[i-1][j-1].back()-a[i])<=k)
                {
                    f[i][j]=f[i-1][j-1]+1;
                    if(f[i-1][j-1]>0) tr[i][j]=tr[i-1][j-1];
                    tr[i][j].pb(a[i]);
                }
                else
                {
                    f[i][j]=1; tr[i][j].pb(a[i]);
                }
            }
            if(f[i-1][j-1]==0){ f[i][j]=1; tr[i][j].pb(a[i]); }
        }
        else
        {
            int x,y;
            if(f[i][j-1]<f[i-1][j]) x=i-1, y=j;
            else if(f[i][j-1]>f[i-1][j]) x=i, y=j-1;
            else
            {
                bool o=Cmp(i,j);
                if(o==0) x=i, y=j-1;
                else x=i-1, y=j;
            }
            f[i][j]=f[x][y];
            if(f[x][y]>0) tr[i][j]=tr[x][y];
            continue;
        }
    }
    //fori(i,1,n) fori(j,1,n) cout << i __ j __ f[i][j] ___;
    cout << f[n][n] ___;
    fori(i,0,f[n][n]-1) cout << tr[n][n][i] _;
}
void Apps3()
{
    reverse(a+1,a+n+1);
    reverse(b+1,b+n+1);
    fori(i,1,n) fori(j,1,n)
    {
        if(a[i]==b[j])
        {
            if(abs( d[i-1][j-1].fi - a[i] )<=k || d[i-1][j-1].fi==0)
            {
                f[i][j]=f[i-1][j-1]+1;
                d[i][j]={a[i],1};
            }
            else
            {
                f[i][j]=1; d[i][j]={a[i],4};
            }
        }
        else
        {
            if(f[i][j-1]<f[i-1][j]) f[i][j]=f[i-1][j], d[i][j]={d[i-1][j].fi,2};
            else if(f[i][j-1]>f[i-1][j]) f[i][j]=f[i][j-1], d[i][j]={d[i][j-1].fi,3};
            else
            {
                if(d[i][j-1].fi>d[i-1][j].fi)
                {
                    f[i][j]=f[i][j-1]; d[i][j]={d[i][j-1].fi,3};
                }
                else f[i][j]=f[i-1][j], d[i][j]={d[i-1][j].fi,2};
            }
        }
    }
    int x=n,y=n;
    cout << f[n][n] ___;
    while(d[x][y].fi!=0)
    {
        if(d[x][y].se==1) cout << d[x][y].fi _;
        if(d[x][y].se==4) break;
        if(d[x][y].se==1) x--, y--;
        else if(d[x][y].se==2) x--;
        else y--;
    }
}
int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    scanf("%d %d",&n,&k);
    fori(i,1,n) scanf("%d",&a[i]);
    fori(i,1,n) scanf("%d",&b[i]);
    if(n<=20) Apps1();
    else if(n<=100) Apps2();
    else Apps3();
}


