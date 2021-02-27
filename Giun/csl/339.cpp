#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
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

const int numStick[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int minStick[8]; // 2 -> 7

inline bool cmp(string const &num1, string const &num2){
    return num1.size() < num2.size() || (num1.size() == num2.size() && num1 < num2);
}

void findMinNum(int n, string minNum, string &bestAns){
    if(minNum.size() > bestAns.size()) return;
    if(n == 0){
        if(cmp(minNum, bestAns)) bestAns = minNum;
    }
    else{
        if(minNum.empty()){
            lp(i, 2, 7){
                minStick[6] = 6;
                if(n - i >= 2 || n - i == 0) findMinNum(n - i, minNum + to_string(minStick[i]), bestAns);
            }
        }
        else{
            if(n % 7 == 0 && minNum.back() == '8' && n) findMinNum(n - 7, minNum + '8', bestAns);
            else lpd(i, 7, 2){
                minStick[6] = 0;
                if(n - i >= 2 || n - i == 0) findMinNum(n - i, minNum + to_string(minStick[i]), bestAns);
            }
        }
    }
}

void sol(int n){
    // int n;
    // cin >> n;
    string maxNum = ((n % 2) ? "7" : "1"), minNum;
    maxNum += string(n / 2 - 1, '1');
    minNum = maxNum;
    findMinNum(n, "", minNum);
    cout << minNum << ' ' << maxNum << '\n';
}

// #define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lpd(i, 9, 0) minStick[numStick[i]] = i;
    lp(i, 2, 39) sol(i);
}