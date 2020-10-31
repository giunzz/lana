#include<bits/stdc++.h>
int n,i,j,h,k,t,d,m,f[3003][3003],l,r;
using namespace std;
string res,s[3003][3003],ss[3003][3003],sss,a[3003],fs[3003][3003],fss[3003][3003],sp=" ";
bool kt(string s1,string s2)
{
    if (s1.length()<s2.length()) return true;
    if (s1.length()>s2.length()) return false;
    return (s1<s2);
}
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>m>>n>>k;
    for(i=1;i<=m;i++) cin>>a[i];
    for(i=1;i<=m;i++)
    {
        f[i][i]=i;
        for(j=i+1;j<=m;j++) if (kt(a[j],a[f[i][j-1]])) f[i][j]=j; else f[i][j]=f[i][j-1];
    }
    for(i=1;i<=min(m,k);i++)
    {
        h=0;
        for(j=0;j<i;j++)
        {
            t=f[h+1][m-(i-j)+1];
            s[i][j+1]=a[t];
            h=t;
        }
    }
    for(i=1;i<=min(m,k);i++)
    {
        fs[i][i]=s[i][i];
        for(j=i-1;j>=1;j--) fs[i][j]=s[i][j]+sp+fs[i][j+1];
    }
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++)
    {
        f[i][i]=i;
        for(j=i+1;j<=n;j++) if (kt(a[j],a[f[i][j-1]])) f[i][j]=j; else f[i][j]=f[i][j-1];
    }
    for(i=1;i<=min(n,k);i++)
    {
        h=0;
        for(j=0;j<i;j++)
        {
            t=f[h+1][n-(i-j)+1];
            ss[i][j+1]=a[t];
            h=t;
        }
    }
    for(i=1;i<=min(n,k);i++)
    {
       fss[i][i]=ss[i][i];
        for(j=i-1;j>=1;j--) fss[i][j]=ss[i][j]+sp+fss[i][j+1];
    }
    res="#";
    for(i=0;i<=min(m,k);i++)
    {
        h=k-i;
        if (h<=n)
        {
        sss="";
        l=1;r=1;
        while (l<=i||r<=h)
        {
            if (l>i) sss+=ss[h][r],r++;
            else
            if (r>h) sss+=s[i][l],l++;
            else
            if (s[i][l]<ss[h][r]||(s[i][l]==ss[h][r]&&fs[i][l]<fss[h][r])) sss+=s[i][l],l++; else sss+=ss[h][r],r++;
            sss+=sp;
        }
        if (res=="#") res=sss; else res=min(res,sss);
        }
    }
    cout<<res;
}
