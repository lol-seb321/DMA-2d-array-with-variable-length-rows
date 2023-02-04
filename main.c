// Dynamically allocating a 2d array with m rows and variable length columns for each row 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** createRand2DArray(int m, int *L){

  // allocating mem for a row of double pointers that can store address of another pointer
  int **temp = (int**)malloc(m*sizeof(int *));
  
  // allocating mem of array of int for each row index (this will be our columns)
  // note this for loop creates our 2D Array
  for(int i = 0; i<m; i++)
    {
       temp[i] = (int*)malloc(L[i]*sizeof(int));
    }
   

  // filling up our 2D array with random numbers
  for(int i = 0; i<m; i++)
    for(int j = 0; j<L[i]; j++) // for each row we fill up with a column of lengthArray(in main)
      temp[i][j] = rand()%100;

  return temp;
  }

// driver function
int main(void) {

  int lengthArray[5] = {3, 2, 4, 5, 2};

  int ** arr = createRand2DArray(5, lengthArray);

// printing our 2D array
  for(int i = 0; i<5; i++)
    {
    for(int j = 0; j<lengthArray[i]; j++)
      printf("%d\t", arr[i][j]);

      printf("\n");
      }

  // free our columns then our rows of DMA
  for(int i = 0; i<5; i++)
    free(arr[i]);
  
  free(arr);
  
  return 0;
}

// Dynamically allocating a 2d array with fixed m rows and n columns

/*
int ** createRand2DArray(int m, int n){

  // allocating mem for a row of double pointers that can store address of another pointer
  int **temp = (int**)malloc(m*sizeof(int *));
  
  // allocating mem of array of int for each row index (this will be our columns)
  // note this for loop creates our 2D Array
  for(int i = 0; i<m; i++)
    temp[i] = (int*)malloc(n*sizeof(int));

  // filling up our 2D array with random numbers
  for(int i = 0; i<m; i++)
    for(int j = 0; i<n; i++)
      temp[i][j] = rand()%100;

  return temp;
  }

// driver function
int main(void) {
  int r, c;
  printf("How many rows and columns?");
  scanf("%d %d", &r, &c);

  int ** arr = createRand2DArray(r, c);

// printing our 2D array
  for(int i = 0; i<r; i++)
    {
    for(int j = 0; i<c; i++)
      printf("%d\t", arr[i][j]);

      printf("\n");
      }

  for(int i = 0; i<r; i++)
    free(arr[i]);
  
  free(arr);
  
  return 0;
}
*/

// Dynamically allocating a 2d array with m rows and variable length columns for each row 