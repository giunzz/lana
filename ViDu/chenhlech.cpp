#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,mi,b[100005], a[100005],s=0,vt;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("CHENHLECH.INP", "r", stdin);
    freopen("CHENHLECH.OUT", "w", stdout);
    cin>>n;
    a[0]=0;
    s=0;
    for (int i=1; i<=n ; i++) {
        cin>>a[i];
        s+=a[i];
        a[i]=a[i]+a[i-1];
    }
    for (int i=1; i<=n ; i++) cout<<a[i]<<"  ";
    cout<< endl;
    cout<<s<<endl;
    for (int i=1; i<=n ; i++) cout<<s-a[i]-a[i]<<"  ";
    mi=10006;
    cout<<endl;
    for (int i=1; i<=n ; i++){
        if (mi>s-a[i])  mi=s-a[i], cout<<mi<<"  ";
        if (mi>0) b[i]=1,vt=i;
        s=s-a[i]-a[i];
    }
    cout<<endl;
    cout<<vt;
    return 0;
}
