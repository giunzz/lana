#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
int l[4007];
int r[4007];
ii dp[107][107][107];
int n,denta;
int oo=999999999;
bool dpp[107][107][107];
string stx(int a)
{
    string kq="";
    while (a>0)
    {
        kq=char(a%10+48)+kq;
        a/=10;
    }
    return kq;
}
int check(int a,int b)
{
    string s1=stx(a);
    string s2=stx(b);
    if (s1>s2)
        return a;
    else
        return b;
}
ii slv(int i,int j,int k)
{
    if (i>n||j>n)
        return ii(0,0);
    if (dpp[i][j][k]==true)
        return dp[i][j][k];
    dpp[i][j][k]=true;
    ii cur=ii(0,0);
    if (l[i]==r[j])
    {
        if (k>0)
        {
            if (abs(l[i]-l[k])<=denta)
            {
                ii val=slv(i+1,j+1,i);
                cur.fi=val.fi+1;
                cur.se=l[i];
            }
        }
        else
        {
            ii val=slv(i+1,j+1,i);
            cur.fi=val.fi+1;
            cur.se=l[i];
        }
    }
    else
    {
        ii val1=slv(i+1,j,k);
        ii val2=slv(i,j+1,k);
        if (val1.fi>val2.fi)
        {
            cur.fi=val1.fi;
            cur.se=val1.se;
        }
        else if (val1.fi<val2.fi)
        {
            cur.fi=val2.fi;
            cur.se=val2.se;
        }
        else
        {
            cur.fi=val1.fi;
            cur.se=check(val1.se,val2.se);
        }
    }
    return dp[i][j][k]=cur;
}
void trace(int i,int j,int k)
{
    if (i>n||j>n) return;
    ii cur=slv(i,j,k);
    if (cur.se!=0) cout<<cur.se<<" ";
    while (l[i]!=cur.se&&i<=n) i++;
    while (r[j]!=cur.se&&j<=n) j++;
    trace(i+1,j+1,i);
}
int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    //int n,denta;
    cin>>n>>denta;
    for (int i=1; i<=n; i++)
        cin>>l[i];
    for (int i=1; i<=n; i++)
        cin>>r[i];
    if (n<=100)
    {
        cout<<slv(1,1,0).fi<<"\n";
        trace(1,1,0);
    }
    return 0;
}
