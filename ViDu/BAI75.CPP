#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int p[10]={0},a,b;
void tach (int n){
    while (n > 0){
          p[n%10]+=1;
          n= n / 10;
    }
}

int main(){
    freopen("BAI75.INP", "r", stdin);
    freopen("BAI75.OUT", "w", stdout);
    cin >> a >> b;
    for (int i=a ; i<= b ; i++ ){
        tach (i);
    }
    for (int i=0 ; i<= 9 ; i++)
        if ( p[i]!= 0) cout << i << " " << p[i] << endl;
        return 0;
}
