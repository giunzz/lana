#include <bits/stdc++.h>
using namespace std;
int n;
long long in,sum,res;
vector <long long> pbl;
vector <int> mre,les;
int main(){
    freopen("ARRANGE.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> in;
        pbl.push_back(in);
        sum+=in;
    }
    if(sum%n==0){
        for(int i=0;i<n;i++)
            if(pbl[i]>sum/n)
                mre.push_back(i);
            else
                if(pbl[i]<sum/n)
                    les.push_back(i);
        int j=0;
        for(int i=0;i<mre.size();i++)
            while(pbl[mre[i]]>sum/n){
                if(pbl[mre[i]]+pbl[les[j]]>=sum/n*2){
                    res=res+(sum/n-pbl[les[j]])*abs(mre[i]-les[j]);
                    pbl[mre[i]]-=(sum/n-pbl[les[j]]);
                    j++;
                }
                else{
                    pbl[les[j]]+=(pbl[mre[i]]-sum/n);
                    pbl[mre[i]]=sum/n;
                }
            }
        cout << res;
    }
}
