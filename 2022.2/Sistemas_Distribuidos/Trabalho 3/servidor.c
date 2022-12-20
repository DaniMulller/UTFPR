#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


#define PORT 4321
#define MAX_MSG 4096

int main(void) {
    struct sockaddr_in client, server;
    int serverfd, clientfd;

    char buffer[MAX_MSG];

    fprintf(stdout, "Inicializando o Servidor...\n");

    /* Criando o Socket */
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd == -1) {
        perror("Não foi possível criar o Socket: ");
        return -1;
    }

    /* Propriedades da conexão */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;


    /* Verifica se a porta ja esta em uso */
    int yes = 1;
    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR,
                  &yes, sizeof(int)) == -1) {
        perror("Erro de opções do Socket: ");
        return -1;
    }


    /* Da Binda da porta ao Socket */
    if(bind(serverfd, (struct sockaddr*)&server, sizeof(server)) == -1 ) {
        perror("Erro de Bind do Socket: ");
        return -1;
    }

    if(listen(serverfd, 1) == -1) {
        perror("Erro de escuta: ");
        return -1;
    }
    fprintf(stdout, "Escutando a porta %d\n", PORT);

    socklen_t client_len = sizeof(client);
    if ((clientfd=accept(serverfd,
        (struct sockaddr *) &client, &client_len )) == -1) {
        perror("Erro de aceitação: ");
        return -1;
    }


    /* Mensagem de boas-vindas */
    strcpy(buffer, "Olá, Cliente!\n\0");


    /* Envia mensagem para o cliente */
    if (send(clientfd, buffer, strlen(buffer), 0)) {
        fprintf(stdout, "Cliente conectado.\nEsperando mensagem do Cliente ...\n");

        do {
            char resposta[MAX_MSG];
            /* Inicializando o Buffer */
            memset(buffer, 0x0, MAX_MSG);

            /* Recebe a mensagem do Cliente */
            int message_len;
            if((message_len = recv(clientfd, buffer, MAX_MSG, 0)) > 0) {
                buffer[message_len - 1] = '\0';
                printf("Cliente disse: %s\n", buffer);
            }


            /* Se for mensagem 'quit' finaliza o programa */
            if(strcmp(buffer, "sair") == 0) {
                send(clientfd, "sair", 4, 0);
                
            } else {
                printf("Envie uma resposta: ");
                scanf("%s",resposta);
                send(clientfd, resposta, sizeof(resposta), 0);
            }

        } while(strcmp(buffer, "sair"));
    }

    /* Fecha a conexão com o Cliente */
    close(clientfd);

    /* Fecha o Socket local */
    close(serverfd);

    printf("Conexão fechada com sucesso!\n\n");

    return 0;
}