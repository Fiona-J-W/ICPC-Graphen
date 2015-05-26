#include<vector>
#include<algorithm>
#include<queue> // not priority_queue!
#include<iostream>

using namespace std;

struct ArrivalEvent {
  int to;
  int weight;
};


bool operator < (const ArrivalEvent& e1, const ArrivalEvent& e2) {
	   // inversed
    return e1.weight > e2.weight;
}

vector<int> dijkstra(vector<vector<ArrivalEvent>>& nodes, int startnode) {
  vector<int> distances (nodes.size(), 2000000000);

  priority_queue<ArrivalEvent> todo;

  todo.push({startnode, 0});

  while(!todo.empty()) {
    auto current = todo.top();
    todo.pop();

    if(current.weight < distances[current.to]) {
      distances[current.to] = current.weight;

      for(int i = 0; i < nodes[current.to].size(); i++) {
        ArrivalEvent next = nodes[current.to][i];
        next.weight += current.weight;

        todo.push(next);
      }
    }
  }

  return distances;
}

int dijkstra_to_target(vector<vector<ArrivalEvent>>& nodes, int startnode, int target) {
  vector<int> distances (nodes.size(), 2000000000);

  priority_queue<ArrivalEvent> todo;

  todo.push({startnode, 0});

  while(!todo.empty()) {
    auto current = todo.top();
    todo.pop();

    // Early return
    if(current.to == target) return current.weight;

    if(current.weight < distances[current.to]) {
      distances[current.to] = current.weight;

      for(int i = 0; i < nodes[current.to].size(); i++) {
        ArrivalEvent next = nodes[current.to][i];
        next.weight += current.weight;

        todo.push(next);
      }
    }
  }

  // target not found
  return -1;
}


int main() {
  vector<vector<ArrivalEvent>> nodes = {
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

  cout << "dijkstra_to_target(nodes, 0, 4) = " << dijkstra_to_target(nodes, 0, 4) << endl;
}
