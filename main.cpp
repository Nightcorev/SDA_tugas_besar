#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"

int main() {
    Loket loket1 = {"Lita","Avengers - Endgame",{"on", "on", "on"},{"09:00", "12:30", "15:30"}, {"studio1", "studio2", "studio3"},{50,50,50}, NULL};
    Loket loket2 = {"Siska","Spider-Man - No Way Home", {"on", "on", "on"} , {"09:30", "12:30", "15:00"}, {"studio2", "studio3", "studio1"},{50,50,50}, NULL};
	Loket loket3 = {"Ananda","Gatot Kaca",{"on", "on", "on"},{"10:00", "12:30", "16:00"}, {"studio3", "studio1", "studio2"},{50,50,50}, NULL};
	int jumlah_tiket;
    char nama_pembeli[100], jadwal_pesan[10], studio_pesan[10];
	int pilihan = 0, x;
    float harga[3] = {40.000, 35.000, 30.000};
    //Avengers 3jam 30menit
    //Spiderman 3 jam
    //Gatot Kaca 2jam 30 menit
    char durasi_film1[20] = "3Jam-30Menit", durasi_film2[20] = "3Jam", durasi_film3[20] = "2Jam-30Menit";
    
	
	update_loket_status(&loket1);
	update_loket_status(&loket2);
	update_loket_status(&loket3);
    
	while (pilihan != 4) {
        system("cls");
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
		printf ( "|====================================================|\n");
		printf ( " Pilih : ");
        scanf("%d", &pilihan);
		
        switch (pilihan) {
            case 1:
                // Tambah pembeli ke antrian
                menu:
                system("cls");
        		printf("\t========== FILM ==========\n");
				printf("\t1. Avengers - Endgame\n");
				printf("\tHarga Tiket: Rp %.3f\n", harga[0]);
				printf("\tDurasi Film: %s\n", durasi_film1);
				printf("\t-------------------------------------------------\n");
				for (int i = 0; i < 3; i++) {
				printf("\t[%d] %s: %s : %s : sisa kursi = %d\n",i,loket1.status_loket[i], loket1.jadwal[i], loket1.studio[i], loket1.stok_tiket[i]);
				if (i != 2) {
        			printf("");
    				}
				}
				printf("\n");

				printf("\t2. Spider-Man - No Way Home \n");
				printf("\tHarga Tiket: Rp %.3f\n", harga[1]);
				printf("\tDurasi Film: %s\n", durasi_film2);
				printf("\t-------------------------------------------------\n");
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s : sisa kursi = %d\n",i,loket2.status_loket[i], loket2.jadwal[i], loket2.studio[i], loket2.stok_tiket[i]);
    			if (i != 2) {
        			printf("");
    				}
				}
				printf("\n");

				printf("\t3. Gatot Kaca \n");
				printf("\tHarga Tiket: Rp %.3f\n", harga[2]);
				printf("\tDurasi Film: %s\n", durasi_film3);
				printf("\t-------------------------------------------------\n");
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s : sisa kursi = %d\n",i,loket3.status_loket[i], loket3.jadwal[i], loket3.studio[i], loket3.stok_tiket[i]);
    			if (i != 2) {
        			printf("");
    				}
				}
				printf("\t=================================================\n");
				printf("\tPilih Film:");
        		scanf("%d", &pilihan);
        		printf("\tPilih [nomor jadwal]:");
        		scanf("%d", &x);
                printf("\t----------------------------------\n");
				if (strcmp(loket1.status_loket[x], "online") == 0 && pilihan == 1){
                    printf("\tAnda memilih loket film Avengers - Endgame.\n");
					printf("\tJadwal & studio: %s & %s \n",loket1.jadwal[x],loket1.studio[x]);
                    printf("\tYang Melayani: %s\n", loket1.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", loket1.stok_tiket[x]);
                    printf("\t-------------------------------\n");
					printf("\tMasukkan Nama Anda: ");
    				scanf("%s", nama_pembeli);
					printf("\tMasukkan jumlah tiket yang dibeli: ");
    				scanf("%d", &jumlah_tiket);
    				float total_harga1 = hitung_total_harga(harga[0], jumlah_tiket);
					printf("\tTotal harga:\t\tRp %.3f\n", total_harga1);
    				if (jumlah_tiket <= loket1.stok_tiket[x]){
    					loket1.stok_tiket[x] = loket1.stok_tiket[x] - jumlah_tiket;
    					tambahPembeli(&loket1, jumlah_tiket, nama_pembeli, x);
    					bioskop_isfull(&loket1);
    					system("pause");
					}else{
						printf("tiket yang anda pesan melebihi dari stok...");
						system("pause");
						goto menu;
					}
                    
                } else if (strcmp(loket2.status_loket[x], "online") == 0 && pilihan == 2) {
					printf("\tAnda memilih loket film Spider-Man - No Way Home.\n");
					printf("\tjadwal & studio: %s & %s \n",loket2.jadwal[x],loket2.studio[x]);
                    printf("\tYang Melayani: %s\n", loket2.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", loket2.stok_tiket[x]);
					printf("\t-------------------------------\n");
					printf("\tMasukkan Nama Anda: ");
    				scanf("%s", nama_pembeli);
					printf("\tMasukkan jumlah tiket yang dibeli: ");
    				scanf("%d", &jumlah_tiket);
					float total_harga2 = hitung_total_harga(harga[1], jumlah_tiket);
					printf("\tTotal harga:\t\tRp %.3f\n", total_harga2);
					if (jumlah_tiket <= loket2.stok_tiket[x]){
						loket2.stok_tiket[x] = loket2.stok_tiket[x] - jumlah_tiket;
    					tambahPembeli(&loket2, jumlah_tiket, nama_pembeli,x);
    					bioskop_isfull(&loket2);
    					system("pause");
					}else{
						printf("tiket yang anda pesan melebihi dari stok...");
						system("pause");
						goto menu;
					}
					
                } else if (strcmp(loket3.status_loket[x], "online") == 0 && pilihan == 3) {
					printf("\tAnda memilih loket film Gatot Kaca.\n");
					printf("\tjadwal & studio: %s & %s \n",loket3.jadwal[x],loket3.studio[x]);
                    printf("\tYang Melayani: %s\n", loket3.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", loket3.stok_tiket[x]);
                    printf("\t-------------------------------\n");
					printf("\tMasukkan Nama Anda: ");
    				scanf("%s", nama_pembeli);
					printf("\tMasukkan jumlah tiket yang dibeli: ");
    				scanf("%d", &jumlah_tiket);
    				float total_harga3 = hitung_total_harga(harga[2],jumlah_tiket);
					printf("\tTotal harga:\t\tRp %.3f\n", total_harga3);
    				if (jumlah_tiket <= loket3.stok_tiket[x]){
    					loket3.stok_tiket[x] = loket3.stok_tiket[x] - jumlah_tiket;
    					tambahPembeli(&loket3, jumlah_tiket, nama_pembeli, x);	
    					bioskop_isfull(&loket3);
    					system("pause");
					}else{
						printf("tiket yang anda pesan melebihi dari stok...");
						system("pause");
						goto menu;
					}
					
                } else {
                    printf("\t\t\tMaaf, loket sedang offline/Penuh. Silakan pilih jadwal lain.\n");
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
				printf("\tAvengers - Endgame \n");
				printf("\tYang melayani: %s\n", loket1.nama_pekerja_loket);
				printf("\tHarga Tiket: Rp %.3f\n", harga[0]);
				for (int i = 0; i < 3; i++) {
				printf("\t[%d] %s: %s : %s : sisa kursi = %d\n",i,loket1.status_loket[i], loket1.jadwal[i], loket1.studio[i], loket1.stok_tiket[i]);
				if (i != 2) {
        			printf(" ");
    				}
				}
				printf(" \n");
				printf("\t====================================\n");
				printf("\tSpider-Man - No Way Home\n");
				printf("\tYang melayani: %s\n", loket2.nama_pekerja_loket);
				printf("\tHarga Tiket: Rp %.3f\n", harga[1]);
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s : sisa kursi = %d\n",i,loket2.status_loket[i], loket2.jadwal[i], loket2.studio[i], loket2.stok_tiket[i]);
    			if (i != 2) {
        			printf(" ");
    				}
				}
				printf(" \n");
				printf("\t====================================\n");
				printf("\tGatot Kaca \n");
				printf("\tYang melayani: %s\n", loket3.nama_pekerja_loket);
				printf("\tHarga Tiket: Rp %.3f\n", harga[2]);
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s : sisa kursi = %d\n",i,loket3.status_loket[i], loket3.jadwal[i], loket3.studio[i], loket3.stok_tiket[i]);
    			if (i != 2) {
        			printf(" ");
    				}
				}
				printf(" \n");
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
