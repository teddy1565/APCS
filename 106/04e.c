/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int num;
    struct node *list;
}node;
typedef struct DFSList{
    node *n;
    struct DFSList *next;
    struct DFSList *prev;
}DFSList;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int **Plist = (int**)malloc(sizeof(int*)*(n-1));
        DFSList *LIST= malloc(sizeof(DFSList));
        LIST->n=NULL;
        LIST->next=NULL;
        LIST->prev=NULL;
        for(int i=0;i<(n-1);i++){
            Plist[i] = (int*)malloc(sizeof(int)*2);
            scanf("%d%d",&Plist[i][0],&Plist[i][1]);
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<(n-1);j++){
                if(LIST->n==NULL){
                    node *o = malloc(sizeof(node));
                    o->num = Plist[j][i];
                    o->list=NULL;
                    LIST->n = o;
                }else{
                    DFSList *search = LIST;
                    while(search->prev!=NULL)search = search->prev;
                    int find=0;
                    while(search->next!=NULL){
                        if(Plist[j][i]==search->n->num){
                            find=1;
                            break;
                        }
                        search = search->next;
                    }
                    if(Plist[j][i]==search->n->num)find=1;
                    if(find==0){
                        node *o = malloc(sizeof(node));
                        o->num = Plist[j][i];
                        o->list = NULL;
                        LIST->next = malloc(sizeof(DFSList));
                        LIST->next->n=o;
                        LIST->next->prev = LIST;
                        LIST->next->next=NULL;
                        LIST = LIST->next;
                    }
                }
            }
        }
        while(LIST->prev!=NULL)LIST = LIST->prev;
        // for(int i=0;i<(n-1);i++){
        //     printf("%d\t%d\n",Plist[i][0],Plist[i][1]);
        // }
        // printf("\n");
        // while(LIST->prev!=NULL)LIST = LIST->prev;
        // while(LIST->next!=NULL){
        //     printf("%d",LIST->n->num);
        //     LIST = LIST->next;
        // }
        // printf("%d",LIST->n->num);
    }
    return 0;
}
