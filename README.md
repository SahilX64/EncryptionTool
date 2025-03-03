# Encryption Tool

This is an encryption and decryption tool implemented in C that supports two types of ciphers: Caesar Cipher and Substitution Cipher. The program allows users to encrypt and decrypt messages, providing a shift key for Caesar Cipher and a custom alphabet for Substitution Cipher.

## Features
- **Caesar Cipher**: Shift each letter in the message by a specified number of positions in the alphabet.
- **Substitution Cipher**: Replace each letter in the message with a corresponding letter from a custom alphabet.
- **Encryption and Decryption**: The tool can either encrypt or decrypt messages based on user input.

## Requirements
- A C compiler (e.g., GCC) to compile the source code.
- A terminal or command prompt to run the program.

## Installation

1. Clone or download the repository containing the `encryption_tool.c` file.
2. Ensure you have a C compiler installed:
   - **Windows**: MinGW or TDM-GCC.
   - **macOS/Linux**: GCC.

## Usage

### Step 1: Compile the Program
To compile the program, run the following command in your terminal or command prompt:

bash
gcc -o encryption_tool encryption_tool.c
This will generate an executable file called encryption_tool.

Step 2: Run the Program
After compiling, run the program with the following command:

Windows:
encryption_tool.exe

macOS/Linux:
./encryption_tool

Step 3: Follow the Prompts
The program will prompt you to choose between:

Inputting text directly or using a text file.
Choosing between Caesar Cipher or Substitution Cipher.
Entering a shift key for Caesar Cipher or a custom alphabet for Substitution Cipher.
Encrypting or decrypting the text.
You can choose to save the result to a file if desired.

**Example**

Welcome to the Enhanced Encryption Tool!
Would you like to (1) input text directly or (2) use a text file? 1
Choose a cipher:
1. Caesar Cipher
2. Substitution Cipher
Enter your choice (1 or 2): 1
Enter the shift key (positive integer): 3
Choose an option:
1. Encrypt
2. Decrypt
Enter your choice (1 or 2): 1
Enter the text you want to encrypt or decrypt: Hello World
Processed text: Khoor Zruog
Would you like to save the result to a file? (y/n): y
Enter the output file name (with extension): output.txt
Result saved to output.txt
