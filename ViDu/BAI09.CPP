#include<bits/stdc++.h>
using namespace std;
const  long maxn=1e6+9;
long a[maxn],b[maxn]={0},n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("BAI09.INP","r",stdin);
    freopen("BAI09.OUT","w",stdout);
    cin >> n;
    for (int i=1 ; i<= n ; i++) cin >> a[i];
    b[1]=0;
    for (int i=1 ; i<= n ; i++){
        for (int j= i-1 ; j>= 1 ; j-- ){
            if (a[i] < a[j] ) b[i]+=1;
        }
    }
    for (int i=1 ; i<= n ; i++) cout << b[i] << " ";
    return 0;
}

