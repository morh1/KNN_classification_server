#ifndef KNN_CLASSIFICATION_SERVER_OPERATIONS_H
#define KNN_CLASSIFICATION_SERVER_OPERATIONS_H

#include "KNN.h"

class Operations {
public:
    KNN knn;
    bool dataUploaded;

    Operations();
    void dataUploadedSuccessfully();
    void loadKnnFromStringTrain(string str);
    void loadKnnFromStringTest(string str);

    void uploadCSVDataFile();
    void algorithmSettings();
    void classifyData();
    void displayData();
    void downloadResults();
    void exit();
};


#endif //KNN_CLASSIFICATION_SERVER_OPERATIONS_H
