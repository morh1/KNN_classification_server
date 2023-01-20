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
    list<LabeledVector> Labeled_vectors;
    list<UnlabeledVector> Unlabeled_vectors;
    int vecSize=0;
    string mat = "EUC";
    int k=5;
    bool validData=false;
public:
/**
 * sets the unlabeled  vectors list
 * @param (list<UnlabeledVector> list)
 */
    void setUnLabeledList(list<UnlabeledVector> list);
/**
 * sets the LabeledVector  vectors list
 * @param (list<LabeledVector> list)
 */
    void setLabeledList(list<LabeledVector> list);

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
 * mat getter
 */
string getMat();
/**
 * creat string that contain all the unlabeled vectors classification.
 */
string createClassificationStr();
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
/**
* sets the vector size
* @param int x
*/
    void setVectorSize(int x);
/**
 * returns the vectorSize
 * @return int
 */
    int getVectorsize();
    /**
 * returns the labeled vectors list
 * @return  list<LabeledVector>
 */
    list<LabeledVector> getLabeledList();
 /**
* returns the labeled vectors list
* @return  list<UnlabeledVector>
*/
    list<UnlabeledVector> getUnLabeledList();
 /**
* sets valid data parameter
* @param  bool
*/
    void setValidData(bool b);
};


#endif //ADVANCED_PROGRAMING_ASS2_KNN_H
