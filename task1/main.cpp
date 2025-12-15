#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "ean_code.h"
#include "item.h"
#include "shop.h"

int main() {
    std::vector<Item> initial_items;
    Shop shop("https://buyhere.com",
              "Mein Shop",
              "Rabattstrasse",
              "80",
              "4780",
              "Billigsdorf",
              initial_items);

    char mode = '\0';

    while (true) {
        std::cout << "\nArtikel h(inzufuegen, b(earbeiten, q(uit: ";
        std::cin >> mode;

        if (mode == 'q') {
            break;
        }

        if (mode == 'h') {
            std::string ean, name, description;
            double price;
            int cat_int;

            std::cout << "EAN-Code? ";
            std::cin >> ean;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Bezeichnung: ";
            std::getline(std::cin, name);

            std::cout << "Beschreibung: ";
            std::getline(std::cin, description);

            std::cout << "Preis in Cent: ";
            std::cin >> price;

            std::cout << "Kategorie (0=Clothing, 1=Electronics, 2=Game, 3=Food): ";
            std::cin >> cat_int;

            Category cat = static_cast<Category>(cat_int);

            try {
                Item item(EAN_code(ean), name, description, price, cat);
                shop.add_item(item);
                std::cout << "Artikel hinzugefuegt.\n";
            } catch (const std::exception& e) {
                std::cout << "Fehler: " << e.what() << "\n";
            }
        } else if (mode == 'b') {
            std::string ean;
            std::cout << "EAN-Code? ";
            std::cin >> ean;

            try {
                Item& item = shop.findItem(EAN_code(ean));
                item.print(std::cout);
                std::cout << "\n";

                char action = '\0';
                while (true) {
                    std::cout << "aendern B(ezeichnung, Be(schreibung, P(reis, F(ertig: ";
                    std::cin >> action;

                    if (action == 'f') {
                        break;
                    }

                    if (action == 'b') {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::string name;
                        std::cout << "Neue Bezeichnung: ";
                        std::getline(std::cin, name);
                        item.setName(name);
                    } else if (action == 's' || action == 'e') {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::string description;
                        std::cout << "Neue Beschreibung: ";
                        std::getline(std::cin, description);
                        item.setDescription(description);
                    } else if (action == 'P') {
                        double price;
                        std::cout << "Neuer Preis in Cent: ";
                        std::cin >> price;
                        item.setPrice(price);
                    }

                    item.print(std::cout);
                    std::cout << "\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Fehler: " << e.what() << "\n";
            }
        } else {
            std::cout << "Ungueltige Eingabe.\n";
        }
    }

    return 0;
}
