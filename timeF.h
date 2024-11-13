#ifndef TIME_F_H
#define TIME_F_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void start(struct timespec* start_time);
void end(struct timespec* end_time);
double calculate_time(struct timespec start_time,struct timespec end_time);
double calculate_speedup(double serial_time,double parallel_time);
double calculate_diff(double serial_time,double parallel_time);

#endif
