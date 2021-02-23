#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "tamgiac2"
using namespace std;

cll MOD = 1e9 + 7;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

struct quang{
    ll a, b;
    void dau(){
        a *= -1, b *= -1;
    }
    void rg(){
        ll tmp = __gcd(abs(a), abs(b));
        if(!tmp) tmp = 1;
        // if(!a || !b) tmp = max(abs(a), abs(b));
        a /= tmp, b /= tmp;
        if(a == 0) b = 1;
        if(b == 0) a = 1;
    }
};

bool operator<(quang const &x, quang const &y){
    // if(x.a < y.a) return 1;
    // return x.a == y.a && x.b < y.b;
    return x.b * y.a < y.b * x.a; //tan alpha = -xa/xb => cot alpha = -xb/xa  ?? -yb/ya
}

bool operator==(quang const &x, quang const &y){
    // return x.a == y.a && x.b == y.b;
    return x.a * y.b == x.b * y.a;
}

ll n;
vec(ll) r, sum[2];
vec(quang) l, o;
map<quang, ll> cnt;

void init(){
    ll c;
    lp(i, 1, n){
        cin >> l[i].a >> l[i].b >> c;
        if(l[i].a < 0) l[i].dau(); 
        l[i].rg();
        quang tmp = {l[i].a, l[i].b};
        if(!cnt[tmp]++) o.push_back(tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    l.resize(n + 1);
    init();
    ll res = 0, s = 0;
    lp(i, 0, o.size() - 1){
        res = cnt[o[i]];
        r.push_back(res);
        // cerr << o[i].a <<  ' ' <<o[i].b << '\n';
        sum[0].push_back(s = (res + s) % MOD);
    }
    s = 0;
    // cerr << (o[3] == o[4]);
    // cerr << o.size();
    lp(i, 0, r.size() - 1){
        res = sum[0].back() - sum[0][i];
        sum[1].push_back(s = (s + r[i] * res) % MOD);
    }
    res = 0;
    lp(i, 0, r.size() - 1){
        res = (res + r[i] * (sum[1].back() - sum[1][i])) % MOD;
    }
    cout << res;
}

// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// using namespace std;
// #define TEN "tamgiac2"
// #define dx freopen(TEN".inp","r",stdin);freopen(TEN".out","w",stdout);
// #define don freopen(TEN".inp","r",stdin);
// #define boost ios::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
// const long long mod = int(1e9+7);
// struct line
// {
// 	long long a,b,c;
// }d[300005];
// bool cmp(const line &x,const line &y)
// {
// 	return x.a*y.b < x.b*y.a;
// }
// int n;
// long long dem[300005];
// long long f[300005];
// main()
// {
// 	//boost
// 	//dx
//  ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//    //  freopen("tamgiac2.inp","r",stdin);
//  //   freopen("tamgiac2.out","w",stdout);
// 	cin >> n;
// 		for (int i=1;i<=n;i++)
// 		{
// 			cin >> d[i].a >> d[i].b >> d[i].c;
// 			if (d[i].b<0)
// 			{
// 				d[i].a*=-1;
// 				d[i].b*=-1;
// 				d[i].c*=-1;
// 			}
// 			dem[i]=f[i]=0;
// 		}
// 		f[0]=0;
// 		sort (d+1,d+n+1,cmp);
// 		long long t=1;
// 		int de=1;
// 		for (long long i=1;i<n;i++)
// 		{
// 			if (d[i].a*d[i+1].b != d[i].b*d[i+1].a)
// 			{
// 				dem[de]=t;
// 				de++;
// 				t=1;
// 			}
// 			else t++;
// 		}
// 		dem[de]=t;
// 		for (int i=1;i<=de;i++)
// 		{
// 			f[i]=f[i-1]+dem[i];
// 		}
// 		long long ans=0;
// 		for (int i=1;i<de;i++)
// 		{
// 			for (int j=i+1;j<=de;j++)
// 			{
// 				ans= (ans+(((dem[i]*dem[j])%mod)*((n-f[j])%mod))%mod)%mod;
// 			}
// 		}
// 		cout << ans << endl;
// 		//for(int i=1;i<=de;i++) cout<<f[i]<< " ";
// 		cout<<endl;
// }