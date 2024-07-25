#include<zmq.h>
#include <cstring>

// 写一段代码，实现worker端的功能
int main(int argc, char *argv[]){
    void *context = zmq_ctx_new();
    void *receiver = zmq_socket(context, ZMQ_PULL);
    zmq_connect(receiver, "tcp://localhost:5557");  // 接收 5557 端口的消息

    void *sender = zmq_socket(context, ZMQ_PUSH);
    zmq_connect(sender, "tcp://localhost:5558");  // 发送到 5558 端口

    printf("Worker is running...\n");

    while (1)
    {
        char buffer[10];
        zmq_recv(receiver, buffer, 10, 0);
        printf("Worker received message: %s\n", buffer);
        printf("Worker is processing...\n");
        zmq_send(sender, buffer, 10, 0);
        memset(buffer, 0, sizeof(buffer));
    }

    zmq_close(receiver);
    zmq_close(sender);
    zmq_ctx_destroy(context);
    return 0;
}