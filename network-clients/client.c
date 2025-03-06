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

	struct addrinfo hints;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	struct addrinfo* server_addr_list;
	// localhost is the "loopback hostname". It means "this machine, the one
	// that this client program is running on".
	int getaddrinfo_result = getaddrinfo("localhost", "51728", &hints, &server_addr_list);
	
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
	
	
	// TODO Receive its response
	

	// TODO Shutdown connection and close the socket FD
	
}
