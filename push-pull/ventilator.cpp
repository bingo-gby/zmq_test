# include<zmq.h>


// 写一段代码，实现ventilator端的功能
int main(int argc, char *argv[]){
    void *context = zmq_ctx_new();
    void *sender = zmq_socket(context, ZMQ_PUSH);
    zmq_bind(sender, "tcp://*:5557");   // 连接5557 端口

    printf("Ventilator is running...\n");

    while (1)
    {
        const char *message = "Hello";
        printf("Ventilator is sending message: %s\n", message);
        zmq_send(sender, message, 6, 0);
    }

    zmq_close(sender);
    zmq_ctx_destroy(context);
    return 0;
}