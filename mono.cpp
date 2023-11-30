#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to perform monoalphabetic substitution
void monoalphabeticSubstitution(char plaintext[], char key[]) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            // Convert to uppercase for simplicity
            char currentChar = toupper(plaintext[i]);

            // Check if the character is a letter
            if (isalpha(currentChar)) {
                // Apply substitution
                plaintext[i] = isupper(plaintext[i]) ? key[currentChar - 'A'] : tolower(key[currentChar - 'a']);
            }
        }
    }
}

int main() {
    char plaintext[1000];
    char key[ALPHABET_SIZE];

    // Get plaintext input
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Get key input
    printf("Enter substitution key (26 unique letters): ");
    fgets(key, sizeof(key), stdin);

    // Validate key length
    if (strlen(key) != ALPHABET_SIZE + 1) {
        printf("Error: Key must be exactly 26 characters long.\n");
        return 1;
    }

    // Validate key contains only letters
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (!isalpha(key[i])) {
            printf("Error: Key must contain only letters.\n");
            return 1;
        }
    }

    // Perform monoalphabetic substitution
    monoalphabeticSubstitution(plaintext, key);

    // Display the encrypted text
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
