#include<bits/stdc++.h>
using namespace std;
long long a,b,s,h,tich,thuong,du;

int main(){
//freopen("cau3.INP"."r",stdin);
//freopen("cau3.out"."w",stdout);
cin >> a >> b;
s = a + b;
h = max(a,b)-min(a,b);
tich = a*b;
thuong = max(a,b)/min(a,b);
du = max(a,b)%min(a,b);
cout << "tong hai chu so la: " << s << endl;
cout << "hieu hai chu so la: " << h << endl;
cout << "tich hai chu so la: " << tich << endl;
cout << "thuong hai chu so la: " << thuong << endl;
cout << "so du cua hai chu so la: " << du << endl;
return 0;
}

