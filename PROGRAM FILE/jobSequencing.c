#include <stdio.h>
#define MAX 100
struct Job
{
    int id;
    int profit;
    int deadline;
};
void sortJobs(struct Job jobs[], int n)
{
    int i, j;
    struct Job temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(jobs[j].profit < jobs[j + 1].profit)
            {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}
int findMaxDeadline(struct Job jobs[], int n)
{
    int i, max = jobs[0].deadline;

    for(i = 1; i < n; i++)
    {
        if(jobs[i].deadline > max)
        {
            max = jobs[i].deadline;
        }
    }
    return max;
}
int main()
{
    struct Job jobs[MAX];
    int n, i, j;

    printf("Enter number of jobs: ");
    scanf("%d", &n);
    printf("Enter profits:\n");
    for(i = 0; i < n; i++)
    {
        jobs[i].id = i + 1;
        scanf("%d", &jobs[i].profit);
    }
    printf("Enter deadlines:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &jobs[i].deadline);
    }
    sortJobs(jobs, n);
    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[MAX];
    for(i = 1; i <= maxDeadline; i++)
    {
        slot[i] = -1;
    }
    int totalProfit = 0;
    for(i = 0; i < n; i++)
    {
        for(j = jobs[i].deadline; j >= 1; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("\nSlot Arrangement:\n");
    for(i = 1; i <= maxDeadline; i++)
    {
        if(slot[i] == -1)
            printf("Slot %d : _\n", i);
        else
            printf("Slot %d : J%d\n", i, slot[i]);
    }
    printf("\nMaximum Profit = %d\n", totalProfit);
    return 0;
}