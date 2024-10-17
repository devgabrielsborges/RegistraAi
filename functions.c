//
// Created by borges on 10/16/24.
//

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include "struct.h"

void mostrarTelaInicial() {
    printf(
        "\nEscolha a opcao desejada\n"
        "[1] registrar usuario  [2] editar usuario [3] mostrar todos os usuarios"
        " [4] apagar todos os dados [5] sair\n\n"
    );
}

void registrarUsuario(dado_usuario *usuarios, int indice) {
    printf("Login: \n");
    scanf("%9s", usuarios[indice].login);  // Limitar a leitura para 9 caracteres

    printf("Senha: \n");
    scanf("%19s", usuarios[indice].senha);  // Limitar a leitura para 19 caracteres

    printf("Nome: \n");
    scanf("%19s", usuarios[indice].nome);  // Limitar a leitura para 19 caracteres

    printf("Endereco: \n");
    scanf("%39s", usuarios[indice].endereco);  // Limitar a leitura para 39 caracteres

    printf("Nascimento: (dd/mm/aaaa) \n\n");
    scanf("%10s", usuarios[indice].nascimento);  // Limitar a leitura para 10 caracteres
}

int editarUsuario(dado_usuario *usuarios, int indice_atual) {
    if (indice_atual == 0) {
        printf("Nao ha dados registrados ate o momento\n\n");
        return 3;
    }
    char login[10], senha[20];

    printf("Login: \n");
    scanf("%9s", login);

    printf("Senha: \n");
    scanf("%19s", senha);

    for (int i = 0; i < indice_atual; i++) {
        // Se encontrar um usuario e senha correspondentes
        if (strcmp(login, usuarios[i].login) == 0 && strcmp(senha, usuarios[i].senha) == 0) {
            registrarUsuario(usuarios, i);  // Permite editar o usuário
            return 0;
        }
    }
    printf("Usuario ou senha incorretos\n");
    return 1;
}

void mostrarUsuarios(dado_usuario *usuarios, int indice_atual) {
    printf("Nome | Endereco | Nascimento\n\n");

    for (int indice = 0; indice < indice_atual; indice++) {
        printf("%s | %s | %s\n", usuarios[indice].nome, usuarios[indice].endereco, usuarios[indice].nascimento);
    }
}