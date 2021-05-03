#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    int visit;
    int length;
    struct node **p;
}node;
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
        for(int j=0;j<list[i].length;j++){
            for(int k=0;k<n;k++){
                if(list[k].value==numbers[j]){
                    list[k].p[0] = &list[i];
                }
            }
        }
    }
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
        for(int i=0;i<n;i++){
            printf("%d ",p[i].value);
        }
        printf("\n");
        //end
        printf("end\n");
        for(int i=0;i<n-1;i++){
            free(data[i]);
        }
        free(data);
    }
    return 0;
}