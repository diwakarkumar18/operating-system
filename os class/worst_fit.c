#include <stdio.h>

#define MAX 25

int main()
{
    int b[MAX], f[MAX];      // block sizes, file sizes
    int bf[MAX] = {0};       // block filled (0 = free, 1 = used)
    int ff[MAX] = {0};       // file -> block mapping
    int frag[MAX];           // fragmentation

    int nb, nf, i, j;
    int worstIdx, maxFrag;

    printf("\n\tMemory Management Scheme - Worst Fit\n");

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter number of files: ");
    scanf("%d", &nf);

    // Input block sizes
    printf("\nEnter sizes of blocks:\n");
    for(i = 0; i < nb; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    // Input file sizes
    printf("\nEnter sizes of files:\n");
    for(i = 0; i < nf; i++)
    {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    // Worst Fit Logic
    for(i = 0; i < nf; i++)
    {
        worstIdx = -1;
        maxFrag = -1;

        for(j = 0; j < nb; j++)
        {
            if(bf[j] == 0 && b[j] >= f[i])
            {
                int temp = b[j] - f[i];

                if(temp > maxFrag)
                {
                    worstIdx = j;
                    maxFrag = temp;
                }
            }
        }

        if(worstIdx != -1)
        {
            ff[i] = worstIdx;
            frag[i] = maxFrag;
            bf[worstIdx] = 1;
        }
        else
        {
            ff[i] = -1;
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