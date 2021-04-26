#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    int visit;
    struct node *N;
}node;
node* node_generator(int n,int *N){
    
}
node* build_tree(int **data,int n,int *data_heap){

}
int* data_sqrt(int **data,int n){
    int *data_heap = malloc(sizeof(int)*n);
    int index=0;
    for(int i=0;i<(n-1);i++){
        int find=0;
        for(int j=0;j<=index;j++){
            if(data_heap[j]==data[i][0]){
                find=1;
                break;
            }
        }
        if(find==0){
            data_heap[index] = data[i][0];
            index++;
        }
    }
    for(int i=0;i<(n-1);i++){
        int find=0;
        for(int j=0;j<=index;j++){
            if(data_heap[j]==data[i][1]){
                find=1;
                break;
            }
        }
        if(find==0){
            data_heap[index] = data[i][1];
            index++;
        }
    }
    return data_heap;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0;i<(n-1);i++){
            data[i] = (int*)malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        int *data_heap = data_sqrt(data,n);
        node *o = build_tree(data,n,data_heap);
    }
    return 0;
}