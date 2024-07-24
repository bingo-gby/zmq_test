#include<zmq.h>

int main(int argc, char *argv[]){
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(subscriber, "tcp://localhost:5555");
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

    printf("Client is running...\n");

    while (1)
    {
        char buffer[10];
        zmq_recv(subscriber, buffer, 10, 0);
        printf("Client received reply: %s\n", buffer);
    }

    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}