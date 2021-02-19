#include<iostream>
#include<cmath>

using namespace std;
long long  k,n,i,s=1;
int main(){
    cin>>n;
    while (i<=n-1){
        s=s+6*i;
        i++;
    }
    cout<<s;
    return 0;
}



