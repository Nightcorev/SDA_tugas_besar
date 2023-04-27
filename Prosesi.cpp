#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"
#include <time.h>

void tambahPembeli(Loket *loket, int jumlah_tiket, char* nama_pembeli, int x, int pilihan, int stok_tiket[3][3]) {
    // Buat node baru untuk pembeli
    Pembeli *pembeli_baru = (Pembeli*) malloc(sizeof(Pembeli));
    strcpy(pembeli_baru->nama_pembeli, nama_pembeli);
	pembeli_baru->jumlah_tiket = jumlah_tiket;
    pembeli_baru->next = NULL;
	
	stok_tiket[pilihan][x] = stok_tiket[pilihan][x] - jumlah_tiket;
        // Jika stok tiket kurang dari jumlah tiket yang diminta
    // Cek apakah antrian kosong
    if (loket->head == NULL) {
        loket->head = pembeli_baru;
    } else {
        // Jika tidak kosong, tambahkan node pembeli baru ke akhir antrian
        Pembeli *current = loket->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pembeli_baru;
    }
}
// Fungsi untuk menghapus pembeli dari antrian
void hapusPembeli(Loket *loket) {
    // Cek apakah antrian kosong
    if (loket->head == NULL) {
        printf("\t%s : Antrian kosong.\n", loket->nama_film);
    } else {
        // Jika tidak kosong, hapus node pembeli pertama dari antrian
        Pembeli *hapus = loket->head;
        Pembeli *tmp = loket->head;
		loket->head = hapus->next;
        
        free(hapus);
        printf("\t%s : Pembeli pertama berhasil dihapus dari antrian.\n", loket->nama_film);
    }
}

// Fungsi untuk menampilkan antrian pembeli di setiap loket
void tampilAntrian(Loket *loket) {
    printf("\tLoket (%s) %s: \n", loket->nama_pekerja_loket, loket->nama_film);

    // Cek apakah antrian kosong
    if (loket->head == NULL) {
        printf("\tAntrian kosong.\n");
        printf("\n\t====================================\n");
    } else {
        // Jika tidak kosong, tampilkan node-node pembeli di antrian
        Pembeli *current = loket->head;
        printf("\tPembeli:");
        while (current != NULL) {
        	printf(" %s(%d) -",current->nama_pembeli, current->jumlah_tiket);
            current = current->next;
        }
        printf("\n\t===================================\n");

    }
}



void update_loket_status(Loket *loket) {
    time_t current_time;
    struct tm* time_info;
    char time_string[100];

    // Dapatkan waktu saat ini
    time(&current_time);
    time_info = localtime(&current_time);

    // Format waktu saat ini menjadi string
    strftime(time_string, sizeof(time_string), "%H:%M", time_info);

    // Cek status setiap jadwal pada loket
    for (int i = 0; i < 3; i++) {
        if (strcmp(loket->jadwal[i], time_string) < 0) {
            strcpy(loket->status_loket[i], "offline");
        } else {
            strcpy(loket->status_loket[i], "online");
        }
    }
}
