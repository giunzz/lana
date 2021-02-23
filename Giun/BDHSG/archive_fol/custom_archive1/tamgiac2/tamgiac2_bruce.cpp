// C++ program to find the number of 
// triangles that can be formed 
// using a set of lines in Euclidean 
// Plane 
#include <bits/stdc++.h> 
using namespace std; 
#define Fname "tamgiac2"

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".ans", "w", stdout);
}

#define EPSILON numeric_limits<double>::epsilon() 

// double variables can't be checked precisely 
// using '==' this function returns true if 
// the double variables are equal 
bool compareDoubles(double A, double B) 
{ 
	double diff = A-B; 
	return (diff<EPSILON) && (-diff<EPSILON); 
} 

// This function returns the number of triangles 
// for a given set of lines 
int numberOfTringles(int a[], int b[], int c[], int n) 
{ 
	//slope array stores the slope of lines 
	double slope[n]; 
	for (int i=0; i<n; i++) 
		slope[i] = (a[i]*1.0)/b[i]; 

	// slope array is sorted so that all lines 
	// with same slope come together 
	sort(slope, slope+n); 

	// After sorting slopes, count different 
	// slopes. k is index in count[]. 
	int count[n], k = 0; 
	int this_count = 1; // Count of current slope 
	for (int i=1; i<n; i++) 
	{ 
		if (compareDoubles(slope[i], slope[i-1])) 
			this_count++; 
		else
		{ 
			count[k++] = this_count; 
			this_count = 1; 
		} 
	} 
	count[k++] = this_count; 

	// calculating sum1 (Sum of all slopes) 
	// sum1 = m1 + m2 + ... 
	int sum1 = 0; 
	for (int i=0; i<k; i++) 
		sum1 += count[i]; 

	// calculating sum2. sum2 = m1*m2 + m2*m3 + ... 
	int sum2 = 0; 
	int temp[n]; // Needed for sum3 
	for (int i=0; i<k; i++) 
	{ 
		temp[i] = count[i]*(sum1-count[i]); 
		sum2 += temp[i]; 
	} 
	sum2 /= 2; 

	// calculating sum3 which gives the final answer 
	// m1 * m2 * m3 + m2 * m3 * m4 + ... 
	int sum3 = 0; 
	for (int i=0; i<k; i++) 
		sum3 += count[i]*(sum2-temp[i]); 
	sum3 /= 3; 

	return sum3; 
} 

const int maxn = 3e5 + 7;
long long a[maxn], b[maxn], c[maxn];

#define ll long long
#define lp(a, b, c) for(ll a = b; a <= c; ++a)

bool ch(ll x, ll y, ll xp, ll yp){
    return x * yp != y * xp;
}

// Driver code 
int main() 
{ 
	// lines are stored as arrays of a, b 
	// and c for 'ax+by=c' 
    OF();
    ll n;  
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
	// n is the number of lines 
	// int n = sizeof(a)/sizeof(a[0]); 
    ll res = 0;
    lp(i, 0, n - 1){
        lp(j, i + 1, n - 1){
            lp(z, j + 1, n - 1){
                if(ch(a[i], b[i], a[j], b[j]) && ch(a[z], b[z], a[j], b[j]) && ch(a[i], b[i], a[z], b[z])) ++res;
            }
        }
    } 
    cout << res;
	return 0; 
} 