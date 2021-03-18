// #include<bits/stdc++.h>
// using namespace std;
// int x[30],dem=0,sum=0,best=30,n,maxa[30],a[30],s;
// void capnhat()
// {
//     if (sum==s && best>dem) best=dem;
// }

// void qlui(int i)
// {
//     for(int j=0;j<=1;j++)
//     {
//         x[i]=j;
//         sum+=x[i]*a[i];
//         dem+=j;
//         if (i==n) capnhat();
//         else if(dem+(s-sum)/maxa[i+1]<best) qlui(i+1);
//         sum-=x[i]*a[i];
//         dem-=j;
//     }
// }
// int main()
// {
//     freopen("atm.inp","r",stdin);
//     freopen("atm.out","w",stdout);
//     cin>>n>>s;
//     for(int i=1;i<=n;i++) cin>>a[i];
//     maxa[n]=a[n];
//     for(int i=n-1;i>=1;i--)maxa[i]=max(a[i],maxa[i+1]);
//     //for(int i=1;i<=n;i++)cout<<maxa[i]<<" ";
//     //cout<<endl;
//     qlui(1);
//     if (best==30) cout<<-1;
//     else cout<<best;
//     return 0;
// }
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int MAX_LENGTH = 20;
const int MAX_SUM = 105;
long long f[MAX_LENGTH][MAX_SUM][3];
string N;
int S;

void solve() {
  for (int d = 1; d <= 9; d++) {
    if (d < N[0] - '0') {
      f[1][d][0] = 1;
    }
    else if (d == N[0] - '0') {
      f[1][d][1] = 1;
    }
    else {
      f[1][d][2] = 1;
    }
  }
  int len = (int) N.size();
  for (int i = 1; i < len; i++) {
    for (int sum = 0; sum <= S; sum++) {
      for (int status = 0; status <= 2; status++) {
        if (f[i][sum][status] == 0) {
          continue;
        }
        for (int d = 0; d <= 9; d++) {
          int newSum = sum + d;
          int newStatus;
          if (status == 0) {
            newStatus = 0;
          }
          else if (status == 2) {
            newStatus = 2;
          }
          else {
            if (d < N[i] - '0') {
              newStatus = 0;
            }
            else if (d == N[i] - '0') {
              newStatus = 1;
            }
            else {
              newStatus = 2;
            }
          }
          f[i + 1][newSum][newStatus] += f[i][sum][status];
          cerr << f[i+1][newSum][newStatus] << " " << f[i][sum][status] << endl;
        }
      }
    }
  }
  long long ans = 0LL;
  for (int i = 1; i <= len; i++) {
    int maxStatus = 1;
    if (i < len) {
      maxStatus = 2;
    }
    for (int status = 0; status <= maxStatus; status++) {
      ans += f[i][S][status];
    }
  }
  cout << ans;
}

int main () {
  freopen("giun.inp", "r", stdin);
  freopen("giun1.out", "w", stdout);
  cin >> N >> S;
  solve();
  return 0;
}