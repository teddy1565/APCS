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
typedef struct target{
    int value;
    struct node *t;
}target;
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
// node *DFS(node *o,int counter,int max,node *target){
//     if(o->c!=NULL){
//         for(int i=0;i<o->childAmount;i++){
//             target = DFS(&o->c[i],counter+1,max,target);
//         }
//         return target;
//     }else{
//         if(counter<=max){
//             return target;
//         }
//     }
//     return DFS(o,counter,counter,o);
// }
int DFS_S(node *o,int depth){//對每個節點標出節點深度為多少
    o->visit = depth;
    for(int i=0;i<o->childAmount;i++){
        DFS_S(&o->c[i],depth+1);
    }
    return 0;
}
target *DFS_P1(node *o,target *t){//找出最深的節點
    if(o->visit>t->value){
        t->value = o->visit;
        t->t = o;
    }
    for(int i=0;i<o->childAmount;i++){
        t = DFS_P1(&o->c[i],t);
    }
    return t;
}
int DFS_INITIAL(node *o){//將所有節點之visit初始化
    o->visit=0;
    for(int i=0;i<o->childAmount;i++){
        DFS_INITIAL(&o->c[i]);
    }
    return 0;
}
int DFS_E(node *o,int max){
    if(o->visit==0)max++;
    for(int i=0;i<o->childAmount;i++){
        if(o->c[i].visit==1)continue;
        max = DFS_E(&o->c[i],max);
    }
    o->visit=1;
    if(o->p!=NULL)max = DFS_E(o->p,max);
    return max;
}
void printNode(node *o){//輸出樹的數值 debug用
    printf("id:[%d]\tvisit:[%d]\n",o->id,o->visit);
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
        target *t = malloc(sizeof(target));
        t->value = 0;
        t->t = origin;
        DFS_S(origin,0);//DFS過程初始
        t = DFS_P1(origin,t);//找出最深之子節點
        DFS_INITIAL(origin);
        printNode(origin);
        printf("[%d]\n",DFS_E(t->t,0));
        // printf("\n[%d]\n",DFS(origin,0,0,temp)->id);
        free(A);
        free(B);
        A=NULL;
        B=NULL;
    }
    return 0;
}
