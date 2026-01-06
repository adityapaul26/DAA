#include <stdio.h>

// Function to calculate the maximum profit
float knapsack(int capacity, int n, int weight[], int profit[])
{
    float maxProfit = 0.0;
    double taken[3] = {0.0};
    for (int i = 0; i < n; i++)
    {
        if (weight[i] > capacity)
        {
            maxProfit += (profit[i] * (float)capacity / weight[i]);
            taken[i] = (double)capacity / weight[i];
            break;
        }
        else
        {
            maxProfit += profit[i];
            taken[i] = 1.0;
            capacity -= weight[i];
        }
    }

    printf("the fraction of items taken are:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t", i + 1);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf \t", taken[i]);
    }
    printf("\n");
    return maxProfit;
}

int main()
{
    int n, capacity;

    // Taking user input for the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];
    float ratio[n];

    // Taking user input for profits and weights
    for (int i = 0; i < n; i++)
    {
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%d %d", &profit[i], &weight[i]);
        ratio[i] = (float)profit[i] / weight[i];
    }

    // Taking user input for knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sorting items based on profit/weight ratio in descending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                // Swap ratio
                float temp = ratio[j + 1];
                ratio[j + 1] = ratio[j];
                ratio[j] = temp;

                // Swap profit
                int tempInt = profit[j + 1];
                profit[j + 1] = profit[j];
                profit[j] = tempInt;

                // Swap weight
                tempInt = weight[j + 1];
                weight[j + 1] = weight[j];
                weight[j] = tempInt;
            }
        }
    }

    // Calculate and print the maximum profit
    printf("Maximum Profit: %.2f\n", knapsack(capacity, n, weight, profit));

    return 0;
}
