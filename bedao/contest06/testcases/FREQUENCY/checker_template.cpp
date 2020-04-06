#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define sp ' '
void verify(bool x, string s = "Wrong answer") {
	if (x == false) {
		cout << s << endl << "0.0" << endl;
		exit(0);
	}
}
void OK() {
	cout << "Ok, right answer\n1.0";
	exit(0);
}

const string name = "frequency"; // change
const string inp = ".inp", out = ".out", sol = ".out"; // back to out

struct data {

} con, ans;

istream& operator >> (istream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os >> x[i];
	return os;
}
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << ' ';
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}

const int maxn = 500005;

vector<int> pos[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// template
	 string inFolder, outFolder;
	 getline(cin, inFolder);
	 getline(cin, outFolder);
	 string inFile = inFolder + name + inp, outFile = outFolder + name + out, ansFile = inFolder + name + sol;
	 ifstream fin(inFile.c_str()), fout(outFile.c_str()), fans(ansFile.c_str()); // change all cin to this
	// end of template
	// check if we can read all input normally

	// statement input

  int n, q; fin >> n;
  for(int i = 1; i <= n; ++i) {
    int v; fin >> v;
    pos[v].push_back(i);
  }
  fin >> q;
	// end of statement input

	// contestant output
  for(int i = 0; i < q; ++i) {
    int l, r; fin >> l >> r;
    int v; fout >> v;
    int u; fans >> u;
    if(u == 0) {
      verify(v == 0);
      continue;
    }
    int c = upper_bound(pos[v].begin(), pos[v].end(), r) - lower_bound(pos[v].begin(), pos[v].end(), l);
    verify(c == 1);
  }
  // end of contestant output

	// answer input
	// end of answer input

	// check
	// end of check
	OK();
}
