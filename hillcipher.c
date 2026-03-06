//hill cipher
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char plaintext[100],ciphertext[100];
    int key[2][2];
    int i,j,k=0;

    printf("enter plaintext: ");
    fgets(plaintext,100,stdin);
    //strcpy(plaintext,"sasi");
    int len=strlen(plaintext);

    char temp[100];
    int t=0;

    for(i=0;i<len;i++)
        if(plaintext[i]!=' ' && plaintext[i]!='\n')
            temp[t++]=tolower(plaintext[i]);

    temp[t]='\0';
    
    // int key[2][2]={{3,3},{2,5}};
    printf("enter 2x2 key matrix:\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            scanf("%d",&key[i][j]);

    if(t%2!=0){
        temp[t]='x';
        temp[t+1]='\0';
        t++;
    }

    for(i=0;i<t;i+=2){
        int p1=temp[i]-'a';
        int p2=temp[i+1]-'a';

        int c1=(key[0][0]*p1+key[0][1]*p2)%26;
        int c2=(key[1][0]*p1+key[1][1]*p2)%26;

        ciphertext[k++]=c1+'a';
        ciphertext[k++]=c2+'a';
    }
    ciphertext[k]='\0';
    printf("ciphertext: %s",ciphertext);

    return 0;
}