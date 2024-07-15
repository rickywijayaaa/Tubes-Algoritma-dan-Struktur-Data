#ifndef __load__
#define __load__

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/ADT_List/liststatis.h"
#include "../ADT/ADT_List/listdinamis.h"
#include "../ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "../ADT/ADT_Mesin-Kata/mesinkata.h"
#include "../ADT/ADT_Queue/circular_queue.h"
#include "../ADT/ADT_Stack/stack.h"
#include "console.h"
#include "../ADT/struc.h"

boolean FileExists(char *fname);

void Load(ListPenyanyi * LP, SetLagu *lagu2,MapAlbum *m2,ListDinamik *daftarplaylist, char* NamaFile, QueueLagu* QueueLagu, HistoriLagu* HistoryLagu, status *LaguSekarang);

#endif