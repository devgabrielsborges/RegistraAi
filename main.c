#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "struct.h"

int main(void)
{
    int ultimo_indice = 0, indice_atual = 0, sair = 0;
    dado_usuario dados[10];

    int condicao, nivel_login = 0;
    char *login = malloc(10*sizeof(char)), *senha = malloc(10*sizeof(char));

    printf("Bem-vindo ao RegistraAi\n\n");
    do
    {
        while (nivel_login == 0) {
            exibirTelaInicial(nivel_login);
            scanf("%d", &condicao);

            switch (condicao) {
            case 1:
                printf("Login: \n");
                scanf("%s", login);

                printf("Senha: \n");
                scanf("%s", senha);

                nivel_login = fazerLogin(login, senha, dados, &indice_atual);
                break;
            case 2:
                inserirCadastro(dados, &ultimo_indice);
                indice_atual = ultimo_indice;
                break;
            case 3:
                limpaTela();
                break;
            case 4:
                free(login);
                free(senha);

                return 0;
            default:
                return 1;
            }
        }

        while(nivel_login != 0)
        {
            printf("Voce esta logado\n\n");
            nivel_login = fazerLogin(login, senha, dados, &indice_atual);
            exibirTelaInicial(nivel_login);
            scanf("%d", &condicao);



            switch (nivel_login)
            {
            case 1:
                switch (condicao)
                {
                    case 1:
                        nivel_login = 0;
                        break;
                    case 2:
                        visualizarDados(dados, indice_atual); // dados dele mesmo
                        getchar();
                        break;
                    case 3:
                        editarDados(dados, indice_atual); // editar dados dele mesmo

                        // sincronizando login e senha apos alteracoes
                        strcpy(login, dados[indice_atual].login);
                        strcpy(senha, dados[indice_atual].senha);

                        break;
                    default:
                        return 1;

                        }
                        break;
            case 2:
                switch (condicao)
                {
            case 1:
                nivel_login = 0; // logoff
                break;
            case 2:
                visualizarTD(dados, ultimo_indice); // dados de todos
                getchar();
                // condicaoUsuario(&condicao, nivel_login);
                // if (condicaoUsuario(&condicao, nivel_login) == 1) return 1;
                break;
            case 3:
                editarDadoEspecifico(dados); // editar dado especifico
                break;
            case 4:
                inserirCadastro(dados, &ultimo_indice);
                break;
            default:
                return 1;

                }
                break;
        default:
            return 1;
            }
        }
    } while (1);
}