#include "play.h"

void playsong (ListPenyanyi lp, SetLagu sl, MapAlbum ma, QueueLagu* Ql, HistoriLagu* Hl) {
    printf("Daftar Penyanyi :\n");
    DisplayListPenyanyi(lp);

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();

    if (!isMemberListPenyanyi(currentCommand, lp)){
        printf("Nama Penyanyi ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    
    Word namapenyanyi = currentCommand;
    char *penyanyi=wordToString(namapenyanyi);
    int idpenyanyi = albumtoidpenyanyi(lp, namapenyanyi);

    printf("Daftar album oleh ");
    displayWord(namapenyanyi);
    printf(" : \n");
    displayMapAlbum(ma, idpenyanyi);

    printf("Masukkan Nama Album yang dipilih : ");
    STARTCOMMAND();

    if (!IsMemberMapAlbum(ma,currentCommand)){
        printf("Album ");
        displayWord(currentCommand);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        return;
    }
    Word namaalbum = currentCommand;
    char *album=wordToString(namaalbum);
    int idalbum = laguAlbumID(namaalbum, ma);

    printf("Daftar lagu album ");
    displayWord(namaalbum);
    printf(" oleh ");
    displayWord(namapenyanyi);
    printf(" : \n");
    DisplaySetLagu(sl, idalbum);

    printf("Masukkan ID Lagu yang dipilih :  ");
    STARTCOMMAND();
    int idlagu = wordToInt(currentCommand);
    int jumlahlagu = CountLaguByAlbumID(&sl,idalbum);

    if((idlagu<=0) || (idlagu > jumlahlagu)){
        printf("ID lagu tidak valid\n");
        return;
    }
    Word namalagu = namalagufromalbum (sl, idalbum, idlagu);
    char *lagu=wordToString(namalagu);


    printf ("Memutar lagu \"");
    displayWord(namalagu);
    printf ("\" oleh ");
    displayWord(namapenyanyi);


    printf ("\n");
    QueClear(Ql);
    
    while ((*Hl).idxTop>=0) {
        (*Hl).idxTop--;
        (*Hl).count--;
    }
    printf ("History dikosongkan.\n");

    current.album=album;
    current.lagu=lagu;
    current.penyanyi=penyanyi;
}



void playPlaylist(ListDinamik LD, QueueLagu* Ql, HistoriLagu* Hl) {
    if (IsEmptyLD(LD)) {
        printf("Playlist kosong, tidak ada yang bisa dimainkan.\n");
    } else {
        CreateHist(Hl);
        CCreateQueue(Ql);
        printf("Masukkan ID Playlist yang dipilih : ");
        STARTCOMMAND(); // Mulai membaca kata
        printf("\n");
        int idplaylist = wordToInt(currentCommand) - 1;
        if(IsIdxValidLD(LD, idplaylist)){
            if ((idplaylist >= 0) && (idplaylist < LD.Neff)) {
                printf ("Memutar playlist \"");
                displayWord(Title(LD.Content[idplaylist]));
                printf ("\"\n");
            } else {
                printf("ID %d tidak ada dalam daftar, silakan coba lagi\n", idplaylist+1);
            }
        }


        Address P = LD.Content[idplaylist].First;
        current.lagu = wordToString(LD.Content[idplaylist].First->Info.Lagu);
        current.penyanyi = wordToString(LD.Content[idplaylist].First->Info.Penyanyi);
        current.album = wordToString(LD.Content[idplaylist].First->Info.Album);
       
        currentIDplay = idplaylist+1;
        P = Next(P);
        while (P != NULL) {
            Cenqueue(Ql, wordToString(Info(P).Penyanyi), wordToString(Info(P).Album), wordToString(Info(P).Lagu));
            PushLagu(Hl, wordToString(Info(P).Penyanyi), wordToString(Info(P).Album), wordToString(Info(P).Lagu));
            P = Next(P);
        }
    }
}