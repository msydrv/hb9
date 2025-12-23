#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

#include "vector.h"   // deine Implementierung

int main() {
    try {
        std::cout << "===== Konstruktor-Tests =====\n";

        Vector v0(3);                         // Nullvektor R^3
        Vector v1({1.0, 2.0, 3.0});
        Vector v2({4.0, 5.0, 6.0});

        std::cout << "v0 = " << v0 << "\n";
        std::cout << "v1 = " << v1 << "\n";
        std::cout << "v2 = " << v2 << "\n";

        std::cout << "\n===== Addition / Subtraktion =====\n";

        Vector v_add = v1 + v2;
        Vector v_sub = v2 - v1;

        std::cout << "v1 + v2 = " << v_add << "\n";
        std::cout << "v2 - v1 = " << v_sub << "\n";

        std::cout << "\n===== Skalarprodukt =====\n";

        Vector dot = v1 * 3.0; 
        std::cout << "v1 * 3 = " << dot << "\n";

        std::cout << "\n===== Norm (Laenge) =====\n";

        std::cout << "|v1| = " << v1.norm() << "\n";
        std::cout << "|v2| = " << v2.norm() << "\n";

        std::cout << "\n===== Vektorprodukt (nur R^3) =====\n";

        Vector cross = v1 / v2;
        std::cout << "v1 x v2 = " << cross << "\n";

        std::cout << "\n===== Fehlerfall: falsche Dimension =====\n";

        Vector v4({1.0, 2.0, 3.0, 4.0});
        std::cout << "Versuche v1 / v4 ...\n";
        Vector bad = v1 / v4;   // MUSS Exception werfen
        std::cout << bad << "\n"; // sollte nie erreicht werden
    }
    catch (const std::runtime_error& e) {
        std::cerr << "runtime_error: " << e.what() << "\n";
    }
    catch (...) {
        std::cerr << "Unbekannte Exception!\n";
    }

    std::cout << "\n===== Programmende =====\n";
    return 0;
}
