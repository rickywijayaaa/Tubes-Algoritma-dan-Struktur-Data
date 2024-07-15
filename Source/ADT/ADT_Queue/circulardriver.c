#include <stdio.h>
#include "circular_queue.h"
int main() {
    QueueLagu Q;
    CCreateQueue(&Q);

    printf("Is Queue Empty? %s\n", CIsEmpty(Q) ? "Yes" : "No");
    printf("Is Queue Full? %s\n", CIsFull(Q) ? "Yes" : "No");
    printf("Queue Length: %d\n", CLength(Q));

    Cenqueue(&Q, "Adele", "21", "Rolling in the Deep");
    Cenqueue(&Q, "Ed Sheeran", "haha", "Shape of You");
    Cenqueue(&Q, "Taylor Swift", "1989", "Blank Space");

    printf("Queue Contents:\n");
    CdisplayQueue(Q);

    char *penyanyiDequeue, *albumDequeue, *laguDequeue;
    Cdequeue(&Q, &penyanyiDequeue, &albumDequeue, &laguDequeue);
    printf("Dequeued Element: %s - %s - %s\n", penyanyiDequeue, albumDequeue, laguDequeue);
    Cenqueue(&Q, "John Legend", "Love in the Future", "All of Me");

    printf("Updated Queue Length: %d\n", CLength(Q));

    printf("Queue Contents after Dequeue and Enqueue:\n");
    CdisplayQueue(Q);

    return 0;
}