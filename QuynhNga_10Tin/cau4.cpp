#include<bits/stdc++.h>
using namespace std;
double x,y,tong,hieu,tich,thuong;

int main(){
//freopen("cau4.INP"."r",stdin);
//freopen("cau4.out"."w",stdout);
cin >> x >> y;
tong = x + y;
hieu = max(x,y)-min(x,y);
tich = x*y;
thuong = max(x,y)/min(x,y);
cout << "tong hai chu so la: " << tong << endl;
cout << "hieu hai chu so la: " << hieu << endl;
cout << "tich hai chu so la: " << tich << endl;
cout << "thuong hai chu so la: " << thuong << endl;
return 0;
}
