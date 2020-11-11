#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	for(ll i = 1; i <= 12; i++){
		if(12%i == 0) cerr << i << ' ';
	}
	cerr << '\n';	
	for(ll i = 1; i <= 12*12; i++){
		if((12*12)%i == 0) cerr << i << ' ';
	}
}