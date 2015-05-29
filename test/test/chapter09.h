#ifndef CHAPTER09_H
#define CHAPTER09_H

int prepare_key(char *key);
void encrypt(char *data, char const *key);
void decrypt(char *data, char const *key);
void test_encrypt(void);

#endif