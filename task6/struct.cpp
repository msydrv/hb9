#include"struct.h"


Stack::Stack(int m, int n) {
    if(m==0) this->wert = n+1;
    else if(n == 0 && m>0) this->wert = Stack(m-1, 1).wert;
    else this->wert = Stack(m-1, Stack(m, n-1).wert).wert;
}

std::ostream& operator<<(std::ostream& o, Stack x) {
    return o << x.wert << std::endl;
}