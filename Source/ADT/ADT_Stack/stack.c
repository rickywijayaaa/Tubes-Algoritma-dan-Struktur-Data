#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../struc.h"
#include "../boolean.h"

void CreateHist(HistoriLagu *S){
    (*S).idxTop = -1; 
    (*S).count = 0;
}
/*  
I.S. Sembarang
F.S. Terbentuk Stack kosong
*/

boolean IsHistEmpty(HistoriLagu S){
    return(S.count==0);
}
/*  
Menghasilkan True jika Stack kosong, dan False jika Stack tidak kosong
*/
void PushLagu(HistoriLagu *S, char *lagu, char *album, char *artis) {
    if (S->idxTop < MaxEl - 1) {
        S->idxTop++;
        S->hist_lagu[S->idxTop].lagu_playlist = lagu;
        S->hist_lagu[S->idxTop].album_playlist = album;
        S->hist_lagu[S->idxTop].Penyanyi_playlist = artis;
        S->count++;
    } else {
        // Tumpukan penuh, tidak dapat menambahkan lagi
        printf("Tumpukan penuh. Tidak dapat menambahkan lagi.\n");
    }
}

/*
I.S. Sembarang, P terdefinisi
F.S. Menempatkan P pada Top dari S (History lagu)
*/

void PopLagu(HistoriLagu *S, char **lagu, char **album, char **artis) {
    if (S->idxTop >= 0) {
        // Mengakses elemen-elemen dari struktur dengan operator panah (->)
        *lagu = S->hist_lagu[S->idxTop].lagu_playlist;
        *album = S->hist_lagu[S->idxTop].album_playlist;
        *artis = S->hist_lagu[S->idxTop].Penyanyi_playlist;
        S->idxTop--;
        S->count--;
    } else {
        // Tumpukan kosong, tidak dapat menghapus lagi
        printf("Tumpukan kosong. Tidak dapat menghapus lagi.\n");
    }
}

/*
I.S. Stack tidak kosong
F.S. Mengambil P dari Top dari S
*/
void Viewhist(HistoriLagu S) {
    if (IsHistEmpty(S)) {
        printf("Tumpukan kosong. Tidak ada informasi yang dapat ditampilkan.\n");
    } else {
        printf("Daftar Lagu dalam HistoriLagu:\n");
        printf("[");
        for (int i = 0; i <= S.idxTop; i++) {
            printf("(%s, %s, %s)", S.hist_lagu[i].lagu_playlist, S.hist_lagu[i].album_playlist,S.hist_lagu[i].Penyanyi_playlist);
            if (i < S.idxTop) {
                printf(", ");
            }
        }
        printf("], %d\n", S.count);
    }
}

