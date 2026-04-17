
#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main () {
    Agenda agenda = criar_agenda(10);

    Contato contato;
    strcpy(contato.nome, "João Pé de Melão");
    strcpy(contato.telefone, "(69)1111-1111");
    adicionar_contato(&agenda, contato);

    Contato outro;
    strcpy(contato.nome, "Daniel Bobãolião");
    strcpy(contato.telefone, "(69)6969-6969");
    adicionar_contato(&agenda, contato);

    
    listar_contato(&agenda);
    return 0;
}
