#include <bits/stdc++.h>
const long long MOD = 1e9+9;
using namespace std;

int N, MMAX;
long long res = 0;
int M[4], cnt[4][50], a[50];

void _check()
{
    int MF = cnt[0][N];
    int MO = cnt[1][N];
    int MT = cnt[2][N];
    for(int i = 1; i <= N; i++)
    {
        if(a[i] == 0) MF++;
        if(a[i] == 1)
        {
            if(MF == 0) return;
            else MO++, MF--;
        }
        if(a[i] == 2) 
        {
            if(MO >= 1 && MF >= 1)  MT++, MO--, MF--;
            else 
            {
                if(MF >= 3) MF-=3, MT++;
                else return;
            }
        }
    }
    // for(int i = 1; i <= N; i++)
    // {
    //     if(a[i] == 0)   cerr << 50 << ' ';
    //     if(a[i] == 1)   cerr << 1 << ' ';
    //     if(a[i] == 2)   cerr << 2 << ' ';
    // }
    // cerr << "\n";
    res = (res+1)%MOD;

}

void _try(int i)
{
    for(int j = 0; j <= 2; j++)
    {
        cnt[0][i] = cnt[0][i-1];
        cnt[1][i] = cnt[1][i-1];
        cnt[2][i] = cnt[2][i-1];
        // cerr << i << '-' << cnt[0][i] << ' ' << cnt[1][i] << ' ' << cnt[2][i] << '\n';
        for(int x = 0; x <= 2; x++) if(cnt[x][i-1] < 0) return;
        if(j == 1 && (cnt[0][i-1] == 0 || (cnt[1][i-1] >= cnt[0][i-1])))  continue;
        if(j == 2)
        {
            if(cnt[1][i-1] == 0 && cnt[0][i-1] <= 2) continue;
            if(cnt[1][i-1] >= 1 && cnt[0][i-1] == 0) continue;
            if(cnt[2][i-1] == 0 && (cnt[0][i-1] <= cnt[1][i-1]))  continue;
        }
        if(cnt[j][i]+1 > MMAX) continue;
        a[i] = j;
        cnt[j][i]++;
        // if(j == 0)  cnt[j][i]++; 
        // else
        // {
        //     if(j == 1)  cnt[j][i]++, cnt[0][i]--;
        //     else
        //         if(j == 2)
        //         {
        //             if(cnt[1][i] >= 1 && cnt[0][i] >= 1)    cnt[1][i]--, cnt[0][i]--;
        //             else
        //                 if(cnt[0][i] >= 3)  cnt[0][i]-=3;
        //         }  
        // }
        if(i == N)  _check();
        else    _try(i+1);
    }
}


main(int argc, char const *argv[])
{
    freopen("ICECREAM.inp", "r", stdin);
    freopen("ICECREAM.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> MMAX;
    cin >> cnt[0][0] >> cnt[1][0] >> cnt[2][0];   
    _try(1);
    cerr << res;
    cout << res;
    return 0;
}
