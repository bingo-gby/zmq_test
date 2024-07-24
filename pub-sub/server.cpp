#include<zmq.h>

int main(){
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    zmq_bind(publisher, "tcp://*:5555");
    while (1)
    {
        zmq_send(publisher, "Hello", 6, 0);
    }
    zmq_close(publisher);
    zmq_ctx_destroy(context);
}