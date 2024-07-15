/* MODUL ListPenyanyi INTEGER */
/* Berisi definisi dan semua primitif pemrosesan ListPenyanyi integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef ADTListPenyanyi1
#define ADTListPenyanyi1

#include "../ADT_Set/boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include <stdio.h>

/* Kamus Umum */
#define MaxEl 100
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int
#define ElType Word

typedef struct {
	Word A[MaxEl];  /* Memori tempat penyimpanan elemen (container) */
	int NEff;
} ListPenyanyi;

#define ListPenyanyi(i) L.A(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah ListPenyanyi, cara deklarasi dan akses: */
/* Deklarasi: L : ListPenyanyi */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen ListPenyanyi
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create ListPenyanyi kosong */
ListPenyanyi MakeListPenyanyi();
/* I.S. sembarang */
/* F.S. Terbentuk ListPenyanyi L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test ListPenyanyi kosong *** */
boolean IsEmpty(ListPenyanyi L);
/* Mengirimkan true jika ListPenyanyi L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
Word Get(ListPenyanyi L, IdxType i);
/* Prekondisi : ListPenyanyi tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen ListPenyanyi yang ke-i */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(ListPenyanyi L);
/* Mengirimkan banyaknya elemen efektif ListPenyanyi */
/* Mengirimkan nol jika ListPenyanyi kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(ListPenyanyi L);
/* Prekondisi : ListPenyanyi L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(ListPenyanyi L);
/* Prekondisi : ListPenyanyi L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (ListPenyanyi L, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran ListPenyanyi */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (ListPenyanyi L, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk ListPenyanyi */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(ListPenyanyi L, Word X);
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam ListPenyanyi */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(ListPenyanyi *L, Word X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAt(ListPenyanyi *L, Word X, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLast(ListPenyanyi *L, Word X);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirst(ListPenyanyi *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAt(ListPenyanyi *L, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLast(ListPenyanyi *L);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

ListPenyanyi Concat(ListPenyanyi L1, ListPenyanyi L2);
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah ListPenyanyi yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */

void DisplayListPenyanyi(ListPenyanyi L);

boolean isMemberListPenyanyi (Word input, ListPenyanyi LP);

#endif