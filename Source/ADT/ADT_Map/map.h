#ifndef map_H
#define map_H
#include "../ADT_List/liststatis.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include "../struc.h"


/* Membuat Lagu kosong (P.count = 0) sebagai Map dari Album */
void CreateMapAlbum(MapAlbum *P);


/* Mengirim true jika album Penyanyi P kosong (P.count = 0) */
boolean IsEmptyMapAlbum(MapAlbum P);


/* Mengembalikan true jika Word AT adalah member dari MapAlbum P */
boolean IsMemberMapAlbum(MapAlbum P, Word AT);

/* ### Operator Dasar Map ### */



void InsertMapAlbum(MapAlbum *P,valuetype idpenyanyi,Word AT);
/* Menginsert Word AT sebagai nama_album dan penyanyi_id = idpenyanyi*/


//int IndexOfAlbum(Penyanyi P, MapAlbum A);

void displayMapAlbum(MapAlbum P,int idpenyanyi) ;
/* Mendisplay map album*/

int albumtoidpenyanyi(ListPenyanyi P,Word nama);
/* mengirimkan id penyanyi dari sebuah masukan nama penyanyi*/

int laguAlbumID(Word input,MapAlbum P);



int jumlahalbumperpenyanyi(MapAlbum P,int idpenyanyi);
/* mengirimkan banyaknya album yang dimiliki oleh penyanyi dengan id = idpenyanyi*/


#endif