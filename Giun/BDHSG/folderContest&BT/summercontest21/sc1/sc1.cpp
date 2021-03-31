// #include <bits/stdc++.h>
// #define ll int
// #define cll const ll
// #define lp(a, b, c) for(ll a = b; a <= c; ++a)
// #define lpd(a, b, c) for(ll a = b; a >= c; --a)
// #define vec(a) vector<a>
// #define pp(a, b) pair<a, b>
// #define EACHCASE lpd(cs, read(), 1)
// #define Fname "sc1"
// using namespace std;

// ll read(){
//     ll tmp;
//     cin >> tmp;
//     return tmp;
// }

// void giuncute(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// }

// void OF(){
//     freopen(Fname".inp", "r", stdin);
//     freopen(Fname".out", "w", stdout);
// }

// cll mxn = 70 * 9 + 1, mxcost = 622e2 + 1, c[] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500};
// ll cost, totquang, totgiun, dpquang[mxcost][mxn], dpgiun[mxcost][mxn];
// vec(ll) quang, giun;

// void sol(){
//     quang.clear(); giun.clear();
//     quang.push_back(0); giun.push_back(0);
//     totquang = totgiun = 0;
//     cin >> cost;
//     cost /= 1000;
//     if(cost > 62160){
//         cout << "SORRY!!!\n";
//         return;
//     }
//     lp(i, 1, 9){
//         string tmp; ll quangmn, giunmn;
//         cin >> tmp >> quangmn >> giunmn;
//         totquang += quangmn * c[i], totgiun += giunmn * c[i];
//         lp(j, 1, quangmn) quang.push_back(c[i]); lp(j, 1, giunmn) giun.push_back(c[i]);
//     }
//     lp(i, 0, max(totquang, totgiun)) lp(j, 0, max(quang.size(), giun.size())) dpquang[i][j] = dpgiun[i][j] = -1;
    
//     //dp quang 
//     lp(i, 0, quang.size() - 1) dpquang[0][i] = 0;
//     lp(i, 1, totquang){
//         lp(j, 1, quang.size() - 1){
//             if(i - quang[j] < 0){dpquang[i][j] = dpquang[i][j - 1]; continue;}
//             ll res = -1;
//             if(dpquang[i][j - 1] != -1) res = dpquang[i][j - 1];
//             if(dpquang[i - quang[j]][j - 1] != -1) res = max(res, dpquang[i - quang[j]][j - 1] + 1);
//             dpquang[i][j] = res;
//         }
//     }

//     //dp giuncutenhathemattroi
//     lp(i, 0, giun.size() - 1) dpgiun[0][i] = 0;
//     lp(i, 1, totquang){
//         lp(j, 1, giun.size() - 1){
//             if(i - giun[j] < 0) {dpgiun[i][j] = dpgiun[i][j - 1]; continue;}
//             ll res = INT_MAX;
//             if(dpgiun[i][j - 1] != -1) res = dpgiun[i][j - 1];
//             if(dpgiun[i - giun[j]][j - 1] != -1) res = min(res, dpgiun[i - giun[j]][j - 1] + 1);
//             if(res == INT_MAX) res = -1;
//             dpgiun[i][j] = res;
//         }
//     }

//     ll res = INT_MAX;
//     if(cost <= totquang) lp(i, 1, quang.size() - 1) if(dpquang[cost][i] != -1) res = min(res, (int)quang.size() - 1 - dpquang[cost][i]);
//     lp(i, cost + 1, totquang){
//         ll quangtien = -1, giuntien = INT_MAX;
//         lp(j, 1, quang.size() - 1) quangtien = max(quangtien, dpquang[i][j]);
//         lp(j, 1, giun.size() - 1) if(dpgiun[i - cost][j] != -1) giuntien = min(giuntien, dpgiun[i - cost][j]);
//         if(giuntien != INT_MAX && quangtien != -1) res = min(res, (int)quang.size() - 1 - quangtien + giuntien);
//     }
//     if(res == INT_MAX) cout << "SORRY!!!\n";
//     else cout << res << '\n';
// }

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     EACHCASE sol();
// }

#include <bits/stdc++.h>
#define ll int
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sc1"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 140 * 9 + 2, mxcost = 622e2, c[] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500};
ll cost, totquang, dpgiun[mxcost][mxn];
vec(ll) money;

void sol(){
    money.clear(); money.push_back(0);
    totquang = 0;
    cin >> cost;
    cost /= 1000;
    lp(i, 1, 9){
        string tmp; ll quangmn, giunmn;
        cin >> tmp >> quangmn >> giunmn;
        totquang += quangmn * c[i];
        lp(j, 1, quangmn + giunmn) money.push_back(c[i]);    
    }
    if(totquang < cost){
        cout << "SORRY!!!\n";
        return;
    }
    ll need = totquang - cost, num = money.size();
    lp(i, 1, need) lp(j, 1, num - 1){
        ll value = money[j];
        if(i < value) dpgiun[i][j] = dpgiun[i][j - 1];
        else dpgiun[i][j] = min(dpgiun[i][j - 1], dpgiun[i - value][j - 1] + 1);
    }
    cout << (dpgiun[need][num - 1] == 1e9 ? "SORRY!!!" : to_string(dpgiun[need][num - 1])) + '\n';
}

// #define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lp(i, 0, mxn - 1) dpgiun[0][i] = 0;
    lp(i, 1, mxcost - 1) dpgiun[i][0] = 1e9;
    EACHCASE sol();
}