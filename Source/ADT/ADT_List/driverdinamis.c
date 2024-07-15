#include "listdinamis.h"
#include <stdio.h>


int main() {
    Word w,w2;
    ListDinamik l;

    l = CreateLD();
    CreateWord2(13, "K-pop Enjoyer", &w);
    CreateWord2(21, "Be the main character", &w2);


    InsertLD(&l, w, 0);
    InsertLD(&l, w2, 1);


    DisplayLD(l);


    return 0;

}
