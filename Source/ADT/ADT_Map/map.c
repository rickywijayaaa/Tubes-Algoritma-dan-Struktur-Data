#include "map.h"
#include "../struc.h"


/*
typedef struct {
    Word nama_album; // Maksimal Panjang judul album 100 char
    SetLagu album_lagu; // Banyak Lagu dalam album sebanyak 20 
    int lagu_length;
    int penyanyi_id;
} Album;


typedef struct {
    Album Elements[MaxEl]; // berisi album
    int count; // banyaknya album di map tersebut
} MapAlbum;
*/


/* Membuat Lagu kosong sebagai Map dari Album */
void CreateMapAlbum(MapAlbum* P){
    P->count = 0;
}


/* Mengirim true jika album Penyanyi P kosong (P.) */
boolean IsEmptyMapAlbum(MapAlbum P){
    return (P.count == 0);
}

void InsertMapAlbum(MapAlbum *P,valuetype idpenyanyi,Word AT){
    if(IsEmptyMapAlbum(*P)){
    (P)->Elements[(P)->count+1].album_id = (P)->count+1;
    (P)->Elements[(P)->count+1].penyanyi_id = idpenyanyi;
    (P)->Elements[(P)->count+1].nama_album = AT;
    (P)->count++;
    }
    
    else{
        if (!IsMemberMapAlbum(*P,AT)){
            P->Elements[P->count+1].nama_album = AT;
            P->Elements[P->count+1].penyanyi_id = idpenyanyi;
            (P)->Elements[(P)->count+1].album_id = (P)->count+1;
            P->count ++;
        }
    }
    
}


void displayMapAlbum(MapAlbum P, int idpenyanyi) {
    int j=1;
    for(int i = 1; i<= P.count;i++){
        if(P.Elements[i].penyanyi_id==idpenyanyi){
            printf("   %d. ",j);
            displayWord(P.Elements[i].nama_album);
            printf("\n");
            j++;
        }
    }
    
}

int albumtoidpenyanyi(ListPenyanyi P, Word nama) {
    int i, index;

    for (i = 0; i < P.NEff; i++) {
        if (isWordEqual(nama, P.A[i])) {
            index = i;
            return index; 
        }
    }
}

boolean IsMemberMapAlbum(MapAlbum P, Word AT){
    if(IsEmptyMapAlbum(P)){
        return false;
    }
    else{
        for (int i = 1; i <= P.count; i++) {
            if (isWordEqual(P.Elements[i].nama_album, AT)) {
                return true;
            }
        }
        return false;
    }
}

int laguAlbumID(Word input,MapAlbum P){
    int i;
    int index=0;
    for (i=1;i<=P.count;i++){
        if(isWordEqual(input,P.Elements[i].nama_album)){
            index=i;
        }
    }
    return index;
}

int jumlahalbumperpenyanyi(MapAlbum P,int idpenyanyi){
    int count = 0;

    for (int i = 1 ;i<=P.count; ++i) {
        if (P.Elements[i].penyanyi_id == idpenyanyi) {
            count++;
        }
    }

    return count; 
}