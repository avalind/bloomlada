#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "hash.h"
#include "bitvector.h"
#include "bloomfilter.h"

void generate_random_read(size_t read_length, char *store)
{
  const char *symtable = "ACGT";
  for(int i = 0; i < read_length; i++) {
    int key = rand() % 4;
    store[i] = symtable[key];
  };
};

bool add_elements(Bloomfilter *filt, int count)
{
  //filt->add(
  char buf[101];
  buf[100] = '\0';
  for(int c = 0; c < count; c++) {
    generate_random_read(100, buf);
    std::cout << buf << std::endl;
  };
  return true;
};


int main(int argc,char **argv)
{
  srand(time(NULL));
  Bloomfilter bfilt(100, 3);

  add_elements(&bfilt, 100);


  return 0;
};
