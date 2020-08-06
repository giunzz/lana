/*include <bits/stdc++.h>
#include<iostream>
#include<map>
#include <stdio.h>
using namespace std;
int n , x[6007], y[6007] , ans = 0;
map<int,map<int,bool>> d ;
map<int,map<int,bool>> dd;


void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    fastscan(n);
    //cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        fastscan(x[i]);
        fastscan(y[i]);
        //cin >> x[i] >> y[i];
        d[x[i]][y[i]] = 1;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i + 1 ; j <= n ; j++)
        {
            if ( x[i] != x[j]  &&  y[i] != y[j]  ) 
            {
                if (d[x[j]][y[i]] == 1 && d[x[i]][y[j]] == 1)
                {
                        dd[x[i]][y[i]] = 1;
                        dd[x[j]][y[j]] = 1;
                        dd[x[j]][y[i]] = 1;
                        dd[x[i]][y[j]] = 1;
                        ans++;
                }
                
            }
        }
    }
    cout << ans/2;
}*/
//#include <bits/stdc++.h>
#include<iostream>
#include<map>
#include <stdio.h>
#include<algorithm>
using namespace std;
int n , ans = 0;
struct po
{
    int x,y;
}a[(int) 6e3+7];

bool operator<(po const A , po const C)
{
    return A.x < C.x || (A.x == C.x && A.y < C.y);
}
map <po,bool> dd;

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    }   
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    fastscan(n);
    //cin >> n ;
    for (int i = 1 ; i <= n ; i++) 
    {
        fastscan(a[i].x);
        fastscan(a[i].y);
        //cin >> x[i] >> y[i];
        dd[a[i]] = 1;
    }
    sort (a+1,a+1+n);   
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = i + 1 ; j <= n ; j++)
        {
            if ( a[i].x < a[j].x && a[i].y < a[j].y  ) 
            {
                po p1 = {a[j].x , a[i].y} , p2 = {a[i].x , a[j].y};
                if ( dd[p1] & dd[p2]) ans++;
            }
        }
    }
    cout << ans;
}