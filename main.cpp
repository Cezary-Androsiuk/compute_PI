#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

#define x_0 1

long double pi(const unsigned long long &n);
long double x_n_length(const long double &, const unsigned long long &);


int main(int argc, char *argv[]){
    std::cout << std::setprecision(10000);
    // n-gone == 6*interations
    // for(int i=1; i<100; i++)
        // std::cout << "PI(" << i << "): " << pi(i) << std::endl;
    std::cout << "1/3 = " << (long double) 1 / 3 << std::endl << "long double is not perfectly arcurate\n\n";
    int i = 30;
    std::cout << "PI(" << i << "): \t" << pi(i) << std::endl;
    i = 31;
    std::cout << "PI(" << i << "): \t" << pi(i) << std::endl;
    i = 1023;
    std::cout << "PI(" << i << "): \t" << pi(i) << std::endl;
    i = 1024;
    std::cout << "PI(" << i << "): \t" << pi(i) << std::endl;
}


long double pi(const unsigned long long &n){
    // 3* 2^(n-1) * x_n;
    return 3 * pow(2,n-1) * x_n_length(x_0,n);
    // return 3 * n * x_n_length(x_0,n);
}

long double x_n_length(const long double &x_n_minus_1, const unsigned long long &n){
    if(n == 1)
        return x_n_minus_1;
    
    long double pow_half_x1 = powl(x_n_minus_1/2, 2);
    long double h2_top = 1 - sqrtl(1 - pow_half_x1);
    long double x_n = sqrtl(powl(h2_top,2) + pow_half_x1);
    return x_n_length(x_n, n-1);
}