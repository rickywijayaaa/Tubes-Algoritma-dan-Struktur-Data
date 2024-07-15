#include "listb.h"

int main() {
    LinkedList s;
    Word input1, input2, input3;
    Detail w;
    CreateSB(&s);

    //input 1
    CreateWord2(5, "rafly", &input1);
    CreateWord2(5, "ylfar", &input2);
    CreateWord2(5, "faryl", &input3);
    CreateD(&w, input1, input2, input3);
    InsertSB(&s, w, 0);
    //input 2
    CreateWord2(5, "zahra", &input1);
    CreateWord2(5, "arazh", &input1);
    CreateWord2(5, "azhar", &input3);
    CreateD(&w, input1, input2, input3);
    InsertSB(&s, w, 0);

    //input 3
    CreateWord2(6, "wildan", &input1);
    CreateWord2(6, "danwil", &input2);
    CreateWord2(6, "nalwid", &input3);
    CreateD(&w, input1, input2, input3);
    InsertSB(&s, w, 2);

    DisplaySB(s);

    return 0;
}