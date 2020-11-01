#include <vector>
#include <algorithm>

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

struct sum_info {
	size_t index;
	long long value;
};

int main() {
	size_t n, k; std::cin >> n >> k;

	std::vector<int> data (n);
	for (int& x : data) std::cin >> x;

	std::vector<long long> sum (n - k + 1);
	sum[0] = 0; for (size_t i = 0; i < k; ++i) sum[0] += data[i];

	std::vector<sum_info> sum_values (1, {0, sum[0]});
	sum_values.reserve(sum.size());
	for (size_t i = 1; i < sum.size(); ++i) {
		sum[i] = sum[i-1] - data[i-1] + data[i-1+k];
		sum_values.push_back({i, sum[i]});
	}

	std::sort(sum_values.begin(), sum_values.end(), [](sum_info a, sum_info b){
		return a.value > b.value;
	});

	size_t min_sum_index = 999999999, max_sum_index = 0;

	size_t delta = 2*k-1;
	for (sum_info x : sum_values) {
		min_sum_index = std::min(min_sum_index, x.index);
		max_sum_index = std::max(max_sum_index, x.index);
		if (max_sum_index >= min_sum_index + delta) {
			std::cout << x.value << '\n';
			return 0;
		}
	}

	// this should be unreachable because k <= n/3
}

// 10 2 1 2 4 5 2 4 2 2 1 6
