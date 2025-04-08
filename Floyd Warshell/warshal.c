#include <stdio.h>
int i,j,k,n ,A[10][10],D[10][10];



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
                    if(D[i][k]==1 && D[k][j]==1)
                    {
                        D[i][j]=1;
                    }
                    
                }
            }
        }

    
    
}

int main()
{
    printf("Enter no of vertices ");
    scanf("%d",&n);
    printf("Enter the edjecncy \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    calculate();

    printf("The path \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",D[i][j]);
           
        }
        printf("\n");
    }
    

    
}
0  1  1  0
0  0  1  1
0  0  0  1
1  0  0  0

