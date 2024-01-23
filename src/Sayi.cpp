
#include <iostream>
#include <sstream>
#include <iomanip>
#include "../include/Sayi.h"
#include "../include/SayilarListesi.h"
#include "Sayi.h"
using namespace std;

// Sayi sınıfının yapıcı fonksiyonunun tanımlaması
Sayi::Sayi() : ilk(nullptr) {}

// Sayi sınıfının yıkıcı fonksiyonunun tanımlaması
Sayi::~Sayi() {
    Basamak* temp = ilk;
    while (temp != NULL) {
        Basamak* sil = temp;
        temp = temp->sonraki;
        delete sil;
    }
}

// ekle fonksiyonunun tanımlaması
void Sayi::ekle(int deger) {
    if (ilk == NULL) {
        ilk = new Basamak(deger);
    } else {
        Basamak* temp = ilk;
        while (temp->sonraki != NULL) {
            temp = temp->sonraki;
        }
        temp->sonraki = new Basamak(deger);
    }
}

// sayıyı istediğiniz şekilde ekrana yazdıran fonksiyon
void Sayi::yazdir() const {
    // İlk basamağı gösteren geçici bir pointer oluşturuluyor
    Basamak* gecici = this->ilk;

    // Basamak sayısını tutan bir değişken ve basamakların parametrelerini ve değerlerini tutan iki vektör oluşturuluyor
    int basamakSayisi = 0;
    vector<int> parametreler;
    vector<int> basamaklar;

    // Bağlı listenin sonuna gelene kadar basamak sayısını arttırıp basamakların parametrelerini ve değerlerini vektörlere ekliyoruz
    while (gecici != nullptr) {
        basamakSayisi++;
        parametreler.push_back(gecici->parametre * gecici->parametre);
        basamaklar.push_back(gecici->deger);
        gecici = gecici->sonraki;
    }

    // İlk satırı yazdırıyoruz
    cout << "#########";
    for (int i = 0; i < basamakSayisi; i++) {
        cout << "   *********";
    }
    cout << endl;

    // Sayının düğüm parametresini hex formatında bir stringe yazdırıyoruz
    stringstream ss;
    ss << hex << (size_t)this->ilk / 10;
    string ilkStr = ss.str();
    if (ilkStr.size() < 3) {
        ilkStr = string(3 - ilkStr.size(), '0') + ilkStr;
    }

    // Sayının düğüm parametresini ve basamakların parametrelerini hex formatında yazdırıyoruz
    cout << "#" << setw(7) << left << hex << (size_t)this << "#";
    for (int i = 0; i < basamakSayisi; i++) {
        cout << "   *  " << setw(4) << left << parametreler[i] % 1000 << " *";
    }
    cout << endl;

    // Çizgiyi yazdırıyoruz
    cout << "#-------#";
    for (int i = 0; i < basamakSayisi; i++) {
        cout << "   *********";
    }
    cout << endl;

    // Sayının değerini ve basamakları yazdırıyoruz
    cout << "#";
    int boslukSayisi = 7 - basamakSayisi; // 7-(sayının basamak sayısı)= sayının başında o kadar boşluk
    for (int i = 0; i < boslukSayisi; i++) {
        cout << " ";
    }
    for (int i = 0; i < basamakSayisi; i++) {
        cout << basamaklar[i];
    }
    cout << "#";
    for (int i = 0; i < basamakSayisi; i++) {
        cout << "   *   " << setw(1) << left << basamaklar[i] << "   *";
    }
    cout << endl;

    // Son satırı yazdırıyoruz
    cout << "#########";
    for (int i = 0; i < basamakSayisi; i++) {
        cout << "   *********";
    }
    cout << endl;
    cout << endl;
}

	// sil fonksiyonunun tanımlaması 
void Sayi::sil(int i) { // sayının basamaklarını bir vektöre kopyala 
	vector<int> basamaklar; Basamak* temp = ilk; while (temp != NULL) { basamaklar.push_back(temp->deger); temp = temp->sonraki; } int n = basamaklar.size(); // sayının basamak sayısı
	// sayının sonundan i. basamağı sil
	if (i >= 0 && i < n) { // eğer i geçerli bir indeks ise
	basamaklar.erase (basamaklar.begin () + n - 1 - i);
}
	// sayıyı yeniden oluştur
	ilk = NULL; // sayının ilk basamağını sıfırla
	for (int j = n - 2; j >= 0; j--) { // vektördeki basamakları sondan başa doğru ekle
		ekle(basamaklar[j]);
	}
}

void Sayi::basamaklariCek() {
    basamaklar.clear(); // basamakları tutan vektörü temizle
    Basamak* temp = ilk;
    while (temp != nullptr) {
        basamaklar.push_back(temp->deger);
        temp = temp->sonraki;
    }
}

void Sayi::tekleriBasaAl() {
    vector<int> tekBasamaklar;
    vector<int> ciftBasamaklar;
    Basamak* temp = ilk;
    while (temp != nullptr) {
        if (temp->deger % 2 == 1) {
            tekBasamaklar.push_back(temp->deger);
        } else {
            ciftBasamaklar.push_back(temp->deger);
        }
        temp = temp->sonraki;
    }
    ilk = nullptr; // sayının ilk basamağını sıfırla
    for (int deger : tekBasamaklar) { // tek basamakları sayıya ekle
        ekle(deger);
    }
    for (int deger : ciftBasamaklar) { // çift basamakları sayıya ekle
        ekle(deger);
    }
}

void Sayi::tersCevir() {
    vector<int> tersBasamaklar; // ters basamakları tutan vektör
    Basamak* temp = ilk;
    while (temp != nullptr) {
        tersBasamaklar.insert(tersBasamaklar.begin(), temp->deger); // basamakları vektörün başına ekleyerek ters çevir
        temp = temp->sonraki;
    }
    ilk = nullptr; // sayının ilk basamağını sıfırla
    for (int deger : tersBasamaklar) { // ters basamakları sayıya ekle
        ekle(deger);
    }
}

int Sayi::degeriAl() const {
    int deger = 0;
    Basamak* temp = ilk;
    while (temp != nullptr) {
        deger = deger * 10 + temp->deger; // sayının değerini hesapla
        temp = temp->sonraki;
    }
    return deger;
}

// operator<< fonksiyonunun tanımlaması
ostream& operator<<(ostream& os, const Sayi& s) {
    Basamak* temp = s.ilk;
    while (temp != NULL) {
        os << *temp;
        temp = temp->sonraki;
    }
    return os;
}

