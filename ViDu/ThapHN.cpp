#include<iostream>
#include<stdio.h>
using namespace std;
void Tower(int n , char a, char b, char c ){
    if(n==1){
        cout<<"\t"<<a<<"-------"<<c<<endl;
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
    }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    char a='A', b='B', c='C';
    int n;
    cin>>n;
    Tower(n,a,b,c);
}
 