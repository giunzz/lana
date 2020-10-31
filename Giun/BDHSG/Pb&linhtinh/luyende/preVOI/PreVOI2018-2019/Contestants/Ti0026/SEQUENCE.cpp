#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    char c;
    int res,neg=1;
    c=getchar();
    if(c=='-') {neg=-1;c=getchar();}
    res=c-'0';
    for(c=getchar();c>='0' && c<='9';c=getchar()) res=res*10+c-'0';
    return neg*res;
}
void write(int x)
{
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int m,n,k;
int a[3010],b[3010];
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return (x.first<y.first) || (x.first==y.first && x.second>y.second);
}
int main()
{
    #define file "SEQUENCE"
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j;
    vector<int> va,vb;
    pair<int,int> pa[3010],pb[3010];
    cin>>m>>n>>k;
    for(i=1;i<=m;i++) cin>>a[i];
    for(i=1;i<=n;i++) cin>>b[i];
    for(i=1;i<=m;i++) pa[i]={a[i],i};
    for(i=1;i<=n;i++) pb[i]={b[i],i};
    sort(pa+1,pa+m+1,cmp);sort(pb+1,pb+n+1,cmp);
    i=1;j=1;
    while(va.size()+vb.size()<k)
    {
        while(va.size()+vb.size()<k && ((i<=m && pa[i].first<=pb[j].first) || j==n+1)) {va.push_back(pa[i].second);i++;}
        while(va.size()+vb.size()<k && ((j<=n && pa[i].first>=pb[j].first) || i==m+1)) {vb.push_back(pb[j].second);j++;}
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    i=0;j=0;
    while(i<va.size() || j<vb.size())
    {
        while(i<va.size() && (a[va[i]]<=b[vb[j]] || j==vb.size())) {cout<<a[va[i]]<<" ";i++;}
        while(j<vb.size() && (a[va[i]]>=b[vb[j]] || i==va.size())) {cout<<b[vb[j]]<<" ";j++;}
    }
    return 0;
}
