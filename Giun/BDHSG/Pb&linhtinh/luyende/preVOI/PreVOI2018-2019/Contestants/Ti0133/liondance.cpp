#include<bits/stdc++.h>
#define maxn 4005
#define max1 45
using namespace std;

int n, k, a[maxn], b[maxn];
int ans, r[max1];
vector<int> v;

void Check()
{
    int i=0, j=1;
    while ( i < v.size() && j <= n )
    {
        if ( v[i] == b[j] ) i++, j++;
        else j++;
    }
    if ( !(i == v.size()) )
        return;
    //for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
    for (int i=1; i<v.size(); i++)
        if ( v[i] - v[i-1] > k )
            return;
    if ( ans == v.size() )
    {
        for (int i=0; i<ans; i++)
        {
            if ( v[i] < r[i+1] ) return;
            if ( v[i] > r[i+1] ) break;
        }
    }
    ans= v.size();
    for (int i=0; i<ans; i++)
        r[i+1]= v[i];
}
void Try(int u)
{
    if (u > n)
    {
        if ( ans <= v.size() )
            Check();
        return;
    }
    for (int i=0; i<=1; i++)
    {
        //int x= v.size();
        if ( i == 1 )
            v.push_back(a[u]);
        Try(u+1);
        if ( i == 1 ) v.pop_back();
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("liondance.inp", "r", stdin);
    freopen("liondance.out", "w", stdout);
    cin>> n>> k;
    for(int i=1; i<=n; i++)
        cin>> a[i];
    for(int j=1; j<=n; j++)
        cin>> b[j];
    Try(1);
    cout<< ans<< "\n";
    for (int i=1; i<=ans; i++)
        cout<<r[i]<<" ";
}
