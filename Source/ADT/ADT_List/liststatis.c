#include "liststatis.h"
#include "../ADT_Set/boolean.h"

ListPenyanyi MakeListPenyanyi(){
    ListPenyanyi L;
    int i;
    L.NEff = 0  ;
    return L;
}

boolean IsEmpty(ListPenyanyi L){
    return L.NEff == 0;
}

ElType Get(ListPenyanyi L, IdxType i){
    return L.A[i];
}

void Set(ListPenyanyi *L, IdxType i, ElType v){
    L->A[i] = v;
}

int Length(ListPenyanyi L){
    return L.NEff;
}

IdxType FirstIdx(ListPenyanyi L){
    return 0;
}

IdxType LastIdx(ListPenyanyi L){
    return Length(L)-1;
}

boolean IsIdxValid (ListPenyanyi L, IdxType i){
    return(i>=FirstIdx(L) && i < MaxEl);
}

boolean IsIdxEff (ListPenyanyi L, IdxType i){
    return(i>=FirstIdx(L) && i<= LastIdx(L));
}

boolean Search(ListPenyanyi L, Word X){
    boolean isFound = false;
    for (int i=0; i < L.NEff; i++){
        if (isWordEqual (X,L.A[i])) {isFound = true; break;}
    }
    return isFound;
}

void InsertFirst(ListPenyanyi *L, Word X){
    InsertAt(L,X,0);
}

void InsertAt(ListPenyanyi *L, Word X, IdxType i)
{
    int j;
    for (j = LastIdx(*L) + 1; j > i; j--)
    {
        L->A[j] = L->A[j - 1];
    }
    L->A[i] = X;
    L->NEff++;
}

void InsertLast(ListPenyanyi *L, Word X){
    InsertAt(L, X, Length(*L));
}

void DeleteFirst(ListPenyanyi *L) {
    DeleteAt(L, 0);
}

void DeleteAt(ListPenyanyi *L, IdxType i)
{
    int j;
    for (j = i; j < LastIdx(*L); j++)
    {
        L->A[j] = L->A[j + 1];
    }
    L->NEff--;
}

void DeleteLast(ListPenyanyi *L){
    DeleteAt(L, LastIdx(*L));
}

ListPenyanyi Concat(ListPenyanyi L1, ListPenyanyi L2){
    ListPenyanyi L = MakeListPenyanyi(L);
    int i;
    for (i = 0; i<Length(L1);i++)
    {
        InsertLast(&L, Get(L1,i));
    }
    for (i = 0; i < Length(L2); i++){
        InsertLast(&L, Get(L2, i));
    }
    return L;
}

void DisplayListPenyanyi(ListPenyanyi L){
    for (int i=0; i < L.NEff; i++){
        printf("   %d. ", (i+1));
        for (int j = 0; j < L.A[i].Length; j++){
            printf("%c", L.A[i].TabWord[j]);
        }
        printf("\n");
    }
}

boolean isMemberListPenyanyi(Word input, ListPenyanyi LP) {
    int i;
    for (i = 0; i < LP.NEff; i++) {
        if (StrComp(input.TabWord, LP.A[i].TabWord) == true) {
            return true; 
        }
    }
    return false; 
}