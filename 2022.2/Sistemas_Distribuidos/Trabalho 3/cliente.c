#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4321
#define MAX_MSG 4096
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char *argv[]){
    /* Servidor socket */
    struct sockaddr_in server;
    int sockfd;
    int len = sizeof(server);
    int slen;

    /* Criando os buffers */
    char buffer_in[MAX_MSG];
    char buffer_out[MAX_MSG];

    fprintf(stdout, "Iniciando o Cliente ...\n");

    /*
     * Cria o Socket do Cliente
     */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Erro na criação do Socket!");
        return -1;
    }

    /* Propriedades da conexão */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    /* Conecta ao servidor */
    if (connect(sockfd, (struct sockaddr*) &server, len) == -1) {
        perror("Não foi possível conectar ao servidor!");
        return -1;
    }

    /* Mostra a mensagem vinda do servidor */
    if ((slen = recv(sockfd, buffer_in, MAX_MSG, 0)) > 0) {
        buffer_in[slen + 1] = '\0';
        fprintf(stdout, "Servidor disse: %s\n", buffer_in);
    }

    while(true){
        /* Inicializando os Buffers */
        memset(buffer_in, 0x0, MAX_MSG);
        memset(buffer_out, 0x0, MAX_MSG);

        fprintf(stdout, "Diga algo ao servidor: ");
        fgets(buffer_out, MAX_MSG, stdin);

        /* Envia a mensagem ao servidor */
        send(sockfd, buffer_out, strlen(buffer_out), 0);

        /* Recebe a mensagem do servidor */
        slen = recv(sockfd, buffer_in, MAX_MSG, 0);
        printf("Servidor respondeu: %s\n", buffer_in);

        /* Se for mensagem 'quit' finaliza o programa */
        if(strcmp(buffer_in, "sair") == 0)
            break;
    }

    /* Fecha a conexão com o servidor */
    close(sockfd);

    fprintf(stdout, "\nConexão fechada com sucesso!\n\n");

    return 0;
}