#include <iostream>
#include <fstream>
#include<string>

using namespace std;

int main(void) {
    std :: cout<<"inserisci il nome del file: \n";
	std::string name;
	std::cin>>name;
	    std::ifstream ifs(name) ;
	
	if (ifs.is_open() ) {
	    
		string location;
		double t1,t2,t3,t4;
		while (ifs >> location >> t1 >> t2 >> t3 >> t4) {
		double media= (t1+t2+t3+t4)/ 4.0;
		cout << location << " " << media << "\n";
		}
	}
	return 0;

}