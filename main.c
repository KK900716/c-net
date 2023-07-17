#include <stdio.h>
#include <winsock.h>

int main(int argc, char* argv[]) {
    WSADATA wasData;
    SOCKET hServSock, hClintSock;
    SOCKADDR_IN servAddr, clintAddr;
    int szClintAddr;
    char *message = "Hello world!";
    return 0;
    if (WSAStartup(MAKEWORD(2, 2), &wasData) != 0) {
        printf("error!");
    }
    hServSock = socket();
}