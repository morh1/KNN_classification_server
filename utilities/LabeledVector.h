#ifndef ADVANCED_PROGRAMING_ASS2_LABELEDVECTOR_H
#define ADVANCED_PROGRAMING_ASS2_LABELEDVECTOR_H
#include <iostream>
#include <vector>

using namespace std;
class LabeledVector {
private:
    vector<double> doubleVector;
    string label;
public:
    LabeledVector();
/**
 * The constructor updates the members.
 * @param assignment (vector<double> ,string)
 */
    LabeledVector(vector<double> vector,string label);
/**
* returns the label member
* @return string
*/
    string getLabel();
/**
* returns the vector member
* @return vector<double>
*/
    vector<double> getVector();

/**
* updates the label member
* @param str
*/
    void setLabel(string label);
    /**
* updates the vector member
* @param vector<double>
*/
    void setVec(vector<double> vector);
    /**
* returns the vector member size
* @return int
*/
    int getVecSize();
};
#endif //ADVANCED_PROGRAMING_ASS2_LABELEDVECTOR_H
