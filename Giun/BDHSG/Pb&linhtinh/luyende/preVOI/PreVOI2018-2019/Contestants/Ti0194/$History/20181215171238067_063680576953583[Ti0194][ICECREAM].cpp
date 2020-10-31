#include <iostream>
using namespace std;
const int maxn = 1e5 + 1;
int n, m[maxn],cnt, chk[maxn], low, high;
int mmax;

void Attempt(int i)
{
    bool chka = true;
    bool chkb = true;
    if (i == n)
        return;
    for (int k = 1; k <= 3 ; k++)
    {
        if (k == 1)
        {
            if (m[k] + 1 > mmax)
                chk[k] = false;
            if (chk[k])
            {
                m[k]++;
                Attempt(i + 1);
                m[k]--;
                //chk[1] = true;
            }
        }
        if (k == 2 && m[1] >= 1)
        {
            if (m[2] + 1 > mmax)
                chk[2] = false;
            if (chk[2])
            {
                m[2]++;
                m[1]--;
                Attempt(i + 1);
                m[2]--;
                m[1]++;
               //chk[2] = true;
            }
        }
        if (k == 3 && m[1] >= 0 && m[2] >= 0)
        {
            if (m[3] + 1 > mmax)
                chk[3] = false;
            if (chk[3])
            {
                if (m[1] >= 1 && m[2] >= 1)
                {
                    m[3]++;
                    m[1]--;
                    m[2]--;
                    chka = false;
                    //Attempt(i + 1);
                    //continue;
                }
                if (m[2] == 0 && m[1] >= 3)
                {
                    m[3]++;
                    m[1] -= 3;
                    chkb = false;
                    //Attempt(i + 1);
                    //continue;
                }
                    Attempt(i + 1);

                //chk[3] = true;
                if (chka == false)
                {
                    m[1]++;
                    m[2]++;
                    m[3]--;
                    chka = true;
                }
                if (chkb == false)
                {
                    m[1] += 3;
                    m[3]--;
                    chkb = true;
                }
            }
        }
    }
    cnt++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    cin >> n >> mmax;
    cin >> m[1] >> m[2] >> m[3];
    fill_n(chk,maxn,true);
    Attempt(0);
    cout << cnt;
}

