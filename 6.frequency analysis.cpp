#include<stdio.h>
void breakAffineCipher(char *cipherText) {
    int i, a, b;
    char plainText[100];
    a = 1; 
    b = 1;  
    for (i = 0; cipherText[i]; i++) {
        plainText[i] = (cipherText[i] - 'A' - b) * a;
        plainText[i] = (plainText[i] % 26 + 26) % 26;  
        plainText[i] += 'A';
    }
    printf("Plaintext: %s", plainText);
}
int main() {
    char cipherText[100];
    printf("Enter the ciphertext: ");
    fgets(cipherText, sizeof(cipherText), stdin);
    breakAffineCipher(cipherText);
    return 0;
}
