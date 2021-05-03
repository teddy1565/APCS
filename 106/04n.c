#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    int visit;
    int length;
    struct node **p;
}node;
int get_top(int **data,int n){
    int find=0;
    int start = data[0][0];
    while(find==0){
        find=1;
        for(int i=0;i<n;i++){
            if(data[i][1]==start){
                find=0;
                start = data[i][0];
                break;
            }
        }
    }
    return start;
}
int *get_list(int **data,int n,int target){
    int leng = get_length(data,n-1,target);
    int *list = malloc(sizeof(int)*leng);
    for(int i=0;i<leng;i++){
    
    }
}
int get_length(int **data,int n,int target){
    int counter = 0;
    for(int i=0;i<n;i++){
        if(data[i][0]==target||data[i][1]==target)counter++;
    }
    return counter;
}
node* build_node(node *list,int **data,int n,int start){
    for(int i=0;i<n;i++){
        
    }
    node *o = malloc(sizeof(node));
    o->value = get_top(data,n-1);
    o->length = get_length(data,n-1,o->value);
    o->visit = 0;
    o->p = NULL;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        node *list = malloc(sizeof(node)*n);
        int **data = malloc(sizeof(int*)*(n-1));
        int m = n-1;
        for(int i=0;i<m;i++){
            data[i] = malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        get_list(data,n);
        printf("%d\n",get_top(data,m));
        printf("end\n");
    }
    return 0;
}