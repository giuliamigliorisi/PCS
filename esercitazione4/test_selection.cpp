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
		selection_sort(v);
		if (not is_sorted(v)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (metodo selection) " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(v);
		
		
		
		
		std::vector<float> f(dimensione_scelta);
		rf.fill(f,-50.0f,50.0f);
		std::cout << "vettore " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(f);
		selection_sort(f);
		if (not is_sorted(f)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (metodo selection) " << i+1 << " lunghezza " << dimensione_scelta << "): ";
		print_vector(f);
		
		
		

		std::vector<double> d(dimensione_scelta);
		rf.fill(d,-50.0,50.0);
		std::cout << "vettore " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(d);
		selection_sort(d);
		if (not is_sorted(d)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (metodo selection) " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(d);
		
	}
	
	
	std::vector<std::string> stringa={"casa", "mela", "spiaggia", "mare", "montagna", "scuola", "banca", "libro", "penna", "chiave"};
	std::cout << "vettore di stringhe: ";
	print_vector(stringa);
	selection_sort(stringa);
	if (not is_sorted(stringa)) {
			return EXIT_FAILURE;
		}
	std::cout << "vettore ordinato (metodo selection): ";
	print_vector(stringa);
	
		
		
	return EXIT_SUCCESS;
}

    