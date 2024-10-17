//
// Created by borges on 10/16/24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "struct.h"

void mostrarTelaInicial();
void registrarUsuario(dado_usuario *usuarios, int indice);
void mostrarUsuarios(dado_usuario *usuarios, int indice_atual); // nome, endereco, nascimento
int editarUsuario(dado_usuario *usuarios, int indice_atual);

#endif //FUNCTIONS_H
