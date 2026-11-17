
#include <stdio.h>

int main()
{
    int n, f, i, j, k;
    int p[50], frame[10];
    int faults, hits;
    int time[10], count;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // FIFO Algorithm
    faults = hits = 0;
    k = 0;

    printf("\nFIFO:\n");

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == p[i])
                found = 1;
        }

        if(found)
            hits++;
        else
        {
            faults++;
            frame[k] = p[i];
            k = (k + 1) % f;
        }

        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);

        printf("\n");
    }

    printf("FIFO Page Faults = %d\n", faults);
    printf("FIFO Page Hits = %d\n", hits);

    // LRU Algorithm
    faults = hits = count = 0;

    printf("\nLRU:\n");

    for(i = 0; i < f; i++)
    {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        int found = -1;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == p[i])
                found = j;
        }

        if(found != -1)
        {
            hits++;
            time[found] = ++count;
        }
        else
        {
            faults++;
            int pos = 0;

            for(j = 0; j < f; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }

                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = p[i];
            time[pos] = ++count;
        }

        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);

        printf("\n");
    }

    printf("LRU Page Faults = %d\n", faults);
    printf("LRU Page Hits = %d\n", hits);

    return 0;
}
