# makefile dosyası

# derleyici ve bayrakları belirle
CC=g++
CFLAGS=-Iinclude

# hedefleri ve bağımlılıkları belirle
all: bin/main

bin/main: lib/Basamak.o lib/Sayi.o lib/SayilarListesi.o lib/main.o
	$(CC) -o bin/main lib/Basamak.o lib/Sayi.o lib/SayilarListesi.o lib/main.o

lib/Basamak.o: src/Basamak.cpp include/Basamak.h
	$(CC) $(CFLAGS) -c src/Basamak.cpp -o lib/Basamak.o

lib/Sayi.o: src/Sayi.cpp include/Sayi.h include/Basamak.h include/SayilarListesi.h
	$(CC) $(CFLAGS) -c src/Sayi.cpp -o lib/Sayi.o

lib/SayilarListesi.o: src/SayilarListesi.cpp include/SayilarListesi.h include/Sayi.h include/Basamak.h
	$(CC) $(CFLAGS) -c src/SayilarListesi.cpp -o lib/SayilarListesi.o

lib/main.o: src/main.cpp include/Sayi.h include/Basamak.h include/SayilarListesi.h
	$(CC) $(CFLAGS) -c src/main.cpp -o lib/main.o

# temizleme kuralı
clean:
	rm -f lib/*.o bin/main
