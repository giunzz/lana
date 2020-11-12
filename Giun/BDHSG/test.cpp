#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	for(ll i = 1; i <= 120; i++){
		if(120%i == 0) cerr << i << ' ';
	}
	cerr << '\n';	
	for(ll i = 1; i <= 120*120; i++){
		if((120*120)%i == 0) cerr << i << ' ';
	}
}