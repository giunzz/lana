#include <bits/stdc++.h>
#define fto(i,a,b) for (int i=a; i<=b; i++)
#define fdto(i,a,b) for (int i=a; i>=b; i--)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define maxn 4005
using namespace std;
int n, m, a[maxn], b[maxn];
void nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    cin >> n >> m;
    fto (i,1,n) cin >> a[i];
    fto (j,1,n) cin >> b[j];
}
int l[maxn][maxn], luu[maxn*maxn], c[maxn][maxn];
pii q[maxn*maxn], lv[maxn][maxn];
void xuli()
{
    fto (i,1,n)
        fto (j,1,n)
            if (a[i]==b[j]){
                if (i==1 || j==1 || abs(a[i]-c[i-1][j-1])<=m) {
                    l[i][j]=l[i-1][j-1]+1;
                    c[i][j]=a[i];
                    lv[i][j]={i-1,j-1};
                }
                else {
                    if (l[i-1][j-1]==1 && c[i-1][j-1]<a[i]) {
                        l[i][j]=1;
                        c[i][j]=a[i];
                    }
                    else {
                        l[i][j]=l[i-1][j-1];
                        c[i][j]=c[i-1][j-1];
                        lv[i][j]=lv[i-1][j-1];
                    }
                }
            }
            else {
                l[i][j]=max(l[i-1][j], l[i][j-1]);
                if (max(l[i-1][j],l[i][j-1])>l[i-1][j-1]) {
                    if (l[i-1][j]>l[i][j-1]) { lv[i][j]=lv[i-1][j]; c[i][j]=c[i-1][j]; }
                    else if (l[i-1][j]<l[i][j-1]) { lv[i][j]=lv[i][j-1]; c[i][j]=c[i][j-1]; }
                        else if (c[i-1][j]>c[i][j-1]) {lv[i][j]=lv[i-1][j]; c[i][j]=c[i-1][j];}
                                else {lv[i][j]=lv[i][j-1]; c[i][j]=c[i][j-1];}
                }
                else
                    if (c[i-1][j-1]>=c[i-1][j] && c[i-1][j-1]>=c[i][j-1]) {
                            lv[i][j]=lv[i-1][j-1];
                            c[i][j]=c[i-1][j-1];
                    }
                    else if (c[i-1][j]>=c[i-1][j-1] && c[i-1][j]>=c[i][j-1]) {
                            lv[i][j]=lv[i-1][j];
                            c[i][j]=c[i-1][j];
                    }
                    else if (c[i][j-1]>=c[i-1][j-1] && c[i][j-1]>=c[i-1][j]) {
                            lv[i][j]=lv[i][j-1];
                            c[i][j]=c[i][j-1];
                    }
            }
    int res=0, d=0, cuoi=0;
    fto (i,1,n)
        fto (j,1,n)
            if (l[i][j]>res) {
                d=1; cuoi=1; q[cuoi]={i,j};
                res=l[i][j];
            }
            else if (l[i][j]==res) {
                if (c[i][j]>c[q[cuoi].fi][q[cuoi].se]) {d=1; cuoi=1; q[cuoi]={i,j};}
                    else if (c[i][j]==c[q[cuoi].fi][q[cuoi].se]) q[++cuoi]={i,j};
            }
    cout << res << '\n';
    int cnt=1; luu[1]=c[q[cuoi].fi][q[cuoi].se];
    int i=lv[q[cuoi].fi][q[cuoi].se].fi;
    int j=lv[q[cuoi].fi][q[cuoi].se].se;
    fto (t, 1, res-1) {
        luu[++cnt]=c[i][j];
        int i1=lv[i][j].fi;
        int j1=lv[i][j].se;
        i=i1; j=j1;
    }
    fdto (j,cnt,1) cout << luu[j] << " ";
}

int main()
{
    nhap();
    xuli();
    return 0;
}
