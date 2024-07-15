/* MODUL CIRCULAR CQUEUE */
/* Definisi ADT CQueue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __circular_Cqueue_h__
#define __circular_Cqueue_h__

#include "../boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include "../struc.h"
#define IDX_UNDEF -1
#define IDX_MAX 99

/* Definisi tipe elemen dan indeks pada CQueue */

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah CQueue, maka akses elemen : */
#define CIDX_HEAD(q) (q).idxHead
#define CIDX_TAIL(q) (q).idxTail
#define     CHEAD(q) (q).Isi[(q).idxHead]
#define     CTAIL(q) (q).Isi[(q).idxTail]

/* ********* Prototype ********* */
boolean CIsEmpty (QueueLagu Q);
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean CIsFull (QueueLagu Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int CLength (QueueLagu Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CCreateQueue (QueueLagu * Q);
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void Cenqueue(QueueLagu *Q, char *penyanyi,  char *album,  char *lagu) ;
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
void Cdequeue(QueueLagu *Q, char **penyanyi, char **album, char **lagu);
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display CQueue *** */
void CdisplayQueue(QueueLagu q);
/* Proses : Menuliskan isi CQueue dengan traversal; CQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika CQueue kosong : menulis [] */
/* Note: Output mengandung newline */

#endif
