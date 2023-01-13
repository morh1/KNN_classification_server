#include "Operations.h"
// add here the operation constractor (sett init to false)
void Operations::loadKnnFromStringTrain(string str) {
    this->knn.loadLabeledVectorsString(str);
}
void Operations ::loadKnnFromStringTest(string str) {
    this->knn.loadUnLabeledVectorsString(str);
}
