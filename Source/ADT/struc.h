#ifndef structure_H
#define structure_H
#include "boolean.h"
#include <stdio.h>
#include "ADT_Mesin-Kata/mesinkata.h" 

typedef Word Title;
typedef int Key;
typedef int valuetype;

#define MaxEl 100
#define IDX_UNDEF -1
#define INT_UNDEF -999
#define Nil 0

/*  Akses Elemen Lagu  */
#define LAGU_NAMA(L, i, j, k, l) (L).penyanyi[i].album_penyanyi[j].album_lagu[k].nama_lagu[l]
#define LAGU_ALBUM_ID(L, i, j, k) (L).penyanyi[i].album_penyanyi[j].album_lagu[k].album_id
/*Melihat Daftar lagu yang dimiliki oleh penyanyi tertentu (LIST)*/
// Berfungsi untuk memutar lagu (PLAY)

/*  Akses Elemen Album  */
#define ALBUM_NAMA(A, i, j, k) (A).penyanyi[i].album_penyanyi[j].nama_album[k]
#define ALBUM_LAGU_LENGTH(A, i, j) (A).penyanyi[i].album_penyanyi[j].lagu_length
#define ALBUM_PENYANYI_ID(A, i, j) (A).penyanyi[i].album_penyanyi[j].penyanyi_id
/* Struktur Data Penyanyi yang memiliki Album (yang memiliki Lagu) [List Statis] */

/* ### Akses Elemen Penyanyi ### */
#define PENYANYI_NAMA(S, i, j) (S).penyanyi[i].nama_penyanyi[j]
#define PENYANYI_ALBUM_LENGTH(S, i) (S).penyanyi[i].album_length

/* Akses Elemen ListPenyanyi */
#define LIST_PENYANYI_ID(LS, i) (LS).penyanyi[i]
#define LIST_PENYANYI_LENGTH(LS) (LS).penyanyi_length

/* Akses Elemen pada Playlist*/
#define LIST_PLAYLIST_ID(LP, i) (LP).(*playlist + i)
#define LIST_PLAYLIST_SIZE(LP) (LP).playlistSize
// Berfungsi untuk Menambah Playlist  (PLAY)


#define jumlah_lagu(l) (l).jumlah_lagu

/* STRUKTUR DATA */
/*  Indeks lagu [0..lagu_length] merupakan key dari map album ke lagu dengan
    Nilai variabel nama_lagu merupakan value dari map Album -> Lagu */
typedef struct {
    Word nama_lagu;
    int album_id;
} Lagu;

typedef struct {
	Lagu A[MaxEl];  /* Memori tempat penyimpanan elemen (container) */
	int jumlah_lagu;
} SetLagu; 

typedef struct {
    Key album_id;
    valuetype penyanyi_id;
    Word nama_album;
} Album;

typedef struct {
    Album Elements[MaxEl];
    int count;
} MapAlbum;

typedef struct {
    Title nama_penyanyi[MaxEl]; // Panjang nama penyanyi dibatasi 100 char
    Album album_penyanyi[MaxEl/10]; // banyak album yang dimiliki artis dibatasi 10 album
    int album_length;
} Penyanyi;

/* Struktur Data List Penyanyi (yang memiliki Album yang memiliki Lagu) [List Statis] */

typedef struct {
    char *lagu_playlist;
    char *album_playlist;
    char *Penyanyi_playlist;
} isi_playlist;

typedef struct {
    char *lagu_playlist;
    char *album_playlist;
    char *Penyanyi_playlist;
} Isi_Que;

typedef struct {
    Isi_Que Isi[MaxEl+1];
    int idxHead;
    int idxTail;
} QueueLagu;

// Data Struct yang digunakan untuk antrian pada  queue lagu (Queue lagu & PLAY)
typedef struct {
    char *lagu_playlist;
    char *album_playlist;
    char *Penyanyi_playlist;
} Isi_Stack;

typedef struct {
    Isi_Stack hist_lagu[MaxEl];
    int idxTop;
    int count;
} HistoriLagu;


typedef struct {
    char *lagu;
    char *album;
    char *penyanyi;
}status;
extern status current;

extern int currentIDplay;
// Data Struct yang digunakan untuk menampung history lagu pada stack pada SONGS (Previous & Next)

#endif
