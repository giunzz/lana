#include<iostream>
using namespace std;
int main (){
    int n,x,a[1000];
    cin>>n>>x;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        if (x==a[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}