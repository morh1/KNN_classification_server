#include "UnlabeledVector.h"
/**
 * The default constructor.
 */
UnlabeledVector::UnlabeledVector() {}
/**
 * The constructor updates the members.
 * @param assignment (vector<double> ,string)
 */
UnlabeledVector:: UnlabeledVector(vector<double> vector){
    this->doubleVector = vector;
}
/**
* updates the vector member
* @param vector<double>
*/
void UnlabeledVector:: setVec(vector<double> vector){
    this->doubleVector = vector;
}
/**
* returns the vector member
* @return vector<double>
*/
vector<double> UnlabeledVector::getVector() {
    return this->doubleVector;
}
/**
* returns the vector member size
* @return int
*/
int UnlabeledVector::getVecSize() {
    return this->doubleVector.size();
}
