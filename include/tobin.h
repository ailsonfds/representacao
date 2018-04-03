#ifndef __TOBIN_H__
#define __TOBIN_H__

#include <iostream>
#include <vector>
#include <sstream>

/**
 * Transforma um numero de base dez natural em base dois.
 *
 * @param number O numero natural na base dez a ser convertido para a base dois.
 *
 */
std::vector<bool>& dec_to_bin_nat_32_bit(size_t number);

/**
 * Transforma um numero de base dez natural em base dois.
 *
 * @param number O numero natural na base dez a ser convertido para a base dois.
 *
 */
std::vector<bool>& dec_to_bin_nat(size_t number);

/**
 * Converte um numero inteiro na base dez para a base dois.
 *
 * @param number O numero a ser convertido.
 *
 */
std::vector<bool>& dec_to_bin_int(int number);

/**
 * Converte um numero inteiro na base dez para a base dois.
 *
 * @param number O numero a ser convertido.
 *
 */
std::vector<bool>& dec_to_bin_int_32_bit(int number);

/**
 * Converte um numero em ponto flutuante na base dez para a base dois.
 *
 * @param number O numero a ser convertido.
 *
 */
std::vector<bool>& dec_to_bin_float_IEEE754(double number);

#endif /** __TOBIN_H__ **/