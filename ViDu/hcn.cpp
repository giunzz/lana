#include<bits/stdc++.h>

using namespace std;

typedef struct
{
    pair<int, int> p[6];
} meo;

int n;
meo a[507];
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1 ; i <= n; i++){
        scanf("%d%d%d%d", &a[i].p[1].first, &a[i].p[1].second, &a[i].p[3].first, &a[i].p[3].second);
        a[i].p[2].first = a[i].p[1].first, a[i].p[2].second = a[i].p[3].second;
        a[i].p[4].first = a[i].p[3].first, a[i].p[4].second = a[i].p[1].second;
    }
    for (int i = 1; i < n; i++){
        for (int j = i + 1 <= n; j++){
            
        }
    }
}