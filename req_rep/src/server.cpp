#include <zmq.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REP);
    zmq_bind(socket, "tcp://*:5555");

    printf("Server is running...\n");

    while (1) {
        char buffer[10];
        zmq_recv(socket, buffer, 10, 0);
        printf("Server received message: %s\n", buffer);

        // 模拟一些工作
        sleep(1);

        // 发送响应
        zmq_send(socket, "World", 6, 0);
    }

    zmq_close(socket);
    zmq_ctx_destroy(context);
    return 0;
}