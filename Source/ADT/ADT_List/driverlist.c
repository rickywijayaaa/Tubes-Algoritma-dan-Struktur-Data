#include <stdio.h>
#include "liststatis.h"

int main()
{
    ListPenyanyi penyanyiList = MakeListPenyanyi();
    Word penyanyi1, penyanyi2, penyanyi3;
    assignWord(&penyanyi1, "Adele", 5);
    assignWord(&penyanyi2, "Ed Sheeran", 10);
    assignWord(&penyanyi3, "Taylor Swift", 13);

    InsertFirst(&penyanyiList, penyanyi1);
    InsertLast(&penyanyiList, penyanyi2);
    InsertAt(&penyanyiList, penyanyi3, 1);

    printf("List Penyanyi:\n");
    DisplayListPenyanyi(penyanyiList);

    Word searchWord;
    assignWord(&searchWord, "Ed Sheeran", 10);

    if (Search(penyanyiList, searchWord))
    {
        printf("\n%s ditemukan dalam List Penyanyi.\n", wordToString(searchWord));
    }
    else
    {
        printf("\n%s tidak ditemukan dalam List Penyanyi.\n", wordToString(searchWord));
    }
    DeleteFirst(&penyanyiList);
    DisplayListPenyanyi(penyanyiList);

    return 0;
}
