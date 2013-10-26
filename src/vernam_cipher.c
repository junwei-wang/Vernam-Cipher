#include "vernam_cipher.h"
/*
 *  Author:	Junwei Wang
 *  Date:	12nd, Oct, 2013
 */

/* 
 * xor the first 'len' bits of messages 's0' and 's1', the result will
 * be stored in 'res', check the length of 's0' and 's1' before using
 * this function.
 */
void xor_string_len(unsigned char * res, const unsigned char *s0, 
               const unsigned char * s1, int len) 
{
	int i;	
	for (i = 0; i < len; i++)
		*res++ = *s0++ ^ *s1++;
}

/* 
 * xor the message 's0' with 's1',
 *     if s0_len <= s1_len
 *        xor_string_len(..., s0, s1, s0_len);
 *     else 
 *        xor_string_len(..., s0, s1||s1||...||s1, s0_len)
 */
void xor_string(unsigned char * res, const unsigned char * s0,
            const unsigned char * s1, int s0_len, int s1_len)
{
	if (s0_len <= s1_len) 
		xor_string_len(res, s0, s1, s0_len);
	else {
		while (s0_len >= s1_len) {
			xor_string_len(res, s0, s1, s1_len);
			s0 += s1_len;
			res += s1_len;
			s0_len -= s1_len;
		}				

		if (s0_len > 0)
			xor_string_len(res, s0, s1, s0_len);
	}
}

void encrypt(unsigned char * c, const unsigned char * m,
            const unsigned char * k, int m_len, int k_len)
{
	xor_string(c, m, k, m_len, k_len);
}

void decrypt(unsigned char * m, const unsigned char * c,
            const unsigned char * k, int c_len, int k_len)
{
	xor_string(m, c, k, c_len, k_len);
}
