
bellman_ford: bellman_ford.cpp
	clang++ -Wall -Wextra -Wpedantic -std=c++1y bellman_ford.cpp -o bellman_ford

bellman_ford_graphs: bellman_ford_graph_gen.cpp makefile
	clang++ -Wall -Wextra -Wpedantic -std=c++1y bellman_ford_graph_gen.cpp -o bellman_ford_graph_gen
	rm -rf bellman_ford_graphs
	mkdir bellman_ford_graphs
	./bellman_ford_graph_gen
	bash -c 'for FILE in $$(ls bellman_ford_graphs/*.dot); do sfdp $$FILE -Tsvg -O; done'
	bash -c 'for FILE in $$(ls bellman_ford_graphs/*.dot); do sfdp $$FILE -Tpng -O; done'
