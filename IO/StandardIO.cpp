#include "StandardIO.h"

/**
 * this function reads from the command line.
 * @return
 */
string StandardIO::read() {
    string str;
    getline(cin,str);
    return str;
}
/**
 * this function reads from the command line.
 * @return
 */
void StandardIO::write(string string) {
    cout << string<<endl;
}