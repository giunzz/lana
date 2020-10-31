#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int n, t[45], m1, m2;
bool dain1, dain2;
ull a, b, k, pow2n, pow10[65], h1[1100011], h2[1100011], res1, res2;

void trace1()
{
    ull r=0;
    for (int i=1; i<=n/2; i++)
        if (t[i]==0) r=(r+(a*pow10[n-i])%pow2n)%pow2n;
        else r=(r+(b*pow10[n-i])%pow2n)%pow2n;
    if (r==res1)
    {
        for (int i=1; i<=n/2; i++)
            if (t[i]==0) cout<<a;
            else cout<<b;
        dain1=true;
    }
}

void trace2()
{
    ull r=0;
    for (int i=n/2+1; i<=n; i++)
        if (t[i]==0) r=(r+(a*pow10[n-i])%pow2n)%pow2n;
        else r=(r+(b*pow10[n-i])%pow2n)%pow2n;
    if (r==res2)
    {
        for (int i=n/2+1; i<=n; i++)
            if (t[i]==0) cout<<a;
            else cout<<b;
        dain2=true;
    }
}

void check1()
{
    ull r=0;
    for (int i=1; i<=n/2; i++)
        if (t[i]==0) r=(r+(a*pow10[n-i])%pow2n)%pow2n;
        else r=(r+(b*pow10[n-i])%pow2n)%pow2n;
    m1++; h1[m1]=r;
}

void Try1(int i, int type)
{
    for (int j=0; j<=1; j++)
    {
        t[i]=j;
        if (i==n/2)
        {
            if (type==0) check1();
            else trace1();
        }
        else if (!dain1) Try1(i+1, type);
    }
}

void check2()
{
    ull r=0;
    for (int i=n/2+1; i<=n; i++)
        if (t[i]==0) r=(r+(a*pow10[n-i])%pow2n)%pow2n;
        else r=(r+(b*pow10[n-i])%pow2n)%pow2n;
    m2++; h2[m2]=r;
}

void Try2(int i, int type)
{
    for (int j=0; j<=1; j++)
    {
        t[i]=j;
        if (i==n)
        {
            if (type==0) check2();
            else trace2();
        }
        else if (!dain2) Try2(i+1, type);
    }
}

int bs(int i, ull x)
{
    int l=0, r=m2+1, mid;
    while (r-l>1)
    {
        mid=(l+r)/2;
        if (h1[i]+h2[mid]>x) r=mid;
        else l=mid;
    }
    return l;
}

int main()
{
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>a>>b>>n>>k;
    if (n<=40)
    {
        pow2n=1;
        for (int i=1; i<=n; i++) pow2n=pow2n*2;
        pow10[0]=1;
        for (int i=1; i<n; i++) pow10[i]=(pow10[i-1]*10)%pow2n;
        Try1(1, 0); Try2(n/2+1, 0);
        sort(h2+1, h2+m2+1);
        bool found=false;
        for (int i=1; i<=m1; i++)
        {
            int j=bs(i, k);
            if (h1[i]+h2[j]==k)
            {
                res1=h1[i]; res2=h2[j];
                found=true;
                break;
            }
            j=bs(i, pow2n+k);
            if (h1[i]+h2[j]==pow2n+k)
            {
                res1=h1[i]; res2=h2[j];
                found=true;
                break;
            }
        }
        if (!found) cout<<-1;
        else { Try1(1, 1); Try2(n/2+1, 1); }
        return 0;
    }
    cout<<-1;
    return 0;
}
