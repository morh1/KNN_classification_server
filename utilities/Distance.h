#ifndef ADVANCED_PROGRAMMING_ASSIGNMENT_1_PART_2_DISTANCE_H
#define ADVANCED_PROGRAMMING_ASSIGNMENT_1_PART_2_DISTANCE_H
#include <cmath>
#include <iostream>
#include<vector>
using namespace std;
/**
 * utility function, common calculate.
 *
 * @param assignment (float,float,float)
 * @return (double)
 */
double disCalc(float x1,float x2,float i);
/**
 * the Minkowski algorithem.
 *
 * @param assignment (vector<double> ,vector<double> ,double p)
 * @return (double)
 */
double minkowski(vector<double> v1, vector<double> v2,double p);
/**
 * the euclidean algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double euclidean(vector<double> v1, vector<double> v2);
/**
 * the taxiCab algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double taxiCab(vector<double> v1, vector<double> v2);
/**
 * the canberra algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double canberra(vector<double> v1, vector<double> v2);
/**
 * the chebyshev algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double chebyshev (vector<double> v1, vector<double> v2);

#endif //ADVANCED_PROGRAMMING_ASSIGNMENT_1_PART_2_DISTANCE_H
