#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int uid;
    int kids_num;
    struct node *kids[];
}node;
int main(){
    int N=0;
    while(scanf("%d",&N)!=EOF){
        node *top_ancestor = NULL;
        for(int i=1;i<N;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(top_ancestor==NULL){
                top_ancestor = malloc(sizeof(node));
                top_ancestor->uid = a;
                top_ancestor->kids_num = 1;
                *top_ancestor->kids = malloc(sizeof(node)*top_ancestor->kids_num);
                for(int k=0;k<top_ancestor->kids_num;k++){
                    top_ancestor->kids[k] = NULL;
                }
                top_ancestor->kids[0]->uid=b;
                top_ancestor->kids_num=0;
                *top_ancestor->kids=NULL;
            }
            
        }
    }
    return 0;
}