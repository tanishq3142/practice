#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n;
    printf("ENTER THE NUMBER OF PROCESS ");
    scanf("%d", &n);
    int r;
    printf("ENTER THE NUMBER OF RESOURCES ");
    scanf("%d", &r);
    int avail[r], maxR[n][r], alloc[n][r], need[n][r], safeSeq[n],vis[n];
    printf("ENTER AVAILABLE RESOURCES:");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &avail[i]);
    }
    printf("MAXIMUM RESOURCE ALLOCATION MATRIX:\n");
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &maxR[i][j]);
        }
    }
    printf("RESOURCE ALLOCATION MATRIX:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
            need[i][j] = maxR[i][j] - alloc[i][j];
        }
    }
    int k = 0;
    while (true)
    {
        bool done = false;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                bool t = true;
                for (int j = 0; j < r; j++)
                {
                    t &= (need[i][j] <= avail[j]);
                }
                if (t)
                {
                    for (int j = 0; j < r; j++)
                    {
                        avail[j] += alloc[i][j];
                    }
                    done = true;
                    safeSeq[k++] = i + 1;
                    vis[i]=1;
                }
            }
        }
        if (!done || k == n)
            break;
    }
    // for(int i=0;i<r;i++){
    //     printf("%d ",avail[i]);
    // }
    // printf("\n");
    if(k<n){
        printf("DEADLOCK");
    }
    else{
        printf("SAFE SEQUENCE: ");
        for(int i=0;i<n;i++){
            printf("%d ",safeSeq[i]);
        }
    }
}