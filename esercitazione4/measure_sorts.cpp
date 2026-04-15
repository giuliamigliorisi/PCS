#include <iostream>
#include <vector>
#include <algorithm>
#include "timecounter.h"
#include "randfiller.h"
#include "sort.hpp"


int main() {
    timecounter tc;
	randfiller rf;
	for (int n=4; n<= 8192; n*=2) {
	    std::vector<int> v(n);
		rf.fill(v, -1000, 1000);
		std::vector<int> v_bubble=v;
		std::vector<int> v_insertion=v;
		std::vector<int> v_selection=v;
		std::vector<int> v_std=v;
		tc.tic();
		bubble_sort(v_bubble);
		double secs_bubble=tc.toc();
		std::cout << "per un vettore di dimensione: " << n << " bubble_sort impiega: " << secs_bubble << std::endl;
		tc.tic();
		insertion_sort(v_insertion);
		double secs_insertion=tc.toc();
		std::cout << "per un vettore di dimensione: " << n << " insertion_sort impiega: " << secs_insertion << std::endl;
		tc.tic();
		selection_sort(v_selection);
		double secs_selection=tc.toc();
		std::cout << "per un vettore di dimensione: " << n << " selection_sort impiega: " << secs_selection << std::endl;
		tc.tic();
		std::sort(v_std.begin(), v_std.end());
		double secs_std= tc.toc();
        std::cout << "per un vettore di dimensione: " << n << " sort impiega: " << secs_std << std::endl;
	}
	return 0;
}