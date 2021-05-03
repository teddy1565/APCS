#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    int visit;
    int length;
    struct node *parent;
    struct node *child;
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
    p->child = malloc(sizeof(node)*(p->length-1));
    int *list = get_list(data,n,p->value,p->length);
    p->parent = parent;
    for(int i=0;i<(p->length);++i){
        p->child[i] = *build_tree(data,n,list[i],p);
    }
    free(list);
    list = NULL;
    return p;
}
void print_node(node *o,int parent,int mode){
    if(mode==1)printf("%d\t",o->visit);
    else if(mode==2)printf("%d\t",o->value);
    for(int i=0;i<o->length;i++){
        if(o->child[i].value==parent)continue;
        print_node(&o->child[i],o->value,mode);
    }
}
int DFS(node *o,int counter,node *p,int *level){
    o->visit = 1;
    if(o->length==1&&(o->parent->visit)==1){
        if(counter>(*level)){
            *level = counter;
            p = o;
        }
    }
    printf("{%d}\n",o==o->parent);
    for(int i=0;i<((o->length-1));i++){
        //printf("{%d}:{%d}\n",o->p[i].value,o->p[i].visit);
        DFS(&o->child[i],counter+1,p,level);
    }
    return 0;
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
        o->child = malloc(sizeof(node)*(o->length));
        o->parent = o;
        int *list = get_list(data,n,o->value,o->length);
        for(int i=0;i<o->length;i++){
            o->child[i] = *build_tree(data,n,list[i],o);
        }
        int DFS_Counter = 0;
        node *max_p = NULL;
        int level = 0;
        DFS(o,DFS_Counter,max_p,&level);
        printf("\n[%d]\n",level);
        printf("end\n");
    }
    return 0;
}