#include <iostream>
#include <string>
using namespace std;

<<<<<<< HEAD
int main() 
{
	//int T,i,lo,index_A = 0,index_B = 0,len_A,len_B;
	//string A,B,small;
	//char final[200010];
	int T,i;
	cin>>T;
	for(i=0;i<T;i++)
	{
		int T,i,lo,index_A = 0,index_B = 0,len_A,len_B,n;
		string A,B,small;
		char final[200010];
		cin>>A>>B;
		len_A = A.length();
		len_B = B.length();
		A.push_back('a');
		B.push_back('b');
		//lo = len_A < len_B ? len_A : len_B;
		//small = len_A < len_B ? A : B;
		for(i = 0 ; i < len_A + len_B ; i++)
		{
			if((int)A[index_A] < (int)B[index_B])
			{
				final[i] = A[index_A];
				index_A ++;
			}
			else if((int)A[index_A] > (int)B[index_B])
			{
				final[i] = B[index_B];
				index_B ++;
			}
			else
			{
				n = 0;
				while((int)A[index_A] == (int)B[index_B])
				{
					index_A ++;
					index_B ++;
					n++;
				}
				if((int)A[index_A] < (int)B[index_B])
				{
					index_A -= n;
					index_B -= n;
					final[i] = A[index_A];
					index_A ++;
				}
				else if((int)A[index_A] > (int)B[index_B])
				{
					index_A -= n;
					index_B -= n;
					final[i] = B[index_B];
					index_B ++;
				}
                cerr << index_A << ' ' << index_B << '\n';
			}
		}
		for(i = 0 ; i < len_A + len_B ; i++)
		{
			cout<<final[i];
		}
		cout<<endl;
	}
	return 0;
=======
void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

// int Phi(int n) { // = n (1-1/p1) ... (1-1/pn)
//     if (n == 0) return 0;
//     int ans = n;
//     for (int x = 2; x*x <= n; ++x) {
//         if (n % x == 0) {
//             ans -= ans / x;
//             while (n % x == 0) n /= x;
//         }
//     }
//     if (n > 1) ans -= ans / n;
//     return ans;
// }

struct quang{
    ll a, b;
    bool operator<(quang const &x) const{
        return a < x.a || (a == x.a && b > x.b);
    }
    bool operator>(quang const &x) const{
        return x < *this;
    }
};

ll cnt(ll x, ll y){
    ll tmp = 0;
    while(x / y){
        tmp += x / y;
        y *= y;
    }
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // priority_queue<quang, vec(quang), greater<quang>> q;
    // // OF();
    // // lp(i, 1, 75){
    // //     if(75 % i == 0) cout << i << ' ';
    // // }
    // q.push(quang{1, 3});
    // q.push(quang{2, 3});
    // q.push(quang{1, 4});
    // q.push(quang{1, 1});
    // while(q.size()){
    //     cerr << q.top().a << ' ' << q.top().b << '\n';
    //     q.pop();
    // }
    cerr << __gcd(-2, 6);
>>>>>>> 1213466bc19fd3c6d4e722f67454f08cffd28a08
}