#ifndef set_H
#define set_H
#include <stdio.h>
#include "boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
# include "../struc.h"


/* Definisi SetLagu S kosong : S.jumlah_lagu = 0 */
/* S.jumlah_lagu = jumlah element Set */
/* S.Elements = tempat penyimpanan element Lagu */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySetLagu(SetLagu *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah SetLagu S kosong berkapasitas MaxEl */


/* ********* Predikat Untuk test keadaan KOLEKSI ********* */

boolean IsEmptySetLagu(SetLagu W);
/* Mengirim true jika Set S kosong*/

/* ********** Operator Dasar Lagu ********* */
void InsertSetLagu(SetLagu *S, Word Elmt,int idalbum);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

boolean IsMemberLagu(SetLagu S, Word Elmt);
/* True jika Elmt sudah member dari SetLagu*/

void DisplaySetLagu(SetLagu S, int idalbum);
/* Mendisplay SetLagu*/

Word namalagufromalbum (SetLagu p2,int albumid, int lagukeberapa);
// menghasilkan nama lagu dari input albumid dan urutan nya

int CountLaguByAlbumID(SetLagu *setLagu, int targetAlbumID) ;
// menghasilkan jumlah lagu yang ada di album tersebut

#endif