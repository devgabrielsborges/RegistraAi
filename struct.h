//
// Created by borges on 10/16/24.
//

#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    char login[10];
    char senha[20];
    char nome[20];
    char endereco[40];
    char nascimento[11]; // dd/mm/aaaa, incluindo o terminador nulo
} dado_usuario;


#endif //STRUCT_H
