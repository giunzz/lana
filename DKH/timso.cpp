#include <bits/stdc++.h>
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
const string tenfile = "timso";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii df[] = {2, 3, 5, 7};
ii n, m, ts[11] = {0}, s = 0;

bool tachn(){
    int t = n;
    loop(i, 0, 3)
        while(!(t % df[i]))
            ++ts[df[i]], t /= df[i], s += df[i];
    if(t != 1) return 1;
    else return 0;
}

void xuly4(){
    ts[4] = ts[2] / 2;
    ts[2] %= 2;
}

void xuly1(){
    ts[1] = m - s;
    s = m;
}

void xuly(){
    while((m - s) >= 3 && ts[3] > 1)
        s += 3, ts[3] -= 2, ++ts[9];
    while((m - s) >= 2 && ts[2] > 2)
        s += 2, ts[2] -= 3, ++ts[8];
    while((m - s) >= 1 && ts[3] > 0 && ts[2] > 0)
        s += 1, --ts[2], --ts[3], ++ts[6];
    xuly4();
    xuly1();
}

int main(){
    //opt;
    fi;
    scanf("%d%d", &m, &n);
    if (n == 0 && m == 0){
        printf("0");
        return 0;
    }
    if(m != 0 && n == 0){
        cerr << 1;
        if(m % 9 != 0 && (m / 9) <= 4) printf("%d0", m % 9);
        else if(m / 9 <= 5) {
            printf("90");
            m -= 9;
        }
        else {
            printf("-1");
            return 0;            
        }
        loop(i, 1, m / 9) printf("9");
        return 0;
    }    
    if (tachn() || m > 54 || (m == 0 && n != 0)){
        printf("-1");
        return 0;
    }
    if (m < s){
        printf("-1");
        return 0;       
    }
    xuly();
    int tc = 0;
    loop(i, 1, 9) tc += ts[i];
    if (tc > 6){
        printf("-1");
        return 0;
    }
    loop(i, 1, 9)
        loop(j, 1, ts[i]) 
            printf("%d", i);
}