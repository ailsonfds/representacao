#include "tobin.h"

void print_v_bool(std::vector<bool> v);

int main(){
    std::vector<bool> *v = &dec_to_bin_int_32_bit(-15382);
    print_v_bool(*v);
    delete v;
    std::vector<bool> *v2 = &dec_to_bin_float_IEEE754(3.14);
    print_v_bool(*v2);
    delete v2;
    return 0;
}	

void print_v_bool(std::vector<bool> v){
	for(bool b : v){
        std::cout << (b?"1":"0");
    }
    std::cout << std::endl;
}