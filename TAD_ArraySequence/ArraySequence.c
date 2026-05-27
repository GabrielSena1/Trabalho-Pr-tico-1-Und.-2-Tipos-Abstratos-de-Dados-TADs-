#include "ArraySequence.h"
#include <stdio.h>
#include <stdlib.h>

void init_arrayseq(ArraySequence* as) {
    as->capacity = 2;
    as->current_size = 0;
    as->arr = (int*)malloc(as->capacity * sizeof(int));
}

void free_arrayseq(ArraySequence* as) {
    free(as->arr);
    as->capacity = 0;
    as->current_size = 0;
}

void resize_arrayseq(ArraySequence* as) {
    as->capacity *= 2;
    as->arr = (int*)realloc(as->arr, as->capacity * sizeof(int));
}

void pushBack(ArraySequence* as, int value) {
    if (as->current_size == as->capacity) resize_arrayseq(as);
    as->arr[as->current_size++] = value;
}

void insert_arrayseq(ArraySequence* as, int pos, int value) {
    if (pos < 0 || pos > as->current_size) {
        printf("Posicao invalida!\n");
        return;
    }
    if (as->current_size == as->capacity) resize_arrayseq(as);
    
    for (int i = as->current_size; i > pos; i--) {
        as->arr[i] = as->arr[i - 1];
    }
    as->arr[pos] = value;
    as->current_size++;
}

void pushFront(ArraySequence* as, int value) {
    insert_arrayseq(as, 0, value);
}

void remove_arrayseq(ArraySequence* as, int pos) {
    if (pos < 0 || pos >= as->current_size) {
        printf("Posicao invalida!\n");
        return;
    }
    for (int i = pos; i < as->current_size - 1; i++) {
        as->arr[i] = as->arr[i + 1];
    }
    as->current_size--;
}

int find_arrayseq(ArraySequence* as, int value) {
    for (int i = 0; i < as->current_size; i++) {
        if (as->arr[i] == value) return i;
    }
    return -1; 
}

int size_arrayseq(ArraySequence* as) {
    return as->current_size;
}

void print_arrayseq(ArraySequence* as) {
    printf("[ ");
    for (int i = 0; i < as->current_size; i++) {
        printf("%d ", as->arr[i]);
    }
    printf("]\n");
}