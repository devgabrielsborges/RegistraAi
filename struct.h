//
// Created by borges on 10/8/24.
//

#ifndef STRUCT_H
#define STRUCT_H

// struct dado_usuario;

typedef struct {
    char login[10];  //strcmp("borges", "borges") -> 1
    char senha[20];
    char nome[20];
    char endereco[50];
    char contato[15];
    char nascimento[11];  // dd/mm/aaaa
} dado_usuario;


#endif //STRUCT_H
