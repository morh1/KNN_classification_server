#ifndef KNN_CLASSIFICATION_SERVER_DEFAULTIO_H
#define KNN_CLASSIFICATION_SERVER_DEFAULTIO_H
#include <string>

using namespace std;
class DefaultIO {
public:
    virtual string read() =0;
    virtual void write(string string) =0;
};
#endif //KNN_CLASSIFICATION_SERVER_DEFAULTIO_H
