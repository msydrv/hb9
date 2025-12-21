#include <iostream>
#include <stdexcept>

#include "secret.h"

using namespace std;

int main() {
    cout << "=== Konstruktoren ===\n";
    Secret open1("Hello");
    Secret open2("World");
    Secret locked1("TopSecret", "1234");

    cout << "open1: " << open1 << "\n";
    cout << "open2: " << open2 << "\n";
    cout << "locked1: " << locked1 << "\n";   // darf nichts ausgeben

    cout << "\n=== len() ===\n";
    cout << "open1.len(): " << open1.len() << "\n";
    cout << "locked1.len(): " << locked1.len() << "\n"; // muss 0 sein

    cout << "\n=== lock() ===\n";
    bool r1 = open1.lock("pw");
    cout << "lock open1: " << r1 << "\n";
    cout << "open1 after lock: " << open1 << "\n";

    bool r2 = open1.lock("newpw"); // darf nicht gehen (schon gesperrt)
    cout << "lock again: " << r2 << "\n";

    cout << "\n=== unlock() ===\n";
    bool r3 = open1.unlock("wrong");
    cout << "unlock wrong pw: " << r3 << "\n";

    bool r4 = open1.unlock("pw");
    cout << "unlock correct pw: " << r4 << "\n";
    cout << "open1 after unlock: " << open1 << "\n";

    cout << "\n=== operator+ ===\n";
    try {
        Secret sum = open1 + open2;
        cout << "sum: " << sum << "\n";
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << "\n";
    }

    try {
        Secret fail = open1 + locked1; // muss Exception werfen
        cout << fail << "\n";
    } catch (const runtime_error& e) {
        cout << "Exception (expected): " << e.what() << "\n";
    }

    cout << "\n=== Ausgabeoperator << ===\n";
    cout << "open2: " << open2 << "\n";
    cout << "locked1: " << locked1 << "\n"; // leer

    cout << "\n=== Ende Tests ===\n";
    return 0;
}
