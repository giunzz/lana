#include <iostream>
using namespace std;
int n,m;
int W[50],V[50],L[50][50];

void Op(){
    for(int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            L[i][j] = L[i-1][j];
            if(j>=W[i] && L[i][j] < L[i-1][j-W[i]] + V[i]){
                L[i][j] = L[i-1][j-W[i]]+V[i];
            }
        }
    }
}

void TruyVet(){
    cout << L[n][m] << endl;
    while (n!=0){
        if(L[n][m] != L[n-1][m]){
            cout << n << " " << W[n] << " " << V[n] << endl;
            m=m-W[n];
        }
        n--;
    }
}
int main (){
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> W[i] >> V[i];
    }
    sizeof(L, 0, sizeof(L));
    Op();
    TruyVet();
    
    return 0;
}