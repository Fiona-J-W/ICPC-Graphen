#include<vector>
#include<algorithm>
#include<queue> // not priority_queue!
#include<iostream>

using namespace std;

struct edge {
	int to;
	double weight;
};


bool operator < (const edge& e1, const edge& e2) {
	   // inversed
    return e1.weight > e2.weight;
}


using node = vector<edge>;

vector<double> dijkstra(vector<node>& nodes, int startnode /*, int target */) {
	// initialize all distances with infinity
	vector<double> distances (nodes.size(), 100000000000);

	priority_queue<edge> todo;
	
	edge start;
	start.to = startnode;
	start.weight = 0;

	todo.push(start);

	while(!todo.empty()) {
		auto current = todo.top();
		todo.pop();
	
		// early return possible, like this: 
		// if(current.to == target) returen current.weight;

		// only if there is no better way to reach the node
		if(current.weight < distances[current.to]) {
			distances[current.to] = current.weight;

			for(int i = 0; i < nodes[current.to].size(); i++) {
				edge next = nodes[current.to][i];
				next.weight += current.weight;

				todo.push(next);
			}
		}
	}

	return distances;
}


int main() {
	vector<node> nodes = { 
		{ 
			// start
			{ 1, 1 },
			{ 2, 3 }
		},
		{ 
			{ 3, 3 },
		},
		{ 
			{ 4, 4 },
		},
		{
			{ 4, 1 }
		},
		{
			// ziel
		}		
	};

	auto res = dijkstra(nodes, 0);

	for(int i = 0; i < res.size(); i++) {
		cout << "res[" << i << "] = " << res[i] << endl;
	}
}
