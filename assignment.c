#include <stdio.h>
#include <stdbool.h>

#define N 4 
int findMin(int cost[N][N], bool rowCovered[N], bool colCovered[N]) {
    int minVal = __INT_MAX__;
   
    for (int i = 0; i < N; i++) {
        if (!rowCovered[i]) {
            for (int j = 0; j < N; j++) {
                if (!colCovered[j] && cost[i][j] < minVal) {
                    minVal = cost[i][j];
                }
            }
        }
    }
   
    return minVal;
}

void branchAndBound(int cost[N][N], bool rowCovered[N], bool colCovered[N], int step, int currentCost, int* minCost) {
    if (step == N) {
        if (currentCost < *minCost) {
            *minCost = currentCost;
        }
        return;
    }
   
    int minVal = findMin(cost, rowCovered, colCovered);
   
    if (currentCost + minVal >= *minCost) {
        return; 
    }
   
    for (int i = 0; i < N; i++) {
        if (!rowCovered[i]) {
            rowCovered[i] = true;
            for (int j = 0; j < N; j++) {
                if (!colCovered[j]) {
                    colCovered[j] = true;
                    branchAndBound(cost, rowCovered, colCovered, step + 1, currentCost + cost[i][j], minCost);
                    colCovered[j] = false; 
                }
            }
            rowCovered[i] = false; 
        }
    }
}

int main() {
    int cost[N][N];

    printf("Enter the cost matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Enter the cost of assigning agent %d to task %d: ", i, j);
            scanf("%d", &cost[i][j]);
        }
    }

    bool rowCovered[N] = {false};
    bool colCovered[N] = {false};
    int minCost = __INT_MAX__;
   
    branchAndBound(cost, rowCovered, colCovered, 0, 0, &minCost);

    printf("Minimum assignment cost: %d\n", minCost);

    return 0;
}


