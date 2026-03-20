#include <iostream>
#include <fstream>
#include<string>
#include<cmath>


int main()
{
static const int N = 6;
double arr[N]= {2,3.2,6,1,9.2,10};
double minimo = arr[0];
double massimo = arr[0];
double somma = arr[0];
for (int i=1;i<N;i++){
    minimo=std::min(minimo,arr[i]);
	massimo=std::max(massimo,arr[i]);
	somma=somma+arr[i];
}
double media= somma/N;
	
std::cout << "il minimo è: " << minimo << "\n";
std::cout << "il massimo è: " << massimo << "\n";
std::cout << "la media è: " << media << "\n";
double quadrato=pow(arr[0]-media,2);
for ( int k=1; k<N; k++)
    quadrato = quadrato + pow(arr[k]-media,2);
double deviazione = std::sqrt(quadrato/N);
std::cout << "la deviazione standard è: " << deviazione << "\n";
}



