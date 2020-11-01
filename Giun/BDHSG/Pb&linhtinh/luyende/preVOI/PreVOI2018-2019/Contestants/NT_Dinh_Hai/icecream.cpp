/*
* @Author: ReJiKai
* @Date:   2018-12-20 15:22:07
* @Last Modified by:   ReJiKai
* @Last Modified time: 2018-12-20 15:22:11
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int n, mmax, m5, m1, m2, res;

void cal(int i){
    if(i == n + 1){
        res++;
        return;
    }
    if((m5 + 1) <= mmax) m5++, cal(i + 1), m5--;
    if(m5 && (m1 + 1) <= mmax) m5--, m1++, cal(i + 1), m1--, m5++;
    int ok = 0;
    if(m5 && m1 && (m2 + 1) <= mmax) m5--, m1--, m2++, cal(i + 1), m2--, m1++, m5++, ok = 1;
    if(!ok && m5 >= 3 && (m2 + 1) <= mmax) m5 -= 3, m2++, cal(i + 1), m2--, m5 += 3;
}

void sub1(){
    res = 0;
    cal(1);
    cout << res;
}

int main(){
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);
    cin >> n >> mmax >> m5 >> m1 >> m2;
    sub1();
    return 0;
}
