# include <stdio.h>
# include <stdlib.h>
# include "listb.h"



Address NewNodeSB(Detail x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        PasteD(x, &Info(p));
        Next(p) = NULL;
    }
    return p;
}

boolean IsIdxValidSB(LinkedList s, int i) {
    return i < LengthSB(s) && i >= 0;
}

void CreateSB(LinkedList *s){
    First(*s) = Nil;
}

boolean IsEmptySB(LinkedList s) {
    return First(s) == Nil;
}

int LengthSB(LinkedList s) {
    Address p;
    int counter;
    counter = 0;
    p = First(s);
    while (p != Nil) {
        p = Next(p);
        counter++;
    }
    return counter;
}
void GetSB(LinkedList *s, Detail *x, int i) {
    int idx;
    Address p;

    idx = 0;
    p = First(*s);

    while (p != Nil && idx != i) {
        idx++;
        p = Next(p);
    }

    if (i == idx) {
        PasteD(Info(p), x);
    }

}

void SetSB(LinkedList *s, Detail x, int i) {
    int idx;
    Address p;

    idx = 0;
    p = First(*s);

    while (p != Nil && idx != i) {
        idx++;
        p = Next(p);
    }

    if (i == idx) {
        PasteD(x, &Info(p));
    }
}

void InsertSB(LinkedList *s, Detail x, int i) {
    Address p;
    p = NewNodeSB(x);

    if (p != NULL) {
        if (i == 0) {
            Next(p) = First(*s);
            First(*s) = p;
        }
        else {
            int counter = 0;
            Address loc = First(*s);
            while (counter < i - 1) {
                counter++;
                loc = Next(loc);
            }
            Next(p) = Next(loc);
            Next(loc) = p;
        }
    }
}

void DeleteSB(LinkedList *s, Detail *x, int i) {
   
        Address p;
        p = First(*s);

        if (p != NULL) {
            if (i == 0) {
                First(*s) = Next(p);
                PasteD(Info(p),x);
                free(p);
            }
            else {
                int counter = 0;
                Address loc = First(*s);
                while (counter < i - 1) {
                    counter++;
                    loc = Next(loc);
                }
                p = Next(loc);
                PasteD(Info(p), x);
                Next(loc) = Next(p);
                free(p);
            }
        }      
    

}

void DisplaySB(LinkedList s) {
    Address p;
    p = First(s);
    
    if (p == Nil) {
        printf("Kosong\n");
    }
    else {
        int i = 0;
        while (p != Nil) {
            printf("    %d. ", i+1);
            DisplayD(Info(p));
            p = Next(p);
            i++;
        }
    }
}

boolean IsMemberLinked(LinkedList s, Detail x) {
    boolean found = false;
    Address p;
    p = First(s);
    
    while (p != Nil && !found) {
        if (IsIsiSama(Info(p), (x))) {
            found = true;
        }
        else {
            p = Next(p);
        }
    }

    return found;
}