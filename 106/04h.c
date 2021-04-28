#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int n;
    int visit;
    struct node *N;
}node;
node* add_leaves(node *o,int **data,int n,int o_n){
    for(int i=0;i<o_n;i++){
        for(int j=0;j<(n-1);j++){
            
        }
    }
}
node* build_tree(node *o,int **data,int n){
    int counter=0;
    for(int i=0;i<(n-1);i++){
        if(data[i][0]==o->n||data[i][1]==o->n)counter++;
    }
    o->N = malloc(sizeof(node)*counter);
    int *data_heap = malloc(sizeof(int)*counter);
    for(int i=0,j=0;i<(n-1);i++){
        if(data[i][0]==o->n||data[i][1]==o->n){
            data_heap[j] = data[i][0]==o->n?data[i][1]:data[i][0];
            j++;
        }
    }
    for(int i=0;i<counter;i++){
        o->N[i].n = data_heap[i];
        o->N[i].visit=0;
        o->N[i].N=NULL;
    }
    return add_leaves(o,data,n,counter);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0,j=n-1;i<j;i++){
            data[i] = (int*)malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        node *origin = malloc(sizeof(node));
        origin->n=data[0][0];
        origin->visit=0;
        origin->N = NULL;
        build_tree(origin,data,n);
    }
    return 0;
}