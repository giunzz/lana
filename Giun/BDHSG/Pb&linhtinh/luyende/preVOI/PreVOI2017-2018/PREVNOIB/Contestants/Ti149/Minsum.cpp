#include <bits/stdc++.h>

using namespace std;

vector< int > factor;

void analyze(int A, int B)
{
    factor.clear();
    int cnt = 0;
    for(int i = 2; i <= sqrt(A); i++){
        cnt = 0;
        while(A % i == 0)
                cnt++, A/= i;
        while(B % i == 0)
                cnt++, B/= i;
        if (cnt & 1) factor.push_back(i);
    }
    for(int i = 2; i <= sqrt(B); i++){
        cnt = 0;
        while(A % i == 0)
                cnt++, A/= i;
        while(B % i == 0)
                cnt++, B/= i;
        if (cnt & 1) factor.push_back(i);
    }
    if (A > 1)
        if (B % A > 0) factor.push_back(A);
    if (B > 1)
        if (A % B > 0) factor.push_back(B);
}

void Solve(int A, int B)
{
    analyze(A, B);
    int n = factor.size();
    int nA, nB, ansA, ansB;
    ansA = A; ansB = B;
   // for(int i = 0; i < n; i++) cerr<< factor[i] <<' ';
   // cerr<<'\n';
    for(int st = 0; st < (1<<n); st++){
        nA = nB = 1;
        for(int i = 0; i < n; i++)
            if (st & (1<<i)) nA*= factor[i];
                else nB*= factor[i];
         if ((nA + nB) < (ansA + ansB)) ansA = nA, ansB = nB;
    }
    cout<< ansA <<' '<< ansB <<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("Minsum.inp","r",stdin);
    freopen("Minsum.out","w",stdout);

    int T, A, B;
    cin>> T;
    while(T--){
        cin>> A >> B;
        Solve(A, B);
    }
    return 0;
}
