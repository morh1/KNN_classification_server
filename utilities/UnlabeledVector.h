//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_UNLABELEDVECTOR_H
#define KNN_CLASSIFICATION_SERVER_UNLABELEDVECTOR_H
#include <vector>

using namespace std;
class UnlabeledVector {
private:
    vector<double> doubleVector;
public:
    UnlabeledVector();
/**
 * The constructor updates the members.
 * @param assignment (vector<double>)
 */
    UnlabeledVector(vector<double> vector);
/**
* returns the vector member
* @return vector<double>
*/
    vector<double> getVector();
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


#endif //KNN_CLASSIFICATION_SERVER_UNLABELEDVECTOR_H
