#include<bits/stdc++.h>
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define vi vector<int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define F1(i, a, b) for(int i=a; i<=b; i++)
#define F2(i, a, b) for(int i=a; i>=b; i--)
#define maxm 3000
#define oo 2000000000
using namespace std;
template<typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}
int m, n, k, a[maxm+1], b[maxm+1], res[2*maxm+1], tmin=oo, foo[maxm+1];
int dp1[maxm+1][maxm+1], a1[maxm+2], b1[maxm+2], cnt1, cnt2, it1, it2;
int dp2[maxm+1][maxm+1], c[maxm+1];
void input()
{
    cin>>m>>n>>k;
    for(int i=1; i<=m; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
}
void extract(int i)
{
    if(i>0)
    {
        tmin=-1;
        for(int j=m; j>=1; j--)
        {
            if(dp1[j][i]!=-1)
            {
                if(tmin==-1)
                {
                    tmin=j;
                }
                else
                {
                    if(a[j]<=a[tmin]) tmin=j;
                }
            }
        }
        //cout<<tmin<<endl;
        int j=0; it1=i;
        while(it1>0)
        {
            a1[++j]=a[tmin];
            tmin=dp1[tmin][it1];
            it1--;
        }
        //cout<<dp1[5][3]<<endl;
    }
    if(k-i>0)
    {
        tmin=-1;
        for(int j=n; j>=1; j--)
        {
            if(dp2[j][k-i]!=-1)
            {
                if(tmin==-1) tmin=j;
                else if(b[j]<=b[tmin]) tmin=j;
            }
        }
        //cout<<tmin<<endl;
        int j=0; it1=k-i;
        while(it1>0)
        {
            b1[++j]=b[tmin];
            tmin=dp2[tmin][it1];
            it1--;
        }
        //for(int j=1; j<=k-i; j++) cout<<b1[j]<<" "; cout<<endl;
    }
}
bool cmp()
{
    for(int i=1; i<=k; i++)
    {
        if(foo[i]<res[i]) return 1;
        if(foo[i]>res[i]) return 0;
    }
    return 0;
}
void gan()
{
    for(int i=1; i<=k; i++) res[i]=foo[i];
}
void solve()
{
    F1(i, 1, k) res[i]=oo;
    //for(int i=1; i<=k; i++) cout<<res[i]<<" ";cout<<endl;
    F1(i, 1, m) dp1[i][1]=i; c[m]=m;
    for(int i=m-1; i>=1; i--)
    {
        c[i]=-1;
        if(dp1[i][1]==-1) continue;
        if(c[i+1]==-1) c[i]=i;
        else
        {
            if(a[i]<=a[c[i+1]]) c[i]=i;
            else c[i]=c[i+1];
        }
    }
    //for(int i=1; i<=m; i++) cout<<c[i]<<" "; cout<<endl;
    F1(i, 2, m)
    {
        for(int j=m; j>=1; j--)
        {
            if(m-j+1<i) dp1[j][i]=-1;
            else dp1[j][i]=c[j+1];
        }
        if(dp1[m][i]==-1) c[m]=-1;
        else c[m]=m;
        for(int j=m-1; j>=1; j--)
        {
            c[j]=-1;
            if(dp1[j][i]==-1) continue;
            if(c[j+1]==-1) c[j]=j;
            else
            {
                if(a[j]<=a[c[j+1]]) c[j]=j;
                else c[j]=c[j+1];
            }
        }
    }
    //for(int i=1; i<=m; i++) cout<<dp1[i][3]<<" "; cout<<endl;
    for(int i=1; i<=n; i++) dp2[i][1]=i; c[n]=n;
    for(int i=n-1; i>=1; i--)
    {
        c[i]=-1;
        if(dp2[i][1]==-1) continue;
        if(c[i+1]==-1) c[i]=i;
        else
        {
            if(b[i]<=b[c[i+1]]) c[i]=i;
            else c[i]=c[i+1];
        }
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=n; j>=1; j--)
        {
            if(n-j+1<i) dp2[j][i]=-1;
            else dp2[j][i]=c[j+1];
        }
        if(dp2[n][i]==-1) c[n]=-1;
        else c[n]=n;
        for(int j=n-1; j>=1; j--)
        {
            c[j]=-1;
            if(dp2[j][i]==-1) continue;
            if(c[j+1]==-1) c[j]=j;
            else
            {
                if(b[j]<=b[c[j+1]]) c[j]=j;
                else c[j]=c[j+1];
            }
        }
    }
    //for(int  i=1; i<=n; i++) cout<<dp2[i][3]<<" "; cout<<endl;
    int tmp;
    for(int i=0; i<=min(k, m); i++)
    {
        if(i>m||k-i>n) continue;
        extract(i);
        if(i==0)
        {
            for(int j=1; j<=k; j++) foo[j]=b1[j];
        }
        else if(k-i==0)
        {
            for(int j=1; j<=k; j++) foo[j]=a1[j];
        }
        else
        {
            a1[i+1]=-oo;
            b1[i+1]=-oo;
            it1=1; it2=1;
            for(int j=1; j<=k; j++)
            {
                if(it1==i+1)
                {
                    foo[j]=b1[it2];
                    it2++;
                    continue;
                }
                if(it2==k-i+1)
                {
                    foo[j]=a1[it1];
                    it1++;
                    continue;
                }
                if(a1[it1]<b1[it2])
                {
                    foo[j]=a1[it1];
                    it1++;
                    continue;
                }
                else if(b1[it2]<a1[it1])
                {
                    foo[j]=b1[it2];
                    it2++;
                    continue;
                }
                else
                {
                    if(a1[it1+1]<b1[it2+1])
                    {
                        foo[j]=a1[it1];
                        it1++;
                        continue;
                    }
                    else
                    {
                        foo[j]=b1[it2];
                        it2++;
                        continue;
                    }
                }
            }
        }
        if(cmp())
        {
            tmp=i;
            gan();
        }
    }
    //cout<<tmp<<endl;
    //extract(5);
    //for(int i=1; i<=5; i++) cout<<a1[i]<<" "; cout<<endl;
    //extract(5);
    //for(int i=1; i<=5; i++) cout<<a1[i]<<" "; cout<<endl;
    //for(int i=1; i<=4; i++) cout<<b1[i]<<" "; cout<<endl;
    for(int i=1; i<=k; i++) cout<<res[i]<<" ";
    cout<<endl;
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("SEQUENCE.inp", "r", stdin);
    freopen("SEQUENCE.out", "w", stdout);
    input();
    solve();
}

