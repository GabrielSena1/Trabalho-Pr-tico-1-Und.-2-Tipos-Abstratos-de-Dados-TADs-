#include "Set.h"
#include <stdio.h>
#include <stdlib.h>

void init_set(Set* s) {
    s->capacity = 5;
    s->current_size = 0;
    s->arr = (int*)malloc(s->capacity * sizeof(int));
}

void free_set(Set* s) {
    free(s->arr);
    s->capacity = 0;
    s->current_size = 0;
}

void resize_set(Set* s) {
    s->capacity *= 2;
    s->arr = (int*)realloc(s->arr, s->capacity * sizeof(int));
}

int contains_set(Set* s, int elem) {
    for (int i = 0; i < s->current_size; i++) {
        if (s->arr[i] == elem) return 1; 
    }
    return 0; 
}

void add_set(Set* s, int elem) {
    if (contains_set(s, elem)) return; 
    if (s->current_size == s->capacity) resize_set(s);
    s->arr[s->current_size++] = elem;
}

void remove_set(Set* s, int elem) {
    for (int i = 0; i < s->current_size; i++) {
        if (s->arr[i] == elem) {
            s->arr[i] = s->arr[s->current_size - 1]; 
            s->current_size--;
            return;
        }
    }
}

Set* union_set(Set* A, Set* B) {
    Set* result = (Set*)malloc(sizeof(Set));
    init_set(result);
    for (int i = 0; i < A->current_size; i++) add_set(result, A->arr[i]);
    for (int i = 0; i < B->current_size; i++) add_set(result, B->arr[i]);
    return result;
}

Set* intersection_set(Set* A, Set* B) {
    Set* result = (Set*)malloc(sizeof(Set));
    init_set(result);
    for (int i = 0; i < A->current_size; i++) {
        if (contains_set(B, A->arr[i])) {
            add_set(result, A->arr[i]);
        }
    }
    return result;
}

void print_set(Set* s) {
    printf("{ ");
    for (int i = 0; i < s->current_size; i++) {
        printf("%d%s", s->arr[i], (i < s->current_size - 1) ? ", " : " ");
    }
    printf("}\n");
}