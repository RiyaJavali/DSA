#include<stdio.h>
#include<time.h>

void transpose();
//void inverse();
void multiply();

void main()
{
    clock_t start,end;
    double total;
    start=clock();
    transpose();
    //inverse();
    multiply();
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("time: %f",total);
}

void transpose()
{
    int a[10][10],r,c,i,j;
    int trans[10][10];
    printf("TRANSPOSE OF A MATRIX\n");
    printf("enter rows and columns\n");
    scanf("%d%d",&r,&c);

    printf("\nEnter matrix elements:\n");
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j)
    {
    printf("Enter element a%d%d: ",i+1,j+1);
    scanf("%d",&a[i][j]);
  }

    printf("\nEntered matrix: \n");
  for (i = 0; i < r; ++i)
      for (j = 0; j < c; ++j)
    {
        printf("%d  ", a[i][j]);
            if (j == c - 1)
              printf("\n");
  }
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
  {
    trans[j][i] = a[i][j];
  }
  printf("\nTranspose of the matrix:\n");
  for (i = 0; i < c; ++i)
  for (j = 0; j < r; ++j)
  {
    printf("%d  ", trans[i][j]);
    if (j == r - 1)
    printf("\n");
  }
}



void multiply()
{
    int a[10][10],b[10][10],r,c,i,j;
    int rslt[10][10];
    printf("MULTIPLICATION OF MATRICES\n");
    printf("enter rows and columns\n");
    scanf("%d%d",&r,&c);
    printf("\nEnter matrix1 elements:\n");
  for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
    {
    printf("Enter element a%d%d: ",i+1,j+1);
    scanf("%d",&a[i][j]);
  }
  printf("\nEnter matrix2 elements:\n");
  for (int i = 0; i < r; ++i)
  for (int j = 0; j < c; ++j)
    {
    printf("Enter element a%d%d: ",i+1,j+1);
    scanf("%d",&b[i][j]);
  }
  for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            rslt[i][j] = 0;

            for (int k = 0; k < r; k++)
            {
                rslt[i][j] += a[i][k] * b[k][j];
            }

            printf("%d\t", rslt[i][j]);
        }

        printf("\n");
    }
}
