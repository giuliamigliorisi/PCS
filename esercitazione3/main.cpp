#include <concepts> 
#include <iostream>
#include "rational.hpp"
int main() {
    rational<int> r1(3, 6);
	rational<int> r2(10,-5);
	std::cout << "r1 (3/6): " << r1 << "\n";
	std::cout << "r2 (10/-5): " << r2 << "\n";
	rational<int> somma= r1+ r2;
	std::cout << "r1+r2: " << somma << "\n";
	rational<int> r3(5, 0);
	std::cout << "r3 (5/0): " << r3 << "\n";
	rational<int> r4(0, 0);
	std::cout << "r4 (0/0): " << r4 << "\n";
	rational<int> somma1= r3+ r2;
	std::cout << "r3+r2: " << somma1 << "\n";
	rational<int> somma2= r4+ r2;
	std::cout << "r4+r2: " << somma2 << "\n";
	rational<int> r5(1, 6);
	std::cout << "r5 (1,6): " << r5 << "\n";
	rational<int> r6(1, 6);
	std::cout << "r6 (1,6): " << r6 << "\n";
	rational<int> somma3= r6+ r5;
	std::cout << "r5+r6: " << somma3 << "\n";
	rational<int> divisione= r5/r6;
	std::cout << "r5/r6: " << divisione << "\n";
	rational<int> moltiplicazione= r2*r5;
	std::cout<< "r2*r5: " << moltiplicazione << "\n";
	rational<int> moltiplicazione1= r3*r6;
	std::cout<< "r3*r6: " << moltiplicazione1 << "\n";
	
	
	
	
	return 0;
}
