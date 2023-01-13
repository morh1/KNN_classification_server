#include "LabeledVector.h"
/**
 * The default constructor.
 */
LabeledVector::LabeledVector() {}
/**
 * The constructor updates the members.
 * @param assignment (vector<double> ,string)
 */
LabeledVector:: LabeledVector(vector<double> vector,string label){
    this->doubleVector = vector;
    this->label = label;
}
/**
* returns the label member
* @return string
*/
string LabeledVector::getLabel() {
    return this->label;
}
/**
* updates the label member
* @param str
*/
void LabeledVector:: setLabel(string label){
    this->label = label;
}
/**
* updates the vector member
* @param vector<double>
*/
void LabeledVector:: setVec(vector<double> vector){
    this->doubleVector = vector;
}
/**
* returns the vector member
* @return vector<double>
*/
vector<double> LabeledVector::getVector() {
    return this->doubleVector;
}
/**
* returns the vector member size
* @return int
*/
int LabeledVector::getVecSize() {
    return this->doubleVector.size();
}
