#include<bits/stdc++.h>

const int maxN = 1e5 + 5;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b)for(int i=a;i>=b;i--)
#define READ(F)   freopen(F".inp", "r", stdin)
#define WRITE(F)  freopen(F".out", "w", stdout)
#define FILL(a)   fill_n(a , maxN , 0)
#define ll        long long
#define F         "arrange"
#define pb        push_back

using namespace std;

int n, a[maxN], cnt = 0, temp, chk[maxN], cnt2 = 1, res = 0;
ll s = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    READ(F);
    WRITE(F);
    cin >> n;
    For(i, 1, n)
    {
        cin >> a[i];
        s += a[i];
    }
    if(s % n == 0)
    {
        temp = s / n;
        For(i, 1, n)
        if(a[i] > temp)
        {
            ++cnt;
            chk[cnt] = i;
        }
        For(i, 1, n)
        {
            while(a[i] < temp && cnt2 <= cnt)
            {
                if(a[chk[cnt2]] - temp >= temp - a[i])
                {
                    res += (abs(chk[cnt2] - i)) * (temp - a[i]);
                    a[chk[cnt2]] = a[chk[cnt2]] - temp + a[i];
                    a[i] = temp;
                }
                else
                {
                    res += (abs(chk[cnt2] - i)) * (a[chk[cnt2]] - temp);
                    a[i] = a[i] + a[chk[cnt2]] - temp;
                    a[chk[cnt2]] = temp;
                }
                if(a[chk[cnt2]] == temp) cnt2++;
            }
        }
        cout << res ;
        return 0;
    }
    else
    {
        temp = ceil(s /(long double) n);
        cnt2 = s - (temp - 1) * n;
        cnt  = n - cnt2;
        int dem = 0, dem2 = 0, l, h;
        For(i, 1, n)
        {
            if(dem < cnt && a[i] < temp - 1)
            {
                l = h = i;
                while(a[i] < temp - 1)
                {
                    l--;
                    if(a[l] > temp - 1)
                    {
                        if(a[l] - temp >= temp - a[i])
                        {
                            res += (abs(l - i)) * (temp - 1 - a[i]);
                            a[l] = a[l] - temp + 1 + a[i];
                            a[i] = temp - 1;
                        }
                        else
                        {
                            res += (abs(l - i)) * (a[l] - temp + 1);
                            a[i] = a[i] + a[l] - temp + 1;
                            a[l] = temp - 1;
                        }
                    }
                    else
                    {
                        h++;
                        if(a[h] > temp - 1)
                        {
                            if(a[h] - temp >= temp - a[i])
                            {
                                res += (abs(h - i)) * (temp - 1 - a[i]);
                                a[h] = a[h] - temp + 1 + a[i];
                                a[i] = temp - 1;
                            }
                            else
                            {
                                res += (abs(h - i)) * (a[h] - temp + 1);
                                a[i] = a[i] + a[h] - temp + 1;
                                a[h] = temp - 1;
                            }
                        }
                    }
                }
                dem++;
            }
            else dem++;
            if(dem == cnt) break;
        }
        For(i, 1, n)
        {
            if(dem2 < cnt2 && a[i] < temp)
            {
                l = h = i;
                while(a[i] < temp)
                {
                    l--;
                    if(a[l] > temp)
                    {
                        if(a[l] - temp >= temp - a[i])
                        {
                            res += (abs(l - i)) * (temp - a[i]);
                            a[l] = a[l] - temp + a[i];
                            a[i] = temp;
                        }
                        else
                        {
                            res += (abs(l - i)) * (a[l] - temp);
                            a[i] = a[i] + a[l] - temp;
                            a[l] = temp;
                        }
                    }
                    else
                    {
                        h++;
                        if(a[h] > temp)
                        {
                            if(a[h] - temp >= temp - a[i])
                            {
                                res += (abs(h - i)) * (temp - a[i]);
                                a[h] = a[h] - temp + a[i];
                                a[i] = temp;
                            }
                            else
                            {
                                res += (abs(h - i)) * (a[h] - temp);
                                a[i] = a[i] + a[h] - temp;
                                a[h] = temp;
                            }
                        }
                    }
                }
                dem2++;
            }
            else dem2++;
            if(dem2 == cnt2) break;
        }
    }
    cout << res / 2;
    return 0;
}
