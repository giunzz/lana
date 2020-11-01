#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int cd1,cd2,a[100000],b[100000],need;
vector <int> result,kq;
int ok[401][401][401];
void inp()
{
    cin >> cd1 >> cd2 >> need;
    for (int i = 1 ; i <= cd1 ; i++) cin >> a[i];
    for (int i = 1 ; i <= cd2 ; i++) cin >> b[i];
}
void do_it(int t , int l1 , int l2)
{
   // if (ok[t][l1][l2] == 1) return;
    //ok[t][l1][l2] = 1;
    if (t > need)
    {
        if (result.size() == 0) result = kq;
        else
        for (int i = 0 ; i < need ; i++)
        {
            if (result[i] != kq[i] &&result[i] > kq[i])
            {
                result = kq;
                return;
            }
            if (result[i] != kq[i]) return;
        }
        return;
    }
    if (l1 <= cd1)
    {
        kq.push_back(a[l1]);
        do_it(t+1 , l1+1,l2);
        kq.pop_back();
    }
    if (l2 <= cd2)
    {
        kq.push_back(b[l2]);
        do_it(t+1,l1,l2+1);
        kq.pop_back();
    }
    if (l1 <= cd1) do_it(t , l1+1 ,l2);
    if (l2 <= cd2) do_it(t , l1 , l2 +1);

}
main()
{
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
    inp();
    do_it(1,1,1);
    for (auto g : result) cout <<g<<" ";
}
