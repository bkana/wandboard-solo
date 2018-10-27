#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main(void)
{
    int client_socket;
    char buffer[BUF_SIZE]; /* Ein-/ Ausgabepuffer anlegen */
	struct sockaddr_in addr;
    int size;

	/* Socket anlegen und pruefen, ob es geklappt hat */
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if ( client_socket > 0)
    {
        printf ("Socket wurde angelegt\n");
    }

	/* Zielsocket festlegen */
    addr.sin_family = AF_INET;
    inet_aton("192.168.0.10", &addr.sin_addr); /* IP-Adresse des Servers */
    addr.sin_port = htons(15000); /* Port des Servers setzen */

	/* Verbinden mit Ziel-Socket */
    if ( connect(client_socket, (struct sockaddr*) &addr, sizeof (addr) ) == 0)
    {
        printf ("Verbindung mit dem Server hergestellt\n");
    }

    do
    {
        /* Nachricht  empfangen und ausgeben */
        size = recv(client_socket, buffer, BUF_SIZE-1, 0);
        buffer[size] = 0; /* String terminieren */
        printf ("Nachricht erhalten: %s\n", buffer);

        if (strcmp (buffer, "quit\n"))
        {
            /* Text einlesen und senden */
            printf ("Nachricht zum Versenden: ");
            fgets (buffer, BUF_SIZE, stdin);
            send(client_socket, buffer, strlen(buffer), 0);
        }
		
    } while (strcmp (buffer, "quit\n") != 0);

    close (client_socket);
    return 0;
}
