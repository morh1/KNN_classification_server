#include "SocketIO.h"
/**
 * SocketIO constructor init by a sock number.
 */
SocketIO::SocketIO(int sock) {
    this->sock = sock;
}

/**
 * the read function of SocketIO ,read the string from the buffer ,for be able to get strings larger the
 * some constant ,we using symbol "@" that stands for the end of the read value.
 * @return
 */
string SocketIO::read() {
    char ch = 0;
    string read_string;
    while(ch != '@'){
        recv(sock,&ch,sizeof(char),0);
        if (ch != '@' && ch != 0){
            read_string += ch;
        }
    }
    return read_string;
}
/**
 * The write function of Socket IO is write data based on the connected socket, the @ is using in the read
 * function to recognize when the string is over.
 * @param string
 */
void SocketIO::write(string string) {
    string += "@";
    const char* send_buffer = string.c_str();
    send(sock,send_buffer, string.size()+1,0);
}