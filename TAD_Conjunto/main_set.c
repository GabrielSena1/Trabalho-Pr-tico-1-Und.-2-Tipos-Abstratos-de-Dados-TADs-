#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

int main() {
    Set A, B;
    init_set(&A);
    init_set(&B);
    
    add_set(&A, 1); add_set(&A, 2); add_set(&A, 3); add_set(&A, 5);
    add_set(&B, 3); add_set(&B, 4); add_set(&B, 5); add_set(&B, 6);
    
    printf("Conjunto A: "); print_set(&A);
    printf("Conjunto B: "); print_set(&B);
    
    Set* uniao = union_set(&A, &B);
    printf("Uniao: "); print_set(uniao);
    
    Set* intersecao = intersection_set(&A, &B);
    printf("Intersecao: "); print_set(intersecao);
    
    free_set(&A);
    free_set(&B);
    free_set(uniao); free(uniao);
    free_set(intersecao); free(intersecao);
    
    return 0;
}