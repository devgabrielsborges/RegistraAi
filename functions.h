//
// Created by borges on 10/8/24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "struct.h"
extern void exibirTelaInicial(int nivel_login);
extern void inserirCadastro(dado_usuario dados[10], int *indice);
extern int fazerLogin(char *login, char *senha,dado_usuario dados[10], int *indice_atual);
extern void visualizarDados(dado_usuario dados[10], int indice);
extern int editarDados(dado_usuario dados[10], int indice);
extern void visualizarTD(dado_usuario dados[10], int ultimo_indice);
extern void editarDadoEspecifico(dado_usuario *dados);
extern void limpaTela(void);


#endif //FUNCTIONS_H
