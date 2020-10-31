#include<bits/stdc++.h>
#define maxn 3005
using namespace std;

int n, m, k;
int a[maxn], b[maxn];
int r[2*maxn], p[maxn], t[2*maxn], cnt;
vector<int> v, A[maxn];

void Check()
{
    v.clear();
    for (int i=1; i<=n; i++)
        if ( p[i] == 1 )
            v.push_back(a[i]);
    //for (int i=0; i<cnt; i++) cout<<v[i]<<" "; cout<<endl;
    if ( A[cnt].size() == 0 )
    {
        A[cnt].resize(cnt+1);
        for (int i=1; i<=cnt; i++)
            A[cnt][i]= v[i-1];
    }
    else
    {
        for (int i=1; i<=cnt; i++)
        {
            if ( v[i-1] > A[cnt][i] ) return;
            if ( v[i-1] < A[cnt][i] ) break;
        }
        for (int i=1; i<=cnt; i++)
            A[cnt][i]= v[i-1];
    }
}
void Try(int u)
{
    if (u > n)
    {
        if ( k - cnt <= m )
            Check();
        return;
    }
    for (int i=0; i<=1; i++)
    {
        if ( i == 1 ) cnt++;
        p[u]= i;
        Try(u+1);
        if ( i == 1 ) cnt--;
    }
}

void Get()
{
    if ( A[k-cnt].size() == 0 )
        return;
    v.clear(); v.push_back(0);
    for (int i=1; i<=m; i++) if ( p[i] == 1 ) v.push_back(b[i]);
    int i= 1, j= 1, d=0;
    while ( i <= k-cnt && j <= cnt )
    {
        //cout<<i<<" "<<j<<" "<<A[k-cnt][i]<<" "<<v[j]<<endl;
        if ( A[k-cnt][i] < v[j] )
            t[++d]= A[k-cnt][i], i++;
        if ( A[k-cnt][i] > v[j] )
            t[++d]= v[j], j++;
        if ( A[k-cnt][i] == v[j] )
        {
            if ( A[k-cnt][i+1] > v[j+1] )
                t[++d]= v[j], j++;
            else
                t[++d]= A[k-cnt][i], i++;
        }
    }
    while ( i <= k - cnt ) t[++d]= A[k-cnt][i], i++;
    while ( j <= cnt ) t[++d]= v[j], j++;

    //cout<<endl;
    //for (int i=1; i<=cnt; i++) cout<<v[i]<<" "; cout<<endl;
    //for (int i=1; i<=k-cnt; i++) cout<<A[k-cnt][i]<<" "; cout<<endl;
    //for (int i=1; i<=k; i++) cout<<t[i]<<" "; cout<<endl<<endl;
    for (int i=1; i<=k; i++)
    {
        if ( t[i] > r[i] ) return;
        if ( t[i] < r[i] ) break;
    }
    for (int i=1; i<=k; i++)
        r[i]= t[i];

}
void Tryagain(int u)
{
    if (u > m)
    {
        if ( k - cnt <= n )
            Get();
        return;
    }
    for (int i=0; i<=1; i++)
    {
        if ( i == 1 ) cnt++;
        p[u]= i;
        Tryagain(u+1);
        if ( i == 1 ) cnt--;
    }
}

void sexyBuffalo()
{
    for (int i=1; i<=k; i++)
        r[i]= INT_MAX;
    Try(1);
    cnt= 0;
    for (int i=1; i<=n; i++) p[i]= 0;
    //for (int i=k-m; i<=n; i++) { for (int j=1; j<=i; j++) cout<<A[i][j]<<" "; cout<<endl; }
    Tryagain(1);

    for (int i=1; i<=k; i++)
        cout<< r[i]<< " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    cin>> n>> m>> k;
    for (int i=1; i<=n; i++)
        cin>> a[i];
    for (int i=1; i<=m; i++)
        cin>> b[i];

    sexyBuffalo();
}
