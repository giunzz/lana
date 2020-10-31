#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

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

std::vector<std::vector<int>> adjlist;
std::vector<int> value;

std::vector<int> dfs(int node) {
	if (adjlist[node].empty()) {
		return {value[node], std::abs(value[node] - 1)};
	}
	if (adjlist[node].size() == 1) {
		std::vector<int> ans = dfs(adjlist[node][0]);
		for (int i = ans.size(); i --> 0;)
			ans[i] += std::abs(i - value[node]);
		return ans;
	}
	// adjlist[node].size() == 2
	std::vector<int> v0 = dfs(adjlist[node][0]);
	std::vector<int> v1 = dfs(adjlist[node][1]);

	std::vector<int> ans (v0.size() + v1.size() - 1, INT_MAX);

	for (int i = v0.size(); i --> 0;) {
		for (int j = v1.size(); j --> 0;) {
			ans[i+j] = std::min(ans[i+j],
			v0[i] + v1[j] + std::abs(i+j - value[node])
			);
		}
	}
	return ans;
}

int main() {
	int nNode; std::cin >> nNode;
	adjlist.assign(nNode, {});
	value.resize(nNode); for (int& x : value) std::cin >> x;

	for (int i = 1; i < nNode; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		adjlist[u].push_back(v);
	}

	std::vector<int> result = dfs(0);
	std::cout << *std::min_element(result.begin(), result.end()) << '\n';

	return 0;
}
