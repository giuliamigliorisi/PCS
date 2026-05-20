#include <iostream>
#pragma once

class unidirected_edge 
{
    private:
    int n1;
	int n2;
	
public:
    unidirected_edge(int a, int b)
	{
	    if (a<=b) {
		    n1=a;
			n2=b;
			}
		else {
		    n1=b;
			n2=a;
		}
	}
	
	int from() const { return n1; }
	int to() const { return n2; }
	
	bool operator<(const unidirected_edge& other) const {
	    if ( n1 != other.n1) return n1< other.n1;
		return n2<other.n2;
	}
	
	bool operator==(const unidirected_edge& other) const {
	    return n1==other.n1 && n2==other.n2;
	}
};


std::ostream&
operator<<(std::ostream& os, const unidirected_edge& e)
{
    os << "(" << e.from() << ", " << e.to() << ")";
	return os;
}
