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
    string mat;
    int k;
public:
/**
 * the function get vector and return it's classification by implements the KNN algorithm
 *
 * @param (vector<double>)
 * @return (string)
 */
KNN(LoadData load);

/**
 * metric setter
 */
void setMat(string mat);

/**
 * k neighborhood setter  setter
 */
void setK(int k);
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