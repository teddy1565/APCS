#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    2021/1/23
    目前解題思路，先將樹產生出來，長相大概是單向串鍊連結。
    取最遠距離則由最頂部的至高祖先，向左搜尋。
    找到後再一次從最頂部向下找最右。
    其中經過的路徑加起來應該就會是最遠距離

    PS:
    偷偷記載一下，這一個月來精神狀況十分差勁，解題思路應該會再修改掉。
    希望精神狀況能盡快恢復...。
*/
typedef struct node{
    int uid;
    int kids_num;
    struct node *kids[];//一個節點可能有多名小孩 使用陣列搭配realloc 動態調整大小
}node;
int main(){
    int N=0;
    while(scanf("%d",&N)!=EOF){
        node *top_ancestor = NULL;
        for(int i=1;i<N;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(top_ancestor==NULL){ //若最頂部祖先不存在 則初始化至高祖先內容
                top_ancestor = malloc(sizeof(node));
                top_ancestor->uid = a;
                top_ancestor->kids_num = 1;
                *top_ancestor->kids = malloc(sizeof(node)*top_ancestor->kids_num);
                for(int k=0;k<top_ancestor->kids_num;k++){
                    top_ancestor->kids[k] = NULL; //將陣列中每個元素指向NULL(初始化)
                }
                top_ancestor->kids[0]->uid=b;
                top_ancestor->kids_num=0;
                *top_ancestor->kids=NULL;
            }
            
        }
    }
    return 0;
}