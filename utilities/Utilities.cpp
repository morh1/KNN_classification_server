#include <iostream>
#include "Utilities.h"
#include "LoadData.h"
#include <list>
#include <bits/stdc++.h>


using namespace std;
/**
 * checks if the port string is valid
 * @param  (string str)
 * @return (bool)
 */
bool Utilities::validPort(string port) {
    if (!(Utilities::validInt(port))){
        return false;
    }
    int portNumber = stoi(port);
    if(portNumber>=0 && portNumber<=65535){
        return true;
    }
    return false;
}
/**
 * checks if the ip string is valid
 * @param  (string str)
 * @return (bool)
 */
bool Utilities::validIp(string ip) {
    regex ipv4("(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
    if(regex_match(ip, ipv4)){
        return true;
    }
    return false;

}
/**
 * checks if the vector numbers are valid
 * @param  (list<string>)
 * @return (bool)
 */
bool Utilities::vectorListValid(list<string> vector_list) {
    while(!vector_list.empty()){
        if(!validateNumStr(vector_list.back())){
            return false;
        }
        vector_list.pop_back();
    }
    return true;
}
/**
 * separates the input by space into a list
 *
 * @param  (string)
 * @return (list<string>)
 */
list<string> Utilities::separateInput(string str_input){
    list<string> input_list;
    string str;
    stringstream stream;
    stream.str(str_input);

    while (stream >> str) {
        input_list.push_back(str);
    }
    return input_list;
}
/**
 * checks if the vector string is valid
 *
 * @param  (string)
 * @return (bool)
 */

bool Utilities:: validateVectorString(string const &vector_str){
    string num;
    stringstream stream;
    stream.str(vector_str);

    while (stream >> num) {
        if (!validateNumStr(num)){
            return false;
        }
    }
    return true;
}
/**
 * checks if a single double string is valid
 * @param  (string)
 * @return (bool)
 */
bool Utilities::validateNumStr(string str) {
    bool dotFlag= false;
    int strSize = str.size();
    if (strSize > 100){
        return false;
    }
    //enable the case that the number is in the form of *[E,e]-[1-9]* (e.g 0.234E-4).
    for(int i=strSize-3; i>0;i--){
        if((str[i]=='E' || str[i]=='e') && (str[i+1]=='+'|| str[i+1]=='-')){
            for( int j=i+2;j<strSize;j++){
               if(!isdigit(str[j])){
                   return false;
               }
            }
            string sub = str.substr(i+2,strSize);
            if (sub.size() > 9 || stoi(sub) > 300 -strSize ){
                return false;
            }
            strSize=i;
            break;
        }
    }
    //if the first char is not -,+ or a digit
    if(!(isdigit(str[0]) || str[0] == '+' || str[0] == '-' || str[0] == '.')){
        return false;
    }
    if( str[0] == '+' || str[0] == '-'){
        if (strSize < 2 || !isdigit(str[1])){
            return false;
        }
    } if( str[0] == '.' ){
        dotFlag = true;
        if (strSize < 2 || !isdigit(str[1])){
            return false;
        }
    }
    for (int i=1 ; i < strSize;i++){
        if (isdigit(str[i]) ){
            continue;
        }
            //only one . in a double
        else if (str[i] == '.' && !dotFlag){
            dotFlag = true;
            if (i + 1 == strSize || i == 0){
                return false;
            }
            if (i == 1 && (str[0] == '+' || str[0] == '-')){
                return false;
            }
            continue;
        }
        return false;
    }
    return true;

}
/**
 * gets a string and return it as a vector
 * @param  (vector<double> v, string strVec)
 * @return (vector<double>)
 */
vector<double> Utilities::vectorFromString(vector<double> v, string strVec) {
    stringstream stream;
    string num;
    stream.str(strVec);
    while (stream >> num){
        v.push_back(stod(num));
    }
    return v;
}
/**
 * valid the name of the metric
 * @param disStr
 * @return
 */
bool Utilities::validDisStr(string disStr){
    if (disStr == "MAN" || disStr == "AUC" || disStr == "CHB" || disStr == "CAN" || disStr == "MIN"){
        return true;
    }
    return false;
}

/**
 * checks if k is a valid integer
 * @param  (string)
 * @return (bool)
 */
bool Utilities::validInt(string k){
    for(int i=0;i< k.size();i++){
        if (!(isdigit(k[i]))){
            return false;
        }
    }
    return true;

}
/**
 * the function checks if the user's input is valid
 * if k is a number, if the distance name is valid and if the vector is valid
 * @param  (string str)
 * @return (bool)
 */
bool Utilities:: validInput(string str){
    bool valid =true;
    if (str.empty()){
        cout << "invalid input" << endl;
        valid = false;
        return valid;
    }
    //separate the string into a list by space
    list<string> input_list = Utilities::separateInput(str);
    //if the k isn't an integer
    if (input_list.empty()){
        cout << "invalid input" << endl;
        valid = false;
        return valid;
    }
    if (!Utilities::validInt(input_list.back())) {
        cout << "invalid input" << endl;
        valid = false;
        return valid;
    }
    //pop the k number left with the distance function's name and the vector
    input_list.pop_back();
    if (input_list.empty()){
        cout << "invalid input" << endl;
        valid = false;
        return valid;
    }
    //if the distance string isn't a valid distance algorithm name
    if (!Utilities::validDisStr(input_list.back())) {
        cout << "invalid input" << endl;
        valid = false;
        return valid;
    }
    //left with the vector
    input_list.pop_back();
    if (input_list.empty()){
        cout << "invalid input" << endl;
        valid = false;
        return valid;
    }
    if (!Utilities::vectorListValid(input_list)) {
        cout << "invalid input" << endl;
        valid = false;
    }
    return valid;
}