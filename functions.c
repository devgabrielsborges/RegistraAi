//
// Created by borges on 10/8/24.
//

#include "functions.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void exibirTelaInicial(int nivel_login)
{
    limpaTela();

    switch (nivel_login)
    {
        case 0:
            printf(
               "Nivel de usuario atual: %d\n"
               "[1] iniciar login  [2] inserir cadastro  [3] limpar tela  [4] sair \n\n", nivel_login);
            break;
        case 1:
            printf(
               "Nivel de usuario atual: %d\n"
               "[1] logoff  [2] visualizar dados  [3] editar dados\n\n", nivel_login);
            break;
        case 2:
            printf(
               "Nivel de usuario atual: %d\n"
               "[1] logoff  [2] visualizar todos os dados [3] editar dado especifico [4] inserir cadastro\n\n", nivel_login);
            break;
        default:
            printf("Opcao invalida\n\n");
            system("pause");

    }
}


void inserirCadastro(dado_usuario **linked_dados)
{
    limpaTela();
    dado_usuario *node = malloc(sizeof(dado_usuario));
    // if (node == NULL) return;

    printf("Login (max 9 caracteres):\n");
    scanf(" %9s", node->login);  // Limite de 9 caracteres + terminador

    printf("Senha (max 9 caracteres):\n");
    scanf(" %9s", node->senha);

    printf("Nome (max 19 caracteres):\n");
    scanf(" %19s", node->nome);
    getchar(); // capturando \n que sobrou no buffer

    printf("Endereco (max 49 caracteres):\n");
    fgets(node->endereco, 50, stdin);
    // scanf(" %19s", node->endereco);

    printf("Contato (max 14 caracteres):\n");
    fgets(node->contato, 15, stdin);
    // scanf(" %14s", node->contato);

    printf("Nascimento (max 10 caracteres):\n");
    scanf(" %10s", node->nascimento); // dd/mm/aaaa

    node->next = *linked_dados;
    *linked_dados = node;

}



int fazerLogin(char *login, char *senha, dado_usuario *linked_dados, dado_usuario **usuario)
{
    if (strcmp(login, "admin") == 0 && strcmp(senha, "admin") == 0) return 2;

    dado_usuario *ptr = linked_dados;

    while(ptr != NULL)
    {
        if (strcmp(login, ptr->login) == 0 && strcmp(senha, ptr->senha) == 0)
        {
            *usuario = ptr;
            return 1;
        }
    }
    printf("Login ou senha inválidos\n");
    return 0;
}

void visualizarDados(dado_usuario *usuario) // mostrar dados[indice]
{

    printf("Login | Senha | Nome | Endereco | Contato | Nascimento\n");
    if (usuario != NULL)
    {
        printf("%s | %s | %s | %s | %s | %s |\n",
                  usuario->login, usuario->senha, usuario->nome, usuario->endereco,
                  usuario->contato, usuario->nascimento
                  );
    }
}
int editarDados(dado_usuario *usuario) // dado_usuario dados[indice]. apenas dele mesmo
{
        // Permitir apenas a edição dos campos que não sejam login e senha
        limpaTela();

        printf("Editar Nome:\n");
        scanf("%s", usuario->nome);

        printf("Editar Endereço:\n");
        scanf("%s", usuario->endereco);

        printf("Editar Contato:\n");
        scanf("%s", usuario->contato);

        printf("Editar Nascimento:\n");
        scanf("%s", usuario->nascimento);

        return 0;
    }

void visualizarTD(dado_usuario *linked_dados)
{
    printf("Indice | Login | Senha | Nome | Endereco | Contato | Nascimento\n");
    printf("---------------------------------------------------------------\n");

    int indice = 0;
    dado_usuario *ptr = linked_dados;

    while(ptr != NULL)
    {
        printf("%d | %s | %s | %s | %s | %s | %s |\n",
          indice++,
          ptr->login,
          ptr->senha,
          ptr->nome,
          ptr->endereco,
          ptr->contato,
          ptr->nascimento
    );
        ptr = ptr->next;
    }

    printf("---------------------------------------------------------------\n");
    getchar();  // Pausa para leitura
}


void editarDadoEspecifico(dado_usuario *linked_dados)
{
    int indice;
    printf("Digite o indice do dado a ser alterado:\n");
    scanf("%d", &indice);

    dado_usuario *ptr = linked_dados;
    int i = 0;
    while (ptr != NULL && i < indice) {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL) {
        printf("Indice invalido.\n");
        return;  // Sai da função se o índice for inválido
    }

    // Permite a edição dos campos
    printf("Editar Login (max 9 caracteres):\n");
    scanf("%9s", ptr->login);

    printf("Editar Senha (max 9 caracteres):\n");
    scanf("%9s", ptr->senha);

    printf("Editar Nome (max 19 caracteres):\n");
    scanf("%19s", ptr->nome);

    printf("Editar Endereço (max 19 caracteres):\n");
    scanf("%19s", ptr->endereco);

    printf("Editar Contato (max 14 caracteres):\n");
    scanf("%14s", ptr->contato);

    printf("Editar Nascimento (max 10 caracteres):\n");
    scanf("%10s", ptr->nascimento);

    printf("\nDado alterado com sucesso!\n\n");
}



void limpaTela()
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para (Linux/Mac)
    #endif
}
