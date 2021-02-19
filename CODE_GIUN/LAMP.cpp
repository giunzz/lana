#include<iostream>
//#define giuncute freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout)
using namespace std;

int n , q , x , y , ans[100007] = {0};

int main()
{
    //giuncute;
    scanf("%d%d",&n,&q);
    //cin >> n >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        //cin >> x >> y;
        scanf("%d%d",&x,&y);
        for (int j = x ; j <= y ; j++)
        {
            if (ans[j] == 0) ans[j] = 1;
            else ans[j] = 0;
        }
    }
    for (int i = 1 ; i <= n ; i++) printf("%d ",ans[i]);
    return 0;
}