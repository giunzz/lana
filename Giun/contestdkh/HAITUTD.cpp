#include <bits/stdc++.h>
using namespace std;
const int pi = 96;
string s;
int co[29][50007], n, t;
bool d[29];

/*void fill(){
    for (int i = 1; i<= 26; i++){
        if(d[i]){
            for (int j = 1; j <= n; j++) co[i][j] += co[i][j - 1];
        }
    }
}*/

void inp(){
    n = 0;
    int ca;
    getline(cin, s);
    s = "0" + s;
    while (true){
        //cerr << n << endl;
        ++n;
        ca = (int)s[n] - pi;
        d[ca] = 1;
        //cerr << ca << endl;
        co[ca][n] = 1;
        for (int i = 1; i <= 26; i++) {
            if(d[i]) co[i][n] += co[i][n - 1];
        }
        if (n == s.length() - 1) break;
    }
    //cerr << n << endl;
    //fill();
    //cerr << 1 << endl;
    cin >> t;
    //cerr << t << endl;
}

/*bool che(int a, int b, int c, int d){
    if (b - a == d - c){
        for (int i = 1; i <= 26; i++){
            if(co[i][b] - co[i][a - 1] != co[i][d] - co[i][c - 1]) return 0;
        } 
        return 1;
    }
    return 0;
}*/

void pri(int a, int b, int c, int d){
    for (int i = 1; i <= 26; i++) cout << co[i][b] - co[i][a - 1] << " ";
    //cout << "    ";
    for (int i = 1; i <= 26; i++) cout << co[i][d] - co[i][c - 1] << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HAITUTD.INP", "r", stdin);
    freopen("HAITUTD.OUT", "w", stdout);
    //memset(co, 0, sizeof(co));
    inp();
    //cerr << clock() << " ms";
    for (int i = 1; i <= n; i++){
        for (int j= 1; j <= 26; j++){
            cerr << co[j][i] << " ";
        }
        cerr << endl;
    }
    //cerr << t << endl;
    int a, b, c, d;
    while(t != 0){
        cin >> a >> b >> c >> d;
        pri(a, b, c, d);
        cout << "\n";
        --t;
    }
    return 0;
}