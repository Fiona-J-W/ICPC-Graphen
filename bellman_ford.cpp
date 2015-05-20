
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>


using node = std::size_t;
using dist = double;

using edge = struct {
	node from;
	node to;
	dist weight;
};

const auto inf_dist = std::numeric_limits<dist>::infinity();

std::vector<dist> bellman_ford(std::size_t node_count, const std::vector<edge>& edges, node source) {
	auto min_dists = std::vector<dist>(node_count, inf_dist);
	min_dists[source] = 0;
	for (auto i = std::size_t{}; i < node_count + 1; ++i) {
		auto changes = false;
		for(const auto& e: edges) {
			const auto old_dist = min_dists[e.to];
			const auto new_dist = min_dists[e.from] + e.weight;
			if (new_dist < old_dist) {
				min_dists[e.to] = new_dist;
				changes = true;
			}
		}
		if (!changes) { break; }
		if (i == node_count) {
			throw std::runtime_error{"negative cycle"};
		}
	}
	return min_dists;
}

int main() try {
	const auto edges = std::vector<edge>{
		{0, 1,  7}, {0, 4,  -1},
		{1, 0, 10}, {1, 3,  -4},
		{2, 4,  1},
		{3, 0,  0}, {3, 2, 2.5},
		{4, 1, 23}
	};
	const auto min_dists = bellman_ford(5, edges, 0);
	std::copy(min_dists.begin(), min_dists.end(), std::ostream_iterator<dist>{std::cout, "\n"});
} catch (std::runtime_error& e) {
	std::cerr << "Error: " << e.what() << '\n';
}
