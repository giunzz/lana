#include <bits/stdc++.h>
using namespace std;
const int maxn = 37;
int f[maxn][maxn][maxn] = {{{0}}}, c[maxn], sumall = 0, n, t, a, b;
stack<int> st;
queue<int> qu;

void init(){
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        sumall += c[i];
    }
    /*for (int i = 0; i <= a; i++){
        for (int j = 0; j <= b; j++){
            f[0][i][j] = 0, f[0][j][i] = 0;
        }
    }*/
}

int sol(int x, int y, int z){
    int sum = 0, minn = 201;
    if (x == 0){
        f[x][y][z] = 0;
        return f[x][y][z];
    }
    else {
        for (int i = 0; x - i - 1 >= 0 && y - i >= 0; i++){
            //if (x == n) cerr << i << endl;
            minn = min(minn, sol(x - 1 - i, z, y - i));
            //if (x == n) cerr << minn << endl;
        }
        for (int i = 1; i <= x; i++) sum += c[i];
        f[x][y][z] = sum - minn;
        //cerr << x << " " << y  << " " << z << " " << f[x][y][z] << endl;
        return f[x][y][z];
    }
}

/*void sol(){
    for (int x = 1; i <= n; i++){
        for (int y = a; y >= 0; y++){
            for (int z = b; z >= )
        }
    }
}*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Test00\\SPC4.INP", "r", stdin);
    freopen("spc4.out", "w", stdout);
    cin >> t;
    for(int i = 1; i <= t; i++){
        sumall = 0;
        init();
        int kq = sol(n, a, b);
        if (sumall - kq > kq) cout << "LOSE\n";
        else if (sumall - kq == kq) cout << "DRAW\n";
        else cout << "WIN\n";
        //cerr << kq << " " << sumall - kq;
    }
    cerr << clock() << " ms";
}

/*
ket qua: f[n][a][b]
dung mang 3 chieu f[i][x][y]
f the hien gia tri tong bai dang co cua x
i la so bai  tren ban
x la so luot minh con lai de chay hon 1 lan
y la so luot doi thu con lai de chay hon 1 lan
y tuong: max(a1 + a2 +..+ ai - cac cau hinh f[i - 1])
*/