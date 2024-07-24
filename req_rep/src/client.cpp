#include <zmq.h>
#include <stdio.h>

int main() {
    void *context = zmq_ctx_new();
    void *socket = zmq_socket(context, ZMQ_REQ);
    zmq_connect(socket, "tcp://localhost:5555");

    printf("Client is running...\n");

    for (int i = 0; i < 5; ++i) {
        // 发送消息
        zmq_send(socket, "Hello", 6, 0);

        // 接收响应
        char buffer[10];
        zmq_recv(socket, buffer, 10, 0);
        printf("Client received reply: %s\n", buffer);
    }

    zmq_close(socket);
    zmq_ctx_destroy(context);
    return 0;
}