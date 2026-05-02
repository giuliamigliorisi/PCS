#include <iostream>
#include <vector>
#include "randfiller.h"
#include "sort.hpp"
#include <string>

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(void)
{
    randfiller rf; 
	for (int i=0; i<100; i++)
	{
	    std::vector<int> appoggio(1);
		rf.fill(appoggio,5,50); 
		int dimensione_scelta=appoggio[0];
		std::vector<int> v(dimensione_scelta);
		rf.fill(v,-50,50);
		std::cout << "vettore " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(v);
		bubble_sort(v);
		if (not is_sorted(v)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (test_bubble) " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(v);
		
		
		
		std::vector<float> f(dimensione_scelta);
		rf.fill(f,-50.0f,50.0f);
		std::cout << "vettore " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(f);
		bubble_sort(f);
		if (not is_sorted(f)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (test bubble) " << i+1 << " lunghezza " << dimensione_scelta << "): ";
		print_vector(f);
		
		

		std::vector<double> d(dimensione_scelta);
		rf.fill(d,-50.0,50.0);
		std::cout << "vettore " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(d);
		bubble_sort(d);
		if (not is_sorted(d)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (test bubble) " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(d);

		
	}
	
	std::vector<std::string> stringa={"casa", "mela", "spiaggia", "mare", "montagna", "scuola", "banca", "libro", "penna", "chiave"};
	std::cout << "vettore di stringhe: ";
	print_vector(stringa);
	bubble_sort(stringa);
	if (not is_sorted(stringa)) {
			return EXIT_FAILURE;
		}
	std::cout << "vettore ordinato (test bubble): ";
	print_vector(stringa);
	
	
	return 0;
}




    
	
	
	
	
	
	