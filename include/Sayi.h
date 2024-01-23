
#ifndef SAYI_H
#define SAYI_H

#include "Basamak.h"
#include <vector>

class Sayi {
private:
    Basamak* ilk; // sayının ilk basamağı
    std::vector<int> basamaklar; // basamakları tutan vektör
public:
	int deger=0;
    Sayi(); // sayı oluşturan yapıcı fonksiyon
    ~Sayi(); // sayıyı silen yıkıcı fonksiyon
    void ekle(int deger); // sayıya basamak ekleyen fonksiyon
    void yazdir() const; // sayıyı istediğimiz şekilde ekrana yazdıran fonksiyon
	void tersCevir(); // sayının basamaklarını ters çeviren fonksiyon
    void tekleriBasaAl(); // sayının tek basamaklarını başa taşıyan fonksiyon
    void sil(int i); // sayının sonundan i. basamağı silen fonksiyon
    friend std::ostream& operator<<(std::ostream& os, const Sayi& s); // sayıyı ekrana yazdıran fonksiyon
    void basamaklariCek(); // sayının basamaklarını sırasıyla çeken fonksiyon
    int degeriAl() const; // sayının değerini döndüren fonksiyon

};

#endif // SAYI_H
