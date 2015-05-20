#include<vector>
#include<algorithm>
#include<queue> // not priority_queue!
#include<iostream>

using namespace std;

struct edge {
  size_t to;
  double weight;
};


bool operator < (const edge& e1, const edge& e2) {
	   // inversed
    return e1.weight > e2.weight;
}

using node = vector<edge>;

vector<double> dijkstra(vector<node>& nodes, size_t startnode) {
  vector<double> distances (nodes.size(), 100000000000);

  priority_queue<edge> todo;

  todo.push({startnode, 0});

  while(!todo.empty()) {
    auto current = todo.top();
    todo.pop();

    if(current.weight < distances[current.to]) {
      distances[current.to] = current.weight;

      for(size_t i = 0; i < nodes[current.to].size(); i++) {
        edge next = nodes[current.to][i];
        next.weight += current.weight;

        todo.push(next);
      }
    }
  }

  return distances;
}

int dijkstra_to_target(vector<node>& nodes, size_t startnode, size_t target) {
  vector<double> distances (nodes.size(), 100000000000);

  priority_queue<edge> todo;

  todo.push({startnode, 0});

  while(!todo.empty()) {
    auto current = todo.top();
    todo.pop();

    // Early return
    if(current.to == target) return current.weight;

    if(current.weight < distances[current.to]) {
      distances[current.to] = current.weight;

      for(size_t i = 0; i < nodes[current.to].size(); i++) {
        edge next = nodes[current.to][i];
        next.weight += current.weight;

        todo.push(next);
      }
    }
  }

  // target not found
  return -1;
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

  for(size_t i = 0; i < res.size(); i++) {
    cout << "res[" << i << "] = " << res[i] << endl;
  }

  cout << "dijkstra_to_target(nodes, 0, 4) = " << dijkstra_to_target(nodes, 0, 4) << endl;
}
