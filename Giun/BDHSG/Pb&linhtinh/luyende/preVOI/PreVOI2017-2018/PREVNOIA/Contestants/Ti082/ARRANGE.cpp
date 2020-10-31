#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
template<typename T> inline void read(T &x)
{
        char c;
        bool neg = false;
        while (!isdigit(c = getchar()) && c != '-');
        x = 0;
        if (c == '-')
        {
                neg = true;
                c = getchar();
        }
        do
        {
                x = x * 10 + c - '0';
        }
        while (isdigit(c = getchar()));
        if (neg) x = -x;
}
template<typename T> inline void write(T x)
{
        if (x < 0)
        {
                putchar('-');
                write(-x);
                return;
        }
        if (x < 10)
        {
                putchar(char(x + 48));
        }
        else
        {
                write(x/10);
                putchar(char(48 + x%10));
        }
}
template<typename T> inline void writeln(T x)
{
        write(x);
        putchar('\n');
}
int n,a[maxn],val,TMP[maxn];
ll sum,res1,res2,res3,res4;
void sub2()
{
/////////////////////////////////////////////////////////////////1
        for (int i=1; i<=n; ++i)
        {
                if (a[i]>=val) continue;
                int t1=i,t2=i;
                while(a[i]<val)
                {
                        if (t1>1)
                        {
                                t1--;
                                int tmp=min(a[t1]-val,val-a[i]);
                                a[t1]-=tmp;
                                a[i]+=tmp;
                                res1+=1ll*(i-t1)*tmp;
                        }
                        if (a[i]>=val) break;
                        if (t2<n)
                        {
                                t2++;
                                if (a[t2]<=val) continue;
                                int tmp=min(a[t2]-val,val-a[i]);
                                a[t2]-=tmp;
                                a[i]+=tmp;
                                res1+=1ll*(t2-i)*tmp;
                        }
                }
        }
        for (int i=1; i<=n; ++i)
        {
                if (a[i]<=val+1) continue;
                int t1=i,t2=i;
                while(a[i]>val+1)
                {
                        if (t2<n)
                        {
                                ++t2;
                                if (a[t2]==val)
                                {
                                        a[i]--;
                                        a[t2]++;
                                        res1+=(t2-i);
                                }
                        }
                        if (a[i]<=val+1) break;
                        if (t1>1)
                        {
                                --t1;
                                if (a[t1]==val)
                                {
                                        a[i]--;
                                        a[t1]++;
                                        res1+=(i-t1);
                                }
                        }
                }
        }
//////////////////////////////////////////////////////////////////////4
        for (int i=1; i<=n; ++i)
                a[i]=TMP[i];
        for (int i=n; i>=1; --i)
        {
                if (a[i]>=val) continue;
                int t1=i,t2=i;
                while(a[i]<val)
                {
                        if (t1>1)
                        {
                                t1--;
                                int tmp=min(a[t1]-val,val-a[i]);
                                a[t1]-=tmp;
                                a[i]+=tmp;
                                res4+=1ll*(i-t1)*tmp;
                        }
                        if (a[i]>=val) break;
                        if (t2<n)
                        {
                                t2++;
                                if (a[t2]<=val) continue;
                                int tmp=min(a[t2]-val,val-a[i]);
                                a[t2]-=tmp;
                                a[i]+=tmp;
                                res4+=1ll*(t2-i)*tmp;
                        }
                }
        }
        for (int i=1; i<=n; ++i)
        {
                if (a[i]<=val+1) continue;
                int t1=i,t2=i;
                while(a[i]>val+1)
                {
                        if (t2<n)
                        {
                                ++t2;
                                if (a[t2]==val)
                                {
                                        a[i]--;
                                        a[t2]++;
                                        res4+=(t2-i);
                                }
                        }
                        if (a[i]<=val+1) break;
                        if (t1>1)
                        {
                                --t1;
                                if (a[t1]==val)
                                {
                                        a[i]--;
                                        a[t1]++;
                                        res4+=(i-t1);
                                }
                        }
                }
        }
//////////////////////////////////////////////////////////////////////2
        for (int i=1; i<=n; ++i)
                a[i]=TMP[i];
        for (int i=n; i>=1; --i)
        {
                if (a[i]>=val) continue;
                for (int j=n; j>=1; --j)
                {
                        if (a[j]<=val) continue;
                        int tmp=min(a[j]-val,val-a[i]);
                        a[j]-=tmp;
                        a[i]+=tmp;
                        res2+=1ll*abs(i-j)*tmp;
                        if (a[i]>=val) break;
                }
        }
        for (int i=1; i<=n; ++i)
        {
                if (a[i]<=val+1) continue;
                int t1=i,t2=i;
                while(a[i]>val+1)
                {
                        if (t2<n)
                        {
                                ++t2;
                                if (a[t2]==val)
                                {
                                        a[i]--;
                                        a[t2]++;
                                        res2+=(t2-i);
                                }
                        }
                        if (a[i]<=val+1) break;
                        if (t1>1)
                        {
                                --t1;
                                if (a[t1]==val)
                                {
                                        a[i]--;
                                        a[t1]++;
                                        res2+=(i-t1);
                                }
                        }
                }
        }
///////////////////////////////////////////////////////////////////////////////////3
        for (int i=1; i<=n; ++i)
                a[i]=TMP[i];
        for (int i=1; i<=n; ++i)
        {
                if (a[i]>=val) continue;
                for (int j=1; j<=n; ++j)
                {
                        if (a[j]<=val) continue;
                        int tmp=min(a[j]-val,val-a[i]);
                        a[j]-=tmp;
                        a[i]+=tmp;
                        res3+=1ll*abs(i-j)*tmp;
                        if (a[i]>=val) break;
                }
        }
        for (int i=1; i<=n; ++i)
        {
                if (a[i]<=val+1) continue;
                int t1=i,t2=i;
                while(a[i]>val+1)
                {
                        if (t2<n)
                        {
                                ++t2;
                                if (a[t2]==val)
                                {
                                        a[i]--;
                                        a[t2]++;
                                        res3+=(t2-i);
                                }
                        }
                        if (a[i]<=val+1) break;
                        if (t1>1)
                        {
                                --t1;
                                if (a[t1]==val)
                                {
                                        a[i]--;
                                        a[t1]++;
                                        res3+=(i-t1);
                                }
                        }
                }
        }
        write(min(min(res1,res4),min(res2,res3)));
}
int main()
{
        freopen("ARRANGE.inp","r",stdin);
        freopen("ARRANGE.out","w",stdout);
        cin.tie(0);
        cout.tie(0);
        read(n);
        for (int i=1; i<=n; ++i)
        {
                read(a[i]);
                sum+=a[i];
                TMP[i]=a[i];
        }
        val=sum/n;
        sub2();
}
