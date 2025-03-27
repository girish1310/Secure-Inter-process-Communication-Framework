#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIXED_KEY "osproject1234567" 


void xorEncryptDecrypt(char *message, const char *key, char *output) {
    int msgLen = strlen(message);
    int keyLen = strlen(key);

    for (int i = 0; i < msgLen; i++) {
        output[i] = message[i] ^ key[i % keyLen];  // XOR with key
    }
    output[msgLen] = '\0'; 
}

int main() {
    char *message;
    char *encrypted;
    char *decrypted;
    char userKey[17]; 
    int maxLen;

    // message length input
    printf("Enter the length of your message: ");
    scanf("%d", &maxLen);
    getchar(); 

    // Allocate memory dynamically
    message = (char *)malloc(maxLen + 1);
    encrypted = (char *)malloc(maxLen + 1);
    decrypted = (char *)malloc(maxLen + 1);

    if (!message || !encrypted || !decrypted) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    return 0;
}
