
#include <iostream>
#include "../include/Basamak.h"

using namespace std;

// Basamak sınıfının yapıcı fonksiyonunun tanımlaması
Basamak::Basamak(int deger) : deger(deger), sonraki(nullptr) {
	parametre = deger * deger; // parametre üyesinin değerini hesapla
}

// operator<< fonksiyonunun tanımlaması
ostream& operator<<(ostream& os, const Basamak& b) {
    os << b.deger;
    return os;
}
