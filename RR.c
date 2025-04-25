#include<stdio.h>
int main(){
    int n;
    printf("ENTER THE NUMBER OF PROCESS:");
    scanf("%d",&n);
    int at[n],p[n],bt[n],rem_bt[n],ct[n],tat[n],wt[n];
    float avg_tat=0,avg_wt=0;
    printf("ENTER THE ARRIVAL TIME OF EACH PROCESS :");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
        p[i]=i+1;
    }
    printf("ENTER THE BURST TIME OF EACH PROCESS :");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("ENTER THE TIME QUANTUM:");
    int q;
    scanf("%d",&q);
    int curr_time = 0;
    while (1)
    {
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(rem_bt[i]==0){
                cnt++;
            }
            else{
                if(curr_time<at[i]){
                    curr_time=at[i];
                }
                if(rem_bt[i]>q){
                    rem_bt[i]-=q;
                    curr_time+=q;
                }
                else{
                    curr_time+=rem_bt[i];
                    rem_bt[i]=0;
                    ct[i]=curr_time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    cnt++;
                }
                printf("| %d | ",p[i]);
            }
        }
        if(cnt==n){
            break;
        }
    }
    printf("\nP_NO   BT      CT      TAT      WT\n");
    for(int i=0;i<n;i++){
       
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],ct[i],tat[i],wt[i]);
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    printf("THE AVERAGE TURN AROUND TIME: %f\n",avg_tat/n);
    printf("THE AVERAGE WAITING TIME: %f",avg_wt/n);
    
}