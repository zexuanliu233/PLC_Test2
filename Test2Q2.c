#include <stdio.h>
#include<time.h>

int main(void) {
  //define the array, with a size of 1000*1000
  int two[500][500];
  int i, j;
  int a;
  for(i = 0; i<500; i++){
    for(j = 0; j<500; j++){
      two[i][j] = i;
    }
  }
  //define time clock, start and finish
  clock_t start, finish;
  int *point = &two[1][0];
  int *pointer = &two[0][0];
  printf("jjjj");
  printf("%d",*(pointer - 1));

  //only using subscripting
  double  duration1;
  start = clock(); 
  for(j=0; j<500 ; j++){
    for(i=0; i<500; i++){
      //just accessing, no action
      two[i][j];
    }
  } 
  finish = clock(); 
  duration1 = (double)(finish - start)/ CLOCKS_PER_SEC;
  
  //only using pointer
  double  duration2;
  start = clock(); 
  for(j=0; j<500 ; j++){
    for(i=0; i<500; i++){
      //just accessing, no action
      *(*(two+i)+j);
    }
  }  
  finish = clock(); 
  duration2 = (double)(finish - start)/ CLOCKS_PER_SEC;

  printf("\nTime to access array through subscript is %f", duration1);
  printf("\nTime to access array through pointer is %f", duration2);

    
  return 0;
}

