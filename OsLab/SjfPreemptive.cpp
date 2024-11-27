#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, time = 0, smallest, remain;
    float totaltat = 0, totalwt = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], p[n];
    
    // Input process details
    for(i = 0; i < n; i++) {
        printf("Enter burst & arrival time for process[%d]: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
        rt[i] = bt[i];
        p[i] = i;
    }
    
    remain = n;
    
    while(remain != 0) {
        smallest = -1;
        int min_bt = INT_MAX;
        
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min_bt) {
                min_bt = rt[i];
                smallest = i;
            }
        }
        
        if(smallest == -1) {
            time++;
            continue;
        }
        
        rt[smallest]--;
        time++;
        
        if(rt[smallest] == 0) {
            remain--;
            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            totaltat += tat[smallest];
            totalwt += wt[smallest];
        }
    }
    
    // Display results
    for(i = 0; i < n; i++) {
        printf("\n%d %d %d %d %d %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\n%d", totaltat/n);
    printf("\n%d", totalwt/n);
    
    return 0;
}
