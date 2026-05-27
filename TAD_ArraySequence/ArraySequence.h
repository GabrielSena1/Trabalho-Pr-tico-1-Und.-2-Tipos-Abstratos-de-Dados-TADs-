#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

typedef struct {
    int* arr;
    int capacity;
    int current_size;
} ArraySequence;

void init_arrayseq(ArraySequence* as);
void free_arrayseq(ArraySequence* as);
void pushBack(ArraySequence* as, int value);
void pushFront(ArraySequence* as, int value);
void insert_arrayseq(ArraySequence* as, int pos, int value);
void remove_arrayseq(ArraySequence* as, int pos);
int find_arrayseq(ArraySequence* as, int value);
int size_arrayseq(ArraySequence* as);
void print_arrayseq(ArraySequence* as);

#endif