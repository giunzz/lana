#include <bits/stdc++.h>

using namespace std;
int n,m,k,p,a[3005],b[3005],c[3005],s1,s2;
int check(int x, int y)
{
    while (a[x]==b[y]) {if ((x==m && y==n)|| a[x]!=a[x-1]) return 0;if (x<m) x++;if (y<n) y++;}
    if (a[x]>b[y]) return -1;else return 1;
}
void ghep()
{
    int i=1,j=1;
    p=0;
    while (m+n>p)
    {
        if (j>n || a[i]<b[j]) {p++;c[p]=a[i];i++;}
        else if (i>m || a[i]>b[j]) {p++;c[p]=b[j];j++;}
        else
            if (a[i]==b[j])
        {
            int r=check(i,j);
            if (r==0) {int g=a[i];while (a[i]==g) {p++;c[p]=a[i];i++;}}
            if (r==-1) while (a[i]==b[j] && j<=n) {p++;c[p]=b[j];j++;}
            if (r==1) while (a[i]==b[j] && i<=m) {p++;c[p]=a[i];i++;}
        }
    }
}
void solve()
{
    int x=1;
    while (n+m>k)
    {
        if (s1>=s2)
        {
            x=1;
            while (a[x]<=a[x+1] && x<m) x++;
            if (x!=m) {m--;for (int i=x;i<=m;i++) a[i]=a[i+1];x--;}
            if (x==m) break;
        }
        else
        {
            x=1;
            while (b[x]<=b[x+1]&& x<n) x++;
            if (x!=n) {n--;for (int i=x;i<=n;i++)b[i]=b[i+1];x--;}
            if (x==n) break;
        }
    }
    x=1;
    a[m+1]=10;b[n+1]=10;
    ghep();
    for (int i=1;i<=p;i++) cout<<c[i]<<" ";
}
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>k;
    int s1=0,s2=0;
    for (int i=1;i<=m;i++) {cin>>a[i];if (a[i]<a[i-1]) s1++;}
    for (int i=1;i<=n;i++) {cin>>b[i];if (b[i]<b[i-1]) s2++;}
    solve();
    return 0;
}
