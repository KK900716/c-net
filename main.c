#include <stdio.h>
#include <winsock.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[]) {
    WSADATA wasData;
    SOCKET hServSock, hClintSock;
    SOCKADDR_IN servAddr, clintAddr;
    int szClintAddr;
    char message[] = "Hello world!";
    if (WSAStartup(MAKEWORD(2, 2), &wasData) != 0)
        printf("error!");
    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    if (hServSock == INVALID_SOCKET)
        printf("error!");
    memset(&servAddr, 0, sizeof servAddr);
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi("8080"));
    if (bind(hServSock, (SOCKADDR*) &servAddr, sizeof servAddr) == SOCKET_ERROR)
        printf("bind error!");
    if (listen(hServSock, 5) == SOCKET_ERROR)
        printf("listen error!");
    szClintAddr = sizeof clintAddr;
    hClintSock = accept(hServSock, (SOCKADDR*)&clintAddr, &szClintAddr);
    if (hClintSock == INVALID_SOCKET)
        printf("accept error!");
    send(hClintSock, message, sizeof message, 0);
    closesocket(hClintSock);
    closesocket(hServSock);
    WSACleanup();
    return 0;
}