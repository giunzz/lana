#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

typedef pair<int, int> II;

vector<II> pa, pb;
map<int, II> countAll;
vector<int> have;
int a, b;
int t;

void fact (int x, vector<II> &px)
{
    for (int i = 2; i * i <= x; i++)
    {
        int c = 0;
        while (x % i == 0)
        {
            x /= i;
            c++;
        }
        px.push_back(II(i, c));
    }
    if (x > 1) px.push_back(II(x, 1));

}

int main()
{
    #define file "MINSUM"
    freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        pa.clear(); pb.clear(); countAll.clear(); have.clear();
        fact(a, pa); fact(b, pb);
        for (int i = 0; i < pa.size(); i++)
        {
            countAll[pa[i].first].first = pa[i].second;
        }
        for (int i = 0; i < pb.size(); i++)
        {
            countAll[pb[i].first].second = pb[i].second;
        }
        for (map<int, II> :: iterator it = countAll.begin(); it != countAll.end(); it++)
        {
            if (abs(it -> second.first - it -> second.second) & 1)
                have.push_back(it -> first);
        }
        int ret = (int)(2e9), aBest = (int)(1e9), bBest = (int)(1e9);
        for (int mask = 0; mask < (1 << have.size()); mask++)
        {
            int ra = 1, rb = 1;
            for (int i = 0; i < have.size(); i++)
            {
                if ((mask >> i) & 1)
                    ra *= have[i];
                else
                    rb *= have[i];
            }
            if (ret > (ra + rb))
            {
                ret = ra + rb;
                aBest = ra;
                bBest = rb;
            }
        }
        cout << aBest << " " << bBest << endl;
    }

    return 0;
}

