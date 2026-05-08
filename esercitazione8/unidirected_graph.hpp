#include <iostream>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#pragma once
#include <vector>
#include "unidirected_edge.hpp"

 class unidirected_graph {
 private:
    std::list<unidirected_edge> edges;
	std::map<int, std::set<int>> mappa_adiacenza;
public:
    unidirected_graph()=default;
	
	/* costruttore di copia */
	
	unidirected_graph(const unidirected_graph& other)
	    : edges(other.edges), mappa_adiacenza(other.mappa_adiacenza) {}
	
	
	/* metodo neighbours */
	
	std::vector<int> neighbours(int node) const {
		std::vector<int> n_list;
		for (const auto& e : edges) {
			if (e.from() == node) {
				n_list.push_back(e.to());
			}
			else if (e.to() == node) {
				n_list.push_back(e.from());
			}
		}
		return n_list;
	}
	
	/* costruttore per aggiungere archi */
	
	void add_edge(const unidirected_edge& e) {
		edges.push_back(e);
		mappa_adiacenza[e.from()].insert(e.to());
		mappa_adiacenza[e.to()].insert(e.from());
	}
	
	
	/*per restituire tutti gli archi*/
	
	std::list<unidirected_edge> all_edges() const {
		return edges;
	}
	
	/*per restituire tutti i nodi*/
	
	std::set<int> all_nodes() const {
		std::set<int> nodes;
		for (auto const& [node, neighbors] : mappa_adiacenza) {
			nodes.insert(node);
		}
		return nodes;
	}
	
	
	
	/* per fornire la numerazione degli archi*/
	
	
	int edge_number(const unidirected_edge& e) const {
		int pos=0;
		for (const auto& edge : edges) {
			if (edge==e) return pos;
			pos++;
		}
		return -1;
	}
	
	
	/* restituisce l'arco in una data posizione*/
	
	unidirected_edge edge_at(int index) const {
		auto it =edges.begin();
		std::advance(it,index);
		return *it;
	}
	
	
	
	/* operatore differenza G-G' */
	
	
	unidirected_graph operator-(const unidirected_graph& other) const {
		unidirected_graph result;
		for (const auto& e : edges) {
			auto it=std::find(other.edges.begin(), other.edges.end(), e);
			if (it==other.edges.end()) {
				result.add_edge(e);
			}
		}
		return result;
	}
 };
	
	
	
	