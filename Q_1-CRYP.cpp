#include <stdio.h>
#include <string.h>

void caesarCipher(char message[], int key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
        }

        printf("%c", ch);
    }

    printf("\n");
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from the message
    message[strcspn(message, "\n")] = '\0';

    // Loop through keys 1 to 25
    for (key = 1; key <= 25; ++key) {
        printf("Key %d: ", key);
        caesarCipher(message, key);
    }

    return 0;
}
