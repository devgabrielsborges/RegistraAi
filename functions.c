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


void inserirCadastro(dado_usuario *dados, int *indice)
{
    limpaTela();

    printf("Login (max 9 caracteres):\n");
    scanf(" %9s", dados[*indice].login);  // Limite de 9 caracteres + terminador

    printf("Senha (max 9 caracteres):\n");
    scanf(" %9s", dados[*indice].senha);

    printf("Nome (max 19 caracteres):\n");
    scanf(" %19s", dados[*indice].nome);

    printf("Endereco (max 19 caracteres):\n");
    scanf(" %19s", dados[*indice].endereco);

    printf("Contato (max 14 caracteres):\n");
    scanf(" %14s", dados[*indice].contato);

    printf("Nascimento (max 10 caracteres):\n");
    scanf(" %10s", dados[*indice].nascimento); // dd/mm/aaaa

    *indice += 1;
}



int fazerLogin(char *login, char *senha, dado_usuario dados[10],int *indice_atual)
{
    if (strcmp(login, "admin") == 0 && strcmp(senha, "admin") == 0) return 2;

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(login, dados[i].login) == 0 && strcmp(senha, dados[i].senha) == 0)
        {
            *indice_atual = i;
            return 1;
        }
    }
    printf("Login ou senha invalidos\n");
    return 0; // login ou senha invalidos
}

void visualizarDados(dado_usuario dados[10], int indice) // mostrar dados[indice]
{
    printf("Login | Senha | Nome | Endereco | Contato | Nascimento\n");
    printf("%s | %s | %s | %s | %s | %s |\n",
          dados[indice].login, dados[indice].senha, dados[indice].nome, dados[indice].endereco,
          dados[indice].contato, dados[indice].nascimento
          );
    getchar();
}
int editarDados(dado_usuario dados[10], int indice) // dado_usuario dados[indice]. apenas dele mesmo
{
        // Permitir apenas a edição dos campos que não sejam login e senha
        limpaTela();

        printf("Editar Nome:\n");
        scanf("%s", dados[indice].nome);

        printf("Editar Endereço:\n");
        scanf("%s", dados[indice].endereco);

        printf("Editar Contato:\n");
        scanf("%s", dados[indice].contato);

        printf("Editar Nascimento:\n");
        scanf("%s", dados[indice].nascimento);

        return 0;
    }

void visualizarTD(dado_usuario dados[10], int ultimo_indice)
{
    printf("Indice | Login | Senha | Nome | Endereco | Contato | Nascimento\n");
    printf("---------------------------------------------------------------\n");

    for (int indice = 0; indice < ultimo_indice; indice++)
    {
        // Exibir apenas os dados inseridos
        printf("%d | %s | %s | %s | %s | %s | %s |\n",
              indice,
              dados[indice].login,
              dados[indice].senha,
              dados[indice].nome,
              dados[indice].endereco,
              dados[indice].contato,
              dados[indice].nascimento
        );
    }

    printf("---------------------------------------------------------------\n");
    getchar();  // Pausa para leitura
}


void editarDadoEspecifico(dado_usuario *dados)
{
    int indice;
    printf("Digite o indice do dado a ser alterado:\n");
    scanf("%d", &indice);

    // Verifica se o índice está dentro do limite
    if (indice >= 0 && indice < 10)
    {
        printf("Editar Login (max 9 caracteres):\n");
        char temp_login[10];
        scanf("%9s", temp_login);
        strncpy(dados[indice].login, temp_login, 9);
        dados[indice].login[9] = '\0'; // Garante que a string tenha um terminador nulo

        printf("Editar Senha (max 9 caracteres):\n");
        char temp_senha[10];
        scanf("%9s", temp_senha);
        strncpy(dados[indice].senha, temp_senha, 9);
        dados[indice].senha[9] = '\0';

        printf("Editar Nome (max 19 caracteres):\n");
        char temp_nome[20];
        scanf("%19s", temp_nome);
        strncpy(dados[indice].nome, temp_nome, 19);
        dados[indice].nome[19] = '\0';

        printf("Editar Endereço (max 19 caracteres):\n");
        char temp_endereco[20];
        scanf("%19s", temp_endereco);
        strncpy(dados[indice].endereco, temp_endereco, 19);
        dados[indice].endereco[19] = '\0';

        printf("Editar Contato (max 14 caracteres):\n");
        char temp_contato[15];
        scanf("%14s", temp_contato);
        strncpy(dados[indice].contato, temp_contato, 14);
        dados[indice].contato[14] = '\0';

        printf("Editar Nascimento (max 9 caracteres):\n");
        char temp_nascimento[10];
        scanf("%9s", temp_nascimento);
        strncpy(dados[indice].nascimento, temp_nascimento, 9);
        dados[indice].nascimento[9] = '\0';

        printf("\nDado alterado com sucesso!\n\n");
    }
    else
    {
        printf("Indice inválido!\n");
    }

    // Pausar a execução para que o usuário veja a mensagem
    printf("Pressione Enter para continuar...");
    getchar(); // Consumir o caractere de nova linha remanescente no buffer
    getchar(); // Esperar pelo Enter do usuário
}


void limpaTela()
{
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para (Linux/Mac)
    #endif
}
