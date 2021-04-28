#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    int visit;
    int length;
    struct node *p;
}node;
int find_top(int **data,int n){
    int start = data[0][0];
    for(int i=0;i<(n-1);i++){
        if(data[i][1]==start){
            start = data[i][0];
            i=0;
        }
    }
    return start;
}
int get_length(int **data,int n,int target){
    int counter=0;
    for(int i=0;i<(n-1);i++){
        if(data[i][0]==target||data[i][1]==target)counter++;
    }
    return counter;
}
int* get_child_list(int **data,int n,int target){
    int counter=1;
    for(int i=0;i<(n-1);i++){
        if(data[i][0]==target)counter++;
    }
    int *result=malloc(sizeof(int)*counter);
    for(int i=0,j=0;i<(n-1);i++){
        if(data[i][0]==target){
            result[j+1]=data[i][1];
        }
    }
    result[0]=counter;
    return result;
}
node* build_child(int **data,int n,node *parent){
    int *list = get_child_list(data,n,parent->value);
    for(int i=0;i<parent->length;i++){
        parent->p[i].value = list[i+1];
        parent->p[i].length = get_length(data,n,parent->p[i].value);
        parent->p[i].visit=0;
        parent->p[i].p = NULL;
        if(parent->p[i].length>0){
            parent->p[i].p = malloc(sizeof(node)*parent->p[i].length);
            parent->p[i].p = build_child(data,n,&parent->p[i]);
        }
    }
    free(list);
    list=NULL;
    return parent->p;
}
node* build_tree(int **data,int n,int origin){
    node *o = malloc(sizeof(node));
    o->value = origin;
    o->length = get_length(data,n,origin);
    o->visit=0;
    o->p = malloc(sizeof(node)*(o->length));
    o->p = build_child(data,n,o);
    return o;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0;i<(n-1);i++){
            data[i] = malloc(sizeof(int*)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        build_tree(data,n,data[0][0]);
        printf("end");
    }
    return 0;
}