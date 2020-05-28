#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e6 + 7;

int n;
int a[N];
char q[N];

int main() {
    fileInput("toffees");
    fast;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> q[i];
    }

    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n - 1; i++) {
        if (q[i] == 'L') {
            a[i] = max(a[i + 1] + 1, a[i] + 1);
        } else if (q[i] == 'R') {
            a[i + 1] = max(a[i] + 1, a[i + 1] + 1);
        } else if (q[i] == '=') {
            a[i] += 1;
            a[i + 1] += 1;
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        if (q[i] == 'L') { /*a[i] > a[i + 1]*/
            if (a[i + 1] == 0 and a[i] > a[i + 1] + 1) {
                a[i + 1] += 1;
            } else if (a[i + 1] == 0 and a[i] == a[i + 1] + 1) {
                a[i + 1] += 1;
                a[i] += 1;
            } else if (a[i + 1] != 0 and a[i] == a[i + 1]) {
                a[i] += 1;
            } else continue;
        } else if (q[i] == 'R') { /*a[i] < a[i + 1]*/
            if (a[i] == 0 and a[i + 1] > a[i] + 1) {
                a[i] += 1;
            } else if (a[i] == 0 and a[i + 1] == a[i] + 1) {
                a[i] += 1;
                a[i + 1] += 1;
            } else if (a[i] != 0 and a[i + 1] == a[i]) {
                a[i + 1] += 1;
            } else continue;
        } else if (q[i] == '=') { /*a[i] == a[i + 1]*/
            if (a[i] == a[i + 1]) {
                continue;
            } else if (a[i] > a[i + 1]) {
                a[i + 1] += (a[i] - a[i + 1]);
            } else if (a[i] < a[i + 1]) {
                a[i] += (a[i + 1] - a[i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return (0);
}