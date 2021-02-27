#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    int id;
    int visit;
    struct node *p;
    struct node *c;
}node;
void buildTree(node *CurrentNode,node *p,int N,int Leng,int *A,int *B){
    CurrentNode->id = N;
    CurrentNode->visit=0;
    CurrentNode->p=p;
    int CurrentNodeChildes = 0;
    for(int i=0;i<(Leng-1);i++){
        if(A[i]==N){
            CurrentNodeChildes++;
        }
    }
    if(CurrentNodeChildes)CurrentNode->c = malloc(sizeof(node)*CurrentNodeChildes);
    else CurrentNode->c = NULL;
    for(int i=0,j=0;i<(Leng-1);i++){
        if(A[i]==N){
            buildTree(&CurrentNode->c[j],CurrentNode,B[i],Leng,A,B);
            j++;
        }
    }
}
int main(){
    int keyin=0;
    while(scanf("%d",&keyin)!=EOF){
        int *A = malloc(sizeof(int)*(keyin-1));
        int *B = malloc(sizeof(int)*(keyin-1));
        int RootN;
        for(int i=0;i<(keyin-1);i++){
            scanf("%d%d",&A[i],&B[i]);
            if(i==0)RootN=A[0];
            for(int j=0;j<i;j++){
                if(RootN==B[j])RootN=A[j];
            }
        }
        node *origin = malloc(sizeof(node));
        buildTree(origin,NULL,RootN,keyin,A,B);
        printf("%d\n",origin->c[0].c[0].id);
        free(A);
        free(B);
        A=NULL;
        B=NULL;
    }
    return 0;
}
