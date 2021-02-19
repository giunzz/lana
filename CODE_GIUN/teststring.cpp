#include <bits/stdc++.h>

using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    int i = 0, j = n - 1, d = 0;
    while (i < j && d < k){
        if (s[i] < s[j]){
            s[i] = s[j];
            //cerr << i << " ";
            ++d;
        }
        else if (s[i] > s[j]){
            s[j] = s[i];
            //cerr << i << endl;
            ++d;
        }
        //cerr << (s[i] < s[j]) << endl;
        ++i, --j;
    }
    if (!(i >= j)) return "-1";
    else if (d < k){
        i = 0, j = n - 1;
        cout << d << " " << k << endl;
        while (d < k - 1 && i < j){
            cout << 1 << endl;
            if (s[i] != 57) s[i] = 57, s[j] = 57, d += 2;
            ++i, --j;
        }
        return s;
    }
    else return s;
}
int main(){
    string s = "092282";
    cout << highestValuePalindrome(s, 6, 3);
    return 0;
}
