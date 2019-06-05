#include <iostream>
#include <iterator>

#include "Hashtable.h"
#include "HashFunctions.h"

using namespace std;

class Adress {
private:
  
public:
  string owner;
  string street;
  string town;
  int year;
  int pets;
  /* TODO: add */

  Adress() {
    this->year = 0;
    this->pets = 0;
  }

  Adress(string owner, string street, string town, int year, int pets) {
    /* TODO */
    this->owner = owner;
    this->street = street;
    this->town = town;
    this->year = year;
    this->pets = pets;
  }

  friend std::ostream& operator<< (std::ostream &out, const Adress& adress);
};

std::ostream& operator<< (std::ostream &out, const Adress& Adress) {
  cout << Adress.owner << "'s adress is " << Adress.street << ", " << Adress.town;
  return out;
}

int main() {
  /* TODO: create hashtable database */
  Hashtable<string, Adress> db(7, &smart_hash);

  Adress a1("Bender Bending Rodriguez", "Robot Arms Apts.", "New York", 3000, 4);
  Adress a2("Amy Wong", "Wong Ranch", "Western hemisphere of Mars", 3000, 4);
  Adress a3("Hubert J. Farnsworth", "West 57th Street", "New York", 2380, 10);
  Adress a4("Leela Turanga", "Planet Express Starship", "New York", 2900, 55);
  Adress a5("John A. Zoidberg", "Decapod 10", "Space", 3000, 40);
  Adress a6("Kif Kroker", "Nimbus Starship", "Space", 2800, 30);
  Adress a7("Philip J. Fry", "Applied Cryogenics", "New York", 2800, 30);

  /* TODO: Add Adresss to hashtable */
  cout << "------------------------ HASHTABLE INITIAL --------------------------\n";
  
  db.put("Robot Arms Apts." ,a1);
  db.put("Western hemisphere of Mars", a2);
  db.put("West 57th Street", a3);
  db.put("Planet Express Starship", a4);
  db.put("Decapod 10", a5);
  db.put("Nimbus Starship", a6);
  
  db.put("Applied Cryogenics", a7);
  db.print_hashtable();
  cout << "\n------------------------ STATUS ADRESA -------------------------------\n";
  /* TODO: Print status of address - does somebody live there or not? */
  string AdressToFind = "Supermassive Black Hole";
  if (db.has_key(AdressToFind) == 0)
    cout << "There is nobody\n";
  else
    cout << "somebody live there\n";

  cout << "\n------------------------ AN MUTARE ----------------------\n";
  /* TODO: Print the year when the owner moved in */
  string house_owner = "John A. Zoidberg";

  for (int i = 0; i < db.get_capacity(); i++) {
    std::list<struct info<string, Adress>>::iterator it;
  
    for (it = db.H[i].begin(); it != db.H[i].end(); it++) {
      if (house_owner == it->value.owner) {
        cout << "The owner exist\n";
      }
    }
    
  }
    cout << "\n------------------------ HASHTABLE DUPA ELIMINARI -------------------\n";
  /* TODO: Remove owners with more than 50 pets */

    for (int i = 0; i < db.get_capacity(); i++) {
    std::list<struct info<string, Adress>>::iterator it;
  
    for (it = db.H[i].begin(); it != db.H[i].end(); it++) {
      if (it->value.pets > 50) {
        string strada = it->value.street;
        cout << strada << '\n';
        db.remove(strada);
        it--;
      }
    }
    
  }
  
  //db.remove("Planet Express Starship");
  //db.remove("Decapod 10");

  db.print_hashtable();

  return 0;
}
