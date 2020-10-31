#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int t,a,b,mem[N], cnt;

void load() {
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
}

void process() {

    cin >> t;
    for (int ii = 1 ; ii <= t ; ++ ii) {

        cin >> a >> b;
        map < int , int > Map;
        map < int , int > ::iterator it;

        int j = 2;
        bool ok = 0;
        if (a <= 50 && b <= 50) ok = 1;

        while ( j <= sqrt(a)) {

            int d = 0;
            while (a % j == 0) {
                ++d;
                a /= j;
            }

            if (d > 0) Map[j] += d;
            ++j;

        }
        if (a > 1) ++Map[a];

        j = 2;
        while ( j <= sqrt(b)) {

            int d = 0;
            while (b % j == 0) {
                ++d;
                b /= j;
            }

            if (d > 0) Map[j] += d;
            ++j;
        }
        if (b > 1) ++ Map[b];

        int cnt = 0;

        for (it = Map.begin() ; it !=  Map.end() ; ++ it) {
            if ((*it).second % 2)
                mem[++cnt] = (*it).first;
        }

        if (ok) {

            int  nho = 1e9, nho1 = 1e9;

            for (int i = 0 ; i < (1 << cnt) ; ++ i) {
                int res = 1, res1 = 1;

                for (int j = 0 ; j < cnt ; ++ j)
                    if (i & (1 << j))
                        res = res * mem[j + 1];
                    else
                        res1 = res1 * mem[j + 1];


                if (nho + nho1 > res + res1) {
                   nho = res;
                    nho1 = res1;
                }
            }

            if (nho > nho1) swap(nho,nho1);
            cout << nho << " " << nho1 << endl;
                continue;
        }

        int res = 1 ,res1 = 1;
        sort(mem+1,mem+1+cnt);

        for (int i = cnt ; i > 0 ; -- i) {
            if (res > res1)
                res1 = res1 * mem[i];
            else
                res = res * mem[i];
        }

        if (res > res1) swap(res,res1);

        cout << res << " " << res1 << endl;
    }
}

int main() {
    load();
    process();
    return 0;
}
