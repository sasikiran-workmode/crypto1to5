#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char plaintext[100],ciphertext[100];
    int key,i;
    //strcpy(plaintext,"sasi");
    
    printf("enter plaintext: ");
    fgets(plaintext,100,stdin);

    printf("enter key: ");
    //key=2;
    scanf("%d",&key);

    int len=strlen(plaintext);

    for(i=0;i<len;i++){
        if(!isalpha(plaintext[i]))
            continue;

        char p=tolower(plaintext[i]);
        int c=((p-'a')+key)%26;

        ciphertext[i]=c+'a';
    }

    ciphertext[len]='\0';

    printf("ciphertext: %s",ciphertext);

    return 0;
}