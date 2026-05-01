#include <stdio.h>

#define FRAMES 3
#define PAGES 12

int fr[FRAMES];

void display()
{
    int i;
    printf("\n");
    for(i = 0; i < FRAMES; i++)
    {
        if(fr[i] != -1)
            printf("%d\t", fr[i]);
        else
            printf("-\t");
    }
}

int main()
{
    int page[PAGES] = {2,3,2,1,5,2,4,5,3,2,5,2};
    int i, j, flag, pf = 0, top = 0;

    // Initialize frames
    for(i = 0; i < FRAMES; i++)
    {
        fr[i] = -1;
    }

    printf("FIFO Page Replacement:\n");

    for(j = 0; j < PAGES; j++)
    {
        flag = 0;

        // Check if page already in frame
        for(i = 0; i < FRAMES; i++)
        {
            if(fr[i] == page[j])
            {
                flag = 1;
                break;
            }
        }

        // If page not found → Page Fault
        if(flag == 0)
        {
            fr[top] = page[j];
            top = (top + 1) % FRAMES; // circular queue
            pf++;
        }

        printf("Page %d:", page[j]);
        display();
    }

    printf("\n\nTotal Page Faults = %d\n", pf);

    return 0;
}