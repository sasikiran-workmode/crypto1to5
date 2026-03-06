#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char plaintext[100],key[100],ciphertext[100];
    int i;

    printf("enter plaintext: ");
    scanf("%s",plaintext);

    printf("enter key (same length): ");
    scanf("%s",key);

    int len=strlen(plaintext);

    for(i=0;i<len;i++){
        char p=tolower(plaintext[i]);
        char k=tolower(key[i]);

        int c=((p-'a')+(k-'a'))%26;

        ciphertext[i]=c+'a';
    }

    ciphertext[len]='\0';

    printf("ciphertext: %s",ciphertext);

    return 0;
}