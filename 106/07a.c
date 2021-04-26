#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int n;
    int visit;
    struct node *L;
    struct node *R;
}node;
node* Node(int **data,int n,node* origin){

}
node* build_node(int **data,int n){
    node *origin = malloc(sizeof(node));
    origin->n = data[0][0];
    origin->L = NULL;
    origin->R = NULL;
    int counter=0;
    for(int i=0,j=n-1;i<j;i++){
        if(data[i][0]==data[0][0]){
            counter++;
        }
    }
    origin->R=malloc(sizeof(node)*counter);
    for(int i=0,j=n-1,c=0;i<j;i++){
        if(data[i][0]==data[0][0]){
            origin->R[c].n=data[i][1];
            origin->R[c].R=NULL;
            origin->R[c].L=NULL;
            c++;
        }
    }
    counter=0;
    for(int i=0,j=n-1;i<j;i++){
        if(data[i][1]==data[0][0]){
            counter++;
        }
    }
    origin->L=malloc(sizeof(node)*counter);
    for(int i=0,j=n-1,c=0;i<j;i++){
        if(data[i][1]==data[0][0]){
            origin->L[c].n=data[i][0];
            origin->L[c].R=NULL;
            origin->L[c].L=NULL;
            c++;
        }
    }
    return Node(data,n,origin);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int **data = (int**)malloc(sizeof(int*)*(n-1));
        for(int i=0,j=n-1;i<j;i++){
            data[i] = (int*)malloc(sizeof(int)*2);
            scanf("%d%d",&data[i][0],&data[i][1]);
        }
        node *p = build_node(data,n);
        printf("%d\n",p->n);
        printf("%d\n",p->L[0].n);
        printf("%d\n",p->R[0].n);
        printf("end\n");
    }
    return 0;
}