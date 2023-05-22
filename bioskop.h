#ifndef bioskop_h
#define bioskop_h
#include <stdio.h>
#include <string.h>

// Struktur data untuk pembeli tiket
typedef struct pembeli {
    int jumlah_tiket;
    char nama_pembeli[100];
    char jadwal_pesan[10];
    char studio_pesan[10];
    struct pembeli *next;
} Pembeli;

// Struktur data untuk antrian pembeli di setiap loket
typedef struct loket {
	char nama_pekerja_loket[100];
    char nama_film[100];
    char status_loket[10][10];
    char jadwal[10][10];
    char studio[10][10];
    int stok_tiket[3];
    Pembeli *head;
} Loket;


int compare_time(char* jadwal);
void update_loket_status(Loket *loket);
void tambahPembeli(Loket *loket, int jumlah_tiket, char* nama_pembeli, int x);
void hapusPembeli(Loket *loket);
void tampilAntrian(Loket *loket);
void bioskop_isfull(Loket *loket);
float hitung_total_harga(float harga_tiket, int jumlah_tiket);
#endif
