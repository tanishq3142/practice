#include <stdio.h>
#include <string.h>
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
    return;
}
int main()
{
    int n;
    printf("ENTER THE NUMBER OF PROCESS:");
    scanf("%d", &n);
    int p[n], bt[n], ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    printf("ENTER THE BURST TIME:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for(int j=i+1;j<n;j++){
            if(bt[j]<bt[i]){
                swap(&bt[j],&bt[i]);
                swap(&p[j],&p[i]);
            }
        }
    }
    int cur_time = 0;
    for(int i=0;i<n;i++){
        ct[i]=cur_time+bt[i];
        tat[i]=ct[i];
        wt[i]=tat[i]-bt[i];
        cur_time+=bt[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i]>p[j]){
                swap(&p[i],&p[j]);
                swap(&bt[i],&bt[j]);
                swap(&ct[i],&ct[j]);
                swap(&tat[i],&tat[j]);
                swap(&wt[i],&wt[j]);
            }
        }
    } 
    printf("P_NO   BT      CT      TAT      W\n");
    for(int i=0;i<n;i++){
       
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],ct[i],tat[i],wt[i]);
    }
}