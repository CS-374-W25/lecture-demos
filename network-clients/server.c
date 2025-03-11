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

	// Bind the listening socket to port 51728 and a local network interface
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(51728);
	int bind_result = bind(socket_fd, (struct sockaddr*) &addr, sizeof(addr));
	if (bind_result == -1) {
		printf("Failed on bind!\n");
		return 1;
	}

	int listen_result = listen(socket_fd, 10);
	if (listen_result == -1) {
		printf("Failed on listen!\n");
		return 1;
	}


	pid_t child_pids[300];
	size_t n_child_pids = 0;
	while (1) {
		struct sockaddr_in client_addr;
		socklen_t client_socklen;

		pid_t temp_child_pids[300];
		size_t n_temp_child_pids = 0;
		int i;
		for (i = 0; i < n_child_pids; i++) {
			int exit_status;
			int wait_result = waitpid(child_pids[i], &exit_status, WNOHANG);
			if (!wait_result) {
				temp_child_pids[n_temp_child_pids] = child_pids[i];
				n_temp_child_pids++;
			}
		}

		for (i = 0; i < n_temp_child_pids; i++) {
			child_pids[i] = temp_child_pids[i];
		}
		n_child_pids = n_temp_child_pids;

		int communication_socket_fd = accept(socket_fd, (struct sockaddr*) &client_addr, &client_socklen);

		pid_t fork_result = fork();

		if (fork_result == 0) {
			// Child does this stuff
			if (communication_socket_fd == -1) {
				printf("Error on accept!\n");
				exit(1);
			}
			char message[260] = {'\0'};
			int max_bytes_to_recv = 260;
			int total_bytes_received = 0;
			int max_remaining_bytes_to_recv = max_bytes_to_recv;
			while (strstr(message, "@@") == NULL) {
				int bytes_read = recv(communication_socket_fd, message + total_bytes_received, max_remaining_bytes_to_recv, 0);
				if (bytes_read > 0) {
					max_remaining_bytes_to_recv -= bytes_read;
					total_bytes_received += bytes_read;
				} else {
					// Some error occurred
					return 1;
				}
			}

			size_t length = strlen(message);
			message[length - 1] = '\0';
			message[length - 2] = '\0';

			char* response;
			if (strcmp(message, "what's your name?") == 0) {
				// Respond with "My name is ChatBot9000, the world's smartest chatbot!"
				response = "My name is ChatBot9000, the world's smartest chatbot!@@";
			} else if (strcmp(message, "open sesame") == 0) {
				// Respond with "You guessed the secret passphrase! Here, have a cookie :)"
				response = "You guessed the secret passphrase! Here, have a cookie :)@@";
			} else {
				// Respond with "Sorry! I don't know what that means"
				response = "Sorry! I don't know what that means@@";
			}

			int total_bytes_to_send = strlen(response);
			int total_bytes_sent = 0;
			int remaining_bytes_to_send = total_bytes_to_send;

			while (remaining_bytes_to_send > 0) {
				int bytes_sent = send(communication_socket_fd, response + total_bytes_sent, remaining_bytes_to_send, 0);
				if (bytes_sent > 0) {
					remaining_bytes_to_send -= bytes_sent;
					total_bytes_sent += bytes_sent;
				} else {
					// Some error occurred
					printf("Error on send!\n");
					return 1;
				}
			}

			shutdown(communication_socket_fd, SHUT_RDWR);
			close(communication_socket_fd);
			exit(0);
		}

		// Parent code
		child_pids[n_child_pids] = fork_result;
		n_child_pids++;
	}
}
