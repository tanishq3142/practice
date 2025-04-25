// #include<stdio.h>
// int main(){
//     int n;
//     printf("ENTER THE NUMBER OF PROCESS:");
//     scanf("%d",&n);
//     int at[n],p[n],bt[n],rem_bt[n],ct[n],tat[n],wt[n];
//     float avg_tat=0,avg_wt=0;
//     printf("ENTER THE ARRIVAL TIME OF EACH PROCESS :");
//     for(int i=0;i<n;i++){
//         scanf("%d",&at[i]);
//         p[i]=i+1;
//     }
//     printf("ENTER THE BURST TIME OF EACH PROCESS :");
//     for(int i=0;i<n;i++){
//         scanf("%d",&bt[i]);
//         rem_bt[i]=bt[i];
//     }
//     printf("ENTER THE TIME QUANTUM:");
//     int q;
//     scanf("%d",&q);
//     int curr_time = 0;
//     while (1)
//     {
//         int cnt = 0;
//         for(int i=0;i<n;i++){
//             if(rem_bt[i]==0){
//                 cnt++;
//             }
//             else{
//                 if(curr_time<at[i]){
//                     curr_time=at[i];
//                 }
//                 if(rem_bt[i]>q){
//                     rem_bt[i]-=q;
//                     curr_time+=q;
//                 }
//                 else{
//                     curr_time+=rem_bt[i];
//                     rem_bt[i]=0;
//                     ct[i]=curr_time;
//                     tat[i]=ct[i]-at[i];
//                     wt[i]=tat[i]-bt[i];
//                     cnt++;
//                 }
//                 printf("| %d | ",p[i]);
//             }
//         }
//         if(cnt==n){
//             break;
//         }
//     }
//     printf("\nP_NO   BT      CT      TAT      WT\n");
//     for(int i=0;i<n;i++){
       
//         printf("%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],ct[i],tat[i],wt[i]);
//         avg_tat+=tat[i];
//         avg_wt+=wt[i];
//     }
//     printf("THE AVERAGE TURN AROUND TIME: %f\n",avg_tat/n);
//     printf("THE AVERAGE WAITING TIME: %f",avg_wt/n);
    
// }
#include<stdio.h>
#define MAX 100

int main() {
    int n, q;
    printf("ENTER THE NUMBER OF PROCESS: ");
    scanf("%d", &n);
    
    int at[MAX], bt[MAX], rem_bt[MAX], ct[MAX], tat[MAX], wt[MAX], p[MAX];
    float avg_tat = 0, avg_wt = 0;
    
    printf("ENTER THE ARRIVAL TIME OF EACH PROCESS:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
        p[i] = i + 1;
    }

    printf("ENTER THE BURST TIME OF EACH PROCESS:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("ENTER THE TIME QUANTUM: ");
    scanf("%d", &q);

    int time = 0, done = 0;
    int queue[MAX], front = 0, rear = 0, visited[MAX] = {0};
    for (int i = 0; i < n; i++) {
        if (at[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (done < n) {
        if (front == rear) time++;

        int idx = queue[front++];
        
        if (rem_bt[idx] > q) {
            printf("| P%d ", p[idx]);
            rem_bt[idx] -= q;
            time += q;
        } else {
            printf("| P%d ", p[idx]);
            time += rem_bt[idx];
            rem_bt[idx] = 0;
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done++;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i] && at[i] <= time) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (rem_bt[idx] > 0) {
            queue[rear++] = idx;
        }

        // If queue becomes empty, move time to next arrival
        if (front == rear) {
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    time = at[i];
                    queue[rear++] = i;
                    visited[i] = 1;
                    break;
                }
            }
        }
    }

    printf("|\n\nP_NO   BT      CT      TAT      WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("THE AVERAGE TURN AROUND TIME: %.2f\n", avg_tat / n);
    printf("THE AVERAGE WAITING TIME: %.2f\n", avg_wt / n);

    return 0;
}
