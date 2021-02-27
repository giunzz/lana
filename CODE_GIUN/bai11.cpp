#include<bits/stdc++.h>
using namespace std;
int n , a[200][200] , m[200][200]  , c[200][200] , d[200][200] ;

void print_matrix(int x[200][200])
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 0 ; j < n ; j++) cout << x[i][j] << " ";
        cout << endl;
    }
}
void hoanvi(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
void sort_matrix(int m[200][200],int d,int c)
{
    for(int i=0;i<c*d-1;i++)
        for(int j=i+1;j<c*d;j++)
            if(m[i/c][i%c]>m[j/c][j%c])
                hoanvi(m[i/c][i%c],m[j/c][j%c]);
}

void sort_zigzac_ngang(int m[200][200] )
{
    int ok = 1;
    for (int i = 0 ; i < n ;i++)
    {
        if (ok == 1 )
        {
            for (int j = 0 ; j < n ; j++)
            {
                cout << m[i][j] << " ";
                a[i][j] = m[i][j];
            }
            ok = 2;
            cout << endl;
        }
        else
        {
            for (int j = n - 1 ; j >= 0 ; j--)
            {
                cout << m[i][j] << " ";
                a[i][n-j-1] = m[i][j];
            }
            cout << endl;
            ok = 1;
        }
    }
}
void sort_zigzac_doc(int a[200][200])
{
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        for (int j = n - 1 ; j >= 0 ; j--)
        cout  << a[j][i] << " ";
        cout << endl;
    }
}

void sort_xoa_oc(int c[200][200])
{
  int d = 0, i, gt = 1;
  int hang = n - 1, cot = n - 1;
  while(gt <= n*n)
    {
    for(i = d; i <= cot; i++) {
      c[d][i] = gt++; // gan tu trai sang phai
    }
    for(i = d+1; i <= hang; i++){
      c[i][cot] = gt++; // gan tu tren xuong duoi
    }
    for(i = cot-1; i>=d && gt <= n * n; i--){
      c[hang][i]=gt++; // tu phai sang trai
    }
    for(i = hang-1; i>d && gt <= n * n; i--){
      c[i][d] = gt++; // tu duoi len
    }
    d++; hang--; cot--;    // thu nho xoan oc
  }
  print_matrix(c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < n ; j++) cin >> m[i][j];
    sort_matrix(m,n,n);
    sort_zigzac_ngang(m);
    //print_matrix(a);
    sort_zigzac_doc(a);
    sort_xoa_oc(c);
}
