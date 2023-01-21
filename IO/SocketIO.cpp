#include "SocketIO.h"

SocketIO::SocketIO(int client_sock) {
    this->sock = client_sock;
}
string SocketIO::read() {
    /*
     * char ch = 0;
    string read_string = "";
    while(ch != 10){
        recv(sock,&ch,sizeof(char),0);
        read_string += ch;
    }
    //cout <<" read " <<  read_string<<endl;
    return read_string;
     */
    char buffer[4096] ={0};
    recv(this->sock,buffer,sizeof(buffer),0);
    string s(buffer);
    return s;
}
void SocketIO::write(string string) {
     const char* send_buffer = string.c_str();
    send(sock,send_buffer, string.size()+1,0);
    //cout <<" send " <<string<<endl;
}