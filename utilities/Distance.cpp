#include "Distance.h"

using namespace std;

/**
 * utility function, common calculate.
 *
 * @param assignment (float,float,float)
 * @return (double)
 */
double disCalc(float x1,float x2,float i){
    float val=0;
    //avsolute the subtracted values.
    val=abs(x1-x2);
   // exponent the val by i 
    return pow(val,i);
}
/**
 * the Minkowski algorithem.
 *
 * @param assignment (vector<double> ,vector<double> ,double p)
 * @return (double)
 */
double minkowski(vector<double> v1, vector<double> v2,double p){
    double distance=0;
    //the sigma
    for (int i=0; i<(int)v1.size();i++){
        distance+=disCalc(v1[i],v2[i],p);
    }
    // exponent the val by 1/p 
    return pow(distance,1/p);
}
/**
 * the euclidean algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double euclidean(vector<double> v1, vector<double> v2){
    double distance=0;
    //the sigma
    for (int i=0; i<(int)v1.size();i++){
        distance+=disCalc(v1[i],v2[i],2);
    }

    return sqrt(distance);
}
/**
 * the taxiCab algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double taxiCab(vector<double> v1, vector<double> v2){
    return minkowski(v1,v2,1);

}
/**
 * the canberra algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double canberra(vector<double> v1, vector<double> v2){
    double distance=0;
        //the sigma

    for (int i=0; i<(int)v1.size();i++){
        //if the vectors hold 0 in the same index we will get 0 in the denominator, in that case we are not sum it.
        if(v1[i] ||  v2[i]){
            distance+=disCalc(v1[i],v2[i],1)/(abs(v1[i])+abs(v2[i]));
        }
    }
    return distance;
}
/**
 * the chebyshev algorithem.
 *
 * @param assignment (vector<double> ,vector<double>)
 * @return (double)
 */
double chebyshev (vector<double> v1, vector<double> v2){
    double maxVal=0;
    //looking for the max val.
     for (int i=0; i<(int)v1.size();i++){
        if(disCalc(v1[i],v2[i],1)>maxVal){
            maxVal=disCalc(v1[i],v2[i],1);
        }
    }
    return maxVal;
}

