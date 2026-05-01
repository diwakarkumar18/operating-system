#include <stdio.h>

#define MAX 25

int main()
{
    int frag[MAX], b[MAX], f[MAX];
    int bf[MAX] = {0}, ff[MAX] = {0};
    int i, j, nb, nf, temp, highest;

    printf("\n\tMemory Management Scheme - Worst Fit\n");

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input block sizes
    printf("\nEnter the size of the blocks:\n");
    for(i = 0; i < nb; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    // Input file sizes
    printf("\nEnter the size of the files:\n");
    for(i = 0; i < nf; i++)
    {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    // Worst Fit Logic
    for(i = 0; i < nf; i++)
    {
        highest = -1;
        ff[i] = -1;

        for(j = 0; j < nb; j++)
        {
            if(bf[j] == 0)  // block is free
            {
                temp = b[j] - f[i];

                if(temp >= 0 && temp > highest)
                {
                    highest = temp;
                    ff[i] = j;
                }
            }
        }

        if(ff[i] != -1)
        {
            frag[i] = highest;
            bf[ff[i]] = 1;
        }
        else
        {
            frag[i] = -1;
        }
    }

    // Output
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");

    for(i = 0; i < nf; i++)
    {
        if(ff[i] != -1)
        {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        }
        else
        {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
        }
    }

    return 0;
}