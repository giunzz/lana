#include<bits/stdc++.h>
using namespace std;

float squareAllNumbers(float n)
{
    int tmp = n;
    string s = to_string(tmp), ans;
    for(int x = 0; x < s.length(); x++){
        int a = s[x] - '0';
        a *= a;
        ans += to_string(a);
    }
    int tmp1 = 0;
    for(char c : ans){
        tmp1 = tmp1 * 10 + (c - '0');
    }
    cerr << tmp1 << endl;
    float kq = tmp1;
    return kq;
}

int main()
{
    float a = 2079123;
    cout << squareAllNumbers(a);
}