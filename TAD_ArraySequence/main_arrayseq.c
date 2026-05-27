#include <stdio.h>
#include "ArraySequence.h"

int main() {
    ArraySequence as;
    init_arrayseq(&as);
    
    // Inserir os valores: [10, 20, 30, 40]
    pushBack(&as, 10);
    pushBack(&as, 20);
    pushBack(&as, 30);
    pushBack(&as, 40);
    printf("Estado inicial: "); print_arrayseq(&as);
    
    // Inserir um elemento no inicio
    pushFront(&as, 5);
    printf("Apos inserir 5 no inicio: "); print_arrayseq(&as);
    
    // Inserir um elemento no meio
    insert_arrayseq(&as, 2, 15);
    printf("Apos inserir 15 na posicao 2: "); print_arrayseq(&as);
    
    // Remover um elemento
    remove_arrayseq(&as, 3); 
    
    // Exibir a estrutura final
    printf("Estrutura final: "); print_arrayseq(&as);
    
    free_arrayseq(&as);
    return 0;
}