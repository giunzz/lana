#include <iostream>
using namespace std;
void of(){
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
}
int main()
{
    // of();
	int a,b,c;
	cout<<"nhap vao canh a: ";
	cin>>a;
	cout<<"nhap vao canh b: ";
	cin>>b;
	cout<<"nhap vao canh c: ";
	cin>>c;
	if (a+b>c && b+c>a && c+a>b){
        if (a*a==b*b+c*c || b*b==c*c+a*a || c*c==b*b+a*a) cout<<"tam giac vuong";
        else if ((a*a==b*b+c*c&&b==c)||(b*b==c*c+a*a&&c==a )||(c*c==b*b+a*a&&b==a)) cout<<"tam giac vuong can";
        else if (a==b&&b==c) cout<<"tam giac deu";
        else if (a==b||b==c||a==c) cout<<"tam giac can";
        else if (a*a>b*b+c*c||b*b>c*c+a*a||c*c>b*b+a*a) cout<<"tam giac tu";
        else if (a*a<b*b+c*c||b*b<c*c+a*a||c*c<a*a+b*b) cout<<"tam giac nhon";
	}
	else if (a+b<c||b+c<a||c+a<b) cout<<"khong phai tam giac";
	return 0;
}