#include<iostream>
#include<fstream>
using namespace std;
long long s=0,c;
int a,b,n,k;
bool xuli(int i){
    if(i==n+1){
        if(s%c==k){
            cout<<s;
            return true;
        }
        return false;
    }
    s=s*10+a;
    if(xuli(i+1)) return true;
    s/=10;
    s=s*10+b;
    if(xuli(i+1)) return true;
    s/=10;
    return false;
}
int main(){
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    c=1;
    for(int i=1;i<=n;i++){
        c*=2;
    }
    if(!xuli(1)) cout<<-1;
}
