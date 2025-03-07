#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>

int main() {
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1) {
		printf("Failed on socket!\n");
		return 1;
	}

	/*
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(51728);
	int connect_result = connect(socket_fd, (struct sockaddr*) &addr, sizeof(addr));
	if (connect_result == -1) {
		printf("Failed on connect!\n");
		return 1;
	}
	*/

	struct addrinfo hints = {0};
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	struct addrinfo* server_addr_list = NULL;
	// localhost is the "loopback hostname". It means "this machine, the one
	// that this client program is running on".
	int getaddrinfo_result = getaddrinfo("localhost", "51728", &hints, &server_addr_list);
	if (getaddrinfo_result != 0) {
		printf("Error on getaddrinfo!\n");
		return 1;
	}
	
	struct addrinfo* itr = server_addr_list;
	int connect_result = -1;
	while (itr != NULL) {
		connect_result = connect(socket_fd, itr->ai_addr, itr->ai_addrlen);
		if (connect_result == 0) {
			break;
		}
		itr = itr->ai_next;
	}

	if (connect_result != 0) {
		printf("Error on connect!\n");
		return 1;
	}
	
	// TODO Send a message to the server
	char message[260];
	printf("Enter a message to send: ");
	fgets(message, 258, stdin);
	size_t length = strlen(message);
	message[length - 1] = '@';
	message[length] = '@';
	message[length + 1] = '\0';

	int total_bytes_to_send = strlen(message);
	int total_bytes_sent = 0;
	int remaining_bytes_to_send = total_bytes_to_send;

	while (remaining_bytes_to_send > 0) {
		int bytes_sent = send(socket_fd, message + total_bytes_sent, remaining_bytes_to_send, 0);
		if (bytes_sent > 0) {
			remaining_bytes_to_send -= bytes_sent;
			total_bytes_sent += bytes_sent;
		} else {
			// Some error occurred
			return 1;
		}
	}
	
	// Receive its response
	char response[260] = {'\0'};
	int max_bytes_to_recv = 260;
	int total_bytes_received = 0;
	int max_remaining_bytes_to_recv = max_bytes_to_recv;
	while (strstr(response, "@@") == NULL) {
		int bytes_read = recv(socket_fd, response + total_bytes_received, max_remaining_bytes_to_recv, 0);
		if (bytes_read > 0) {
			max_remaining_bytes_to_recv -= bytes_read;
			total_bytes_received += bytes_read;
		} else {
			// Some error occurred
			printf("Error on recv!\n");
			return 1;
		}
	}

	length = strlen(response);
	response[length - 1] = '\0';
	response[length - 2] = '\0';
	printf("The server responded with: %s\n", response);

	// TODO Shutdown connection and close the socket FD
	shutdown(socket_fd, SHUT_RDWR);
	close(socket_fd);
}
