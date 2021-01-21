/*#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int  a, b , d = 0;
string DaoNguoc(string s) {
    int length = s.length();
    string temp;
    for (int i = length-1; i >=0; i--) {
        temp.push_back(s[i]);
    }
    return temp;
}
inline bool check(int x)
{
    string s = to_string(x) ;
    reverse(s.begin(),s.end());
    int k = stoi(s);
    if (__gcd(x,k) == 1) return true;
    return false;
}
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("g.out","w",stdout);
    cin >> a >> b;
    for (int i = a ; i <= b ; i++)
    {
        if (check(i) == true) d++;
    }
    cout << d;
    
}*/
#include <iostream>

using namespace std;
int a,b,d;
int ucln (int a,int b) {
    int r;
    while (b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}
int dao(int n) {
    int t=0;int a;
    while (n!=0) {
        a=n%10;
        t=t*10+a;
        n/=10;
    }
    return t;
}
int main () {
    freopen("frienum.inp","r",stdin);
    freopen("frienum.out","w",stdout);
    cin >> a >> b;
    for (int i=a;i<=b;i++) {
        if (ucln(dao(i),i)==1) d+=1;
    }
    cout << d;
    return 0;
}