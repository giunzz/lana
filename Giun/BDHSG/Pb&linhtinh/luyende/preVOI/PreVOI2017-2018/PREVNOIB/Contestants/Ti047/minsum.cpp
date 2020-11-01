
//{
#ifdef _GLIBCXX_DEBUG
	#include <iostream>
#else
	#define NDEBUG
	#include <fstream>
	std::string const name = [](const std::string fullname)->std::string{
		size_t first = 1 + fullname.find_last_of( /* any of */ "/\\");
		size_t dot = fullname.find_first_of('.', first);
		return fullname.substr(first, dot - first);
	}(__FILE__); // calculate in runtime, unfortunately
	namespace std {
		std::ifstream cin ((::name + ".inp").c_str());
		std::ofstream cout ((::name + ".out").c_str());
	}
#endif //} _GLIBCXX_DEBUG

#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> factor (int x) {
	std::vector<int> ans;
	while (x % 2 == 0) { ans.push_back(2); x /= 2; }
	for (int p = 3; p * p <= x; p += 2) {
		while (x % p == 0) { ans.push_back(p); x /= p; }
	}
	if (x != 1) ans.push_back(x);
	return ans;
}

std::vector<long long> divisors (std::vector<int> const & pfactors) {
	// pfactors xhould contains non-duplicate prime factors
	std::vector<long long> ans = {{1}};
	ans.reserve(1 << pfactors.size());

	for (int x : pfactors) {
		for (size_t a = ans.size(); a --> 0;) {
			ans.push_back(ans[a] * (long long)x);
		}
	}

	return ans;
}

template <class T>
std::vector<T> sorted(std::vector<T> x) {
	std::sort(x.begin(), x.end());
	return x;
}

int main() {
	int ntest; std::cin >> ntest;
	while (ntest --> 0) {
		int a, b; std::cin >> a >> b;
		std::vector<int> fa = factor(a), fb = factor(b);
		std::vector<int> f (fa.size() + fb.size());
		std::merge(fa.begin(), fa.end(), fb.begin(), fb.end(), f.begin());

		fa.clear();
		for (int x : f) {
			if (!fa.empty() && fa.back() == x)
				fa.pop_back();
			else
				fa.push_back(x);
		}

		long long product = 1;
		for (int x : fa) product *= x;

		if (product == 1) { std::cout << "1 1\n"; continue; }

		int n = fa.size() / 2;
		fb.assign(fa.begin() + n, fa.end());
		fa.resize(n);

		std::vector<long long> pa = sorted(divisors(fa)), pb = sorted(divisors(fb));

		long long sqrt = std::sqrt(product);
		while (sqrt * sqrt <= product) ++sqrt;
		while (sqrt * sqrt >  product) --sqrt;
		// now sqrt is the largest number
		// <= /* mathematical */ sqrt(product)

		// the 2 printed numbers are factor of (product), one of
		// them are <= sqrt(product) (and hence <= sqrt)
		size_t ptr = pa.size() - 1;
		long long maxA = 1;
		for (long long x : pb) {
			while (ptr + 1 != 0 && pa[ptr] * x > sqrt) --ptr;
			if (ptr + 1 != 0) // ==> pa[ptr] * x <= sqrt
				maxA = std::max(maxA, pa[ptr] * x);
			else // ptr == -1 now, and will only decrease later
				break;
		}

		std::cout << maxA << ' ' << product / maxA << '\n';
	}
}

// 1 434013700 954742052
