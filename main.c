#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "struct.h"

int main(void)
{
    struct dado_usuario *linked_dados = NULL;
    dado_usuario *usuario = NULL;

    int condicao, nivel_login = 0;
    char *login = malloc(10*sizeof(char)), *senha = malloc(10*sizeof(char));

    printf("Bem-vindo ao RegistraAi\n\n");
    while (1)
    {
        while (nivel_login == 0)
        {
            exibirTelaInicial(nivel_login);
            scanf("%d", &condicao);

            switch (condicao)
            {
                case 1: // Tentativa de login
                    printf("Login: \n");
                    scanf("%s", login);

                    printf("Senha: \n");
                    scanf("%s", senha);

                    nivel_login = fazerLogin(login, senha, linked_dados, &usuario); // Aqui fazemos o login uma única vez

                    break;
                case 2: // Inserir cadastro
                    inserirCadastro(&linked_dados);
                    break;
                case 3: // Limpar tela
                    limpaTela();
                    break;
                case 4: // Sair
                    free(login);
                    free(senha);
                    return 0;
                default:
                    printf("Opcao invalida\n");
                    break;
            }
        }

        while (nivel_login != 0) // Usuário logado, realizar ações
        {
            printf("Voce esta logado\n\n");
            exibirTelaInicial(nivel_login); // Mostra as opções dependendo do nível de login
            scanf("%d", &condicao);

            switch (nivel_login)
            {
                case 1: // Usuário comum
                    switch (condicao) {
                        case 1: // Logoff
                            nivel_login = 0; // Sai do login e volta ao estado de não logado
                            break;
                        case 2: // Visualizar dados
                            visualizarDados(usuario); // Exibe dados do próprio usuário
                            getchar(); // Pausa
                            break;
                        case 3: // Editar dados
                            editarDados(usuario); // Permite o usuário editar seus próprios dados
                            break;
                        default:
                            printf("Opcao invalida\n");
                            break;
                    }
                    break;

                case 2: // Administrador
                    switch (condicao)
                    {
                        case 1: // Logoff
                            nivel_login = 0; // Sai do login e volta ao estado de não logado
                            break;
                        case 2: // Visualizar todos os dados
                            visualizarTD(linked_dados); // Exibe todos os dados de usuários
                            getchar(); // Pausa
                            break;
                        case 3: // Editar dado específico
                            editarDadoEspecifico(linked_dados); // Permite editar os dados de um usuário específico
                            break;
                        case 4: // Inserir novo cadastro
                            inserirCadastro(&linked_dados);
                            break;
                        default:
                            printf("Opcao invalida\n");
                            break;
                    }
                break;
                default:
                    return 4;
            }
        }
    }
}