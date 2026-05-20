#include <iostream>
#pragma once
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <climits> 
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"

template<typename T>
class fifo
{
private:
    std::list<T> elementi;
public:
    fifo() {}
	void put(const T& valore)
	{
	elementi.push_back(valore);
	}
	
	T get()
	{
	    T valore=elementi.front();
		elementi.pop_front();
		return valore;
	}
	
	bool empty() const
	{
	    return elementi.empty();
	}
};


template <typename T>
class lifo
{
private:
    std::list<T> elementi;
public:
    lifo() {}
	void put(const T& valore)
	{
	    elementi.push_back(valore);
	}
	
	T get()
	{
	    T valore=elementi.back();
		elementi.pop_back();
		return valore;
	}
	
	bool empty() const
	{
	    return elementi.empty();
	}
};


template <typename Container>
unidirected_graph graph_visit(const unidirected_graph& G, int nodo_sorgente, Container container) {
	unidirected_graph result_tree;
	int num_nodi=G.all_nodes().size();
	std::vector<bool> visitato(num_nodi, false);
	visitato[nodo_sorgente]=true;
	container.put(nodo_sorgente);
	while (!container.empty()){
		int nodo_corrente=container.get();
		for (int vicino : G.neighbours(nodo_corrente)) {
			if (!visitato[vicino]) {
				visitato[vicino]=true;
				container.put(vicino);
				result_tree.add_edge(unidirected_edge(nodo_corrente,vicino));
			}
		}
	}
	return result_tree;
}



void dfs_visit(unidirected_graph& G,
               int u,
               std::vector<bool>& visited,
               unidirected_graph& albero)
{
    visited[u] = true;
	std::vector<int> vicini;

    for (int i = 0; i < G.neighbours(u).size(); i++) {

    vicini.push_back(G.neighbours(u)[i]);
	}
	
	std::sort(vicini.begin(), vicini.end());
	for (int v : vicini) {
		if (!visited[v]) {
			albero.add_edge(unidirected_edge(u,v));
			dfs_visit(G, v, visited, albero);
		}
	}
}


unidirected_graph recursive_dfs(unidirected_graph& G, int nodo_sorgente)
{
    std::vector<bool> visited(G.all_nodes().size(), false);

    unidirected_graph albero;

    dfs_visit(G, nodo_sorgente, visited, albero);

    return albero;
}

	
	
	
	



std::map<int, int> dijkstra(const unidirected_graph& G, int s) {
	
    int N=G.all_nodes().size();    
    std::vector<int> dist(N);
    std::vector<int> pred(N);

    for (int i = 1; i <= N; i++) {
        pred[i] = -1;       
        dist[i] = INT_MAX;  
    }
    
    pred[s] = s;
    dist[s] = 0;
    
    
    std::priority_queue<std::pair<int, int>, 
                        std::vector<std::pair<int, int>>, 
                        std::greater<std::pair<int, int>>> PQ;
    
 
    for (int i = 1; i <= N; i++) {
        PQ.push({dist[i], i}); 
    }
    
    
    while (!PQ.empty()) {
        
        int u=PQ.top().second;
		int d_u=PQ.top().first;
        PQ.pop(); 
        if (d_u > dist[u]) continue; 
        
        
        for (int w : G.neighbours(u)) {
            
            
            if (dist[w] > dist[u] + 1) {
                    
                dist[w] = dist[u] + 1;
                pred[w] = u;
                PQ.push({dist[w], w}); 
                
            }
        }
    }
	std::map<int,int> risultato;
	for (int i=1; i<=N; i++) {
		risultato[i]=dist[i];
	}
	return risultato;
}
