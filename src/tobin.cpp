#include "tobin.h"

/**
 * Transforma um numero de base dez natural em base dois.
 *
 * @param number O numero natural na base dez a ser convertido para a base dois.
 *
 */
std::vector<bool>& dec_to_bin_nat_32_bit(size_t number){
    std::vector<bool> *result = new std::vector<bool>();
    std::vector<bool> tmp(32);
    size_t index = 0;
    while(number >= 2 || index < 31){
        tmp[index++] = ((bool)(number%2));
        number /= 2;
    }
    tmp[index] = ((bool)number);
    for(std::vector<bool>::reverse_iterator rit = tmp.rbegin(); rit != tmp.rend(); ++rit){
        result->push_back(*rit);
    }
    return *result;
}

/**
 * Transforma um numero de base dez natural em base dois.
 *
 * @param number O numero natural na base dez a ser convertido para a base dois.
 *
 */
std::vector<bool>& dec_to_bin_nat(size_t number){
    std::vector<bool> *result = new std::vector<bool>();
    std::vector<bool> tmp;
    while(number >= 2){
        tmp.push_back((bool)(number%2));
        number /= 2;
    }
    tmp.push_back((bool)number);
    for(std::vector<bool>::reverse_iterator rit = tmp.rbegin(); rit != tmp.rend(); ++rit){
        result->push_back(*rit);
    }
    return *result;
}

/**
 * Converte um numero inteiro na base dez para a base dois.
 *
 * @param number O numero a ser convertido.
 *
 */
std::vector<bool>& dec_to_bin_int(int number){
    if(number < 0){ // Verifica se  o numero e negativo, caso seja, calcular o complemento de dois
        number*=(-1); // Passo 1 - Deixa positivo
        std::vector<bool> *result = &dec_to_bin_nat(static_cast<int>(number)); // Passo 2 - Converte para binario
        result->flip(); // Passo 3 - Inverte os bits
        // Passo 4 - Soma mais 1 na base dois
        if(result->at(result->size()-1) == 0){
            result->at(result->size()-1) = 1;
        } else {
            int i = result->size()-1;
            while(result->at(i) == 1){
                result->at(i--) = 0;
            }
            result->at(i) = 1;
        }
        return *result;
    } else {
        return dec_to_bin_nat(static_cast<int>(number));
    }
}

/**
 * Converte um numero inteiro na base dez para a base dois.
 *
 * @param number O numero a ser convertido.
 *
 */
std::vector<bool>& dec_to_bin_int_32_bit(int number){
    if(number < 0){ // Verifica se  o numero e negativo, caso seja, calcular o complemento de dois
        number*=(-1); // Passo 1 - Deixa positivo
        std::vector<bool> *result = &dec_to_bin_nat_32_bit(static_cast<int>(number)); // Passo 2 - Converte para binario
        result->flip(); // Passo 3 - Inverte os bits
        // Passo 4 - Soma mais 1 na base dois
        if(result->at(result->size()-1) == 0){
            result->at(result->size()-1) = 1;
        } else {
            int i = result->size()-1;
            while(result->at(i) == 1){
                result->at(i--) = 0;
            }
            result->at(i) = 1;
        }
        return *result;
    } else {
        return dec_to_bin_nat(static_cast<int>(number));
    }
}

/**
 * Converte um numero em ponto flutuante na base dez para a base dois.
 *
 * @param number O numero a ser convertido.
 *
 */
std::vector<bool>& dec_to_bin_float_IEEE754(double number){
    std::vector<bool> *result = new std::vector<bool>();
    bool signal = number < 0;
    result->push_back(signal);
    if(signal){
        number*=(-1);
    }
    std::string str(std::to_string(number));
    std::stringstream stst(str);
    std::string int_part = "";
    std::string float_part = "0.";
    while(stst.good()){
        char c = stst.get();
        if(c == '.'){
            while(stst.good()){
                c = stst.get();
                float_part += c;
            }
        } else {
            int_part += c;
        }
    }
    std::vector<bool> bin_int_part = dec_to_bin_nat(std::stoi(int_part));
    std::vector<bool> bin_float_part;
    double dec_float_part = std::stod(float_part);
    while(24 > bin_int_part.size() + bin_float_part.size()){
        dec_float_part *= 2;
        if (dec_float_part > 1){
            bin_float_part.push_back(true);
            dec_float_part -= 1;
        } else {
            bin_float_part.push_back(false);
        }
    }
    std::vector<bool> tmp = dec_to_bin_int(bin_int_part.size()-1);
    std::vector<bool> expo(8);
    std::vector<bool>::reverse_iterator rit = tmp.rbegin();
    int index = 7;
    while(rit != tmp.rend() && index >= 0){
        expo[index] = *rit;
        index--;
        ++rit;
    }
    for (bool b: expo){
        result->push_back(b);
        std::cout << b;
    }
    std::cout << std::endl;
    std::vector<bool>::iterator it = bin_int_part.begin();
    while(*it != 1){
        it++;
    }
    it++;
    bin_int_part.erase(bin_int_part.begin(), it);
    bin_int_part.shrink_to_fit();
    for (bool b: bin_int_part){
        result->push_back(b);
        std::cout << b;
    }
    std::cout << std::endl;
    for (bool b: bin_float_part){
        result->push_back(b);
        std::cout << b;
    }
    std::cout << std::endl;
    return *result;
}