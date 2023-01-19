#include "SocketIO.h"

SocketIO::SocketIO(int client_sock) {
    this->sock = client_sock;
}
string SocketIO::read() {
    char ch = ' ';
    string read_string = "";
    while(ch != '\n'){
        recv(sock,&ch,sizeof(char),0);
        read_string += ch;
    }
    return read_string;
}
void SocketIO::write(string string) {
    const char* send_buffer = string.c_str();
    send(sock,send_buffer, strlen(send_buffer),0);
}