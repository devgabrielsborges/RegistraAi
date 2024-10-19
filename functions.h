//
// Created by borges on 10/8/24.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "struct.h"
extern void exibirTelaInicial(int nivel_login);
extern void inserirCadastro(dado_usuario **linked_dados);
extern int fazerLogin(char *login, char *senha, dado_usuario *linked_dados, dado_usuario **usuario);
extern void visualizarDados(dado_usuario *usuario);
extern int editarDados(dado_usuario *usuario);
extern void visualizarTD(dado_usuario *linked_dados);
extern void editarDadoEspecifico(dado_usuario *linked_dados);
extern void limpaTela(void);


#endif //FUNCTIONS_H
