#define task "ICECREAM"
#include <bits/stdc++.h>
using namespace std;

int n, mm, cnt, lib[4], i, pre1, pre2, pre3, res;
bool ch;

bool Can(int x)
{
    if (x == 1) return 1;
    else if (x == 2 && lib[1] == 0) return 0;
    else if (x == 3)
    {
        if (lib[2] == 0)
        {
            ch = 1;
            if (lib[1] == 0)
                return 0;
        }
        else if (lib[1] < 3)
            return 0;
    }
    return 1;
}

void Libra (bool c)
{
    if (c == 1)
    {
        pre1 = lib[1], pre2 = lib[2], pre3 = lib[3];
        if (i == 1) lib[1]++;
        else if (i == 2)
        {
            lib[1]--; lib[2]++;
        }
        else if (i == 3)
        {
            if (lib[2] > 0 && lib[1] > 0)
            {
                lib[2]--; lib[1]--; lib[3]++;
            }
            else
            {
                lib[3]++; lib[1] -= 3;
            }
        }
    }
    else
    {
        lib[1] = pre1;
        lib[2] = pre2;
        lib[3] = pre3;
    }
}

void atp(int x)
{
    if (cnt == n)
        res++;
    for (i = 1; i <= 3 && cnt <= n; i++)
    {
        ch = 0;
        if (lib[i] < mm && Can(i))
        {
            Libra(1);  //xử lý tiền
            cnt++;
            if (lib[1] < 0 || lib[2] < 0 || lib[3] < 0) break;
            atp(x + 1);
            Libra(0); cnt--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    cin >> n >> mm >> lib[1] >> lib[2] >> lib[3];
    atp(1);
    cout << res;
}
