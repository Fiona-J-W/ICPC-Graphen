#include <iomanip>
#include <fstream>
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

const auto output_base_name = std::string{"bellman_ford_graphs/graph_"};
void print_graph(const std::vector<edge>& edges, const std::vector<edge>& used_edges,
                 const std::vector<dist>& nodes, std::size_t i, const std::string& color = "blue");

std::vector<dist> bellman_ford(std::size_t node_count, const std::vector<edge>& edges,
                               node source) {
	auto min_dists = std::vector<dist>(node_count, inf_dist);
	min_dists[source] = 0;
	auto changes_happened = false;
	auto used_edges = std::vector<edge>{};
	auto img_id = 0u;
	print_graph(edges, used_edges, min_dists, img_id++);
	for (auto i = std::size_t{}; i < node_count + 1; ++i) {
		for (const auto& e : edges) {
			const auto old_dist = min_dists[e.to];
			const auto new_dist = min_dists[e.from] + e.weight;
				used_edges.push_back(e);
			if (new_dist < old_dist) {
				min_dists[e.to] = new_dist;
				changes_happened = true;
				print_graph(edges, used_edges, min_dists, img_id++);
			} else {
				print_graph(edges, used_edges, min_dists, img_id++, "cyan");
			}
			used_edges.clear();
		}
		print_graph(edges, used_edges, min_dists, img_id++);
		if (!changes_happened) {
			break;
		} else if (i == node_count) {
			throw std::runtime_error{"negative cycle"};
		}
		changes_happened = false;
	}
	return min_dists;
}

int main() try {
	const auto edges = std::vector<edge>{
	        {0, 1, 7}, {0, 3, 9}, {1, 3, -2}, {2, 4, 1}, {3, 2, 2}, {4, 1, 2}};
	const auto min_dists = bellman_ford(5, edges, 0);
	std::copy(min_dists.begin(), min_dists.end(), std::ostream_iterator<dist>{std::cout, "\n"});
} catch (std::runtime_error& e) {
	std::cerr << "Error: " << e.what() << '\n';
}

void print_graph(const std::vector<edge>& edges, const std::vector<edge>& used_edges,
                 const std::vector<dist>& nodes, std::size_t i, const std::string& color) {
	const auto filename = output_base_name + (i<10? "0" : "") + std::to_string(i) + ".dot";
	std::ofstream output{filename};
	output << std::setprecision(0) << std::fixed;
	output << "strict digraph {\n";
	for (const auto& edge : edges) {
		output << '\t' << edge.from << " -> " << edge.to << " [label=" << edge.weight
		       << "]\n";
	}
	for (auto i = node{}; i < nodes.size(); ++i) {
		output << '\t' << i << " [label=";
		if (nodes[i] == inf_dist) {
			output << "∞";
		} else {
			output << nodes[i];
		}
		output << "]\n";
	}
	for (const auto& edge : used_edges) {
		output << '\t' << edge.from << " -> " << edge.to << " [label=" << edge.weight
		       << "] [color=" << color << "]\n";
		output << '\t' << edge.to << " [label=";
		if (nodes[edge.to] == inf_dist) {
			output << "∞";
		} else {
			output << nodes[edge.to];
		}
		output << "] [color=red]\n";
	}
	output << "}\n";
}
