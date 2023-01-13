#ifndef ADVANCED_PROGRAMING_ASS2_LOADDATA_H
#define ADVANCED_PROGRAMING_ASS2_LOADDATA_H

#include <iostream>
#include <vector>
#include <list>
#include "LabeledVector.h"
#include <cstring>
using namespace std;

class LoadData {
private:
    string path;
    list<LabeledVector> vectors;
    int vectorSize;
public:
    LoadData();
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
