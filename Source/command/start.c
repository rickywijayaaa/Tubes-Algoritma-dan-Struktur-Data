#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "start.h"


// Fungsi Start
status current;
int currentIDplay;
void STARTREAD(ListPenyanyi * LP, SetLagu *lagu2,MapAlbum *m2,ListDinamik *daftarplaylist, char NamaFile []){
  startWFile(NamaFile);
  //MapAlbum mapAl;
  Word NamaPenyanyi;
  Word NamaAlbum;
  Word NamaLagu;
  int panjg;
  CreateMapAlbum(&*m2);
  NotPlaying();
  NotPlayingPlaylist();
  ListDinamik DaftarPlaylist = CreateLD();


  CreateEmptySetLagu(&*lagu2);
  *LP = MakeListPenyanyi();
  //CreateMapAlbum(&mapAl);
  


  
  int loop = wordToInt(currentWord);
  int album,lagu;
  int number =1;
  int idalbum=1;
  printf("\n");
  printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan\n");
  for (int i = 0; i < loop; i++){
    ADVSATUKATA();
    album = currentWord.TabWord[0] - 48;   
    ADVKALIMAT();  
    InsertLast(&*LP, currentWord);
    for (int j = 0; j < album; j++){
      ADVSATUKATA();
      lagu = currentWord.TabWord[0] - 48;
      ADVKALIMAT();
      InsertMapAlbum(&*m2,i,currentWord);
      for (int k = 0; k < lagu; k++)
      {
        ADVKALIMAT();
        InsertSetLagu(&*lagu2,currentWord,number);    
      }
      number++;
    }
    idalbum++;
  }
  printf("\n");
}