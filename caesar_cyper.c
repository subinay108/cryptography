#include<stdio.h>
#include<string.h>

#define MAX 100

char* caesar_encrypt(char* plainText, int key);
char* caesar_decrypt(char* cypherText, int key);

int main(){
    char plainText[] = "HELLO"; // only A-Z
    int key = 15;
    char* cypherText = caesar_encrypt(plainText, key);
    
    printf("Plain Text: %s\n", plainText);
    printf("Cypher Text: %s\n", cypherText);
    printf("After decryption: %s\n", caesar_decrypt(cypherText, key));
}

char* caesar_encrypt(char* plainText, int key){
    int n = strlen(plainText);
    static char cypherText[MAX];
    for(int i = 0; i < n; i++){
        cypherText[i] = 'A' + (plainText[i] - 'A' + key) % 26;
    }
    cypherText[n] = '\0';
    return cypherText;
}

char* caesar_decrypt(char* cypherText, int key){
    int n = strlen(cypherText);
    static char plainText[MAX];
    for(int i = 0; i < n; i++){
        plainText[i] = 'A' + (cypherText[i] - 'A' - key + 26) % 26;
    }
    plainText[n] = '\0';
    return plainText;
}
