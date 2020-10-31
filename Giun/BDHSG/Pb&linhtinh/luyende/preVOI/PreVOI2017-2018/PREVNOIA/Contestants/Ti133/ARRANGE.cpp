#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
long long a[N];
long long val;

long long solve(int l, int r){
	if(l == r){
		return 0;
	}

	int mid = (l + r) >> 1;
	long long sumLef = 0, sumRig = 0;

	for(int i = l; i <= mid; ++i){
		sumLef += a[i];
	}
	for(int i = mid + 1; i <= r; ++i){
		sumRig += a[i];
	}

	int lenLef = mid - l + 1, lenRig = r - mid;

	long long ans = 0;

	if(sumLef < sumRig){
		long long take = max(max(1LL * val * lenLef - sumLef, sumRig - 1LL * (val + 1) * lenRig), 0LL);
		for(int i = mid + 1; i <= r; ++i){
			long long give = min(take, 1LL * a[i]);
			ans += give * (i - mid);
			a[i] -= give;
			a[mid] += give;
			take -= give;
			sumRig -= give;
			sumLef += give;
		}
	
		for(int i = mid - 1; i >= l; --i){
			if(a[mid] <= val + 1) break;
			if(a[i] < val){
				long long give = min(a[mid] - val - 1, val - a[i]);
				ans += 1LL * (mid - i) * give;
			}
		}

		int low = 0, high = 0, pter = mid + 1, ok = 0;	
		long long prefix = a[pter];

		for(int i = mid - 1; i >= l; --i){
			long long limUp = 1LL * (val + 1) * lenLef - sumLef;
			long long limDown = sumRig - 1LL * val * lenRig;

			if(limUp == 0 || limDown == 0) break;
			if(a[i] > val) continue;

			if(low == 0){
				low = i;
				high = i;
			}

			low = min(low, i);
			
			while(a[i] < val){
				while(low > 0 && a[low] <= val) --low;
				while(high <= mid && a[high] <= val) ++high;
				while(pter <= r && prefix <= 1LL * (pter - mid) * val) prefix += a[++pter];

				if(high <= mid){
					if(low == 0 || i - low >= high - i){
						long long recieve = val - a[i];
						recieve = min(recieve, a[high] - val);
						ans += recieve * 1LL * (high - i);
						a[i] += recieve;
						a[high] -= recieve;
					}
					else{
						long long recieve = val - a[i];
						recieve = min(recieve, a[low] - val);
						ans += 1LL * (i - low) * recieve;
						a[i] += recieve;
						a[low] -= recieve;
					}
				}
				else{
					if(pter <= r && (low == 0 || i - low >= pter - i)){
						long long recieve = val - a[i];
						recieve = min(recieve, a[pter]);
						recieve = min(recieve, limUp);
						recieve = min(recieve, limDown);
						ans += recieve * (pter - i);
						a[i] += recieve;
						a[pter] -= recieve;
						sumLef += recieve;
						sumRig -= recieve;
						prefix -= recieve;
					}
					else{
						long long recieve = val - a[i];
						recieve = min(recieve, a[low] - val);
						ans += 1LL * (i - low) * recieve;
					}
				}
			}

			if(pter > r) break;
		}
	}	
	else{	
		long long take = max(max(1LL * val * lenRig - sumRig, sumLef - 1LL * (val + 1) * lenLef), 0LL);
		for(int i = mid; i >= l; --i){
			long long give = min(take, 1LL * a[i]);
			ans += give * (mid + 1 - i);
			a[i] -= give;
			a[mid + 1] += give;
			take -= give;
			sumLef -= give;
			sumRig += give;
		}
	
		for(int i = mid + 2; i <= r; ++i){
			if(a[mid + 1] <= val + 1) break;
			if(a[i] < val){
				long long give = min(a[mid + 1] - val - 1, val - a[i]);
				ans += 1LL * (i - mid + 1) * give;
			}
		}


		int low = 0, high = 0, pter = mid, ok = 0;	
		long long prefix = a[pter];

		for(int i = mid + 1; i <= r; ++i){
			long long limUp = 1LL * (val + 1) * lenRig - sumRig;
			long long limDown = sumLef - 1LL * val * lenLef;

			if(limUp == 0 || limDown == 0) break;
			if(a[i] > val) continue;

			if(low == 0){
				low = i;
				high = i;
			}

			high = max(high, i);
			
			while(a[i] < val){
				while(low > mid && a[low] <= val) --low;
				while(high <= r && a[high] <= val) ++high;
				while(pter >= 0 && prefix <= 1LL * (mid - pter + 1) * val) prefix += a[--pter];

				if(low > mid){
					if(high > r || i - low <= high - i){
						long long recieve = val - a[i];
						recieve = min(recieve, a[low] - val);
						ans += recieve * 1LL * (low - i);
						a[i] += recieve;
						a[low] -= recieve;
					}
					else{
						long long recieve = val - a[i];
						recieve = min(recieve, a[high] - val);
						ans += 1LL * (i - high) * recieve;
						a[i] += recieve;
						a[high] -= recieve;
					}
				}
				else{
					if(pter > 0 && (high > r || high - i >= i - pter)){
						long long recieve = val - a[i];
						recieve = min(recieve, a[pter]);
						recieve = min(recieve, limUp);
						recieve = min(recieve, limDown);
						ans += recieve * (pter - i);
						a[i] += recieve;
						a[pter] -= recieve;
						sumLef -= recieve;
						sumRig += recieve;
						prefix -= recieve;
					}
					else{
						long long recieve = val - a[i];
						recieve = min(recieve, a[high] - val);
						a[i] += recieve;
						a[high] -= recieve;
						ans += 1LL * (i - low) * recieve;
					}
				}
			}

			if(pter < 1) break;
		}

	}

	return ans + solve(l, mid) + solve(mid + 1, r);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}
	else{
		freopen("arrange.inp", "r", stdin);
		freopen("arrange.out", "w", stdout);
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%lld", a + i);
		val += a[i];
	}

	val /= n;


	cout << solve(1, n);

	return 0;
}