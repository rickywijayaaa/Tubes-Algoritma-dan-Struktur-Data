#include "Source/ADT/ADT_Mesin-Kata/mesinkata.h"
#include "Source/ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "Source/ADT/ADT_Map/map.h"
#include "Source/ADT/ADT_List/liststatis.h"
#include "Source/ADT/ADT_List/listdinamis.h"
#include "Source/ADT/ADT_Set/set.h"
#include "Source/ADT/boolean.h"
#include "Source/command/console.h"
#include <stdio.h>
#include "Source/command/play.h"
#include "Source/command/load.h"
#include "Source/command/start.h"

int main() {
    
    char namaFile[] = "save/text.txt";
    ListPenyanyi listmusisi3;
    ListDinamik DaftarPlaylist;
    QueueLagu Q;
    SetLagu lagu2;
    MapAlbum m2;
    HistoriLagu HS;
    CCreateQueue(&Q);
    CreateHist(&HS);
    boolean start = false;
    boolean quit = false;
    boolean load = false;
    welcome();


    while (!quit) {
        printf(">> ");
        STARTCOMMAND(); 
        if (StrComp(currentCommand.TabWord, "START")) {
            STARTREAD(&listmusisi3, &lagu2, &m2, &DaftarPlaylist, namaFile);
            start = true;
            quit=true;
        } else if (StrComp2(currentCommand.TabWord, "LOAD",4)) {
            char* namafileinput2 = currentWordtoFileName(currentCommand);
            if(FileExists(namafileinput2)){
                Load(&listmusisi3,&lagu2,&m2,&DaftarPlaylist,namafileinput2 , &Q,&HS,&current);
                load = true;
                quit = true;
                start = true;
                printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
            }
            else{
                printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
            }
        } else if (StrComp(currentCommand.TabWord, "HELP")) {
            help(start); 
           
        } else {
            invalidCommand(start,load);
        }
    }
    quit=false;
    while (!quit) {
        printf(">> ");
        STARTCOMMAND();

        if (StrComp(wordToString(currentCommand), "LIST DEFAULT")) {
            if (start == true) {
            
                listdefault(listmusisi3, lagu2, m2);
            } else {
                printf("Command tidak bisa dieksekusi!\n");
            }
        } else if (StrComp(currentCommand.TabWord, "PLAY PLAYLIST")) {
            playPlaylist(DaftarPlaylist,&Q,&HS);
        } 
        else if (StrComp(currentCommand.TabWord, "PLAY SONG")) {
            playsong(listmusisi3,lagu2,m2,&Q,&HS);
        }
        else if (StrComp(currentCommand.TabWord, "LIST PLAYLIST")) {
            listplaylist(DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "QUEUE SONG")) {
            QueSong(listmusisi3, m2, lagu2, &Q);
        } else if (StrComp(currentCommand.TabWord, "QUEUE PLAYLIST")) {
            QueList(DaftarPlaylist,&Q);
        } else if (StrComp2(currentCommand.TabWord, "QUEUE SWAP",10)) {
            if (currentCommand.TabWord[currentCommand.Length-1]==';'){}
            QueSwap(&Q);
        } else if (StrComp2(currentCommand.TabWord, "QUEUE REMOVE",12)) {
            QueMove(&Q);
        } else if (StrComp(currentCommand.TabWord, "QUEUE CLEAR")) {
            QueClear(&Q);
        } else if (StrComp(currentCommand.TabWord, "PLAYLIST CREATE")) {
            CreatePlayList(&DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "PLAYLIST ADD SONG")) {
            PLAYLISTADDSONG(listmusisi3, m2, lagu2, &DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "PLAYLIST ADD ALBUM")) {
            PLAYLISTADDALBUM(listmusisi3, m2, lagu2, &DaftarPlaylist);
        } else if (StrComp2(currentCommand.TabWord, "PLAYLIST SWAP",13)) {
            PLAYLISTSWAP(&DaftarPlaylist);
        } else if (StrComp2(currentCommand.TabWord, "PLAYLIST REMOVE",15)) {
            PLAYLISTREMOVE(&DaftarPlaylist);
        }
        else if (StrComp(currentCommand.TabWord, "PLAYLIST DELETE")){
            PLAYLISTDELETE(&DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "SONG NEXT")) {
            SongNext(&HS, &Q);
        } else if (StrComp(currentCommand.TabWord, "SONG PREVIOUS")) {
            SongPrev(&HS, &Q);
        } else if (StrComp2(currentCommand.TabWord, "SAVE",4)) {
            save(listmusisi3, m2, lagu2, Q , HS , DaftarPlaylist);
        } else if (StrComp(currentCommand.TabWord, "QUIT")) {
            QUIT(listmusisi3, m2, lagu2, Q, HS, DaftarPlaylist);
            quit = true;
        }
        else if (StrComp(currentCommand.TabWord, "HELP")) {
            help(start);
        }
        else if (StrComp(currentCommand.TabWord, "STATUS")) {
            statuscurrent(Q,DaftarPlaylist);
        }
        else if (StrComp(currentCommand.TabWord, "CHECK")){
            DisplaySemuaLD(DaftarPlaylist);
        }
        else if (StrComp(currentCommand.TabWord, "ENHANCE")){
            ENHANCE(listmusisi3,lagu2,m2,&DaftarPlaylist);
        }else{
            invalidCommand(start,load);
        }
    }
    
    
    return 0;
    
}