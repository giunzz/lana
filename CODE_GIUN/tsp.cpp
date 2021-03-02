#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
using namespace std;

int n , x[30]={0}  , sum = 0  , A[300][300]={{0}} ,ans = INT_MAX , dd[300]={0};
void blablalolo()
{
    freopen("tsp.inp","r",stdin);
    freopen("tsp.out","w",stdout);
}
void checkans()
{
    if (A[x[n]][1] != 0 && sum + A[x[n]][1] < ans ) ans = sum + A[x[n]][1];
}
inline void quaylui (int vt)
{
    for (int i = 2 ; i <= n ; i++)
    {
        if (dd[i] == 0 && A[x[vt-1]][i] != 0)
        {
            x[vt] = i;
            sum += A[x[vt-1]][i];
            dd[i] = 1;
            if (vt == n)checkans();
            else if ( sum < ans) quaylui(vt+1);
            sum -= A[x[vt-1]][i];
            dd[i] = 0;
        }
    }
}
int main()
{
    giuncute;
    blablalolo();
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++) cin >> A[i][j];
    x[1] = 1;
    quaylui(2);
    cout << ans ;
}
