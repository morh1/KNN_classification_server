#include "Utilities.h"


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
    for(int i=0;i< (int) k.size();i++){
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
/**
* return a valid labeled vectors
*/
list<LabeledVector> Utilities:: createLabeled(string s,KNN* knn){
    stringstream stream(s);
    list<LabeledVector> vecList;
    string token;
    //if the file isn't empty
    if (!s.empty())
    {
        //separate the file's string by new line, etch line is a labeled vector.
        while(getline(stream,token,'\n')){
            //looking for the classification word
            int i=token.length()-1;
            while(token[i]!=','){
                i--;
                if(i==0){
                    return vecList;
                }
            }
            //separate between the classification and the vector string
            string classification =token.substr (i+1,token.length()-1-i);
            string strVec=token.substr (0,i);
            vector<double> l= vectorFromString(strVec);
            //if the vector is valid
            if(l.empty()){
                //return an empty list;
                vecList.clear();
            }
            else{
                if(vecList.empty()){
                    // updates the first vector size member
                    knn->setVectorSize(l.size());
                }
                else
                {
                    // the vectors aren't in the same size >> in valid
                    if((int) l.size()!= knn->getVectorsize()){
                        //return an empty vector list
                        vecList.clear();
                        return vecList;
                    }
                }
                LabeledVector labeledVector;
                //update the vector in the labeledVector
                labeledVector.setVec(l);
                //update the classification in the labeledVector
                labeledVector.setLabel(classification);
                //update the labeledVector list member
                vecList.push_back(labeledVector);
            }
        }
    }
    if(knn->getK()>(int)vecList.size()){
        vecList.clear();
    }
    return vecList;
}
/**
* create the LabeledVector list
* @param assignment (string)
*/
list<UnlabeledVector> Utilities::createUnLabeled(string s,KNN* knn){
    vector<double> l;
    stringstream stream(s);
    list<UnlabeledVector> vecList;
    string token;
    //if the file isn't empty
    if (!s.empty())
    {
        //separate the file's string by new line, etch line is a labeled vector.
        while( getline(stream,token,'\n')){
            l =vectorFromString(token);
            //if the vector is valid
            if(l.empty()){
                vecList.clear();
            }
            else{
                // the vectors aren't in the same size
                if((int) l.size() != knn->getVectorsize()){
                    vecList.clear();
                    return vecList;
                }
                UnlabeledVector unlabeled;
                //update the vector in the unlabeledVector
                unlabeled.setVec(l);
                //update the unlabeledVector list member
                vecList.push_back(unlabeled);
            }
        }
    } return vecList;
}
/**
* return a string as a LabeledVector
* @param (string)
* @return (vector*)
*/
vector<double> Utilities:: vectorFromString(string strVec) {
    vector<double> v;
    stringstream stream(strVec);
    //while the string isn't empty
    while (stream.good()){
        string num;
        //separate the words by ,
        getline(stream,num,',');
        //if the word is digit
        if (!(Utilities::validateNumStr(num))) {
            v.clear();
            return v;
        }
        else{
            v.push_back(stod(num));
        }
    }
    return v;
}