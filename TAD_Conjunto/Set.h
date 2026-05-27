#ifndef SET_H
#define SET_H

typedef struct {
    int* arr;
    int capacity;
    int current_size;
} Set;

void init_set(Set* s);
void free_set(Set* s);
void add_set(Set* s, int elem);
void remove_set(Set* s, int elem);
int contains_set(Set* s, int elem);
Set* union_set(Set* A, Set* B);
Set* intersection_set(Set* A, Set* B);
void print_set(Set* s);

#endif