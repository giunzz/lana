#include <cstdio>
#include <algorithm>
#include<iostream>
#include <fstream>
#define giuncute freopen("FUNC.inp", "r", stdin) , freopen("FUNC.out", "w", stdout)
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
int n;
long long l, r, ans = 0;

int main(){
    giuncute;
    giun;
    cin >> n ;
    //scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        ans = 0;
        //scanf("%lld %lld", &l, &r);
        cin >> l >> r;
        if (l > r) swap(l, r);
        if ((l < 0 && !(l % 2)) || (l >= 0 && l % 2)) ++l;
        if ((r < 0 && !(r % 2)) || (r >= 0 && r % 2)) --r;
        if ((l < 0 && r < 0) || (l >= 0 && r >= 0)){
            ans = (r - l) / 2 + 1;
        }
        if (l < 0 && r >= 0){
            ans = (-1 - l) / 2 + 1 + (r - 0) / 2 + 1;
        }
        //printf("%lli ", ans);
        cout << ans << endl;
    }
        return 0;
}