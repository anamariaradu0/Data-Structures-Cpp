#include <iostream>
#include "Hashtable.h"
#include "HashFunctions.h"

using namespace std;

int main() {

  Hashtable<int, int> hashtable1(7, &int_hash);

  cout << "------------------- Test PUT & GET ----------------------\n";
  hashtable1.put(1211, 1);
  hashtable1.put(4444, 2);
  hashtable1.put(1000, 3);
  hashtable1.put(4566, 4);

  cout << "Dupa adaugarea $$:\n";
  hashtable1.print_hashtable();

  int a = hashtable1.get(4566);
  int b = hashtable1.get(4444);
  int c = hashtable1.get(1000);
  int d = hashtable1.get(1211);

  cout << a << " " << b << " " << c << " " << d << "\n";

  cout << "\n------------------- Test HAS_KEY ------------------------\n";
  if (hashtable1.has_key(1000)) {
    cout << "Valoarea " << hashtable1.get(1000) << ", cu cheia 1000 este in tabel\n";
  } else {
    cout << "Nu exista nici o valoare cu cheia 1000\n";
  }

  if (hashtable1.has_key(1001)) {
    cout << "Valoarea " << hashtable1.get(1001) << ", cu cheia 1001 este in tabel\n";
  } else {
    cout << "Nu exista nici o valoare cu cheia 1001\n";
  }

  cout << "\n------------------- Test REMOVE -------------------------\n";
  hashtable1.remove(1011);
  hashtable1.remove(1000);

  cout << "Dupa stergerea $$:\n";
  hashtable1.print_hashtable();

  if (hashtable1.has_key(1000)) {
    cout << "Valoarea " << hashtable1.get(1000) << " este in tabel\n";
  } else {
    cout << "Nu exista nici o valoare cu cheia 1000\n";
  }

  if (hashtable1.has_key(1211)) {
    cout << "Valoarea " << hashtable1.get(1211) << " este in tabel\n";
  } else {
    cout << "Nu exista nici o valoare cu cheia 1211\n";
  }

  return 0;
}
