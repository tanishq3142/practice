#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    printf("ENTER THE NUMBER OF PROCESSES:");
    scanf("%d",&n);
    int p[n],at[n],bt[n],ct[n],wt[n],tat[n],rem_bt[n];
    float avg_tat=0,avg_wt=0;
    int cnt = 0,curr_time=0;
    printf("ENTER THE ARRIVAL TIME:");
    for(int i=0;i<n;i++){
        p[i]=i+1;
        scanf("%d",&at[i]);
    }
    printf("ENTER THE BURST TIME:");
    for(int i=0;i<n;i++){
        p[i]=i+1;
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    while(cnt<n){
        int mn = -1,mini = INT_MAX;
        for(int i=0;i<n;i++){
            if((rem_bt[i]>0)&&(at[i]<=curr_time)){
                if(mini>rem_bt[i]){
                    mini=rem_bt[i];
                    mn = i;
                }
            }
        }
        if(mn==-1){
            curr_time++;
        }
        else{
            rem_bt[mn]-=1;
            curr_time++;
            if(rem_bt[mn]==0){
                ct[mn]=curr_time;
                tat[mn]=ct[mn]-at[mn];
                wt[mn]=tat[mn]-bt[mn];
                cnt++;
            }
        }
    }
    printf("P_NO    AT    BT    CT    TAT    WT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}