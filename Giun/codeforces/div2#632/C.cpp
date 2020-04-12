/*#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "f";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 2e5 + 7;
ll n, a[maxn], t, dem = 0;

void fs(ll &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c == ' ') fs(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

struct Bst{
    ll value = 0, cnt = 0;
    struct Bst* k_left = NULL;
    struct Bst* k_right = NULL;
};

typedef struct Bst* Node;
Node r = NULL;

Node ins(Node root, int val){
    if (root == NULL){
        Node node = new Bst;
        node -> value = val;
        node -> cnt = 1;
        return node;
    }
    if (val < root -> value)
        root -> k_left = ins(root -> k_left, val);
    if (val > root -> value)
        root -> k_right = ins(root -> k_right, val);
    if (val == root -> value)
        root -> cnt += 1;
    return root;
}

int find(Node root, int val){
    if (root == NULL) return 0;
    ll ans;
    if (val < root -> value) 
        ans = find(root -> k_left, val);
    if (val > root -> value)
        ans = find(root -> k_right, val);
    if (val == root -> value)
        return root -> cnt;
    return ans;
}

void xuly(){
    //if (!a[1]) ++dem;
    //r = ins(r, a[1]);
    r = ins(r, 0);
    loop(i, 1, n){
        //if (!a[i]) ++dem;
        //cerr << a[1];
        dem += find(r, a[i]);
        if (i == 2) cerr << endl << dem;
        ins(r, a[i]); 
    }
}

int main(){
    //opt;
    fi;
    scanf("%I64d", &n);
    a[0] = 0;
    loop(i, 1, n){
        scanf("%I64d", &a[i]);
        a[i] += a[i - 1];
    }
    t = (n*n + n)/2;
    xuly();
    //cerr << t << " " << dem;
    printf("%I64d", t - dem);
}*/


#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=2e5;
int n, a[mxN];
ll b[mxN+1], ans;
map<ll, int> mp;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		b[i+1]=b[i]+a[i];
	}
	for(int i=0, j=0; i<=n; ++i) {
		++mp[b[i]];
		while(mp[b[i]]>1) {
			--mp[b[j++]];
		}
		ans+=i-j;
	}
	cout << ans;
}
