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

bool checkvalid(int mask) // kt ko co 2 bit 1 nao gan nhau 
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
    {
        for (int j = 1 ; j <= (1 << 4) ; j++) f[i][j] = INT_MIN;
    }
    int ans = INT_MIN;
    f[0][0] = 0;
    for (int j = 1 ; j <= n ; j++)
    {
        for (int mask = 1 ; mask <= (1 << 4) ; mask ++)
        {
            if (checkvalid(mask) == false) continue;
            for (int mask1 = 1  ; mask1 <= (1 << 4) ; mask1 ++)
            {
                if (checkvalid(mask1) == false) continue;
                if ((mask & mask1) != 0) continue;
                int val;
                for (int i = 1 ; i <= 4 ; i++)
                {
                    if (checkbit(i,mask) == true) val  += a[i][j];
                }   
                f[j][mask] = f[j-1][mask1] + val;
                ans = max(ans,f[j][mask]);
            }
        }
    }
    cout << ans;
}
int ok = 0;
int main()
{
    giuncute;
    blablalolo();
    cin >> n ; 
    for (int i = 1 ; i <= 4 ; i++)
    {
        for (int j = 1 ; j <= n ; j++) 
        {
            cin >> a[i][j];
            ma = max(ma,a[i][j]);
        }
    }
    if (ma < 0) cout << ma ; 
    else dp();
}

