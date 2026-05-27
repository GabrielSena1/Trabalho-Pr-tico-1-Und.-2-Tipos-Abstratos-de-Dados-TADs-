#ifndef SEQUENCE_H
#define SEQUENCE_H

typedef struct {
    int* arr;
    int capacity;
    int current_size;
} Sequence;

void init_sequence(Sequence* seq);
void free_sequence(Sequence* seq);
void insert_sequence(Sequence* seq, int pos, int elem);
void remove_sequence(Sequence* seq, int pos);
int get_sequence(Sequence* seq, int pos);
void print_sequence(Sequence* seq);

#endif