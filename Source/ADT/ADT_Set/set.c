#include <stdio.h>
#include "set.h"
#include <stdlib.h>


/*typedef struct {
    Word nama_lagu;
    int album_id;
} Lagu;*/
/* *** Konstruktor/Kreator *** */

/*typedef struct {
	Lagu A[MaxEl]; 
	int NEff;
} SetLagu;
*/

void CreateEmptySetLagu(SetLagu *S) {
    jumlah_lagu(*S) = 0;

}

boolean IsEmptySetLagu(SetLagu W) {
    return W.jumlah_lagu == 0;
}

/* Mengirim true jika Lagu S penuh */
/* ********** Operator Dasar Lagu ********* */
void InsertSetLagu(SetLagu *S, Word Elmt,int idalbum) {
    // Insert Elmt into SetLagu if it is not already a member
    int index = (S)->jumlah_lagu + 1;
    if (!IsMemberLagu(*S, Elmt) && S->jumlah_lagu < MaxEl) {
        Lagu newLagu;
        newLagu.nama_lagu = Elmt;
        // You might want to set other fields of newLagu if needed
        S->A[index] = newLagu;
    } else {
        return;
    }
    (S)->A[index].album_id = idalbum;
    (S)->jumlah_lagu++;
}

boolean IsMemberLagu(SetLagu S, Word Elmt) {
    for (int i = 0; i < S.jumlah_lagu; i++) {
        if (isWordEqual(S.A[i].nama_lagu, Elmt)) {
            return true;
        }
    }
    return false;


}

void DisplaySetLagu(SetLagu S, int idalbum)
{
    int i;
    i = 1;
    int j =1;
    boolean check = false;
    while((i<=S.jumlah_lagu)||(!check)){
        if(S.A[i].album_id == idalbum){
            printf("   %d. ",j);
            displayWord(S.A[i].nama_lagu);
            printf("\n");
            j++;

        }
        else {
            check =true;
        }
        i++;
    }
}

int CountLaguByAlbumID(SetLagu *setLagu, int targetAlbumID) {
    int count = 0;

    for (int i = 1; i <= setLagu->jumlah_lagu; ++i) {
        if (setLagu->A[i].album_id == targetAlbumID) {
            count++;
        }
    }

    return count;
}

Word namalagufromalbum (SetLagu p2,int albumid, int lagukeberapa){
    int count =0;

    for (int i = 1; i <= p2.jumlah_lagu; ++i) {
        if (p2.A[i].album_id == albumid) {
            count++;
            if (count == lagukeberapa) {
                return p2.A[i].nama_lagu;
            }
        }
        
    }
}

/*
void DeleteLagu(Lagu *S, infotype Elmt) {
    int i, j;
    for (i = 0; i < MaxEl; i++) {
        if (S->lagu_nama[i] != NULL) {
            for (j = 0; S->lagu_nama[i][j] != '\0' && Elmt[j] != '\0'; j++) {
                if (S->lagu_nama[i][j] != Elmt[j]) {
                    break;
                }
            }
            if (S->lagu_nama[i][j] == '\0' && Elmt[j] == '\0') {
                S->lagu_nama[i] = NULL;
                S->count--; // Mengurangi count saat menghapus elemen
                break;
            }
        }
    }
}

boolean IsMemberLagu(Lagu S, infotype Elmt) {
    int i, j;
    for (i = 0; i < MaxEl; i++) {
        if (S.lagu_nama[i] != NULL) {
            for (j = 0; S.lagu_nama[i][j] != '\0' && Elmt[j] != '\0'; j++) {
                if (S.lagu_nama[i][j] != Elmt[j]) {
                    break;
                }
            }
            if (S.lagu_nama[i][j] == '\0' && Elmt[j] == '\0') {
                return true;
            }
        }
    }
    return false;
}
void DisplayLagu(Lagu S) {
    printf("Album ID: %d\n", S.album_id);
    printf("Daftar Lagu:\n");

    for (int i = 0; i < MaxEl; i++) {
        if (S.lagu_nama[i] != NULL) {
            printf("%d. %s\n", i + 1, S.lagu_nama[i]);
        }
    }
}
*/