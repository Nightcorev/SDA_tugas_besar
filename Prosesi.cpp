#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"
#include <time.h>

void tambahPembeli(Loket *loket, int jumlah_tiket, char* nama_pembeli, int x) {
    // Buat node baru untuk pembeli
    Pembeli *pembeli_baru = (Pembeli*) malloc(sizeof(Pembeli));
    strcpy(pembeli_baru->nama_pembeli, nama_pembeli);
	pembeli_baru->jumlah_tiket = jumlah_tiket;
	strcpy(pembeli_baru->jadwal_pesan, loket->jadwal[x]);
	strcpy(pembeli_baru->studio_pesan, loket->studio[x]);
	pembeli_baru->next = NULL;
	
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
        	printf(" | %s(%d) | %s | %s | =>",current->nama_pembeli, current->jumlah_tiket, current->jadwal_pesan, current->studio_pesan);
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
    
    for (int i = 0; i < 3; i++) {
        if (strcmp("18:30", time_string) < 0 || strcmp("08:00", time_string) > 0) 
		{
            printf("\n\t\tbioskop tutup...");
			exit(1);
        } else {
            break;
        }
    }
    
}

void bioskop_isfull(Loket *loket) {
    for (int i = 0; i < 3; i++) {
        if (loket->stok_tiket[i] == 0) {
            strcpy(loket->status_loket[i], "Penuh");
        }
    }
}

float hitung_total_harga(float harga_tiket, int jumlah_tiket) {
    float total_harga = harga_tiket * jumlah_tiket;
    return total_harga;
}
