#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"
#include <time.h>

int main() {
    // Inisialisasi data loket
    Loket loket1 = {"Lita","Avengers - Endgame",{"on", "on", "on"},{"09:00", "13:00", "17:00"}, {"studio1", "studio3", "studio2"}, NULL};
    Loket loket2 = {"Siska","Spider-Man - No Way Home", {"on", "on", "on"} , {"10:00", "14:00", "18:00"}, "studio2", "studio1", "studio3", NULL};
	Loket loket3 = {"Ananda","Gatot Kaca",{"on", "on", "on"},{"11:00", "15:00", "19:00"}, "studio3", "studio2", "studio1", NULL};
	int jumlah_tiket;
    char nama_pembeli[100];
	int pilihan = 0, x, stok_tiket[4][3] = {{50,50,50},{50,50,50},{50,50,50}, {50,50,50}};
	
	
	update_loket_status(&loket1);
	update_loket_status(&loket2);
	update_loket_status(&loket3);
    
	while (pilihan != 4) {
        system("cls");
//		printf("\t========== MENU ==========\n");
//        printf("\t1. Tambah pembeli ke antrian\n");
//        printf("\t2. Tampilkan antrian pembeli\n");
//        printf("\t3. Cek Studio\n");
//        printf("\t4. Keluar\n");
//        printf("\tPilih menu: ");
		printf( "ษออออออออออออออออออออออออออออออออออออออออออออออออออป\n" );
		printf ( "บ                    Cinema XXIX                   บ\n");
		printf ( "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        printf ( "ษออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf ( "บ                       MENU                       บ\n");
		printf ( "บ                   ------------                   บ\n");
		printf ( "บ1. Pesan Tiket                                    บ\n");
		printf ( "บ2. List Antrian                                   บ\n");
		printf ( "บ3. Cek Studio                                     บ\n");
		printf ( "บ4. Keluar                                         บ\n");
		printf ( "ศออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
		printf ( "|======================================================================================================================|\n");
		printf ( " Pilih : \n");
        scanf("%d", &pilihan);
		
        switch (pilihan) {
            case 1:
                // Tambah pembeli ke antrian
                menu:
                system("cls");
        		printf("\t========== FILM ==========\n");
				printf("\t1. Avengers - Endgame \n");
				for (int i = 0; i < 3; i++) {
				printf("\t[%d] %s: %s : %s\n",i,loket1.status_loket[i], loket1.jadwal[i], loket1.studio[i]);
				if (i != 2) {
        			printf("");
    				}
				}
				printf("\n");

				printf("\t2. Spider-Man - No Way Home \n");
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s\n",i,loket2.status_loket[i], loket2.jadwal[i], loket2.studio[i]);
    			if (i != 2) {
        			printf("");
    				}
				}
				printf("\n");

				printf("\t3. Gatot Kaca \n");
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s\n",i,loket2.status_loket[i], loket2.jadwal[i], loket2.studio[i]);
    			if (i != 2) {
        			printf("");
    				}
				}
				printf("\n");
				printf("\t==================================\n");
				printf("\tPilih Film:");
        		scanf("%d", &pilihan);
        		printf("\tPilih [nomor jadwal]:");
        		scanf("%d", &x);
        		printf("\t==================================\n");
                if (strcmp(loket1.status_loket[x], "online") == 0 && pilihan == 1){
                    printf("\tAnda memilih loket untuk film Avengers - Endgame.\n");
                    printf("\tJadwal & studio: %s & %s \n",loket1.jadwal[x],loket1.studio[x]);
                    printf("\tYang Melayani: %s\n", loket1.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", stok_tiket[pilihan][x]);
                    printf("\t-------------------------------\n");
					printf("\tMasukkan Nama Anda: ");
    				scanf("%s", nama_pembeli);
					printf("\tMasukkan jumlah tiket yang dibeli: ");
    				scanf("%d", &jumlah_tiket);
    				if (jumlah_tiket <= stok_tiket[pilihan][x]){
    					tambahPembeli(&loket1, jumlah_tiket, nama_pembeli, x, pilihan, stok_tiket);
					}else{
						printf("tiket yang anda melebihi dari stok...");
						system("pause");
						goto menu;
					}
                    
                } else if (strcmp(loket2.status_loket[x], "online") == 0 && pilihan == 2) {
                    system("cls");
					printf("\tAnda memilih loket untuk film Spider-Man - No Way Home.\n");
					printf("\tjadwal & studio: %s & %s \n",loket1.jadwal[x],loket1.studio[x]);
                    printf("\tYang Melayani: %s\n", loket1.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", stok_tiket[pilihan][x]);
					printf("\t-------------------------------\n");
					printf("\tMasukkan Nama Anda: ");
    				scanf("%s", nama_pembeli);
					printf("\tMasukkan jumlah tiket yang dibeli: ");
    				scanf("%d", &jumlah_tiket);
					if (jumlah_tiket <= stok_tiket[pilihan][x]){
    					tambahPembeli(&loket2, jumlah_tiket, nama_pembeli, x, pilihan, stok_tiket);
					}else{
						printf("tiket yang anda melebihi dari stok...");
						system("pause");
						goto menu;
					}
					
                } else if (strcmp(loket3.status_loket[x], "online") == 0 && pilihan == 3) {
                    system("cls");
					printf("\tAnda memilih loket untuk film Gatot Kaca.\n");
					printf("\tjadwal & studio: %s & %s \n",loket1.jadwal[x],loket1.studio[x]);
                    printf("\tYang Melayani: %s\n", loket1.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", stok_tiket[pilihan][x]);
                    printf("\t-------------------------------\n");
					printf("\tMasukkan Nama Anda: ");
    				scanf("%s", nama_pembeli);
					printf("\tMasukkan jumlah tiket yang dibeli: ");
    				scanf("%d", &jumlah_tiket);
    				if (jumlah_tiket <= stok_tiket[pilihan][x]){
    					tambahPembeli(&loket3, jumlah_tiket, nama_pembeli, x, pilihan, stok_tiket);	
					}else{
						printf("tiket yang anda melebihi dari stok...");
						system("pause");
						goto menu;
					}
					
                } else {
                	system("cls");
                    printf("\t\t\tMaaf, loket sedang offline. Silakan coba lagi nanti.\n");
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                printf("\n\t====================================\n");
                tampilAntrian(&loket1);
                tampilAntrian(&loket2);
                tampilAntrian(&loket3);
                printf("\n1. Hapus antrian pertama");
                printf("\n2. Kembali\n");
                scanf("%d", &pilihan);
				switch(pilihan){
                	case 1:
                		hapusPembeli(&loket1);
                		hapusPembeli(&loket2);
                		hapusPembeli(&loket3);
                		break;
                	case 2:
                		break;
				}
                system("pause");
				break;
                
            case 3:
                // Tampilkan antrian pembeli di setiap loket
                
                system("cls");
                printf("\t====================================\n");
				printf("\tAvengers - Endgame ");
				for (int i = 0; i < 3; i++) {
				printf("\n\t[%d] %s: %s : %s",i, loket1.jadwal[i], loket1.studio[i], loket1.status_loket[i]);
				if (i != 2) {
        			printf(" | ");
    				}
				}
				printf(" |\n");
				printf("\t====================================\n");
				printf("\tSpider-Man - No Way Home");
				for (int i = 0; i < 3; i++) {
    			printf("\n\t[%d] %s: %s : %s",i, loket2.jadwal[i], loket2.studio[i], loket2.status_loket[i]);
    			if (i != 2) {
        			printf(" | ");
    				}
				}
				printf(" |\n");
				printf("\t====================================\n");
				printf("\tGatot Kaca ");
				for (int i = 0; i < 3; i++) {
    			printf("\n\t[%d] %s: %s : %s",i, loket3.jadwal[i], loket3.studio[i], loket3.status_loket[i]);
    			if (i != 2) {
        			printf(" | ");
    				}
				}
				printf(" |\n");
                printf("\t====================================\n");
				system("pause");
				break;
            
            case 4:
            	// Keluar dari program
                printf("\t\t\tTerima kasih telah menggunakan layanan kami.\n");
                system("pause");
				break;
            
            default:
                // Pilihan tidak valid
                printf("\t\t\tPilihan tidak valid. Silakan coba lagi.\n");
                system("pause");
                break;
        }
    }

    return 0;
}
