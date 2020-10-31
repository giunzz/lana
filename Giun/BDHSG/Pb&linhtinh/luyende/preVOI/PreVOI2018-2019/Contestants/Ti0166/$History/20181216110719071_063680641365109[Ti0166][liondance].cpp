#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define maxn 4001
#define st first
#define nd second
#define Tshiro "liondance"

using namespace std;

const int oo = 1e9+7;

int getbit(int i,int j)
{
    return ((i>>j)&1);
}

int n, k;
int a[maxn], b[maxn];
int sl, sltg, vt, vt1, vt2;
vector<int> tt;
vector<int> res;
map<vector<int>,bool> m;
int f[maxn][maxn], lv[maxn];pii luu[maxn][maxn];
bool kt, ktt;

void sub1()
{
    res.clear();
    fto(i,1,(1<<n)-1)
    {
        kt=true;tt.clear();vt=0;
        fdto(j,n-1,0) if (getbit(i,j))
        {
            if (!vt) {vt=n-j;tt.pb(a[n-j]);}
            else
            {
                if (abs(a[n-j]-a[vt])>k) {kt=false;break;}
                else {vt=n-j;tt.pb(a[n-j]);}
            }
        }
        if (kt)
        {
            m[tt]=1;
        }
    }
    fto(i,1,(1<<n)-1)
    {
        kt=true;tt.clear();vt=0;
        fdto(j,n-1,0) if (getbit(i,j))
        {
            if (!vt) {vt=n-j;tt.pb(a[n-j]);}
            else
            {
                if (abs(b[n-j]-b[vt])>k) {kt=false;break;}
                else {vt=n-j;tt.pb(b[n-j]);}
            }
        }
        if (kt)
        {
            if (m[tt])
            {
                if (res.size()<tt.size())
                {
                    res.clear();
                    for(int z=0; z<tt.size(); ++z) res.pb(tt[z]);
                }
                else if (res.size()==tt.size())
                {
                    for(int z=0; z<tt.size(); ++z)
                    {
                        if (res[z]>tt[z]) {ktt=false;break;}
                        if (res[z]<tt[z]) {ktt=true;break;}
                    }
                    if (ktt)
                    {
                        res.clear();
                        for(int z=0; z<tt.size(); ++z) res.pb(tt[z]);
                    }
                }
            }
        }
    }
    cout << res.size() << '\n';
    for(int i=0; i<res.size(); ++i) cout << res[i] << " ";
}

void sub2()
{
    vt1=vt2=0,kq=0;
    fto(i,1,n)
    fto(j,1,n)
    if (a[i]==b[j])
    {
        int tg=0;
        fto(u,1,i-1)
        fto(v,1,j-1) if (a[u]==b[v] && abs(a[i]-a[u])<=k && (f[u][v]+1>f[i][j] || (f[u][v]+1==f[i][j] && a[u]>tg)))
        {
            f[i][j]=f[u][v]+1;
            luu[i][j]=pii(u,v);
            tg=a[u];
            if (f[i][j]>kq) {vt1=i;vt2=j;kq=f[i][j];}
        }
     }
     sl=0;
     while (vt1 && vt2)
     {
        pii q=luu[vt1][vt2];
        lv[++sl]=a[vt1];
        vt1=q.st;
        vt2=q.nd;
     }
     cout << sl << '\n';
     fdto(i,sl,1) {cout << lv[i] << " ";}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    freopen(Tshiro".inp", "r", stdin);
    freopen(Tshiro".out", "w", stdout);
    cin >> n >> k;
    fto(i,1,n) cin >> a[i];
    fto(i,1,n) cin >> b[i];
    if (n<=20) sub1();
    else sub2();
    return 0;
}
