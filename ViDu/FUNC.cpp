#include <cstdio>
#include <algorithm>

using namespace std;
int n;
long long l, r, ans = 0;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        ans = 0;
        scanf("%lli %lli", &l, &r);
        if (l > r) swap(l, r);
        if ((l < 0 && !(l % 2)) || (l >= 0 && l % 2)) ++l;
        if ((r < 0 && !(r % 2)) || (r >= 0 && r % 2)) --r;
        if ((l < 0 && r < 0) || (l >= 0 && r >= 0)){
            ans = (r - l) / 2 + 1;
        }
        if (l < 0 && r >= 0){
            ans = (-1 - l) / 2 + 1 + (r - 0) / 2 + 1;
        }
        printf("%lli ", ans);
    }
}