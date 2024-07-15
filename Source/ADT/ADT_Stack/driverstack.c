#include <stdio.h>
#include "../boolean.h"
#include "stack.h"


int main() {
    HistoriLagu histori;
    Lagu lagu;

    CreateHist(&histori);

    // Push beberapa lagu ke dalam tumpukan
    Lagu lagu1 = {"Jadi yang kau inginkan", 101};
    Lagu lagu2 = {"Aku cinta kau dan dia ", 102};
    Lagu lagu3 = {"Tuhan Yesus baik ", 102};
    Lagu lagu4 = {"Lagu 3", 103};

    PushLagu(&histori, lagu1);
    PushLagu(&histori, lagu2);
    PushLagu(&histori, lagu3);
    PushLagu(&histori, lagu4);

    printf("Is Stack Empty: %d\n", IsHistEmpty(histori));

    // Pop lagu dari tumpukan
    Lagu poppedLagu;
    PopLagu(&histori, &poppedLagu);
    printf("Popped Lagu: Nama Lagu = %s, Album ID = %d\n", poppedLagu.nama_lagu, poppedLagu.album_id);

    printf("Is Stack Empty: %d\n", IsHistEmpty(histori));
    Viewhist(histori);

    return 0;
}
