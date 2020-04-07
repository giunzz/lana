#include <bits/stdc++.h>
using namespace std;
const string file = "giun";
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)

vector<int> Na{120,187,2911,71,78,1298};
string mlem ;
string numToString(int meo)
{
    string bubu ="";
    char t ;
    while (meo != 0 )
    {
        t = (char)(meo % 10 +48);
        bubu += t;
        meo = meo / 10;
    }
    reverse(bubu.begin(), bubu.end()); 
    return bubu;
}

string setOEequations(vector<int> giun)
{
    string ans ="";
    int a = giun[0] , b = giun[1] , c = giun[2] ,  a1 = giun[3] , b1 = giun[4] , c1 = giun[5];
    cerr << a << " " << b << " " << c << " " << a1 << " " << b1 << "  " << c1 << endl;
    int D = a*b1 - a1*b , Dx = c*b1 - c1*b , Dy = a*c1 - a1*c;
    cerr << D <<" "<< Dx << " " << Dy << " " << endl;
    if (D != 0 ) 
    {
        int x = Dx/D , y = Dy/D;
        cerr << x << " " << y << endl;
        if ( x < 0 ) 
        {
            int tam = abs(x);
            //cerr << tam << endl;
            ans +="-";
            ans +=  numToString(tam ) ;
        }
        else ans += numToString(x) ;
        ans +=",";
        if ( y < 0 ) 
        {
            int tam1 = abs(y);
            //cerr << tam1 << endl;
            ans +="-";
            ans +=  numToString(tam1 ) ;
        }
        else 
        {
            ans +=  numToString(y);
            cerr << numToString(y);
        }
    }
    if ( D == 0 )
        {
            if ( Dx != 0 || Dy != 0 ) ans = "Can not solve";
            else if (Dx == Dy && Dx == 0) ans = "Infinities";
        }
    return ans;
}

int main()
{
    balabolo(file);
    mlem = setOEequations(Na);
    cout << mlem;
    return 0;


}