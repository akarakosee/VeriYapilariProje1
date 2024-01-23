
#ifndef SAYILARLISTESI_H
#define SAYILARLISTESI_H

#include "Sayi.h"

class SayilarListesi {
private:
    class Dugum { // Dugum sınıfının bildirimi
    public:
        Sayi* sayi; // sayıyı tutan pointer
        Dugum* sonraki; // sonraki düğümü gösteren pointer
        Dugum(Sayi* sayi); // düğüm oluşturan yapıcı fonksiyon
    };
    Dugum* ilk; // sayılar listesinin ilk düğümü
public:
	int deger=0;
    SayilarListesi(); // sayılar listesi oluşturan yapıcı fonksiyon
    ~SayilarListesi(); // sayılar listesini silen yıkıcı fonksiyon
    void ekle(Sayi* sayi); // sayılar listesine sayı ekleyen fonksiyon
	void yazdir() const; 
    void tersCevir(); // sayıların basamaklarını ters çeviren fonksiyon
	void tekleriBasaAl(); // sayılar listesindeki tek olan sayıları başa taşıyan fonksiyon
    void enBuyukSayiyiSil(); // en büyük sayıyı listeden silen fonksiyon


};

#endif // SAYILARLISTESI_H
