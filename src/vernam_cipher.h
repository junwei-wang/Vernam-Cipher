#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *  Author:      Junwei Wang 
 *  Date:        10th, Oct, 2013
 *  Description: A simple Vernam Cipher 
 */

/*
 * Encrypt message m using key k, and storing in c
 */ 
void encrypt(unsigned char * c, const unsigned char * m,
            const unsigned char * k, int m_len, int k_len);

/*
 * Decrypt ciphertext c using key k, and storing in m
 */
void decrypt(unsigned char * m, const unsigned char * c,
            const unsigned char * k, int m_len, int k_len);
