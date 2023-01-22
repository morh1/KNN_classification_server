#include "client.h"

using namespace std;
/**
 * creates the socket connection
 * @param (const char* ip_address,int port)
 * return (int)
 */
int creatSocket(const char* ip_address,int port){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    return sock;
}
/**
 * gets a path and data and insert the data to  file in the the path
 * @param (string path,string data)
 */
void toPath(string path,string data) {
    ofstream file;
    //open the file
    file.open(path);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}
/**
 * gets the data that the file contain and send it as one string to the server
 * @param (string path,SocketIO sock)
 */
void sendFile(string path,SocketIO sock) {
    ifstream file(path);
    stringstream buffer;
    buffer << file.rdbuf();
    string csv_string = buffer.str();
    sock.write(csv_string);
}
/**
 * in case the chosen option is one
 * @param (SocketIO socketIo,StandardIO standardIo)
 */
void inputOne(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
    string path =  standardIo.read();
    sendFile(path,socketIo);
    string output = socketIo.read();
    standardIo.write(output);
    //there is error with the classified vectors
    if (output == ERROR){
        return;
    }
    standardIo.write(socketIo.read());
    path =  standardIo.read();
    sendFile(path,socketIo);
    standardIo.write(socketIo.read());
}
/**
 * in case the chosen option is five
 * @param (SocketIO socketIo,StandardIO standardIo)
 */
void inputFive(SocketIO socketIo,StandardIO standardIo){
    //there is no data
    if(socketIo.read() == "false"){
        standardIo.write(socketIo.read());
        return;
    }
    //gets the path
    string path = standardIo.read();
    string data = socketIo.read();
    thread thread(toPath,path,data);
    thread.detach();
}
/**
 * in case the chosen option is two
 * @param (SocketIO socketIo,StandardIO standardIo)
 */
void inputTwo(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
    socketIo.write(standardIo.read());
    //if k isn't valid
    if(socketIo.read()=="false"){
        standardIo.write(socketIo.read());
    }
    //if the metric isn't valid
    if(socketIo.read()=="false"){
        standardIo.write(socketIo.read());
    }
}
/**
 * in case the chosen option is tree
 * @param (SocketIO socketIo,StandardIO standardIo)
 */
void inputThree(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
}
/**
 * in case the chosen option is four
 * @param (SocketIO socketIo,StandardIO standardIo)
 */
void inputFour(SocketIO socketIo,StandardIO standardIo){
    standardIo.write(socketIo.read());
}
/**
 * route the client to each option input
 *
 * @param (SocketIO socketIo,StandardIO standardIo,string input)
 * @return (bool)
 */
bool routeInput(SocketIO socketIo,StandardIO standardIo,string input){
    if(input=="1"){
        inputOne( socketIo, standardIo);
        return true;
    }
    if(input=="2"){
        inputTwo( socketIo, standardIo);
        return true;
    }
    if(input=="3"){
        inputThree( socketIo, standardIo);
        return true;
    }
    if(input=="4"){
        inputFour( socketIo, standardIo);
        return true;
    }
   if(input=="5"){
        inputFive( socketIo, standardIo);
        return true;
    }
    return false;
}
/**
 * the function checks if the arguments if the command line  are valid
 * @param  (char* argv[])
 * @return (bool)
 */
bool validArgv(int argc,char* argv[]){
    if (argc != 3){
        cout << "not right amount of arguments" << endl;
        return false;
    }
    if (!Utilities::validIp( argv[1])) {
        cout << "invalid ip address" << endl;
        return false;
    }
    if (!Utilities::validPort( argv[2])) {
        cout << "invalid port address" << endl;
        return false;
    }
    return true;
}
/**
 * the main function create the socket and display the menu;
 *
 * @param (int argc,char** argv)
 * @return (int)
 */
int main(int argc,char** argv){
    if (!validArgv(argc,argv)){
        return 0;
    }
    char* ip_address = argv[1];
    int port_no = atoi(argv[2]);
    //create the socket
    int clientSock = creatSocket(ip_address,port_no);
    SocketIO socketIo = SocketIO(clientSock);
    StandardIO standardIo = StandardIO();

    string input;
    while (true){
        //write the option list on the client screen.
        standardIo.write(socketIo.read());
        //read the input of the user(should be a number)
        input=standardIo.read();
        //send to the server
        socketIo.write(input);
        if(input=="8"){
            socketIo.write("disconnected");
            close(clientSock);
            return 0;
        }
        //if the input is a valid option number
        if(!routeInput(socketIo,standardIo,input)){
            //we will get an error message
            standardIo.write(socketIo.read());
        }
    }
}
