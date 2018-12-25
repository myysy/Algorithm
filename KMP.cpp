#include<cstdio>
#include<iostream>
using namespace std;
#include<cstring>
const int MAX_LENGTH=100;
char a[MAX_LENGTH];
char b[MAX_LENGTH];
int Next[MAX_LENGTH];
void init_next(void){
    int j=0;
    int k=0;
    Next[0]=0;
    int length=strlen(b);
    if(length==2)
        Next[1]=0;
    for(j=1;j+1<length;j++){
        if(b[j]==b[k]){
            Next[j+1]=k+1;
            k++;
        }else {
            k=Next[k];
            while(k&&b[j]!=b[k]){
                k=Next[k];
            }
            if(k){
                Next[j+1]=k+1;
                k++;
            }else Next[j+1]=0;
        }
    }
    for(int i=0;i<length;i++)
        cout<<Next[i]<<' ';
}
int KMP(void){
    init_next();
    int positionA=0;
    int positionB=0;
    int lengthA=strlen(a);
    int lengthB=strlen(b);
    while(positionB<lengthB&&lengthA-positionA>=lengthB-positionB){
        if(a[positionA]==b[positionB]){
            positionA++;
            positionB++;
        }else {
            positionB=Next[positionB];
            positionA++;
        }
    }
    if(positionB==lengthB)
    return positionA-lengthB+1;
    else return 0;
}
int main(void){
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",a);
        scanf("%s",b);
        printf("\n%d\n",KMP());
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        memset(Next,0,sizeof(Next));
    }
    return 0;
}
/*
bbcabcdababcdabcdabde
abcdabd
*/