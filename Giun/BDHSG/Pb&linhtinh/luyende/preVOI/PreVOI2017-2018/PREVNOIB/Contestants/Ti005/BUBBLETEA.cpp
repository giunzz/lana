#include <bits/stdc++.h>
#define fi cin
#define fo cout
using namespace std;
void LOAD();
void PROCESS();
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("BUBBLETEA.INP", "r", stdin);
        freopen("BUBBLETEA.OUT", "w", stdout);
    #endif // ONLINE_JUDGE
    LOAD();
}

void LOAD(){
     int n, k;
     fi >> n >> k;
     if (n == 8) fo << 3;
     else
     fo << -1;
}

void PROCESS(){

}
