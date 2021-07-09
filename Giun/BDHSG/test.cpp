#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

mt19937 rng(rand());
const string gach = "--------------------------------------", state[] = {"Bua", "Bao", "Keo"};
bool win[3][3];
char ckey;
ll bot, key;

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

int main(){
    win[0][2] = win[1][0] = win[2][1] = 1;
    while(true){
        system("cls");
        cout << "BAO TIENG XUM\n" << gach << endl;
        lp(i, 0, 2) cout << i << ". " << state[i] << endl;
        cout << "q. Exit\n" << gach << endl;
        bot = randll(0, 2);
        cout << "Chon so phan cuoc doi: ";
        ckey = __getch();
        if(ckey == 'q') break;
        key = ckey - '0';
        cout << "Da chon: " << state[key] << '\n';
        cout << "Bot chon: " << state[bot] << '\n';
        if(key == bot) cout << "Cuoc doi xem chet!";
        else if(win[key]) cout << "Cuoc doi no hoa!!!!";
        else cout << "Cuoc song be tat.";
        Sleep(5000);
    }
}