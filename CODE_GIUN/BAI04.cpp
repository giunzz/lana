#include<bits/stdc++.h>

using namespace std;

pair <int, int> dem[1009];

int n , x, y ;
double  mi = DBL_MAX , kq[1009];

float dodai(int o1,int o2 , int p1 , int p2)
{
    float d = sqrt( pow(o1-o2,2) + pow (p1-p2,2)); 
    //d = round( d * 1000.0 ) / 1000.0;
    //double rounded = (int)(d * 1000.0)/1000.0;
    return d ;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("bai04.inp","r",stdin);
    freopen("bai04.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x >> y;
        dem[i].first = x;  // hoành độ
        dem[i].second = y; // tung độ
    }

    //for (int i = 1 ; i <= n  ; i++) cerr << dem[i].first << " " << dem[i].second << endl;

    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (i != j  ) kq[i] += dodai(dem[i].first , dem[j].first ,dem[i].second , dem[j].second); 
        }
        mi = min(mi,kq[i]);
    }

    //for (int i = 1 ; i <= n ; i++) printf("%0.3f " , kq[i]);
    //printf("\n");

    for (int i = 1 ; i <= n ; i++)
    {
        if (kq[i] == mi ) 
        {
            printf("%d %0.3f" , i, mi);
            return 0;
        }
    }
   
}