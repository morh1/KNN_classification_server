#ifndef ADVANCED_PROGRAMING_ASS2_KNN_H
#define ADVANCED_PROGRAMING_ASS2_KNN_H
#include <iostream>
#include "LoadData.h"
#include <vector>
#include "LabeledVector.h"
#include "Distance.h"
#include <map>

using namespace std;
class KNN {
private:
    LoadData loadData;
    string mat = "EUC";
    int k=5;
    bool validData=false;
public:
/**
 * The Knn constructor
 *
 * @param (vector<double>)
 * @return (string)
 */
KNN(LoadData load);
/**
 * The Knn constructor
 *
 * @return (string)
 */
KNN();
/**
 * metric setter
 */
void setMat(string mat);
/**
 * k neighborhood setter
 */
void setK(int k);
/**
 * k neighborhood getter
 */
int getK();
/**
 * validData getter
 */
bool getValidData();
/**
 * validData setter
 */
void setValidData(bool b);
/**
 * mat getter
 */
string getMat();
/**
 * creat string that contain all the unlabeled vectors classification.
 */
string createClassificationStr();
/**
 * LoadData getter
 */
LoadData getLoadData();
/**
 * the function gets 2 vectors and calculate the distance between them according
 * to the distance algorithm name the in the member mat
 *
 * @param (vector<double>,vector<double>)
 * @return (double)
 */
    double stringBasedMetricCalc(vector<double>,vector<double>);
/**
 * the function get vector and return it's classification by implements the KNN algorithm
 *
 * @param (vector<double>)
 * @return (string)
 */
    string findClassification(const vector<double>& vector);
};


#endif //ADVANCED_PROGRAMING_ASS2_KNN_H
