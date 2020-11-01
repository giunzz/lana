#define task "LIONDANCE"
#include <bits/stdc++.h>
using namespace std;

int n, del, a[4005], b[4005], res[4005], phu[4005], f[4005][4005], t, out, i, j, luui = 1, luuj = 1, pre;
bool ch = 0;

void atp (int x)
{
    if ((i == n || j == n) && t >= out)
    {
        for (int i = 1; i <= t; i++)
        {
            if (res[i] < phu[i])
            {
                ch = 1;
                out = t; break;
            }
            else if (res[i] > phu[i])
                return;
        }
        if (ch == 1)
        {
            for (int i = 1; i <= t; i++)
                res[i] = phu[i];
            ch = 0;
        }
        return;
    }
    for (i = luui, j = luuj; i <= n && j <= n;) //Chưa truy đến cơ sở
    {
        if (a[i] == b[j])
        {
            phu[++t] = a[i]; //Chọn luôn a[i]
            ++i;
            ++j; //Truy tiếp f[i + 1][j + 1]
            luui = i; luuj = j;
            atp(x + 1);
             t--;
        }
        else //truy tiếp f[i + 1][j] hoặc f[i][j + 1] tùy theo giá trị nào lớn hơn
            f[i][j] == f[i + 1][j] ? ++i : ++j;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    cin >> n >> del;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = n; i >= 1; --i) //Tính từ hàng dưới lên hàng trên
        for (int j = n; j >= 1; --j) //Trên mỗi hàng tính từ phải qua trái
        {
             if (a[i] == b[j])
            {
                f[i][j] = f[i + 1][j + 1] + 1;
                //pre = a[i];
            }
            else
                f[i][j] = max(f[i + 1][j], f[i][j + 1]);
        }
    atp(1);
    cout << out << '\n';
    for (int i = 1; i <= out; i++)
        cout << res[i] << ' ';
}
