#include "isilagu.h"
#include <stdio.h>

void CreateD(Detail *d, Word penyanyi, Word album, Word lagu) {
    PasteWord(penyanyi, &(*d).Penyanyi);
    PasteWord(album, &(*d).Album);
    PasteWord(lagu, &(*d).Lagu);
}

boolean IsEmptyD(Detail d) {
    return d.Penyanyi.Length == 0 && d.Album.Length == 0 && d.Lagu.Length == 0;
}

boolean IsIsiSama(Detail d1, Detail d2) {
    return (isWordEqual(d1.Penyanyi, d2.Penyanyi) && isWordEqual(d1.Album, d2.Album) && isWordEqual(d1.Lagu, d2.Lagu));
}

void PasteD(Detail source, Detail *dest) {
    PasteWord(source.Penyanyi, &(*dest).Penyanyi);
    PasteWord(source.Album, &(*dest).Album);
    PasteWord(source.Lagu, &(*dest).Lagu);
}

void DisplayD(Detail d) {
    if (IsEmptyD(d)) {
        printf("Kosong\n");
    }
    else {
        displayWord(d.Penyanyi);
        printf(" - ");
        displayWord(d.Album);
        printf(" - ");
        displayWord(d.Lagu);
        printf("\n");
    }
}