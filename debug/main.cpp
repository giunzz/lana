#include<bits/stdc++.h>

using namespace std;

long n,ti = -1 ,ta = -1 , ans = 0 , c;
string chi [12] = {"THAN" , "DAU", "TUAT","HOI","TI", "SUU" , "DAN" , "MAO", "THIN", "TY", "NGO", "MUI" };
string can [10] = { "CANH" ,"TAN", "NHAM" , "QUY","GIAP", "AT", "BINH", "ĐINH" , "MAU" , "KY" };
string s,st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Bai46.inp","r",stdin);
    freopen("Bai46.out","w",stdout);

    cin >> n ;
    cin >> st;

    for (int  i = 0 ; i <= 12 ; i++ ){
        if ( st == chi [i] ) {
                ti = n % 12;
                c = i;
                break;
        }
        else if ( st == can [i] ) {
                c = i;
                ta = n %10;
                break;
        }
    }
    cerr << can[ta] << " " << st << endl;
    cerr << ta << " " << c <<" || " << c %10 << " " << ta %10 ;

    if (ti != -1) {
        if (abs (abs( c - ti ) - n) == c) ans =  abs (abs( c - ti ) - n);
        else ans = abs( c - ti ) + n;
    }
    else {
            if (abs (abs( c - ta ) - n) == c) ans =  abs (abs( c - ta ) - n);
            else ans =  abs( c - ta ) + n ;
    }

    cout << ans;
    return 0;
}
