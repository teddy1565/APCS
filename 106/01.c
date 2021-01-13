#include<stdio.h>

int main(){
    int students=0;
    while(scanf("%d",&students)!=EOF){
        short lucky=101,unlucky=-1;
        int studentss[20];
        for(int i=0;i<students;i++){
            int temp=0;
            scanf("%d",&temp);
            studentss[i] = temp;
            if(temp>unlucky&&temp<60){
                unlucky = temp;
            }else if(temp<lucky&&temp>59){
                lucky = temp;
            }
        }
        for(int i=0;i<students;i++){
            printf("%d ",studentss[i]);
        }
        if(unlucky!=-1)printf("\n%d\n",unlucky);
        else printf("\nbest case\n");
        if(lucky!=101)printf("\n%d\n",lucky);
        else printf("\nworst case\n");
    }
    return 0;
}