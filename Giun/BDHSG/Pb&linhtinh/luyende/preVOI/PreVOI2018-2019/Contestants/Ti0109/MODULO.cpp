#include <bits/stdc++.h>
#define int long long
#define ii pair <int, int>
#define X first
#define Y second

using namespace std;

string S, K;
int N, a, b, k;
char A, B;

int CS(char x){
    return (int)(x - 48);
}

char CX(int x){
    return char (x + 48);
}

string PLUS(string x, string y){
    int lx = x.size();
    int ly = y.size();
    int r = 0;
    string c = "";                                                       
    if (lx > ly){
        for (int i = 1; i <= lx - ly; ++i){
            y = '0' + y;
        }
    }
    else if (lx < ly) {
        for (int i = 1; i <= ly - lx; ++i){
            x = '0' + x;
        }
    }
    int l = x.size();
    for (int i = l - 1; i >= 0; --i){
        int n = CS(x[i]) + CS(y[i]) + r;
        c = CX(n % 10) + c;
        r = n / 10;
    }
    if (r) c = '1' + c;
    return c;
}

string MUL1(string x, char y){
    int a = CS(y), r = 0;
    string mul1 = "";
    for (int i = x.size() - 1; i >= 0; --i){
        int n = CS(x[i]) * a + r;
        mul1 = CX(n % 10) + mul1;
        r = n / 10;
    }
    if (r) mul1 = CX(r) + mul1;
    return mul1;
}

string MUL(string x, string y){
    int d = -1;
    string mul = "0";
    if (x.size() < y.size()) swap(x, y);
    for (int i = y.size() - 1; i >= 0; --i){
        ++d;
        string a = MUL1(x, y[i]);
        for (int k = 1; k <= d; ++k){
            a += '0';
        }
        mul = PLUS(a, mul);
    }
    return mul;
}

string MUU(string n, int k){
	if (k == 0) return "1";
	if (k == 1) return n;
	return MUL(MUU(n, k - 1), n); 
}

int mu(int n, int k){
	if (k == 0) return 1;
	if (k == 1) return n;
	return mu(n, k - 1) * n;
}

bool CHECK(string x){
	if (x.size() != N) return false;
	for (int i = 0; i < x.size(); ++i){
		if (x[i] != A && x[i] != B) return false;
	}
	return true;
}

string CXX(int k){
	int x = k;
	string q = "";
	while (x > 0){
		q = CX(x % 10) + q;
		x /= 10;
	}
	return q;
}

void slow(){
	A = CX(a);
	B = CX(b);
	K = CXX(k);
	string a = MUU("2", N), d;
	if (N == 1) d = "1";
	else d = MUU("5", N - 2); 
	while (!CHECK(S)){
		d = PLUS(d, "1");
		S = PLUS(MUL(a, d), K);
		if (S.size() > N){
			cout << -1;
			exit(0);
		}
	} 
	cout << S;
	exit(0);
}

void sloww(){
	int s;
	for (int i = 0; i < (1 << N); ++i){
		s = 0;
		for (int j = 1; j <= N; ++j){
			if (i & (1 << (j - 1))){
				s = s * 10 + a;
			}
			else s = s * 10 + b;
		}
		if (s % mu(2, N) == k){
			cout << s;
			exit(0);
		}
	}
	cout << -1;
	exit(0);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    	cin >> a;
    	cin >> b;
    	cin >> N;
    	cin >> k;
    	if (N <= 18) sloww();
    	slow(); 
}
