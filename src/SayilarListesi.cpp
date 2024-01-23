
#include <iostream>
#include "../include/SayilarListesi.h"

using namespace std;

// SayilarListesi sınıfının yapıcı fonksiyonunun tanımlaması
SayilarListesi::SayilarListesi() : ilk(nullptr) {}

// SayilarListesi sınıfının yıkıcı fonksiyonunun tanımlaması
SayilarListesi::~SayilarListesi() {
    Dugum* temp = ilk;
    while (temp != NULL) {
        Dugum* sil = temp;
        temp = temp->sonraki;
        delete sil;
    }
}

// ekle fonksiyonunun tanımlaması
void SayilarListesi::ekle(Sayi* sayi) {
    if (ilk == NULL) {
        ilk = new Dugum(sayi);
    } else {
        Dugum* temp = ilk;
        while (temp->sonraki != NULL) {
            temp = temp->sonraki;
        }
        temp->sonraki = new Dugum(sayi);
    }
}

// sayılar listesindeki sayıları istediğiniz şekilde ekrana yazdıran fonksiyon
void SayilarListesi::yazdir() const {
    Dugum* gecici = ilk; // ilk düğümü gösteren geçici pointer
    while (gecici != nullptr) { // bağlı listenin sonuna gelene kadar
        gecici->sayi->yazdir(); // düğümdeki sayıyı istediğiniz şekilde ekrana yazdır
        gecici = gecici->sonraki; // sonraki düğüme geç
    }
}

void SayilarListesi::tersCevir() {
    Dugum* temp = ilk;
    while (temp != nullptr) {
        temp->sayi->tersCevir(); // sayının basamaklarını ters çevir
        temp = temp->sonraki;
    }
}

void SayilarListesi::tekleriBasaAl() {
    Dugum* temp = ilk;
    while (temp != nullptr) {
        temp->sayi->tekleriBasaAl(); // sayının tek basamaklarını başa taşı
        temp = temp->sonraki;
    }
}

void SayilarListesi::enBuyukSayiyiSil() {
    Dugum* temp = ilk;
    Dugum* enBuyukSayiDugumu = nullptr;
    int enBuyukSayi = 0;
    // En büyük sayıyı bul
    while (temp != nullptr) {
        int sayiDegeri = temp->sayi->degeriAl();
        if (sayiDegeri > enBuyukSayi) {
            enBuyukSayi = sayiDegeri;
            enBuyukSayiDugumu = temp;
        }
        temp = temp->sonraki;
    }
	
    // En büyük sayıyı sil
    if (enBuyukSayiDugumu != nullptr) {
        temp = ilk;
        if (temp == enBuyukSayiDugumu) { // Eğer en büyük sayı ilk düğümdeyse
            ilk = temp->sonraki;
        } else {
            while (temp->sonraki != enBuyukSayiDugumu) {
                temp = temp->sonraki;
            }
            temp->sonraki = enBuyukSayiDugumu->sonraki;
        }
        delete enBuyukSayiDugumu;
    }
}
// Dugum sınıfının yapıcı fonksiyonunun tanımlaması
SayilarListesi::Dugum::Dugum(Sayi* sayi) : sayi(sayi), sonraki(nullptr) {}
