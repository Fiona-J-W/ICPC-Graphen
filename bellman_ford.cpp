
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>


using node = std::size_t;
using edge = std::pair<node, node>;
using dist = double;
using graph = std::vector<std::vector<node>>;
using edge_weights = std::unordered_map<edge, dist>;

namespace std {

template<>
struct hash<std::pair<node, node>> {
	std::size_t operator()(const std::pair<node, node>& edge) const {
		// this is ok, because we know that first != second
		return edge.first xor edge.second;
	}
};
}

std::vector<dist> bellman_ford(const graph& g, const edge_weights& edges, node source) {
	auto min_dists = std::vector<dist>(g.size(), std::numeric_limits<dist>::infinity());
	min_dists[source] = 0;
	auto changes_happened = false;
	for (auto i = std::size_t{}; i < g.size() + 1; ++i) {
		for (auto v = std::size_t{}; v < g.size(); ++v) {
			for (auto neighbour: g[v]) {
				const auto old_dist = min_dists[neighbour];
				const auto new_dist =
					min_dists[v] + edges.at({v, neighbour});
				if (new_dist < old_dist) {
					min_dists[neighbour] = new_dist;
					changes_happened = true;
				}
			}
		}
		if (!changes_happened) {
			break;
		} else if(i == g.size()) {
			throw std::runtime_error{"negative cycle"};
		}
		changes_happened = false;
	}
	return min_dists;
}

int main() try {
	const auto g = graph{
		{1, 4},
		{0, 3},
		{4},
		{0, 2},
		{1}
	};
	const auto edges = edge_weights {
		{{0, 1}, 7}, {{0, 4}, -1},
		{{1, 0}, 10}, {{1, 3}, -4},
		{{2, 4}, 1},
		{{3, 0}, 0}, {{3, 2}, 2.5},
		{{4, 1}, 23}
	};
	const auto min_dists = bellman_ford(g, edges, 0);
	std::copy(min_dists.begin(), min_dists.end(), std::ostream_iterator<dist>{std::cout, "\n"});
} catch (std::runtime_error& e) {
	std::cerr << "Error: " << e.what() << '\n';
}
