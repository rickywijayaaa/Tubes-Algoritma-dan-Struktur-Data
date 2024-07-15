#ifndef PLAYSONG_H
#define PLAYSONG_H

#include <stdio.h>
#include "../ADT/struc.h"
#include "../ADT/ADT_List/liststatis.h"
#include "../ADT/ADT_List/listdinamis.h"
#include "../ADT/ADT_Mesin-Kata/mesinkata.h"
#include "../ADT/ADT_MesinKarakter/mesinkarakter.h"
#include "../ADT/boolean.h"
#include "../ADT/ADT_Set/set.h"
#include "../ADT/ADT_Map/map.h"
#include "../ADT/ADT_Stack/stack.h"
#include "../ADT/ADT_Queue/circular_queue.h"
#include "console.h"
void playsong (ListPenyanyi lp, SetLagu sl, MapAlbum ma, QueueLagu* Ql, HistoriLagu* Hl);

void playPlaylist (ListDinamik LD, QueueLagu* Ql, HistoriLagu* Hl);

#endif
