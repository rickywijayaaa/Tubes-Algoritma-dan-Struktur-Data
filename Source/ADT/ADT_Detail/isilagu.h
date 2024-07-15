#ifndef DETAIL_LAGU_H
#define DETAIL_LAGU_H

#include "../ADT_Mesin-Kata/mesinkata.h"
#include "../ADT_List/liststatis.h"

typedef Word ElType;


typedef struct {
    ElType Penyanyi;
    ElType Album;
    ElType Lagu;
} Detail;


void CreateD(Detail *d, Word penyanyi, Word album, Word lagu);
/* I.S. d sembarang. penyanyi, album, dan lagu yang terdefinisi (mungkin kosong). */
/* F.S. d menjadi detail dengan isi pennyanyi, album, dan lagu. */

boolean IsEmptyD(Detail d);
/* Fungsi untuk mengecek jika isi d kosong (penyanyi kosong, album kosong, dan lagu kosong) */
/* Prekondisi d terdefinisi. */

void PasteD(Detail source, Detail *dest);
/* I.S. source terdefinisi, dest sembarang. */
/* F.S. mengisi dest dengan isi source. */

boolean IsIsiSama(Detail d1, Detail d2);
/* F.S. true jika detail sama. */

void DisplayD(Detail d);
/* I.S. d terdefinisi. */
/* F.S. menampilkan "penyanyi - album - lagu". */

#endif