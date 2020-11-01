#include <stdio.h>
#include <queue>
#include <set>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long

using namespace std;

const int N = 1e5 + 2;
typedef pair <int, int> ii;
int n;
ll S, res, a[N], Min, Max;
priority_queue <ii, vector <ii>, greater <ii> > pq;
set <int> s1, s2;
set <int> :: iterator it1;

void fr()
{
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);
}

void inp()
{
    scanf("%d", &n);
    fti(i, 1, n) scanf("%lld", &a[i]), pq.push(ii(a[i], i)), S += a[i];
    Max = Min = S / n;
    if(S % n) ++ Max;
}

void proc()
{
    fti(i, 1, n) if(a[i] >= Max) s1.insert(i);
    int id;
    ll tg1, tg2;
    while(!pq.empty()) {
        if(pq.top().first >= Min) break;
        id = pq.top().second;
        pq.pop();
        it1 = s1.lower_bound(id);
        if(it1 != s1.end()) tg1 = *it1 - id;
        else tg1 = 1e9;
        if(it1 != s1.begin()) -- it1, tg2 = id - *it1;
        else tg2 = 1e9;
        if(tg1 < tg2)
            if(tg2 != 1e9) ++ it1;
        if(a[*it1] - (Min - a[id]) <= Min) a[id] += a[*it1] - Min, res += min(tg1, tg2) * (a[*it1] - Min), a[*it1] = Min;
        else a[*it1] -= Min - a[id], res += min(tg1, tg2) * (Min - a[id]), a[id] = Min;
        if(a[*it1] == Min) s1.erase(it1);
        if(a[id] < Min) pq.push(ii(a[id], id));
    }
    fti(i, 1, n) if(a[i] == Min) s2.insert(i);
    fti(i, 1, n)
        while(a[i] > Max) {
            it1 = s2.lower_bound(id);
            if(it1 != s2.end()) tg1 = *it1 - id;
            else tg1 = 1e9;
            if(it1 != s2.begin()) -- it1, tg2 = id - *it1;
            else tg2 = 1e9;
            if(tg1 < tg2)
                if(tg2 != 1e9) ++ it1;
            -- a[i], ++ a[*it1];
            s2.erase(it1);
            res += min(tg1, tg2);
        }
    printf("%lld\n", res);
}

int main()
{
    fr();
    inp();
    proc();
    return 0;
}
