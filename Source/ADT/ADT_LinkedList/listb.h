#ifndef listb_H
#define listb_H

#include "../ADT_Set/boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include <stdio.h>
#include "../struc.h"
#include "../ADT_Detail/isilagu.h"
#include <stdlib.h>


typedef struct node* Address;

typedef struct node { 
    Detail Info;
    Address Next;
} Node;

typedef struct {
    Word Title;
    Address First;
} LinkedList;

#define Next(q) (q)->Next
#define Info(q) (q)->Info
#define First(sb) ((sb).First)
#define Title(sb) ((sb).Title)

Address NewNodeSB(Detail x);

boolean IsIdxValidSB(LinkedList s, int i);

void CreateSB(LinkedList *s);
/* I.S. sembarang */
/* F.S. Sebuah sb kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah sb kosong */

/* ********** Pemeriksa Status LinkedList ********** */
boolean IsEmptySB(LinkedList s);
/* Mengirim true jika sb kosong: lihat definisi di atas */

int LengthSB(LinkedList s);
/* Mengirimkan banyaknya elemen LinkedList. Mengirimkan 0 jika sb kosong. */

void GetSB(LinkedList *s, Detail *x, int i);
void SetSB(LinkedList *s, Detail x, int i);

void InsertSB(LinkedList *s, Detail x, int i);

void DeleteSB(LinkedList *s, Detail *x, int i);

/* ********** Display LinkedList ********** */
void DisplaySB(LinkedList s);
/* Proses : Menuliskan isi LinkedList dengan traversal, LinkedList ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. sb boleh kosong */
/* F.S. Jika sb tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika LinkedList kosong : menulis [] */

boolean IsMemberLinked(LinkedList s, Detail x) ;

#endif