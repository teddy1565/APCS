#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    int visit;
    int length;
    struct node **p;
}node;
typedef struct root{
    struct node *p;
    int level;
}root;
int get_length(int **data,int n,int target){
    int counter=0;
    for(int i=0;i<n-1;i++){
        if(data[i][0]==target||data[i][1]==target)counter++;
    }
    return counter;
}
int* get_list(int **data,int n,int target){
    int length = get_length(data,n,target);
    int *list = malloc(sizeof(int)*length);
    for(int i=0,j=0;i<n-1;i++){
        if(data[i][0]==target){
            list[j++] = data[i][1];
        }else if(data[i][1]==target){
            list[j++] = data[i][0];
        }
    }
    return list;
}
int get_top(int **data,int n){
    int start = data[0][0];
    int done=0;
    while(done==0){
        done=1;
        for(int i=0;i<n-1;i++){
            if(data[i][1]==start){
                start = data[i][0];
                done=0;
            }
        }
        if(done==1)break;
    }
    return start;
}
node* get_node_list(int **data,int n){
    node *list = malloc(sizeof(node)*n);
    int *number_list = malloc(sizeof(int)*n);
    int index=0;
    for(int i=0;i<n-1;i++){
        int current = data[i][0];
        int find=0;
        for(int j=0;j<=index;j++){
            if(current==number_list[j]){
                find=1;
                break;
            }
        }
        if(find==0){
            number_list[index] = data[i][0];
            index++;
        }
    }
    for(int i=0;i<n-1;i++){
        int current = data[i][1];
        int find=0;
        for(int j=0;j<=index;j++){
            if(current==number_list[j]){
                find=1;
                break;
            }
        }
        if(find==0){
            number_list[index] = data[i][1];
            index++;
        }
    }
    for(int i=0;i<n;i++){
        list[i].value = number_list[i];
        list[i].visit=0;
        list[i].length = get_length(data,n,number_list[i]);
        list[i].p=NULL;
    }
    free(number_list);
    return list;
}
node *build_tree(node *list,int **data,int n){
    for(int i=0;i<n;i++){
        list[i].p = (node**)malloc(sizeof(node*)*list[i].length);
    }
    for(int i=0;i<n;i++){
        int *numbers = get_list(data,n,list[i].value);
        for(int j=0,o=0;j<list[i].length;j++){
            for(int k=0;k<n;k++){
                if(list[k].value==numbers[j]){
                    list[i].p[o++] = &list[k];
                }
            }
        }
        for(int j=0;j<list[i].length;j++){
            for(int k=0;k<n;k++){
                if(list[k].value==numbers[j]){
                    list[k].p[0] = &list[i];
                }
            }
        }
    }
    return &list[0];
}
void printf_node(node *o){
    printf("%d ",o->value);
    o->visit=1;
    for(int i=0;i<o->length;i++){
        if(o->p[i]->visit==1)continue;
        printf_node(o->p[i]);
    }
}
void initial_node(node *o){
    o->visit = 0;
    for(int i=0;i<o->length;i++){
        if(o->p[i]->visit==0)continue;
        initial_node(o->p[i]);
    }
}
root* DFS(node *o,int counter,root *max){
    o->visit = 1;
    if(o->length==1&&o->p[0]->visit==1){
        if(counter>max->level){
            max->level = counter;
            max->p = o;
        }
    }
    for(int i=0;i<o->length;i++){
        if(o->p[i]->visit==1)continue;
        DFS(o->p[i],counter+1,max);
    }
    return max;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0;i<n-1;i++){
            data[i] = malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        node *p = get_node_list(data,n);
        node *o = build_tree(p,data,n);
        int *level = malloc(sizeof(int));
        level = 0;
        int counter = 0;
        root *max = malloc(sizeof(root));
        max->level = 0;
        max->p = NULL;
        root *result = DFS(o,counter,max);
        initial_node(o);
        printf("%d:%d\n",result->level,result->p->value);
        o = result->p;
        max->level = 0;
        max->p = NULL;
        result = DFS(o,counter,max);
        printf("%d:%d\n",result->level,result->p->value);
        //end
        free(level);
        level = NULL;
        free(max);
        max = NULL;
        for(int i=0;i<n-1;i++){
            free(data[i]);
        }
        free(data);
    }
    return 0;
}