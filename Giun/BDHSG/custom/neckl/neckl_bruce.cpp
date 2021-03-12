#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <climits>
using namespace std;
typedef long long ll;
ll n,s1,s2,resMax,resMin;
string s,tmp,tmp2,t;
int chuyen(char c,bool kt){
	if (kt==0)
		if (c=='B')
			return 0;
		else
			return 1;
	if (c=='B')
		return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("neckl.inp","r",stdin); freopen("neckl.ans","w",stdout);
	cin >> s;
	n=s.size();
	resMax=0;
	resMin=INT_MAX;
	for (int i=0;i<n;i++){
		tmp=s.substr(0,i);
		tmp2=s.substr(i,n-i);
		t=tmp2+tmp;
		s1=s2=0;
		for (int j=0;j<n;j++){
			s1+=chuyen(t[j],0)*pow(2,n-j-1);
			s2+=chuyen(t[j],1)*pow(2,n-j-1);
		}
		resMax=max(resMax,max(s1,s2));
		resMin=min(resMin,min(s1,s2));
	}
	reverse(s.begin(),s.end());
	for (int i=0;i<n;i++){
		tmp=s.substr(0,i);
		tmp2=s.substr(i,n-i);
		t=tmp2+tmp;
		s1=s2=0;
		for (int j=0;j<n;j++){
			s1+=chuyen(t[j],0)*pow(2,n-j-1);
			s2+=chuyen(t[j],1)*pow(2,n-j-1);
		}		
		resMax=max(resMax,max(s1,s2));
		resMin=min(resMin,min(s1,s2));
	}
	cout << resMin << " " << resMax;
	return 0;
}