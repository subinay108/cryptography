#include<stdio.h>
#include<string.h>

#define MAX 100

char* viegnere_encrypt(char* plainText, char* key);
char* viegnere_decrypt(char* cypherText, char* key);

int main(){
    char plainText[] = "THEYDRINKTHETEA"; // only A-Z
    char key[] = "DUH";
    char* cypherText = viegnere_encrypt(plainText, key);
    
    printf("Plain Text: %s\n", plainText);
    printf("Cypher Text: %s\n", cypherText);
    printf("After decryption: %s\n", viegnere_decrypt(cypherText, key));
}

char* viegnere_encrypt(char* plainText, char* key){
    int n = strlen(plainText);
    int m = strlen(key);
    static char cypherText[MAX];
    int j = 0;
    for(int i = 0; i < n; i++){
        cypherText[i] = 'A' + (plainText[i] - 'A' + key[j]) % 26;
        j = (j + 1) % m;
    }
    cypherText[n] = '\0';
    return cypherText;
}

char* viegnere_decrypt(char* cypherText, char* key){
    int n = strlen(cypherText);
    int m = strlen(key);
    static char plainText[MAX];
    int j = 0;
    for(int i = 0; i < n; i++){
        plainText[i] = 'A' + ((cypherText[i] - 'A' - key[j]) % 26 + 26) % 26;
        j = (j + 1) % m;
    }
    plainText[n] = '\0';
    return plainText;
}
