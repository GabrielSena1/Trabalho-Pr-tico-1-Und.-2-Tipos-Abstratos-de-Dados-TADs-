#include "Sequence.h"
#include <stdio.h>
#include <stdlib.h>

void init_sequence(Sequence* seq) {
    seq->capacity = 5;
    seq->current_size = 0;
    seq->arr = (int*)malloc(seq->capacity * sizeof(int));
}

void free_sequence(Sequence* seq) {
    free(seq->arr);
    seq->capacity = 0;
    seq->current_size = 0;
}

void resize_sequence(Sequence* seq) {
    seq->capacity *= 2;
    seq->arr = (int*)realloc(seq->arr, seq->capacity * sizeof(int));
}

void insert_sequence(Sequence* seq, int pos, int elem) {
    if (pos < 0 || pos > seq->current_size) {
        printf("Posicao invalida!\n");
        return;
    }
    if (seq->current_size == seq->capacity) {
        resize_sequence(seq);
    }
    for (int i = seq->current_size; i > pos; i--) {
        seq->arr[i] = seq->arr[i - 1];
    }
    seq->arr[pos] = elem;
    seq->current_size++;
}

void remove_sequence(Sequence* seq, int pos) {
    if (pos < 0 || pos >= seq->current_size) {
        printf("Posicao invalida!\n");
        return;
    }
    for (int i = pos; i < seq->current_size - 1; i++) {
        seq->arr[i] = seq->arr[i + 1];
    }
    seq->current_size--;
}

int get_sequence(Sequence* seq, int pos) {
    if (pos < 0 || pos >= seq->current_size) {
        printf("Posicao invalida!\n");
        exit(EXIT_FAILURE); 
    }
    return seq->arr[pos];
}

void print_sequence(Sequence* seq) {
    printf("[ ");
    for (int i = 0; i < seq->current_size; i++) {
        printf("%d ", seq->arr[i]);
    }
    printf("]\n");
}