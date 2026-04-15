#include <optional>
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>

void bubble_sort( std::vector<T>& vec)
{
	
    if (vec.size()==0) {
	    return;
	}
	
	for (int i=0; i<vec.size(); i++) {
	    for(int j=vec.size()-1; j>i; j--) {
            if (vec[j]<vec[j-1]) {
				std::swap(vec[j], vec[j-1]);
			
			}
		}
	}

}

template<typename T>

void insertion_sort( std::vector<T>& vec)
{
	
    for (int j=1; j<vec.size(); j++) {
	    T key=vec[j];
		int i=j-1;
		while ( i>=0 && vec[i]>key) {
		    vec[i+1]=vec[i];
			i--;
		}
		vec[i+1]=key;
	}
}
	
		

template<typename T>

void selection_sort( std::vector<T>& vec)
{
	
    for(int i=0; i<vec.size()-1; i++) {
	    int minimo=i;
		for (int j=i+1; j<vec.size(); j++) {
		     if (vec[j]<vec[minimo]) {
			     minimo =j;
			 }
		}
		std::swap(vec[i], vec[minimo]);
	}
}



template<typename T>
bool is_sorted(const std::vector<T>& vec){
	if (vec.size()<2) {
		return true;
	}
	for (int i=0; i<vec.size()-1; i++) {
		if (vec[i]>vec[i+1]) {
			return false;
		}
	}
	return true;
}




                    				
