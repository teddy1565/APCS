#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int id;
  struct node *next;
  struct node *prev;
}node;
node *build(node *iterator,int a,int b){
    if(iterator->next==NULL&&iterator->prev==NULL){
      node *parent = malloc(sizeof(node));
      parent->id = a;
      parent->prev = iterator;
      iterator->next = parent;
      parent->next=malloc(sizeof(node));
      parent->next->id=b;
      parent->next->prev=parent;
      parent->next->next=NULL;
      iterator = parent;
    }else if(iterator->prev!=NULL){
      
    }
    return iterator;
}
int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    int *input = malloc(sizeof(int)*((n-1)*2));
    
    for(int i=0;i<(n-1)*2;i+=2){
      scanf("%d%d",&*(input+i),&*(input+(i+1)));
    }
    //debug--print input data
    /*printf("\n====OutPut=====\n");
    for(int i=0;i<(n-1)*2;i+=2){
      printf("[%d]\t[%d]\n",*(input+i),*(input+(i+1)));
    }
    printf("======end=====\n");*/
    node *iterator = malloc(sizeof(node));
    iterator->id=-1;
    iterator->next=NULL;
    iterator->prev=NULL;
    for(int i=0;i<(n-1)*2;i+=2){
      iterator = build(iterator,*(input+i),*(input+(i+1)));
    }
    while(iterator->next!=NULL){
      printf("[%d]",iterator->id);
      iterator = iterator->next;
    }
    printf("\nend\n");
    free(input);
    input=NULL;
  }
  return 0;
}