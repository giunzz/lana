#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,i=2;
int main(){
  cin>>n;
    while(i<=sqrt(n)){
        if(n %i ==0) cout<<0;
        else cout<<1;
        i++;
    }
     return 0;

}
