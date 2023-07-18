//
// Created by 44380 on 2023/7/18.
//
#include <stdio.h>
#include <winsock.h>
#include "win.h"

#pragma comment(lib, "ws2_32.lib")

int u_win_sock(const char *port) {
    WSADATA wasData;
    SOCKET hServSock, hClintSock;
    SOCKADDR_IN servAddr, clintAddr;
    int szClintAddr;
    char message[] = "Hello world!";
    if (WSAStartup(MAKEWORD(2, 2), &wasData) != 0) {
        printf("error!");
        return -1;
    }
    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    if (hServSock == INVALID_SOCKET) {
        printf("error!");
        return -1;
    }
    memset(&servAddr, 0, sizeof servAddr);
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(port));
    if (bind(hServSock, (SOCKADDR*) &servAddr, sizeof servAddr) == SOCKET_ERROR) {
        printf("bind error!");
        return -1;
    }
    if (listen(hServSock, 5) == SOCKET_ERROR) {
        printf("listen error!");
        return -1;
    }
    szClintAddr = sizeof clintAddr;
    hClintSock = accept(hServSock, (SOCKADDR*)&clintAddr, &szClintAddr);
    if (hClintSock == INVALID_SOCKET) {
        printf("accept error!");
        return -1;
    }
    send(hClintSock, message, sizeof message, 0);
    closesocket(hClintSock);
    closesocket(hServSock);
    WSACleanup();
    return 0;
}