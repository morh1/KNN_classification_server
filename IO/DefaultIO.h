#ifndef KNN_CLASSIFICATION_SERVER_DEFAULTIO_H
#define KNN_CLASSIFICATION_SERVER_DEFAULTIO_H
#include <string>

using namespace std;
/**
 * this class stands for the abstract object of IO ,implement functionalities that relevant for all the IO types.
 */
class DefaultIO {
public:
    /**
     * this function reads from the IO object and return the read string.
     * @return string
     */
    virtual string read() =0;
    /**
     * this function write to the IO object ,from a given string.
     * @param string
     */
    virtual void write(string string) =0;
};
#endif //KNN_CLASSIFICATION_SERVER_DEFAULTIO_H
