#include<stdio.h>

int i,j,k,len,n;
float swap_acc,ratio;
float A[20][20],c,x[10];

void print_array(void)
{
    for(i=1;i<=n;i++) //ROW
    {
        for(j=1;j<=n+1;j++) //column
        {
            printf("%f ",A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("\nEnter the size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++) // row
    {
        for(j=1; j<=(n+1); j++) // column
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    /* Now finding the elements of diagonal matrix */
    for(len=1; len<=n;) // index
    {
        if(A[len][len] != 0)
        {
            for(i=1; i<=n; i++) // row
            {
                ratio = A[i][len]/A[len][len];
                for(j=len; j<=(n+1); j++) // column
                {
                    if(i!=len)
                    {
                        A[i][j] = A[i][j] - A[len][j]*ratio;
                    }
                    printf("%f ",A[i][j]);
                }
                printf("\n");
            }
            len++;
        }
        else //swaping - pivot
        {
            for(k=1;A[len][len] == 0;k++)
            {
                if(len+k > 3)
                {
                    len++;
                    break;
                }
                if(A[len+k][len] != 0)
                {
                    for(j=1;j<=(n+1);j++) //column
                    {
                        swap_acc = A[len][j];
                        A[len][j] = A[len+k][j];
                        A[len+k][j] = swap_acc;
                    }
                    printf("SWAP\n");
                    print_array();
                }
            }
        }
        printf("Normal index change\n");
        print_array();
    }
    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);
    }
    return(0);
}
