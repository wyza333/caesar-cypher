#include <stdio.h>
#include <string.h>
#define ALPHABET_LENGHT 26

void encode(char *input) {
    for (int i = 1; i <= ALPHABET_LENGHT; i++) {
        printf("Clé %d\t:\t", i);
        for (int j = 0; j < strlen(input); j++) {
            // exclude char not alphabet
            if (input[j] < 'A' || (input[j] > 'Z' && input[j] < 'a') || input[j] > 'z') printf("%c", input[j]);
            // outbound lowercase
            else if (input[j]+i > 'z') printf("%c", (input[j]+i)%'z'+('a'-1));
            // outbound uppercase && block switch upper to lowercase
            else if (input[j]+i > 'Z' && input[j]+i < 'a'+i) printf("%c", (input[j]+i)%'Z'+('A'-1));
            // next char is inbound of his case alphabet
            else if ( (input[j]+i > 'a' && input[j]+i <= 'z') || (input[j]+i >= 'A' && input[j]+i <= 'Z')) printf("%c", input[j]+i);
        }
        printf("\n");
    }
}

void decode(char *input) {
    for (int i = 1; i <= ALPHABET_LENGHT; i++) {
        printf("Clé %d\t:\t", i);
        for (int j = 0; j < strlen(input); j++) {
            // exclude char not alphabet
            if (input[j] < 'A' || (input[j] > 'Z' && input[j] < 'a') || input[j] > 'z') printf("%c", input[j]);
            // outbound lowercase && block switch lower to uppercase
            else if (input[j]-i < 'a' && input[j]-i > 'Z'-i) printf("%c", ('z'-('a'-(input[j]-i))+1));
            // outbound uppercase
            else if (input[j]-i < 'A' ) printf("%c", 'Z'-('A'-(input[j]-i))+1);
            // next char is inbound of his case alphabet
            else if ( (input[j]-i >= 'a' && input[j]-i <= 'z') || (input[j]-i >= 'A' && input[j]-i <= 'Z')) printf("%c", input[j]-i);
        }
        printf("\n");
    }
}

int main(void) {
    encode("hello");
    printf("\n");
    decode("rovvy");
    return 0;
}