#include <iostream>
#include <vector>
#include <algorithm>
#include "timecounter.h"
#include "randfiller.h"
#include "sort.hpp"


int main() {
    timecounter tc;
	randfiller rf;
	int num_vettori=96;
	
	for (int n=4; n<= 100; n++) {
	    std::vector<std::vector<int>> dataset_originale(num_vettori, std::vector<int>(n));
	for (int i=0; i<num_vettori; i++) {
		rf.fill(dataset_originale[i], -100, 100);
	}
	
	auto dataset_bubble= dataset_originale;
	tc.tic();
	for (int i=0; i<num_vettori; i++) {
	    bubble_sort(dataset_bubble[i]);
	}
	double tempo_b=tc.toc();
	double mediab = tempo_b/num_vettori;
	std::cout << "il tempo impiegato dal bubble_sort è in media: " << mediab << std::endl;
	
	
	auto dataset_selection= dataset_originale;
	tc.tic();
	for (int i=0; i<num_vettori; i++) {
	    selection_sort(dataset_selection[i]);
	}
	double tempo_s=tc.toc();
	double medias = tempo_s/num_vettori;
	std::cout << "il tempo impiegato dal selection_sort è in media: " << medias << std::endl;
	
	
	auto dataset_insertion= dataset_originale;
	tc.tic();
	for (int i=0; i<num_vettori; i++) {
	    insertion_sort(dataset_insertion[i], 0, dataset_insertion[i].size()-1);
	}
	double tempo_i=tc.toc();
	double mediai = tempo_i/num_vettori;
	std::cout << "il tempo impiegato dal insertion_sort è in media: " << mediai << std::endl;
	
	
	auto dataset_merge= dataset_originale;
	tc.tic();
	for (int i=0; i<num_vettori; i++) {
	    merge_sort(dataset_merge[i], 0, dataset_merge[i].size()-1);
	}
	double tempo_m=tc.toc();
	double mediam = tempo_m/num_vettori;
	std::cout << "il tempo impiegato dal merge_sort è in media: " << mediam << std::endl;
	
	
	auto dataset_quicksort= dataset_originale;
	tc.tic();
	for (int i=0; i<num_vettori; i++) {
	    quicksort(dataset_quicksort[i], 0, dataset_quicksort[i].size()-1);
	}
	double tempo_q=tc.toc();
	double mediaq = tempo_q/num_vettori;
	std::cout << "il tempo impiegato dal quicksort è in media: " << mediaq << std::endl;
	
	
	
	auto dataset_sort= dataset_originale;
	tc.tic();
	for (int i=0; i<num_vettori; i++) {
	    std::sort(dataset_sort.begin(), dataset_sort.end());
	}
	double tempo_n=tc.toc();
	double median = tempo_n/num_vettori;
	std::cout << "il tempo impiegato dal sort è in media: " << median << std::endl;
	
	
}	

return 0;
}