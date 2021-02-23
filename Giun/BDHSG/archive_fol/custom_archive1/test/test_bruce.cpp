#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

int main(){
    // opt;
    // file;
    int a, b, c;
    cout << "Nhap a, b, c: \n";
    cin >> a >> b >> c;
    bool checktamgiac, checkvuong, checkcan, checktu, checkdeu;
    checktamgiac = checkvuong = checkcan = checktu = checkdeu = 0;
    if(a + b > c && a + c > b && b + c > a) checktamgiac = 1;
    if(a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) checkvuong = 1;
    if(a == b || b == c || c == a) checkcan = 1;
    if(a == b && a == c && c == b) checkdeu = 1;
    if(a*a > b*b+c*c || b*b > a*a+c*c || c*c > a*a+b*b) checktu = 1;
    
    if(checktamgiac){
        if(checkvuong){
            if(checkcan) cout << "Tam giac vuong can";
            else cout << "Tam giac vuong";
        }
        else if(checkdeu) cout << "Tam giac deu";
        else if(checkcan) cout << "Tam giac can";
        else if(checktu) cout << "Tam giac tu";
        else cout << "Tam giac nhon";
    }
    else cout << "Khong ton tai tam giac";
    if((a==b||b==c||a==c)&&(a+b>c&&a+c>b&&b+c>a)&&(Pow(a,2)+Pow(b,2)==Pow(c,2)||Pow(a,2)+Pow(c,2)==Pow(b,2)||Pow(a,2)+Pow(c,2)==Pow(b,2))){
        cout<<"tam giac vuong can";
    }
}
