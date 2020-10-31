#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> ii;
const int N=1e5+2;
int n, a[N];
long long sum, res, tmp;
int main()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for ( int i=1; i<=n; i++ )
    {
        cin >> a[i];
        sum=sum+a[i];
    }
    tmp=sum/n;
    for ( int i=1; i<=n; i++ )
        if ( a[i]<tmp )
        {
            int need=tmp-a[i];
            vector<ii> V;
            V.clear();
            for ( int j=1; j<i; j++ )
                if ( a[j]>tmp )
                    V.push_back(ii(i-j, j));
            for ( int j=i+1; j<=n; j++ )
                if ( a[j]>tmp )
                    V.push_back(ii(j-i, j));
            sort(V.begin(), V.end());

            for ( int j=0; j<V.size(); j++ )
                if ( a[V[j].Y]-tmp>=need )
                {
                    res+=need*V[j].X;
                    a[V[j].Y]-=need; need=0;
                    break;
                }
                else
                {
                    res+=(a[V[j].Y]-tmp)*V[j].X;
                    a[V[j].Y]=tmp; need-=a[V[j].Y]-tmp;
                    break;
                }
        }

    cout << res;
}
