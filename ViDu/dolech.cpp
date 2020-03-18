#include <bits/stdc++.h>
using namespace std;
long n,a[1000000],k,s,s1,tg;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n - 1; i++){
        for(int j = i + 1; j <= n; j++){
            if(a[i] > a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for (int i=1; i<= min(k,n-k); i++) s+=a[i];
    for (int i=min(k,n-k)+1; i<=n; i++) s1+=a[i];
    cout<< s1-s;
    return 0;
}
