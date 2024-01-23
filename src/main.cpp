
#include <fstream>
#include <string>
#include <iostream>
#include "../include/Sayi.h"
#include "../include/SayilarListesi.h"
#include <stdio.h>

using namespace std;

int main() {
    ifstream dosya("Sayilar.txt");
    string satir;
    SayilarListesi* liste = new SayilarListesi();
    while (getline(dosya, satir)) {
        Sayi* sayi = new Sayi();
        for (char c : satir) {
            if (c != ' ') {
                sayi->ekle(c - '0');
            } else {
                sayi->basamaklariCek();
                liste->ekle(sayi);
                sayi = new Sayi();
            }
        }
        sayi->basamaklariCek();
        liste->ekle(sayi);
    }
    liste->yazdir();
    cout << "1. Tek Basamaklari Basa al\n";
    cout << "2. Basamaklari Tersten yazdir\n";
    cout << "3. En buyuk sayiyi listeden cikar\n";
    cout << "4. Cikis\n";
    cout << "Seciminiz: ";
    int secim;
    cin >> secim;
    switch (secim) {
        case 1:
            liste->tekleriBasaAl(); // sayıların tek basamaklarını basa alır
            liste->yazdir();	//sayıları güncellenmiş şekilde yazdırır
            break;
		case 2:
            liste->tersCevir(); // sayıların basamaklarını ters çevir
            liste->yazdir(); // sayıları güncellenmiş şekilde yazdırır       
			break;
        case 3:
			liste->enBuyukSayiyiSil(); // en büyük sayıyı listeden sil
            liste->yazdir(); // sayıları güncellenmiş şekilde yazdırır
			break;
        case 4:
            cout << "Programdan Cikiliyor...\n";
            break;
        default:
            cout << "Gecersiz Secim!\n";
            break;
    }
    delete liste;
    return 0;
}
