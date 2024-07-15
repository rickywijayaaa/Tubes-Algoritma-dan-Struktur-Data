#include <stdio.h> 
#include "isilagu.h"
int main() {
    // Example usage of the Detail struct and functions

    // Create details for a song
    Word penyanyi, album, lagu;
    CreateWord(&penyanyi);
    CreateWord(&album);
    CreateWord(&lagu);


    Detail songDetails;
    CreateD(&songDetails, penyanyi, album, lagu);

    // Display details
    printf("Song Details:\n");
    DisplayD(songDetails);

    // Check if the details are empty
    if (IsEmptyD(songDetails)) {
        printf("Details are empty.\n");
    } else {
        printf("Details are not empty.\n");
    }

    // Create another set of details
    Detail anotherDetails;
    CreateD(&anotherDetails, penyanyi, album, lagu);

    // Paste details from one to another
    printf("\nCopying details:\n");
    PasteD(songDetails, &anotherDetails);
    DisplayD(anotherDetails);

    return 0;
}
