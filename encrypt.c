#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024

// Function for Caesar Cipher
void caesar_cipher(char *input_text, int shift, int direction) {
    int length = strlen(input_text);

    for (int i = 0; i < length; i++) {
        char c = input_text[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            input_text[i] = (char)(((c - base + direction * shift) % 26 + 26) % 26 + base);
        }
    }
}

// Function for Substitution Cipher (Simple Substitution)
void substitution_cipher(char *input_text, const char *key, int direction) {
    const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
    char temp;
    int length = strlen(input_text);
    
    // Adjust text to lowercase for simplicity
    for (int i = 0; i < length; i++) {
        char c = tolower(input_text[i]);

        if (isalpha(c)) {
            int index = strchr(alphabet, c) - alphabet;
            if (direction == 1) {
                temp = key[index];  // Encrypt
            } else {
                temp = alphabet[index];  // Decrypt
            }
            input_text[i] = isupper(input_text[i]) ? toupper(temp) : temp;
        }
    }
}

// Function to read text from a file
void read_file(const char *filename, char *buffer, size_t buffer_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    fread(buffer, sizeof(char), buffer_size - 1, file);
    fclose(file);
    buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
}

// Function to write encrypted/decrypted text to a file
void write_file(const char *filename, const char *buffer) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fputs(buffer, file);
    fclose(file);
}

// Function to get user input safely
int get_valid_shift_key() {
    int shift;
    while (1) {
        printf("Enter the shift key (positive integer): ");
        if (scanf("%d", &shift) != 1 || shift <= 0) {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a positive integer.\n");
        } else {
            return shift;
        }
    }
}

// Function to get the cipher choice from the user
int get_cipher_choice() {
    int choice;
    while (1) {
        printf("Choose a cipher:\n");
        printf("1. Caesar Cipher\n");
        printf("2. Substitution Cipher\n");
        printf("Enter your choice (1 or 2): ");
        if (scanf("%d", &choice) == 1 && (choice == 1 || choice == 2)) {
            return choice;
        } else {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid choice. Please select 1 or 2.\n");
        }
    }
}

int main() {
    char input_text[MAX_TEXT_LENGTH];
    int choice, shift, direction, cipher_choice;
    char file_name[100];

    printf("Welcome to the Enhanced Encryption Tool!\n");

    // Ask whether to use a file or input text directly
    printf("Would you like to (1) input text directly or (2) use a text file? ");
    scanf("%d", &choice);
    getchar(); // To consume the newline character

    if (choice == 1) {
        // Input text directly from the user
        printf("Enter the text you want to encrypt or decrypt: ");
        fgets(input_text, sizeof(input_text), stdin);
        input_text[strcspn(input_text, "\n")] = 0;  // Remove newline character
    } else if (choice == 2) {
        // Ask for file name
        printf("Enter the file name (with extension): ");
        fgets(file_name, sizeof(file_name), stdin);
        file_name[strcspn(file_name, "\n")] = 0;  // Remove newline character

        // Read the text from the file
        read_file(file_name, input_text, sizeof(input_text));
    } else {
        printf("Invalid option.\n");
        return 1;
    }

    // Get the cipher choice
    cipher_choice = get_cipher_choice();

    // Get the shift key for Caesar Cipher
    shift = get_valid_shift_key();

    // Ask whether to encrypt or decrypt
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &direction);
    direction = (direction == 1) ? 1 : -1; // Convert to 1 for encryption, -1 for decryption

    // Apply the chosen cipher
    if (cipher_choice == 1) {
        caesar_cipher(input_text, shift, direction);
    } else if (cipher_choice == 2) {
        // Substitution cipher key (example)
        const char *substitution_key = "qazwsxrdctfvgbnhyujmkiolp";
        substitution_cipher(input_text, substitution_key, direction);
    }

    // Output the result
    printf("\nProcessed text: %s\n", input_text);

    // Ask if the user wants to save the output to a file
    printf("Would you like to save the result to a file? (y/n): ");
    char save_choice;
    getchar();  // Clear the newline left by previous input
    scanf("%c", &save_choice);

    if (save_choice == 'y' || save_choice == 'Y') {
        printf("Enter the output file name (with extension): ");
        char output_file[100];
        getchar(); // To consume the newline character
        fgets(output_file, sizeof(output_file), stdin);
        output_file[strcspn(output_file, "\n")] = 0; // Remove newline character
        write_file(output_file, input_text);
        printf("Result saved to %s\n", output_file);
    }

    return 0;
}
