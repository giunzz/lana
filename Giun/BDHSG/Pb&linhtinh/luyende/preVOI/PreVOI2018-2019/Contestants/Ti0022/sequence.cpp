#include <bits/stdc++.h>
#define fto(i,a,b) for (int i=a; i<=b; i++)
#define fdto(i,a,b) for (int i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define pi pair<int,int>
#define maxn 6005
using namespace std;
int n, m, k, a[maxn], b[maxn];
void nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    cin >> m >> n >> k;
    fto (i,1,m) cin >> a[i];
    fto (i,1,n) cin >> b[i];
}
int c[maxn], luu1[maxn], luu2[maxn], c1[maxn], c2[maxn];
void xuli()
{
    fto (t,1,k) {
        c[t]=1e9;
         fto (i,luu1[t-1]+1,m)
            fto (j,luu2[t-1]+1,n) {
                if (i+j>=t && (m-i+n-j)>=k-t) {
                    if (a[i]<c[t] && a[i]<b[j]) {
                        luu1[t]=i;
                        c[t]=a[i];
                        luu2[t]=luu2[t-1];
                    }
                    else if (b[j]<c[t] && a[i]>b[j]) {
                        luu2[t]=j;
                        c[t]=b[j];
                        luu1[t]=luu1[t-1];
                    }
                }
            }
    }
    fto (i,1,k) cout << c[i] << " ";
}

int main()
{
    nhap();
    xuli();
    return 0;
}
