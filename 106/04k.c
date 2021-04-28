#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    int visit;
    int length;
    struct node *p;
}node;
int* get_data_heap(int **data,int n){
    int *result = malloc(sizeof(int)*n);
    int index=0;
    for(int i=0;i<(n-1);i++){
        int find=0;
        for(int j=0;j<=index;j++){
            if(data[i][0]==result[j]){
                find=1;
                break;
            }
        }
        if(find==0){
            result[index]=data[i][0];
            index++;
        }
    }
    for(int i=0;i<(n-1);i++){
        int find=0;
        for(int j=0;j<=index;j++){
            if(data[i][1]==result[j]){
                find=1;
                break;
            }
        }
        if(find==0){
            result[index]=data[i][1];
            index++;
        }
    }
    return result;
}
node* get_child(int current,int except,int **data,int n){
    int counter=0;
    for(int i=0;i<(n-1);i++){
        if(data[i][0]==current||data[i][1]==current)counter++;
    }
    if(counter==0){
        return NULL;
    }
    node *p=malloc(sizeof(node)*counter);
    for(int i=0,index=0;i<(n-1);i++){
        if(data[i][0]==current&&data[i][1]!=except){
            p[index].value = data[i][1];
            p[index].visit=0;
            p[index].length=counter;
            p[index].p = get_child(data[i][1],current,data,n);
            index++;
        }else if(data[i][1]==current&&data[i][0]!=except){
            p[index].value = data[i][0];
            p[index].visit=0;
            p[index].length=counter;
            p[index].p = get_child(data[i][0],current,data,n);
            index++;
        }
    }
    return p;
}
int get_origin_length(int target,int **data,int n){
    int counter=0;
    for(int i=0;i<(n-1);i++){
        if(data[i][0]==target||data[i][1]==target)counter++;
    }
    return counter;
}
node* build_tree(int **data,int n,int *data_heap){
    node *o = malloc(sizeof(node));
    o->value = data_heap[0];
    o->visit=0;
    o->length=get_origin_length(o->value,data,n);
    o->p = get_child(data_heap[0],-1,data,n);
    return o;
}
void print_node(node *p){
    for(int i=0;i<(p->length);i++){
        printf("%d ",p->p[i].value);
    }
    printf("\n");
    for(int i=0;i<(p->length);i++){
        print_node(&p->p[i]);
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0;i<(n-1);i++){
            data[i] = (int*)malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        int *data_heap = get_data_heap(data,n);
        node *o = build_tree(data,n,data_heap);
        printf("length:%d\n",o->p[0].value);
        printf("end\n");
    }
    return 0;
}