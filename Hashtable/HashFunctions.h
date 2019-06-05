#ifndef __HASHFUNCTIONS_H
#define __HASHFUNCTIONS_H

int int_hash(int number) {
  return number % 7;
}

int char_hash(std::string str) {
  return str.length() + 8497;
}

int smart_hash(std::string str) {
  /* TODO */
  int len = str.size();
  int index = 0;
  int N = 1234, x = 19;
  for (int i = 0; i < len; i++) {
    index = ((index * x) + str[i]) % N;
  }
  return index;
}

#endif
