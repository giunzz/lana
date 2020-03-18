#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

long b,t;
bool isPrime[100000000+1];
void sieve(int N) {

    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}
int main(){
    sieve(1000000);
    cin>>b;
    for (int i=1; i<=b ; i++) {
        cin>>t;
        if ((isPrime[t])== true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    return 0;
}

