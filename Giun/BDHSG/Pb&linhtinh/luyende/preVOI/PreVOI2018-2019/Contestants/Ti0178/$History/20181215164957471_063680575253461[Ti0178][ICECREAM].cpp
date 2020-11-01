// ILTH
// PreVNOI 2018 ^^
#include<bits/stdc++.h>

using namespace std;
const long long BASE = int(1e9)+9;
const int PMTH = 305;
long long m50, m1, m2, n, mmax, a[PMTH], res;

int Tenter()
{
    cin >> n >> mmax;
    cin >> m50 >> m1 >> m2;

    return 0;
}

bool check()
{
    vector<int> curr(4,0);
    curr[1] = m50; curr[2] = m1; curr[3] = m2;
    for(int i=1; i<=n; i++)
    {
        curr[a[i]]++;
        if (curr[a[i]]>mmax) return false;
        if (a[i]==3)
        {
            if (curr[1]<3&&(curr[1]<1||curr[2]<1)) return false;
            if (curr[1]>=1&&curr[2]>=1)
            {
                curr[1]--;
                curr[2]--;
            }
            else
                curr[1]-=3;
        }
        if (a[i]==2)
        {
            if (curr[1]<1) return false;
            curr[1]--;
        }
    }
    return true;
}

int gen(int i)
{
    if (i>n)
    {
        if (check()) res++;
        return 0;
    }
    a[i] = 1; gen(i+1);
    a[i] = 2; gen(i+1);
    a[i] = 3; gen(i+1);

    return 0;
}

int Tsolve()
{
    gen(1);
    cout << res%BASE;

    return 0;
}



int main()
{
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Tenter();
    Tsolve();

    return 0;
}
