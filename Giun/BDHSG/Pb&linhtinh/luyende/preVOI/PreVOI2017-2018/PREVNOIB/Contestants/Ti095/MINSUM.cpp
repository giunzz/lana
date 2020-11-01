#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b) ; i <= _b ; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b) ; i <= _b ; --i)
#define For(i, a, b) for(int i = (a), _b = (b) ; i < _b ; ++i)
#define Ford(i, a, b) for(int i = (a), _b = (b) ; i > _b ; --i)
#define FORV(i, a, b) for(int i = (a), _b = (b) ; i * i <= _b ; ++i)
#define FORE(i, v) for(__typeof((v).begin()) i = (v).begin() ; i != (v).end(); ++i)
#define ll long long
#define ii pair <int,int>
#define mp make_pair
#define pb push_back
#define X first
#define Y second

using namespace std;

const int N = 3005;
const int oo = 1e9;

int A, B, n;
int sum = oo;
ii res;
int d[N], x[N], a[N];
bool prime[N];
set <int> s;

void sang(int x) {
    ///prime[1]=true;
    for(int i=2;i*i<=x;++i) if(!prime[i]) {
		for(int j=i*i;j<=x;j+=i)
			prime[j]=true;
    }

}

void check(int A, int B) {

	///cout << A << " " << B << endl;
	n = 0;
	s.clear();
	FORV(i, 1, A) if(A % i == 0) s.insert(i), s.insert(A / i);
	FORV(i, 1, B) if(B % i == 0) s.insert(i), s.insert(B / i);
	FORE(it, s) if(*it != 1) a[++n] = *it;

	///FOR(i, 1, n) cout << a[i] << " "; cout << endl;

	FOR(i, 1, n) {
		if((A % a[i] == 0) && (B % a[i] == 0)) A /= a[i], B /= a[i];
		else if(A % a[i] == 0) A /= a[i], B *= a[i];
		else if(B % a[i] == 0) A *= a[i], B /= a[i];
		if(sum > A + B) sum = A + B, res = mp(A, B);
		if(A == 1 || B == 1) return;
		if(!prime[A] && !prime[B]) return;
		check(A, B);
	}
}

vector <ii> factorization (int x) {
    vector <ii> res;
    FORV(i, 2, x) if(x % i == 0) {
        res.pb(mp(i, 0));
        while (x % i == 0) {x/= i, res.back().Y++;}
    }
    if(x > 1) res.pb(mp(x, 1));
    return res;
}

void sub_2(void) {
	int t = __gcd(A, B);
	if(t > 1) A /= t, B /= t;
	vector <ii> AA = factorization(A);
	vector <ii> BB = factorization(B);

	For(i, 0, AA.size()) {
		int uoc = AA[i].X;
		int sl = AA[i].Y;
		if(sl % 2 == 0) FOR(j, 1, sl) A /= uoc;
		else {
			FOR(j, 1, sl) A /= uoc;
			if(A < B) A *= uoc;
			else B *= uoc;
		}
	}
	For(i, 0, BB.size()) {
		int uoc = BB[i].X;
		int sl = BB[i].Y;
		if(sl % 2 == 0) FOR(j, 1, sl) B /= uoc;
		else {
			FOR(j, 1, sl) B /= uoc;
			if(A < B) A *= uoc;
			else B *= uoc;
		}
	}
	printf("%d %d\n", A, B);
	return;
}

int main()
{
	freopen("MINSUM.INP", "r", stdin); freopen("MINSUM.OUT", "w", stdout);

	int ntest; scanf("%d", &ntest); while (ntest --)
	{
		scanf("%d%d", &A, &B);
		sub_2();
	}
    return 0;
}
