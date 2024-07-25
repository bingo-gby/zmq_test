#include<zmq.h>

// 写一段代码，实现sink端的功能
int main(int argc, char *argv[]){
    void *context = zmq_ctx_new();
    void *receiver = zmq_socket(context, ZMQ_PULL);
    zmq_bind(receiver, "tcp://*:5558");

    printf("Sink is running...\n");

    while (1)
    {
        char buffer[10];
        zmq_recv(receiver, buffer, 10, 0);
        printf("Sink received message: %s\n", buffer);
    }

    zmq_close(receiver);
    zmq_ctx_destroy(context);
    return 0;
}