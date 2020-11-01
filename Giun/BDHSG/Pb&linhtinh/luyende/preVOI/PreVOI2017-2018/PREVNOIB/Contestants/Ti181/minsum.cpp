#include<bits/stdc++.h>
#define LL long long

using namespace std;

int t, a, b;
LL ans, al, ar;
map<int, int> awp;
set<int> prime;
vector<int> ls;

void dequy(int x, int l, int r){
    if (x == ls.size()){
        if (ans > l + r){
            ans = l + r;
            al = l; ar = r;
        }
        return;
    }
    if ((LL) l * ls[x] <= ans - r) dequy(x + 1, l * ls[x], r);
    if ((LL) r * ls[x] <= ans - l) dequy(x + 1, l, r * ls[x]);
}

int main(){
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);

    scanf("%d", &t);
    for (int ct = 1; ct <= t; ct++){
        scanf("%d %d", &a, &b);
        ans = a + b; al = a; ar = b;
        awp.clear(); prime.clear(); ls.clear();
        for (int i = 2; i <= (int) sqrt(a); i++)
            while (a % i == 0){
                a /= i;
                awp[i]++;
                prime.insert(i);
            }
        if (a != 1){
            awp[a]++;
            prime.insert(a);
        }
        for (int i = 2; i <= (int) sqrt(b); i++)
            while (b % i == 0){
                b /= i;
                awp[i]++;
                prime.insert(i);
            }
        if (b != 1){
            awp[b]++;
            prime.insert(b);
        }
        while (!prime.empty()){
            int tg = *prime.begin();
            prime.erase(tg);
            if (awp[tg] % 2 == 1) ls.push_back(tg);
        }
        dequy(0, 1, 1);
        printf("%lld %lld\n", min(al, ar), max(al, ar));
    }

    return 0;
}
