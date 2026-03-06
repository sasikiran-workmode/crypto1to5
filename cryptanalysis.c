#include <stdio.h>
#include <string.h>
void frequency(char text[]) {

    int freq[256]={0};
    int len=strlen(text);

    for(int i=0;i<len;i++)
        freq[(unsigned char)text[i]]++;
    printf("Character   Frequency   Relative_Frequency\n");

    for(int i=0;i<256;i++){
        if(freq[i]>0){
            double rel=(double)freq[i]/len;
            printf("   %c           %d           %.4f\n",i,freq[i],rel);
        }
    }
}
int main(){

    char plaintext[1000];
    char ciphertext[1000];

    printf("Enter plaintext:\n");
    fgets(plaintext,sizeof(plaintext),stdin);

    printf("Enter ciphertext:\n");
    fgets(ciphertext,sizeof(ciphertext),stdin);

    printf("\nPlaintext Frequency Analysis\n");
    frequency(plaintext);

    printf("\nCiphertext Frequency Analysis\n");
    frequency(ciphertext);

    return 0;
}