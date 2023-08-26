/******************************************************************************
 * Copyright (C) 2023 by Stanley Mwangi
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stat.c
 * @brief Calculate the static of the data
 *
 * @author Stanley Mwangi
 * @date 26/08/2023
 *
 */

#include <stdio.h>
#include <math.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

void main() {

  int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // qsort(test, SIZE, sizeof(int), cmpfunc);
  print_median(test);
  print_statistic(test); 
  print_maximum(test);
  print_minimum(test);
}

void print_statistic(int * data){
  for (int i = 0; i < SIZE -1; i++) {
    printf("first to the last number %d \n", data[i]);
  }
}

void print_median(int * data){

  printf("median is %d \n", data[SIZE/2]);
}

void print_maximum(int * data){

  int max = data[0];
  for (int i = 0; i < SIZE;i++){
    if (data[i] > max) max = data[i];
  }

  printf("max is %d \n", max);
}

void print_minimum(int * data){

  int min = data[0];
  for (int i = 0; i < SIZE;i++){
    if (data[i] < min) min = data[i];
  }

  printf("min is %d \n", min);
}

int cmpfunc (const void * a, const void * b){

  return (*(int*)a - *(int*)b);
}

