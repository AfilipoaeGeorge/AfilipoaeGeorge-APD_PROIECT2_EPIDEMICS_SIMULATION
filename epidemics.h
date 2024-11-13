#ifndef EPIDEMICS_H
#define EPIDEMICS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <fcntl.h>
#include<omp.h>

#define INFECTED_DURATION 2
#define IMMUNE_DURATION 5

//statusul
#define INFECTED 0
#define SUSCEPTIBLE 1
#define IMMUNE 2

typedef struct Person{
    int id;  // id-ul persoanei
    int x, y, future_x, future_y; //coordonatele (x,y) curente si viitoare
    int current_status; // 0 = infectat, 1 = susceptibil
    int future_status; 
    int direction; //(N=0, S=1, E=2, W=3)
    int amplitude;  //amplitudinea de miscare
    int infection_count;  //numarul de infectari
    int infected_time;  //timpul de infectare
    int immune_time;  //timpul de imunitate
} Person; //definim o structura de date de tipul Person care contine toate campurile necesare

void read_input_file(const char *filename);
void write_output_file(const char *filename);
void update_coordinates_and_status(int start,int end);
void check_interactions_and_update_future_statuses_for_new_infections(int start, int end);
void calculate_the_future_coordinates_and_check_interactions_and_update_future_statuses_for_new_infections(int start, int end);
void serial_simulate();
void parallel_simulate_static_1();
void parallel_simulate_static_20();
void parallel_simulate_dynamic_1();
void parallel_simulate_dynamic_20();
void parallel_simulate_dataP();
void print_vector();
void check_or_create_file(char *filePath);
void print_same_result(Person* people);
void print_speedup_in_output_file();
void print_diff_time(double serial_time, double parallel_time);
void free_memory();

extern int TOTAL_SIMULATION_TIME;//numarul de repetari/iteratii
extern int MAX_X_COORD, MAX_Y_COORD; //maximul coordonatelor
extern int N; // numarul de persoane
extern int THREAD_NUMBER;//numarul de thread-uri pe care le folosim la simularea paralela
extern Person *people; //vectorul de persoane pe care o sa il alocam dinamic in functia de citire a datelor din fisier
extern Person *people_parallel; //vector in care memoram starea si toate informatiile initiale ale persoanelor pentru a putea apela simularea paralela dupa cea seriala
extern Person* people_serial;
extern Person *peopleStatic1, *peopleStatic20, *peopleDynamic1, *peopleDynamic20;
extern pthread_barrier_t b1_barrier, b2_barrier, b3_barrier; //bariere pentru a sincroniza operatiile in simularea paralela

#endif
