#include <stdio.h>
int i,j,k,n ,A[10][10],D[10][10];

int min(int a, int b)
{
    if(a<b)
    {
        return a;
    }
    else{
        return b;
    }
}

void calculate()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            D[i][j]=A[i][j];
        }
    }    

        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    D[i][j]=min(D[i][j],(D[i][k]+D[k][j]));
                }
            }
        }

    
    
}

int main()
{
    printf("Enter no of vertices ");
    scanf("%d",&n);
    printf("Enter the weights \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    calculate();

    printf("The shortest path \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",D[i][j]);
           
        }
        printf("\n");
    }
    

    
}

