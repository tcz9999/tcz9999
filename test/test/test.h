#ifndef IODRV_H
#define IODRV_H

void test_fill_longs();

int read_column_numbers(int columns[],int max);
void rearrange(char *output,char const *input,int n_columns,int columns[]);
void test7();

#endif