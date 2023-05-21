#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"
#include <time.h>

int main() {
    // Inisialisasi data loket
    //Avengers 3jam 30menit
    //Spiderman 3 jam
    //Gatot Kaca 2jam 30 menit
    Loket loket1 = {"Lita","Avengers - Endgame",{"on", "on", "on"},{"09:00", "12:30", "15:30"}, {"studio1", "studio2", "studio3"},{50,50,50}, NULL};
    Loket loket2 = {"Siska","Spider-Man - No Way Home", {"on", "on", "on"} , {"09:30", "12:30", "15:00"}, {"studio2", "studio3", "studio1"},{50,50,50}, NULL};
	Loket loket3 = {"Ananda","Gatot Kaca",{"on", "on", "on"},{"10:00", "12:30", "16:00"}, {"studio3", "studio1", "studio2"},{50,50,50}, NULL};
	int jumlah_tiket;
    char nama_pembeli[100];
	int pilihan = 0, x, stok_tiket[4][3] = {{50,50,50},{50,50,50},{50,50,50}, {50,50,50}};
	
	
	update_loket_status(&loket1);
	update_loket_status(&loket2);
	update_loket_status(&loket3);
    
	while (pilihan != 4) {
        system("cls");
		printf( "��������������������������������������������������ͻ\n" );
		printf ( "�                    Cinema XXIX                   �\n");
		printf ( "��������������������������������������������������ͼ\n");
        printf ( "��������������������������������������������������ͻ\n");
		printf ( "�                       MENU                       �\n");
		printf ( "�                   ------------                   �\n");
		printf ( "�1. Pesan Tiket                                    �\n");
		printf ( "�2. List Antrian                                   �\n");
		printf ( "�3. Cek Studio                                     �\n");
		printf ( "�4. Keluar                                         �\n");
		printf ( "��������������������������������������������������ͼ\n");
		printf ( "|====================================================|\n");
		printf ( " Pilih : ");
        scanf("%d", &pilihan);
		
        switch (pilihan) {
            case 1:
                // Tambah pembeli ke antrian
                menu:
                system("cls");
        		printf("\t========== FILM ==========\n");
				printf("\t1. Avengers - Endgame \n");
				for (int i = 0; i < 3; i++) {
				printf("\t[%d] %s: %s : %s : Rp 50.000\n",i,loket1.status_loket[i], loket1.jadwal[i], loket1.studio[i]);
				if (i != 2) {
        			printf("");
    				}
				}
				printf("\n");

				printf("\t2. Spider-Man - No Way Home \n");
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s : Rp 50.000\n",i,loket2.status_loket[i], loket2.jadwal[i], loket2.studio[i]);
    			if (i != 2) {
        			printf("");
    				}
				}
				printf("\n");

				printf("\t3. Gatot Kaca \n");
				for (int i = 0; i < 3; i++) {
    			printf("\t[%d] %s: %s : %s : Rp 50.000\n",i,loket2.status_loket[i], loket2.jadwal[i], loket2.studio[i]);
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
                    printf("\tAnda memilih loket film Avengers - Endgame.\n");
					printf("\tJadwal & studio: %s & %s \n",loket1.jadwal[x],loket1.studio[x]);
                    printf("\tYang Melayani: %s\n", loket1.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", loket1.stok_tiket[x]);
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
					printf("\tAnda memilih loket film Spider-Man - No Way Home.\n");
					printf("\tjadwal & studio: %s & %s \n",loket2.jadwal[x],loket2.studio[x]);
                    printf("\tYang Melayani: %s\n", loket2.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", loket2.stok_tiket[x]);
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
					printf("\tAnda memilih loket film Gatot Kaca.\n");
					printf("\tjadwal & studio: %s & %s \n",loket3.jadwal[x],loket3.studio[x]);
                    printf("\tYang Melayani: %s\n", loket3.nama_pekerja_loket);
                    printf("\tStok tiket: %d\n", loket3.stok_tiket[x]);
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
