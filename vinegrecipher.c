//vinegre cipher
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char plaintext[100],key[100],ciphertext[100];
    int i,j=0;
    //strcpy(plaintext,"sasi");
    printf("enter plaintext: ");
    fgets(plaintext,100,stdin);

    printf("enter key: ");
    scanf("%s",key);

    int plen=strlen(plaintext);
    int klen=strlen(key);

    for(i=0;i<plen;i++){
        if(plaintext[i]==' '||plaintext[i]=='\n')
            continue;

        char p=tolower(plaintext[i]);
        char k=tolower(key[j%klen]);

        int c=((p-'a')+(k-'a'))%26;
        ciphertext[j]=c+'a';
        j++;
    }

    ciphertext[j]='\0';
    printf("ciphertext: %s",ciphertext);
    return 0;
}