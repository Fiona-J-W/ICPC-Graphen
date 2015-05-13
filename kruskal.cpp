#include<vector>
#include<algorithm>
#include<iostream>

using node = int;
using dist = double;

using edge = struct {
	node from;
	node to;
	dist weight;
};
bool operator < (const edge& e1, const edge& e2) {
        return e1.weight < e2.weight;
}

struct UnionFind {
    std::vector<node> uf;
    UnionFind(node max) : uf(max, -1){}

    node find(node n) {
        if (uf[n] >= 0) {
            return uf[n] = find(uf[n]);
        } else {
            return n;
        }
    }

    bool sameSet(node n1, node n2) {
        return find(n1) == find(n2);
    }

    void unify(node n1, node n2) {
        if(sameSet(n1, n2)) {
            return;
        }
        int size1 = uf[find(n1)];
        int size2 = uf[find(n2)];
        if (size1 < size2) {
            std::swap(n1,n2);
        }
        uf[find(n2)] += uf[find(n1)];
        uf[find(n1)] = find(n2);
    }
};

dist kruskal(std::vector<edge>& edges, node maxnode) {
    dist fullweight = 0;
    UnionFind ufind(maxnode + 1);
    std::sort(edges.begin(), edges.end());
    for (const auto& e : edges) {
        if(!ufind.sameSet(e.from, e.to)) {
            ufind.unify(e.from, e.to);
            fullweight += e.weight;
        }
    }
    return fullweight;
}
int main() {
    auto edges = std::vector<edge>{
        {0, 1, 4}, {0, 3, 4}, {0, 2, 2}, {0, 7, 3}, {0, 6, 8},
		{1, 3, 2}, {1, 4, 6}, {1, 5, 1}, {1, 6, 1},
		{2, 4, 4}, {2, 6, 5},
		{3, 1, 2}, {3, 4, 3}, {3, 5, 2}
	};
    node max = 7;
    std::cout << kruskal(edges, max);
}