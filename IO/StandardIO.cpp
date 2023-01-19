#include "StandardIO.h"

string StandardIO::read() {
    string str;
    getline(cin,str);
    return str;
}
void StandardIO::write(string string) {
    cout << string<<endl;
}