#include<stdio.h>
#define MAX 100
int main(){
    int n;
    printf("ENTER THE NUMBER OF PROCESS:");
    scanf("%d",&n);
    int p[MAX],at[MAX],bt[MAX],rem_bt[MAX],ct[MAX],tat[MAX],wt[MAX],q[MAX],visted[MAX]={0};
    printf("ENTER THE ARRIVAL TIME:");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    printf("ENTER THE BURST TIME:");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    int tq;
    printf("ENTER THE TIME QUANTUM:");
    scanf("%d",&tq);
    int front = 0,rear=0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(at[i]==0){
            q[rear++]=i;
            visted[i]=1;
        }
    }
    int curr_time = 0;
    while(cnt<n){
        if(front==rear)curr_time++;
        int idx = q[front++];
        printf("| %d ",idx+1);
        if(rem_bt[idx]>tq){
            rem_bt[idx]-=tq;
            curr_time+=tq;
        }
        else{
            curr_time+=rem_bt[idx];
            rem_bt[idx]=0;
            ct[idx]=curr_time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            cnt++;
        }
        for(int i=0;i<n;i++){
            if(at[i]<=curr_time&&!visted[i]){
                q[rear++]=i;
                visted[i]=1;
            }
        }
        if(rem_bt[idx]>0){
            q[rear++]=idx;
        }
        if(front==rear){
            for(int i=0;i<n;i++){
                if(!visted[i]){
                    visted[i]=1;
                    curr_time=at[i];
                    q[rear++]=i;
                    break;
                }
            }
        }
    }
    printf("|\n\nP_NO   BT      CT      TAT      WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

}