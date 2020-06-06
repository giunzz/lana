#include <bits/stdc++.h>

using namespace std;

int stringToNum(char c)
{
    return c - '0';
}

char numToString(int n)
{
    return (char)(n+48);
}

void chuanHoa(string a, string b) // lam 2 xau co do dai bang nhau
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)  b.insert(0, l1-l2, '0');
    else  a.insert(0, l2-l1, '0');
}

string sum(string a, string b)
{
    string s = "";
    chuanHoa(a,b);      // chuan hoa
    int l = a.length();
    int nho = 0;
    for (int i=l-1; i>=0; i--) {
        nho = stringToNum(a[i]) + stringToNum(b[i]) + nho;    // tinh tong tung doi mot
        s.insert(0, 1 , numToString( nho % 10 ));         // gan phan don vi vao
        nho = nho/10;     // lay lai phan hang chuc
    }
    if (nho > 0) s.insert(0 ,1 ,numToString( nho ));
    return s;
}

int main(){
    int n;
    string a[11],ss ="";

    //cin >> t;
    //cout << t;
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        freopen("bignum.inp","r",stdin);
        freopen("bignum.out","w",stdout);
        cin >> n;
    for (int i=1 ; i<= n ; i++) {
            cin >> a[i];
            cerr << a[i] << " ";
    }
    for (int i = 1 ; i<= n )
   //for (int i=1 ; i<= n ; i++)  sum(ss,a[i]);
    cout << sum("123456","66666666789");
    cout << endl;
    cout << sum("9","89");

    return 0;
}
