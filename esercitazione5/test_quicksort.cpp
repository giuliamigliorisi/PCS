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
		quicksort(v, 0, v.size()-1);
		if (not is_sorted(v)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (metodo quicksort) " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(v);
		
		
		
		
		std::vector<float> f(dimensione_scelta);
		rf.fill(f,-50.0f,50.0f);
		std::cout << "vettore " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(f);
		quicksort(f, 0, f.size()-1);
		if (not is_sorted(f)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (metodo quicksort) " << i+1 << " lunghezza " << dimensione_scelta << "): ";
		print_vector(f);
		
		
		

		std::vector<double> d(dimensione_scelta);
		rf.fill(d,-50.0,50.0);
		std::cout << "vettore " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(d);
		quicksort(d, 0, d.size()-1);
		if (not is_sorted(d)) {
			return EXIT_FAILURE;
		}
		std::cout << "vettore ordinato (metodo quicksort) " << i+1 << " lunghezza " << dimensione_scelta << ": ";
		print_vector(d);
		
	}
	
	
	std::vector<std::string> stringa={"casa", "mela", "spiaggia", "mare", "montagna", "scuola", "banca", "libro", "penna", "chiave"};
	std::cout << "vettore di stringhe: ";
	print_vector(stringa);
	quicksort(stringa, 0, stringa.size()-1);
	if (not is_sorted(stringa)) {
			return EXIT_FAILURE;
		}
	std::cout << "vettore ordinato (metodo quicksort): ";
	print_vector(stringa);
	
		
		
	return EXIT_SUCCESS;
}
