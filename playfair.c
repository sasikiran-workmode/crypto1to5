//playfair cipher

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]){
    int used[26]={0};
    int i,j,k=0;

    used['j'-'a']=1;

    for(i=0;key[i];i++){
        char c=tolower(key[i]);
        if(!used[c-'a'] && isalpha(c)){
            matrix[k/5][k%5]=c;
            used[c-'a']=1;
            k++;
        }
    }

    for(i=0;i<26;i++){
        if(!used[i]){
            matrix[k/5][k%5]='a'+i;
            k++;
        }
    }
}

void findPos(char c,int *row,int *col){
    if(c=='j') c='i';

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(matrix[i][j]==c){
                *row=i;
                *col=j;
                return;
            }
}

int main(){

    char key[50],plaintext[100],clean[100],prepared[100],cipher[100];
    int i,j=0,p=0;
    
    // strcpy(key,"monarchy");
    //strcpy(plaintext,"hello world");

    printf("enter key: ");
    scanf("%s",key);

    generateMatrix(key);

    getchar();

    printf("enter plaintext: ");
    fgets(plaintext,100,stdin);

    int len=strlen(plaintext);

    for(i=0;i<len;i++){
        if(isalpha(plaintext[i])){
            clean[j++]=tolower(plaintext[i]);
            if(clean[j-1]=='j')
                clean[j-1]='i';
        }
    }

    clean[j]='\0';

    for(i=0;i<j;i++){
        prepared[p++]=clean[i];

        if(i+1<j && clean[i]==clean[i+1])
            prepared[p++]='x';
    }

    if(p%2!=0)
        prepared[p++]='x';

    prepared[p]='\0';

    int k=0;

    for(i=0;i<p;i+=2){

        int r1,c1,r2,c2;

        findPos(prepared[i],&r1,&c1);
        findPos(prepared[i+1],&r2,&c2);

        if(r1==r2){
            cipher[k++]=matrix[r1][(c1+1)%5];
            cipher[k++]=matrix[r2][(c2+1)%5];
        }
        else if(c1==c2){
            cipher[k++]=matrix[(r1+1)%5][c1];
            cipher[k++]=matrix[(r2+1)%5][c2];
        }
        else{
            cipher[k++]=matrix[r1][c2];
            cipher[k++]=matrix[r2][c1];
        }
    }

    cipher[k]='\0';

    printf("ciphertext: %s",cipher);

    return 0;
}