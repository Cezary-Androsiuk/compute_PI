#include <iostream>
#include <string>
#include <cmath>


#define RADIUS 1
// started with 6 segments but also need to divide all through 2 at the end
#define SEGMENTS_DV2 3

long double pi(const unsigned long long &iterations);
long double segment_length(const long double &previous_segment_length, const unsigned long long &recursive_iteratior);


int main(int argc, char *argv[]){
    // n-gone == 6*interations
    unsigned long long iterations = 1;
    std::cout << "Input PI precision: ";
    std::cin >> iterations;
    std::cout << "PI: " << pi(iterations) << std::endl;
}


long double pi(const unsigned long long &iterations){
    return (SEGMENTS_DV2 * iterations * segment_length(RADIUS,iterations));
}

long double segment_length(const long double &previous_segment_length, const unsigned long long &recursive_iteratior){
    if(recursive_iteratior == 1) // previous_segment_length * 3 == PI
        return previous_segment_length;
    
    long double psl_2_2 = powl(previous_segment_length/2,2);
    long double y = 1 - sqrtl(powl(RADIUS,2) - psl_2_2);
    long double new_segnemt_length = sqrtl(powl(y,2) + psl_2_2);
    std::cout << "new_segnemt_length: " << new_segnemt_length << std::endl;
    return segment_length(new_segnemt_length, recursive_iteratior-1);
}