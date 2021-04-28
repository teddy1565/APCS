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
int* get_list(int **data,int n,int target,int leng){
    int *list = malloc(sizeof(int)*leng);
    for(int i=0,index=0;i<(n-1);i++){
        if(data[i][0]==target){
            list[index] = data[i][1];
            index++;
        }
    }
    return list;
}
node* build_tree(int **data,int n,int target,node *parent){
    node *p = malloc(sizeof(node));
    p->length = get_length(data,n,target);
    p->value = target;
    p->visit=0;
    p->p = malloc(sizeof(node)*p->length);
    int *list = get_list(data,n,p->value,p->length);
    p->p[0] = *parent;
    for(int i=1;i<(p->length);i++){
        p->p[i] = *build_tree(data,n,list[i-1],p);
    }
    free(list);
    list = NULL;
    return p;
}
void print_node(node *o,int parent){
    printf("%d\t",o->value);
    for(int i=0;i<o->length;i++){
        if(o->p[i].value==parent)continue;
        print_node(&o->p[i],o->value);
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0;i<(n-1);i++){
            data[i] = malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        node *o = malloc(sizeof(node));
        o->value = find_top(data,n);
        o->length = get_length(data,n,o->value);
        o->visit = 0;
        o->p = malloc(sizeof(node)*(o->length));
        int *list = get_list(data,n,o->value,o->length);
        for(int i=0;i<o->length;i++){
            o->p[i] = *build_tree(data,n,list[i],o);
        }
        // print_node(o,o->value);
        printf("end\n");
    }
    return 0;
}