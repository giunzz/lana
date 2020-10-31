#include <bits/stdc++.h>

using namespace std;

typedef pair < long long, int > II;

long long a, b, n, k, mod;
long long pp[100];
II v[(1 << 21)];
int l, r, len;
int x[100];

long long get(long long x, long long y) {
    x = (x - y) % mod;
    if (x < 0)
        x += mod;
    return x;
}

int bs(long long val, int l, int r) {
    //int pos = 0;
    //cout << val << " " << l <<" " << r << endl;
    //return 1
    while (l <= r) {
        int mid = (l + r) >> 1;
        //cout << mid << endl;
        if (v[mid].first == val) 
            return v[mid].second;
        if (v[mid].first > val)
            r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

inline int getbit(int x, int i) {
    return ((x >> i) & 1);
}

void backTrack(int i, int type) {
    if (i > r) {
        long long res = 0;
        for(int j = l; j <= r; j++)
            if (x[j] == 0) 
                res = (res + (a * pp[j]) % mod) % mod;
            else res = (res + (b * pp[j]) % mod) % mod;
        if (type == 0) {
            int temp = 0;
            for(int j = l; j <= r; j++)
                temp = temp * 2 + x[j];
            v[temp] = II(res, temp);
        } else if (type == 1) {
            //cout << res << " " << get(k, res) << endl;
            int zz = bs(get(k, res), 0, len - 1); 
            //cout << zz << endl;
            if (zz != -1) {
                //cout << res << " * " << zz << endl;
                for(int j = r; j >= l; j--)
                    if (x[j] == 0)
                        cout << a;
                    else cout << b;
                //cout << len << endl;
                //cout << (n / 2) << endl;
                for(int j = 0; j < (n / 2); j++)
                    if (getbit(zz, j))
                        cout << b;
                    else cout << a;
                exit(0);
            }
        }
    } else {
        for(int j = 0; j <= 1; j++) {
            x[i] = j;
            backTrack(i + 1, type);
        }
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> a >> b;
    cin >> n >> k;
    mod = 1;
    pp[1] = 1;
    for(int i = 1; i <= n; i++)
        mod *= 2;
    //cout << mod << endl;
    for(int i = 2; i <= n; i++)
        pp[i] = (pp[i - 1] * 10) % mod;
    l = 1; r = n / 2;
    backTrack(1, 0);
    //for(int i = 1; i <= n; i++)
    //    x[i] = 0;
    len = (1 << (n / 2));
    //cout << len << endl;
    //for(int i = 0; i < n; i++)
    sort(v, v + len);
   // for(int i = 0; i < len; i++)
   //     cout << v[i].first <<" " <<  v[i].second << endl;
    l = n / 2 + 1; r = n;
    backTrack(n / 2 + 1, 1);
    cout << "-1";        
    return 0;
}