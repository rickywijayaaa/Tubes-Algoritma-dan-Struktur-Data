#include <stdio.h>
#include "mesinkata.h"
int main() {
    // Test 1
    printf("Test 1:\n");
    STARTCOMMAND();
    printf("Display Word 1: ");
    displayWord(currentCommand);
    printf("\n");

    char *string1 = wordToString(currentCommand);
    printf("Length of Word 1: %d\n", stringLength(string1));
    printf("Word 1: %s\n", string1);

    // Test 2
    printf("\nTest 2:\n");
    STARTCOMMAND();
    printf("Display Word 2: ");
    displayWord(currentCommand);
    printf("\n");

    char *string2 = wordToString(currentCommand);
    printf("Length of Word 2: %d\n", stringLength(string2));
    printf("Word 2: %s\n", string2);

    // Test 3
    printf("\nTest 3:\n");
    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    printf("Converted to Integer: %d\n", x);

    return 0;
}