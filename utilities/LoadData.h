#ifndef ADVANCED_PROGRAMING_ASS2_LOADDATA_H
#define ADVANCED_PROGRAMING_ASS2_LOADDATA_H

#include <iostream>
#include <vector>
#include <list>
#include "LabeledVector.h"
#include "UnlabeledVector.h"

#include <cstring>
using namespace std;

class LoadData {
private:
    list<LabeledVector> Labeled_vectors;
    list<UnlabeledVector> unlabeled_vectors;
    int vectorSize;
    //Irrelevant
    string path;

public:
    LoadData();
/**
* update the LabeledVector list
*  @param assignment (string)
*/
    list<LabeledVector>  createLabeled(string s);
/**
* create the LabeledVector list
* @param assignment (string)
*/
    list<UnlabeledVector>  createUnLabeled(string s);
/**
 * return a string as a LabeledVector
 * @param (string)
 * @return (vector*)
 */
    vector<double> vectorFromString(string strVec);
/**
* returns the labeled vector list member
* @return list (list<LabeledVector>)
*/
    list<LabeledVector> getLabeledList();
/**
 * returns the unlabeled vectors list member
 * @return list (list<UnLabeledVector>)
 */
    list<UnlabeledVector> getUnLabeledList();
/**
* returns the unlabeled vectors list member
* @return list (list<UnLabeledVector>)
*/
    void setUnLabeledList(list<UnlabeledVector> list);
/**
* sets the labeled vector list member
* @param list (list<LabeledVector>)
*/
    void setLabeledList(list<LabeledVector> list);










/**
 * The constructor updates the path member.
 *
 * @param assignment (string)
 */
    LoadData(string path);
 /**
 * The function gets the classified vectors from the csv file
 * and updates the vectors list member.
 *
 */
    void fromPath();
/**
* returns the vector list member
* @return list (list<LabeledVector>)
*/
    list<LabeledVector> getVecList();
 /**
* returns the vectors size
* @return int
*/
    int getVecSize();
/**
* return a string aas a LabeledVector
* @param (string,strimg)
* @return (LabeledVector*)
*/
    LabeledVector* vectorFromString(string strVec,string classification);
/**
* returns the path string member
* @return string
*/
    string getPath();
};
#endif //ADVANCED_PROGRAMING_ASS2_LOADDATA_H
