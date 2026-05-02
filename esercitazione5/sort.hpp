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
	
	for (size_t i=0; i<vec.size(); i++) {
	    for(size_t j=vec.size()-1; j>i; j--) {
            if (vec[j]<vec[j-1]) {
				std::swap(vec[j], vec[j-1]);
			
			}
		}
	}

}

template<typename T>

void insertion_sort( std::vector<T>& vec, int p, int r)
{
	
    for (int j=p+1; j<=r; j++) {
	    T key=vec[j];
		int i=j-1;
		while ( i>=p && vec[i]>key) {
		    vec[i+1]=vec[i];
			i--;
		}
		vec[i+1]=key;
	}
}
	
		

template<typename T>

void selection_sort( std::vector<T>& vec)
{
	
    for(size_t i=0; i<vec.size()-1; i++) {
	    int minimo=i;
		for (size_t j=i+1; j<vec.size(); j++) {
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
	for (size_t i=0; i<vec.size()-1; i++) {
		if (vec[i]>vec[i+1]) {
			return false;
		}
	}
	return true;
}


template<typename T>
void merge ( std::vector<T>& vec, int p, int q, int r)
{
int n1=q-p+1;
int n2=r-q;
std::vector<T> L(n1+1);
std::vector<T> R(n2+1);
for (int i=0; i<n1; i++) {
    L[i]=vec[p+i];
}
for ( int j=0; j<n2; j++) {
    R[j]=vec[q+j+1];
}
if constexpr (std::is_same_v<T, std::string>) {
	L[n1]= "{";
	R[n2]= "{";
} else {
	L[n1]=std::numeric_limits<T>::max();
	R[n2]=std::numeric_limits<T>::max();
}

int i=0, j=0;
for (int k=p; k<=r; k++) {
    if (L[i]<=R[j]) {
	    vec[k]=L[i];
		i= i+1;
	}
	
	else {
	    vec[k]=R[j];
		j=j+1;
	}
}
}
    
template<typename T>

void merge_sort ( std::vector<T>& vec, int p, int r)
{
    if (p<r) {
		
		int q = (p+r)/2;
		merge_sort ( vec, p, q);
		merge_sort ( vec, q+1, r);
		merge( vec, p, q, r);
	}
}




template<typename T>

int partition ( std::vector<T>& vec, int p, int r)
{
	T x=vec[r];
	int i = p-1;
	for (int j=p; j<=r-1; j++) {
		if (vec[j]<=x) {
			i=i+1;
			std::swap(vec[i], vec[j]);
		}
	}
	std::swap(vec[i+1], vec[r]);
	return i+1;
}


template<typename T>

void quicksort ( std::vector<T>& vec, int p, int r)
{
	if (p<r) {
		int q =partition(vec,p,r);
		quicksort(vec,p,q-1);
		quicksort(vec,q+1,r);
	}
}


template<typename T>

void quicksort_modified ( std::vector<T>& vec, int p, int r)
{
	if (p<r) {
		if ((r-p+1) <= 83) {
			insertion_sort(vec, p, r);
		} else {
			int q=partition(vec, p, r);
			quicksort_modified(vec, p, q-1);
			quicksort_modified(vec, q+1, r);
		}
	}
}



                    				
