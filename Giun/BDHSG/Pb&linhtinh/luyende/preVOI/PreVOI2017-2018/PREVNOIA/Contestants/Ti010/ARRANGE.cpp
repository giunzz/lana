				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007
#define HAN "ARRANGE"
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int n , a[N], dem;
long long sum, arr , arm , ans, ar;
queue <int> qu, qu1;
void make_test()
{
	freopen(HAN".inp", "w", stdout);
	srand(time(0));
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//make_test();
	freopen(HAN".inp" , "r", stdin);
	freopen(HAN".out" , "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];

    arr = sum/n;
    arm = sum % n;
    ar = arr + (arm !=0);
    for (int i = 1; i <= n; ++i) {
        if (a[i] < arr){
            while (qu1.size() && a[i] < arr)
            {
                int j = qu1.front();
                qu1.pop();
                if (a[j] - ar <= arr - a[i])
                {
                    ans += 1ll*(a[j] - ar)*(i - j);
                    a[i] += a[j] - ar;
                    a[j] = ar;
                }
                else{
                    ans += 1ll*(arr - a[i])*(i-j);
                    int x = arr - a[i];
                    a[i] = arr;
                    a[j] -= x;
                    qu1.push(j);
                }
            }
            if (a[i] < arr) qu.push(i);
        }
        else if (a[i] > ar)
        {
            while (qu.size() && a[i] > ar)
            {
                int j = qu.front();
                qu.pop();
                if ( arr - a[j] <= a[i] - ar)
                {
                    ans += 1ll*(arr - a[j])*(i - j);
                    int x = arr - a[j];
                    a[j] = arr;
                    a[i] -= x;
                }
                else if (arr - a[j] > a[i] - ar)
                {
                    ans += 1ll*(a[i]-ar)*(i-j);
                    a[j] += a[i] - ar;
                    a[i] = ar;
                    qu.push(j);
                }
            }
            if (a[i] > ar) qu1.push(i);
        }
    }

    if (arm)
    {
        for (int i = 1; i <= n; ++i) if (a[i] >= ar) dem++;
        if (dem < arm)
        {
            for (int i = 1 ; i <= n; ++i) if (a[i] > ar)
            {
                int l = i - 1 , r = i + 1;
                while ( a[i] > ar)
                {
                    while ( l > 0 && a[l] >= ar) l--;
                    while (r <= n && a[r] >= ar) r++;
                    if ( i - l <= r - i && a[l] < ar) {
                        a[l]++;
                        a[i]--;
                        ans +=(i-l);
                    }
                    else a[r]++, a[i]--, ans += (r-i);
                }
            }
        }
        else if (dem > arm) {
            for (int i = 1; i <= n; ++i) if (a[i] < arr)
            {
                int l = i - 1, r = i + 1;
                while ( a[i] < arr )
                {
                    while ( l > 0 && a[l] <= arr) l--;
                    while (r <= n && a[r] <= arr) r++;
                    if ( i - l <= r - i && a[l] > arr){
                        a[l]--;
                        a[i]++;
                        ans +=(i-l);
                    }
                    else a[r]--, a[i]++, ans += (r-i);
                }
            }
        }
    }
    cout <<ans;
}
