#include <stdio.h>
#include <stdlib.h> 
#include "circular_queue.h"
#include "../boolean.h"



/* ********* Prototype ********* */
boolean CIsEmpty (QueueLagu Q) {
    return ((CIDX_HEAD(Q)==IDX_UNDEF) && (CIDX_TAIL(Q)==IDX_UNDEF));
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean CIsFull (QueueLagu Q){
    if (CIDX_HEAD(Q) == 0) {
        return (CIDX_TAIL(Q)==IDX_MAX);
    }
    else {
        return (CIDX_HEAD(Q)==CIDX_TAIL(Q)+1);
    }
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int CLength (QueueLagu Q){
    if (CIsEmpty(Q))
    {
        return 0;
    }
    else if (CIDX_HEAD(Q) <= CIDX_TAIL(Q))
    {
        return CIDX_TAIL(Q) - CIDX_HEAD(Q) + 1;
    }
    else {
        return (CIDX_TAIL(Q)+1 + (IDX_MAX-CIDX_HEAD(Q)+1));
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CCreateQueue(QueueLagu *Q) {
    CIDX_HEAD(*Q) = IDX_UNDEF;
    CIDX_TAIL(*Q) = IDX_UNDEF;
}

/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void Cenqueue(QueueLagu *Q, char *penyanyi,  char *album,  char *lagu) {
    if (CIsEmpty(*Q)) {
        CIDX_HEAD(*Q)=0;
        CIDX_TAIL(*Q)=0;
    } else {
        if (CIDX_TAIL(*Q) == IDX_MAX) {
            CIDX_TAIL(*Q) = 0;
        } else {
            CIDX_TAIL(*Q)++;
        }
    } CTAIL(*Q).Penyanyi_playlist=penyanyi;
    CTAIL(*Q).lagu_playlist=lagu;
    CTAIL(*Q).album_playlist=album;

}
void Cdequeue(QueueLagu *Q, char **penyanyi, char **album, char **lagu) {
    if (CIsEmpty(*Q)) {
        // Queue kosong, tidak ada yang dapat di-dequeue
        *penyanyi = *album = *lagu = NULL;
    } else {
        *penyanyi = CHEAD(*Q).Penyanyi_playlist;
        *album = CHEAD(*Q).album_playlist;
        *lagu = CHEAD(*Q).lagu_playlist;

        // Atur ulang idxHead dan idxTail jika diperlukan
        if (Q->idxHead == Q->idxTail) {
            Q->idxHead = Q->idxTail = IDX_UNDEF;
        } else {
            if (Q->idxHead == IDX_MAX) {
                Q->idxHead = 0;
            } else {
                Q->idxHead++;
            }
        }
    }
}


/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display CQueue *** */
void  CdisplayQueue(QueueLagu Q) {
    if (!CIsEmpty(Q)) {
        for (int i = 0; i < CLength(Q); i++) {
            printf("%d. %s - %s - %s\n",i+1, Q.Isi[i % (MaxEl+1)].Penyanyi_playlist,Q.Isi[i % (MaxEl+1)].album_playlist,Q.Isi[i % (MaxEl+1)].lagu_playlist);
        }
    }
}

/* Proses : Menuliskan isi CQueue dengan traversal; CQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika CQueue kosong : menulis [] */
/* Note: Output mengandung newline */
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer;
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */


/*int main() {
    QueueLagu Q;
    CCreateQueue(&Q);
    Cenqueue(&Q, "Adele", "21", "Rolling in the Deep");
    Cenqueue(&Q, "Ed Sheeran", "haha", "Shape of You");
    Cenqueue(&Q, "Taylor Swift", "1989", "Blank Space");

    printf("Is Queue Empty? %s\n", CIsEmpty(Q) ? "Yes" : "No");
    printf("Is Queue Full? %s\n", CIsFull(Q) ? "Yes" : "No");
    printf("Queue Length: %d\n", CLength(Q));

    printf("Queue Contents:\n");
    displayQueue(Q);

    char *penyanyiDequeue, *albumDequeue, *laguDequeue;
    Cdequeue(&Q, &penyanyiDequeue, &albumDequeue, &laguDequeue);
    printf("Dequeued Element: %s - %s - %s\n", penyanyiDequeue, albumDequeue, laguDequeue);
    Cenqueue(&Q,penyanyiDequeue,albumDequeue,laguDequeue);


    printf("Updated Queue Length: %d\n", CLength(Q));

    printf("Queue Contents after Dequeue:\n");
    displayQueue(Q);

    return 0;
}*/