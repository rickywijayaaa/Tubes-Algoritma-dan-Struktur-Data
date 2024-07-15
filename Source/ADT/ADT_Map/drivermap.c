#include <stdio.h>
#include "map.h"

int main() {
    /* Create MapAlbum */
    MapAlbum mapAlbum;
    CreateMapAlbum(&mapAlbum);

    /* Insert albums into MapAlbum */
    Word w1,w2,w3;
    CreateWord2(6,"Album1",&w1);
    CreateWord2(6,"Album1",&w2);
    CreateWord2(6,"Album1",&w3);
    InsertMapAlbum(&mapAlbum, 1, w1);
    InsertMapAlbum(&mapAlbum, 2, w2);
    InsertMapAlbum(&mapAlbum, 1, w3); // Same penyanyi_id as Album1

    /* Display MapAlbum */
    displayMapAlbum(mapAlbum, 1);

    /* Test IsEmptyMapAlbum */
    if (IsEmptyMapAlbum(mapAlbum)) {
        printf("MapAlbum is empty.\n");
    } else {
        printf("MapAlbum is not empty.\n");
    }

    /* Test IsMemberMapAlbum */
    if (IsMemberMapAlbum(mapAlbum, w2)) {
        printf("Album2 is a member of MapAlbum.\n");
    } else {
        printf("Album2 is not a member of MapAlbum.\n");
    }

    /* Test jumlahalbumperpenyanyi */
    int jumlahAlbum = jumlahalbumperpenyanyi(mapAlbum, 1);
    printf("Penyanyi has %d albums.\n", jumlahAlbum);

    /* Test laguAlbumID */
    int albumID = laguAlbumID(w2, mapAlbum);
    printf("ID of Album2 is: %d\n", albumID);

    return 0;
}