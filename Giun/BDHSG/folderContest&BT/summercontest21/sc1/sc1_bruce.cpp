#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
const int MAX_N = 10;
const int MAX_VALUE = 70005;
const int inf = 100007;
int numTest;
int C, sumQuang, sumGiun;
int a[MAX_N], b[MAX_N];
int dpQuang[MAX_N][MAX_VALUE], dpGiun[MAX_N][MAX_VALUE];
int cost[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_VALUE; j++) {
            dpQuang[i][j] = -1;
            dpGiun[i][j] = inf;
        }
    }
}

void updateMin(int &a, int b) {
    a = min(a, b);
}

void updateMax(int &a, int b) {
    a = max(a, b);
}

void dynamicProgrammingForQuang() {
    for (int i = 0; i <= 9; i++) {
        dpQuang[i][0] = 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j <= sumQuang; j++) {
            if (dpQuang[i][j] == -1) {
                continue;
            }
            int curValue = dpQuang[i][j];
            for (int numbMoney = 0; numbMoney <= a[i]; numbMoney++) {
                updateMax(dpQuang[i + 1][j + numbMoney * cost[i]], curValue + numbMoney);
            }
        }
    }
}

void dynamicProgrammingForGiun() {
    for (int i = 0; i <= 9; i++) {
        dpGiun[i][0] = 0;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j <= sumGiun; j++) {
        if (dpGiun[i][j] == inf) {
            continue;
        }
        int curValue = dpGiun[i][j];
        for (int numbMoney = 0; numbMoney <= b[i]; numbMoney++) {
            updateMin(dpGiun[i + 1][j + numbMoney * cost[i]], curValue + numbMoney);
        }
        }
    }
}

int main () {
    freopen("SC1.INP", "r", stdin);
    freopen("SC1.ANS", "w", stdout);
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; testCase++) {
        cin >> C;
        C /= 1000;
        init();
        sumQuang = 0;
        sumGiun = 0;
        int numbMoney = 0;
        for (int i = 0; i < 9; i++) {
        string s;
        cin >> s >> a[i] >> b[i];
        numbMoney += a[i];
        sumQuang += a[i] * cost[i];
        sumGiun += b[i] * cost[i];
        }
        dynamicProgrammingForQuang();
        dynamicProgrammingForGiun();
        int ans = inf;
        int pos;
        for (int j = C; j <= sumQuang; j++) {
        if (dpQuang[9][j] != -1 && dpGiun[9][j - C] != inf) {
            if (ans > numbMoney - dpQuang[9][j] + dpGiun[9][j - C]) {
            ans = numbMoney - dpQuang[9][j] + dpGiun[9][j - C];
            pos = j;
            }
        }
        }
        if (ans == inf) {
            cout << "SORRY!!!";
        }
        else {
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}