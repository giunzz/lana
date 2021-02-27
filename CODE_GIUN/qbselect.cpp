#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long
using namespace std;
int n , a[5][10005] ,  f[10005][(1 << 4) + 5] , ma  = INT_MIN;
void blablalolo()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
}
bool checkbit(int pos , int mask)
{
    if ((mask&(1<<pos)) > 0) return true;
    return false;
}
bool check(int mask) // kt ko co 2 bit 1 nao gan nhau
{
    for (int i = 0 ; i <= 2 ; i++)
    {
        if (checkbit(i,mask) && checkbit(i+1,mask) ) return false;
    }
    return true;
}
void dp ()
{
    for (int i = 1 ; i <= n ; i++)
        for (int j = 0 ; j < (1 << 4) ; j++) f[i][j] = INT_MIN;
    int ans = INT_MIN;
    f[0][0] = 0;
    for (int i = 1 ;i <= n ; i++)
    {
        for (int j = 0 ; j < (1<<4) ; j++)
        {
            int sum = 0 , opt = INT_MIN;
            if (check(j) == false) continue;
            for (int bit = 0 ; bit < 3 ; bit++)
                if ( j & (1<<bit)) sum += a[i][bit];
            for (int last = 0 ; last < (1 << 4) ; last++)
            {
                if (check(last) == false || (last&j) != 0 ) continue;
                opt = max(opt,f[i-1][last]);
            }
            f[i][j] = opt+sum;
            ans = max(ans,f[i][j]);
            cerr << opt << " " << sum << endl;

        }
    }
    cout << ans+ans/3-1;

}
int ok = 0;
int main()
{
    giuncute;
    blablalolo();
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 0 ; j < 3  ; j++)
        {
            cin >> a[i][j];
            ma = max(ma,a[i][j]);
        }
    }
    if (ma <= 0) cout << ma ;
    else dp();
}


// con cac





