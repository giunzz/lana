#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a,b_=b;i<=b_;++i)
#define ford(i,a,b) for(int i=a,b_=b;i>=b_;--i)
#define forv(i,a) for(auto &i:a)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ___ << "\n"
#define __ << " " <<
#define _ << " "
#define getbit(x,i) (((x)>>(i))&1)
#define onbit(x,i) ((x)|(1<<(i)))
#define INF 1000000000000000
using namespace std;

const int N=3005;
int n,m,k,a[N],b[N],c[2*N];

int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin >> m >> n >> k;
    fori(i,1,m) cin >> a[i];
    fori(i,1,n) cin >> b[i];
    if(m+n==k)
    {
        fori(i,1,m) c[i]=a[i];
        fori(i,1,n) c[i+m]=b[i];
        sort(c+1,c+k+1);
        fori(i,1,k) cout << c[i] _; return 0;
    }
}
