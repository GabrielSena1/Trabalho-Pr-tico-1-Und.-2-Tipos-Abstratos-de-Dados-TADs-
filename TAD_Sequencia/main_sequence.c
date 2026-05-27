#include <stdio.h>
#include "Sequence.h"

int main() {
    Sequence seq;
    init_sequence(&seq);
    
    printf("--- Teste TAD Sequencia ---\n");
    
    for (int i = 0; i < 10; i++) {
        insert_sequence(&seq, i, (i + 1) * 10);
    }
    
    printf("Sequencia apos inserir 10 elementos:\n");
    print_sequence(&seq);
    
    remove_sequence(&seq, 5); 
    remove_sequence(&seq, 4); 
    
    printf("Sequencia apos remover 2 elementos do meio:\n");
    print_sequence(&seq);
    
    free_sequence(&seq); 
    return 0;
}