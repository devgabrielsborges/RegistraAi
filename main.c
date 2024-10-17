#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "functions.h"

int main(void) {
    dado_usuario *usuarios = malloc(sizeof(dado_usuario) * 10);  // alocando espaço para 10 usuários
    int indice_atual = 0, condicao;

    printf("Bem-vindo ao RegistraAi\n\n");
    do {
        mostrarTelaInicial();
        scanf("%d", &condicao);

        switch (condicao) {
            case 1:
                registrarUsuario(usuarios, indice_atual);
                indice_atual++;
                break;
            case 2:
                editarUsuario(usuarios, indice_atual);
                break;
            case 3:
                mostrarUsuarios(usuarios, indice_atual);
                break;
            case 4:
                printf("Dados apagados\n");
                free(usuarios);
                return 0;
            case 5:
                // Limpando tela
                #ifdef _WIN32
                    system("cls");  // Comando para Windows
                #else
                    system("clear");  // Comando para (Linux/Mac)
                #endif
                break;
            default:
                printf("Opcao incorreta\n");
                free(usuarios);
                return 2;
        }

    } while (condicao != 5);

    free(usuarios);
    return 0;
}


