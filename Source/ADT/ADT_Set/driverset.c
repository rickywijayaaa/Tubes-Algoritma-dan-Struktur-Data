#include <stdio.h>
#include "set.h"

int main() {
    SetLagu laguSet;
    CreateEmptySetLagu(&laguSet);

    // Testing IsEmptySetLagu
    if (IsEmptySetLagu(laguSet)) {
        printf("SetLagu is empty.\n");
    } else {
        printf("SetLagu is not empty.\n");
    }
    Word lagu1;
    lagu1.TabWord[0] = 'L';
    lagu1.TabWord[1] = 'A';
    lagu1.TabWord[2] = 'G';
    lagu1.TabWord[3] = 'U';
    lagu1.Length = 4;


    Word lagu2;
    lagu2.TabWord[0] = 'B';
    lagu2.TabWord[1] = 'A';
    lagu2.TabWord[2] = 'R';
    lagu2.TabWord[3] = 'U';
    lagu2.Length = 4;

    // Testing InsertSetLagu
    InsertSetLagu(&laguSet, lagu1, 1);
    InsertSetLagu(&laguSet, lagu2, 1);


    // Testing DisplaySetLagu
    printf("Songs in album 1:\n");
    DisplaySetLagu(laguSet, 1);

    printf("album id: %d\n",laguSet.A[1].album_id);

    // Testing IsMemberLagu
    if (IsMemberLagu(laguSet, lagu1)) {
        printf("Lagu1 is a member of the SetLagu.\n");
    } else {
        printf("Lagu1 is not a member of the SetLagu.\n");
    }

    // Testing namalagufromalbum
    Word hasil = namalagufromalbum(laguSet,1,2);
    printf("Nama lagu from album 1, lagu ke-1: ");
    displayWord(hasil);
    printf("\n");

    // Testing CountLaguByAlbumID
    printf("Number of songs in album 1: %d\n", CountLaguByAlbumID(&laguSet, 1));

    return 0;
}
