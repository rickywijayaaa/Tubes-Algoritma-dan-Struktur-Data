#include "load.h"

boolean FileExists(char *fname) {
     FILE *file;
     file = fopen(fname, "r");
     if ((file == NULL))
     {
          fclose(file);
          return false;
     }
     return true;
}

void Load(ListPenyanyi * LP, SetLagu *lagu2,MapAlbum *m2,ListDinamik *daftarplaylist, char* NamaFile, QueueLagu* QueueLagu, HistoriLagu* HistoryLagu, status *LaguSekarang){
    if (FileExists(NamaFile)){
        startWFile(NamaFile);

        Word NamaPenyanyi;
        Word NamaAlbum;
        Word NamaLagu;
        int panjg;
        CreateMapAlbum(m2);
        NotPlaying();
        NotPlayingPlaylist();
        *daftarplaylist = CreateLD();
        CreateEmptySetLagu(lagu2);
        *LP = MakeListPenyanyi();
        
        int loop = wordToInt(currentWord);
        int album,lagu;
        int number =1;
        int idalbum=1;
        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            album = wordToInt(currentWord);   
            ADVKALIMAT();  
            InsertLast(LP, currentWord);
            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            lagu = wordToInt(currentWord);
            ADVKALIMAT();
            InsertMapAlbum(m2,i,currentWord);
            for (int k = 0; k < lagu; k++)
            {
                ADVKALIMAT();
                InsertSetLagu(lagu2,currentWord,number);    
            }
            number++;
            }
            idalbum++;
        }
        ADVKALIMAT();
        if (StrComp(wordToString(currentWord),"-")){
        current.penyanyi = "-";
        current.album = "-";
        current.lagu = "-";
        }
        else{
            current.penyanyi = wordToString(takewordsemicolon(currentWord, 1));
            current.album = wordToString(takewordsemicolon(currentWord,2));
            current.lagu = wordToString(takewordsemicolon(currentWord,3));
        }
        ADVKALIMAT();
        loop = wordToIntload(currentWord);
        for (int i = 0; i < loop; i++){
            ADVKALIMAT();
            char* penyanyienq = wordToString(takewordsemicolon(currentWord, 1));
            char* albumenq = wordToString(takewordsemicolon(currentWord,2));
            char* laguenq = wordToString(takewordsemicolon(currentWord,3));
            Cenqueue(QueueLagu,penyanyienq,albumenq,laguenq);
        }
        ADVKALIMAT();
        loop = wordToIntload(currentWord);
        for (int j = 0; j < loop; j++){
            ADVKALIMAT();
            char* penyanyistack = wordToString(takewordsemicolon(currentWord, 1));
            char* albumstack = wordToString(takewordsemicolon(currentWord,2));
            char* lagustack = wordToString(takewordsemicolon(currentWord,3));
            PushLagu(HistoryLagu, lagustack, albumstack, penyanyistack);
        }
        ADVKALIMAT();
        loop = wordToIntload(currentWord);
        for (int k = 0; k<loop; k++){
            ADVWORD();
            int sesuatu = wordToInt(currentWord);
            ADVKALIMAT();
            LinkedList a;
            a.Title = currentWord;
            for (int l = 0; l < sesuatu; l++){
                ADVKALIMAT();
                Detail value;
                value.Penyanyi = takewordsemicolon(currentWord, 1);
                value.Album = takewordsemicolon(currentWord, 2);
                value.Lagu = takewordsemicolon(currentWord, 3);
                InsertSB (&a,value,l);
            }
            daftarplaylist->Content[k] = a;
            daftarplaylist->Neff++;
        }                   
    }
    else {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
}