#ifndef ADVANCED_PROGRAMING_ASS2_UTILITIES_H
#define ADVANCED_PROGRAMING_ASS2_UTILITIES_H
#include <string>
#include <vector>
#include <sstream>
#include "LoadData.h"
#include "KNN.h"
using namespace std;
class Utilities {
public:
    /**
 * checks if the port string is valid
 * @param  (string str)
 * @return (bool)
 */
 static bool validPort(string port);
    /**
    * checks if the ip string is valid
    * @param  (string str)
    * @return (bool)
    */
static bool validIp(string ip);
/**
 * checks if the vector numbers are valid
 * @param  (list<string>)
 * @return (bool)
 */
 static bool vectorListValid(list<string> vector_list);
/**
 * checks if k is a valid integer
 * @param  (string)
 * @return (bool)
 */
    static bool validInt(string k);
/**
 * separates the input by space into a list
 *
 * @param  (string)
 * @return (list<string>)
 */
    static list<string> separateInput(string str_input);
    /**
* this function validate the correctness of the inserted input to the program ,
* (need to be only positive or negative floating point numbers
* @param str
* @return
*/
    static bool validateNumStr(string str);
    /**
 * this function validate all string to match the required convention.
 * @param str
 * @return bool
 */
    static bool validateVectorString(string const &str);
/**
 * this function checks if the distance string from the compilation command is valid
 * @param (string disStr)
 * @return bool
 */
    static bool validDisStr(string disStr);
/**
 * the function checks if the user's input is valid
 * if k is a number, if the distance name is valid and if the vector is valid
 * @param  (string str)
 * @return (bool)
 */
    static bool validInput(string str);
/**
* create the LabeledVector list
* @param assignment (string)
*/
    static list<LabeledVector> createLabeled(string s,KNN* knn);
/**
* create the UnLabeledVector list
* @param assignment (string)
*/
    static list<UnlabeledVector> createUnLabeled(string s,KNN* knn);
/**
* return a string as a LabeledVector
* @param (string)
* @return (vector*)
*/
    static vector<double> vectorFromString(string strVec);
};
#endif //ADVANCED_PROGRAMING_ASS2_UTILITIES_H
