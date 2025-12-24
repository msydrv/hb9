/*(*) Implementieren Sie eine Klasse Stack. Verwenden Sie diese Klasse, um die Ackermann Funktion (Hausübungsaufgabe 5.21) iterativ (also nur mit Verwendung von Schleifen und ohne Rekursion) zu lösen.*/

#include<iostream>

class Stack {
    int wert;
public:
    Stack(int, int);

    friend std::ostream& operator<<(std::ostream& o, Stack x);
};

std::ostream& operator<<(std::ostream& o, Stack x);