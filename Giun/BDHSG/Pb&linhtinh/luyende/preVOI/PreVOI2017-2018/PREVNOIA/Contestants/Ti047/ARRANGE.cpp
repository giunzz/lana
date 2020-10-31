#include <vector>
#include <climits>
#include <cstdlib>

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

long long const INF = LLONG_MAX / 2;

int main() {
	int n; std::cin >> n;
	std::vector<int> data (n);
	long long sum = 0;
	for (int& x : data) {
		std::cin >> x;
		sum += x;
	}

	long long norm_size = sum / n, mod = sum % n;

	bool use_mod_compl = mod * 2 > n;
//	bool use_mod_compl = false;

	if (use_mod_compl) {
		++norm_size;
		mod = n - mod;
	}

	std::vector<long long> dp (mod + 1, INF);
	dp[0] = 0;

	long long presum_adj = 0;
	for (int i = 0; i < n; ++i) {
		if (use_mod_compl) {
			presum_adj -= data[i] - norm_size;
		} else {
			presum_adj += data[i] - norm_size;
		}

		int j;
		for (j = mod; j > 0; --j) {
			dp[j] = std::min(dp[j], dp[j-1]) + std::abs(j - presum_adj);
		}
		dp[0] += std::abs(presum_adj);
	}

	std::cout << dp[mod] << '\n';

	return 0;
}
