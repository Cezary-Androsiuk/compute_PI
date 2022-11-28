#include <iostream>
#include <string>
#include <cmath>

#define x_0 1

long double pi(const unsigned long long &n);
long double segment_length(const long double &previous_segment_length, const unsigned long long &recursive_iteratior);


int main(int argc, char *argv[]){
    // n-gone == 6*interations
    unsigned long long iterations = 1;
    std::cout << "Input PI precision: ";
    std::cin >> iterations;
    std::cout << "PI: " << pi(iterations) << std::endl;
}


long double pi(const unsigned long long &n){
    return (3 * n * segment_length(x_0,n)); // 3* y(n) * 1 * n
}

long double segment_length(const long double &previous_segment_length, const unsigned long long &recursive_iteratior){
    if(recursive_iteratior == 1)
        return x_0; // x0 = 1
    
    long double tmp = powl(previous_segment_length/2,2);
    long double x_n = 1 - sqrtl(1 - tmp);
    long double new_segnemt_length = sqrtl(powl(1-x_n,2) + tmp);
    return segment_length(new_segnemt_length, recursive_iteratior-1);
}