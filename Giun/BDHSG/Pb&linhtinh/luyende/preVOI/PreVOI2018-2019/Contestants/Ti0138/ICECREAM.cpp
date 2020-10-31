#include<iostream>
#include<cstdio>
#include<random>
using namespace std;

const int base = 1e9 + 9;
const int H = 3e7;
int cnt, Key, a[301], res;
int N, MMAX, M50, M1, M2;
bool TLE;
vector<int> Hash[15001];

void Input()
{
    cin >> N >> MMAX;
    cin >> M50 >> M1 >> M2;
}

bool LookingForRes(int posi, int key)
{
    for (int a : Hash[posi])
    if (a == key)
        return true;
    return false;
}

void MakeS(int num)
{
    cnt++;
    if (cnt > H)
    {
        TLE = true;
        return;
    }

    if (num > N)
    {
        int key = 0;
        int posi = 0;
        for (int i = 1; i <= N; i++)
        {
            key += a[i] * i;
            posi += a[i];
        }

        if (!LookingForRes(posi, key))
        {
            if (res + 1 == base)
                res = 0;
            else
                res++;
            Hash[posi].push_back(key);
        }
        return;
    }

    if (M50 + 1 <= MMAX)
    {
        M50++;
        a[num] = 50;
        MakeS(num + 1);
        if (TLE)
            return;
        M50--;
    }

    if (M1 + 1 <= MMAX && M50 >= 1)
    {
        M1++;
        M50--;
        a[num] = 1;
        MakeS(num + 1);
        if (TLE)
            return;
        M1--;
        M50++;
    }

    if (M2 + 1 <= MMAX)
    {
        if (M1 >= 1 && M50 >= 1)
        {
            M1--;
            M50--;
            M2++;
            a[num] = 2;
            MakeS(num + 1);
            if (TLE)
                return;
            M1++;
            M50++;
            M2--;
        }
        else
        {
            if (M50 >= 3)
            {
                M50 -= 3;
                M2++;
                a[num] = 2;
                MakeS(num + 1);
                if (TLE)
                    return;
                M50 += 3;
                M2--;
            }
        }
    }
}

void Solve()
{
    cnt = 0;
    TLE = false;
    MakeS(1);
}

void Output()
{
    if (TLE)
        res = (rand() % base + N + MMAX + M50 + M1 + M2) % base;
    else
        cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("ICECREAM.INP" , "r" , stdin);
    freopen("ICECREAM.OUT" , "w" , stdout);

    Input();
    Solve();
    Output();
}

