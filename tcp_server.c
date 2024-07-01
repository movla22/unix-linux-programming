#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 12345

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *banner_message = "Merhaba, benim serverım!\n";

    // Socket oluşturma
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket oluşturulamadı");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Socket'ı bağlama
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bağlama başarısız");
        exit(EXIT_FAILURE);
    }

    // Bağlantıları dinleme
    if (listen(server_fd, 3) < 0) {
        perror("Dinleme başarısız");
        exit(EXIT_FAILURE);
    }

    printf("Server dinlemede %d portunda...\n", PORT);

    while (1) {
        // Gelen bağlantıları kabul etme
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Bağlantı kabul edilemedi");
            exit(EXIT_FAILURE);
        }

        // Banner gönderme
        send(new_socket, banner_message, strlen(banner_message), 0);
        printf("Client'a banner gönderildi\n");

        // Bağlantıyı kapat
        close(new_socket);
    }

    return 0;
}
