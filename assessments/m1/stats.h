/******************************************************************************
 * Copyright (C) 2023 by Stanley Mwangi

 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file Stat.h
 * @brief Calculate the static of the data
 *
 * @author Stanley Mwangi
 * @date 26/08/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_statistic(int[]);
int cmpfunc (const void * , const void * );
void print_median(int *);
void print_maximum(int *);
void print_minimum(int *);

#endif /* __STATS_H__ */
