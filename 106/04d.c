#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{//節點結構
    int id;
    int visit;
    int childAmount;
    struct node *p;
    struct node *c;
}node;
void buildTree(node *CurrentNode,node *p,int N,int Leng,int *A,int *B){//利用遞迴建立樹
    CurrentNode->id = N;
    CurrentNode->visit=0;
    CurrentNode->p=p;
    int CurrentNodeChildes = 0;
    for(int i=0;i<(Leng-1);i++){
        if(A[i]==N){
            CurrentNodeChildes++;
        }
    }
    CurrentNode->childAmount = CurrentNodeChildes;
    if(CurrentNodeChildes)CurrentNode->c = malloc(sizeof(node)*CurrentNodeChildes);
    else CurrentNode->c = NULL;
    for(int i=0,j=0;i<(Leng-1);i++){
        if(A[i]==N){
            buildTree(&CurrentNode->c[j],CurrentNode,B[i],Leng,A,B);
            j++;
        }
    }
}
int Scanner(node *o){
    node *s = o;
    if(s->c!=NULL){
        for(int i=0;i<s->childAmount;i++){
            if(Scanner(&s->c[i]))return 1;
        }
    }else{
        if(s->visit)return 1;
        else return 0;
    }
    return 0;
}
int DFS(node *o,int max){
    if(o->c!=NULL){
        for(int i=0;i<o->childAmount;i++){
            int n = DFS(&o->c[i],max);
            max = n>max?n:max;
        }
    }else{
        int counter=0;
        
        while(o->p!=NULL){

        }
    }
    return 0;
}
void printNode(node *o){//輸出樹的數值 debug用
    printf("%d\n",o->id);
    
    if(o->c!=NULL){
        for(int i=0;i<o->childAmount;i++){
            printNode(&o->c[i]);
        }
    }
}
int main(){
    int keyin=0;
    while(scanf("%d",&keyin)!=EOF){
        int *A = malloc(sizeof(int)*(keyin-1));//儲存父節點
        int *B = malloc(sizeof(int)*(keyin-1));//儲存子節點
        int RootN;
        for(int i=0;i<(keyin-1);i++){//找出根
            scanf("%d%d",&A[i],&B[i]);
            if(i==0)RootN=A[0];
            for(int j=0;j<i;j++){
                if(RootN==B[j])RootN=A[j];
            }
        }
        node *origin = malloc(sizeof(node));
        buildTree(origin,NULL,RootN,keyin,A,B);//生成樹
        //printNode(origin);
        //printf("%d",DFS(origin));
        free(A);
        free(B);
        A=NULL;
        B=NULL;
    }
    return 0;
}
