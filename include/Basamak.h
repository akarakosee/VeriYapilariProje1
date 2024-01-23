
#ifndef BASAMAK_H
#define BASAMAK_H

#include <iostream>

class Basamak {
public:
    int deger; // basamağın değeri
    Basamak* sonraki; // sonraki basamağı gösteren pointer
    int parametre; // basamağın parametresi
    Basamak(int deger); // basamak oluşturan yapıcı fonksiyon
    friend std::ostream& operator<<(std::ostream& os, const Basamak& b); // basamağı ekrana yazdıran fonksiyon
};

#endif // BASAMAK_H
