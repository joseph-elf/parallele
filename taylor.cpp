#include <cmath>
#include <future>
#include <iostream>
#include <chrono>
#include <vector>       // vector functions

using namespace std::chrono;
using namespace std;

void boucleAccelerationAsynchrone(size_t init, size_t end){
	double j = 0;
		for(size_t i(init); i<end; i++){
					j+=1./i;
				}
				cout<<j<<endl;
}
double taylor_part(double x, size_t start, size_t end){
	double result = 0;
	for(size_t i = start; i<end; i++){
		
		result += std::pow(-1,i+1)/i*std::pow(x-1,i);
		}
	return result;
	}

int main(void){
	/*auto start = high_resolution_clock::now();

	double x=0.5;
	size_t n =50000000;
	
	std::future<double> f1 = std::async(taylor_part,x,1,n/2);
	std::future<double> f2 = std::async(taylor_part,x,n/2,n);
	std::cout << f1.get() + f2.get() <<std::endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	std::cout << duration.count() << " ms"<< std::endl;
	
	
	start = high_resolution_clock::now();
	double result = taylor_part(x,1,n);
	std::cout<< result << std::endl;
	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	std::cout << duration.count() << " ms"<< std::endl;*/
	
	
	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	int nbEtoile(1000000000);
	int nbCoeurs(3);
	
	vector<future<void>> taches;
	
	for(size_t coeur(1); coeur <=nbCoeurs; coeur++ ){
	taches.push_back(async(boucleAccelerationAsynchrone,1,nbEtoile));
	
	
	

	}
	
	for(size_t coeur(1); coeur <=nbCoeurs; coeur++ ){
	taches[coeur-1].get();
	stop = high_resolution_clock::now();
	duration = duration_cast<milliseconds>(stop - start);
	std::cout << duration.count() << " ms"<< std::endl;
	
	

	}
	
	
		
	return 0;
	}
