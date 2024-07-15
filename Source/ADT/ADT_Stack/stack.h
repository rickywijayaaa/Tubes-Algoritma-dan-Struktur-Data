# ifndef stackdin_H
# define stacktdin_H

#include "../boolean.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include "../struc.h"

#define Top(S) (S).Top
#define Max(S) (S).Max
#define Count(S) (S).Count
#define NIL NULL

void CreateHist(HistoriLagu *S);
/*  
I.S. Sembarang
F.S. Terbentuk Stack kosong
*/

boolean IsHistEmpty(HistoriLagu S);
/*  
Menghasilkan True jika Stack kosong, dan False jika Stack tidak kosong
*/

void PushLagu(HistoriLagu *S, char *lagu, char *album, char *artis);
/*
I.S. Sembarang, P terdefinisi
F.S. Menempatkan P pada Top dari S (History lagu)
*/

void PopLagu(HistoriLagu *S, char **lagu, char **album, char **artis);
/*
I.S. Stack tidak kosong
F.S. Mengambil P dari Top dari S
*/

void Viewhist(HistoriLagu S);
/*
I.S. Sembarang
F.S. Menampilkan semua Info dari masing-masing elemen dari Stack
*/

# endif