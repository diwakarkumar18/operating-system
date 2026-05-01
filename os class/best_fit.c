#include <stdio.h>

#define MAX 25

int main()
{
    int frag[MAX], b[MAX], f[MAX];
    int bf[MAX] = {0}, ff[MAX] = {0};
    int i, j, nb, nf, temp;
    int lowest;

    printf("\nMemory Management Scheme - Best Fit\n");

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

    // Best Fit Logic
    for(i = 0; i < nf; i++)
    {
        lowest = 100000;

        for(j = 0; j < nb; j++)
        {
            if(bf[j] == 0)
            {
                temp = b[j] - f[i];

                if(temp >= 0 && temp < lowest)
                {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }

        if(lowest != 100000)
        {
            frag[i] = lowest;
            bf[ff[i]] = 1;
        }
        else
        {
            ff[i] = -1;
            frag[i] = -1;
        }
    }

    // Output
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");

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