#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a,b,n,k;
//string res ="";
char res[2000009];
int MOD;
int allow[4] = {2,4,6,8};
bool allowchar[10];
string Result = "";

void init(){
	freopen("modulo.inp","r",stdin);
	freopen("modulo.out","w",stdout);
}

void input(){
	scanf("%lld%lld",&a,&b);
	scanf("%lld%lld",&n,&k);
}

void findResult(){
	// quy uoc a chan, b le
	if (a&1) swap(a,b);
	
	int curMod = k;
	while (curMod){
		if (curMod&1){
			curMod -= b;
			Result += char(b+'0');	
		}
		else{
			curMod -= a;
			Result += char(a+'0');
		}
		if (curMod < 0) curMod += MOD;
		// now, curMod = X*10 % MOD
		
		int curLastDigit = curMod%10;
		int MODLastDigit = MOD%10;
		int transformLastDigit = (10-curLastDigit)%10;
//		cerr<<curMod<<" "<<transformLastDigit<<" "<<MODLastDigit<<endl;
		int k = 0;
		for (k = 0 ; k <= 4 ; k++){
			if ((MODLastDigit*k) % 10 == transformLastDigit)
				break;
		}
//	cerr<<" "<<k<<endl; 
		curMod = (k*MOD + curMod) / 10;
		
	}
	reverse(Result.begin(),Result.end());
	cout << Result;
}

void dfs(int _pos){
	
}

void compute(){
	MOD = pow(2,n);
//	for (int i = 0 ; i < 4 ; i++){
//		allow[i] = allow[i]-k%10;
//		if (allow[i] < 0) allow[i] += 10;
//		allowchar[allow[i]] = 1;
//		cerr<<" ALLOW "<<allow[i]<<endl;
//	}
//	if (!allowchar[a] && !allowchar[b]){
//		cerr<<"-"<<endl;
//		cout << -1;
//	}
	if (a%2==0 && b%2==0 && k&1){
		cout << -1;
	}
	else if (a&1 && b&1 && k%2==0){
		cout << -1;
	}
	else if ((a&1 && b%2==0) || (a%2==0 && b&1)){
		findResult();
	}
	else{
		cout << -1;
	}
}

void output(){
	
}

main(){
	init();
	input();
	compute();
	output();
}
