#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "LoadData.h"
#include "Utilities.h"
using namespace std;
/**
 * The default constructor.
 */
LoadData::LoadData() {}
/**
 * The constructor updates the path member.
 *
 * @param assignment (string)
 */
LoadData :: LoadData(string path){
    this->path = path;
    fromPath();
}
/**
 * The function gets the classified vectors from the csv file
 * and updates the vectors list member.
 *
 */
void LoadData ::fromPath(){
    string line;
    ifstream file;
    //opening the file with the path member
    file.open(getPath());
    if (file.is_open()) {
        //while there is content in the file
        while(getline( file, line)){
            //if the line is empty it means there is no vector
            if(line.empty()){
                cout << "ERROR - there is an empty vector"<<endl;
                exit(0);
            }
            //looking for the classification word
            int i=line.length()-1;
            while(line[i]!=','){
                i--;
            }
            //separate between the classification and the vector string
            string classification =line.substr (i+1,line.length()-1-i);
            string strVec=line.substr (0,i);
            //gets the LabeledVector with updated members
            LabeledVector* l=vectorFromString(strVec,classification);
            //if the vector is valid
            if(l){
                if(this->vectors.empty()){
                    // updates the first the vector size member
                    this->vectorSize = (*l).getVecSize();
                }
                else
                {
                    // the vectors isn't in the same size
                    if((*l).getVecSize()!=this->vectorSize){
                        cout << "ERROR - The size of the vectors is different"<<endl;
                        exit(0);
                    }
                }
                //update the vectors list member
                this->vectors.push_back(*l);
            }
            else{
                cout << "ERROR - not a valid number"<<endl;
                exit(0);
            }
        }
    }
    //the path is wrong
    else {
        cout <<"Failed to open" << endl;
        exit(0);
    }

}
/**
* returns the vector list member
* @return list (list<LabeledVector>)
*/
list<LabeledVector> LoadData::getVecList() {
    return this->vectors;
}
/**
* returns the vectors size
* @return int
*/
int LoadData::getVecSize() {
    return this->vectorSize;
}
/**
* return a string aas a LabeledVector
* @param (string,strimg)
* @return (LabeledVector*)
*/
LabeledVector* LoadData::vectorFromString(string strVec,string classification) {
    vector<double> v;
    stringstream stream(strVec);
    //while the string isn't empty
    while (stream.good()){
        string num;
        //separate the words by ,
        getline(stream,num,',');
        //if the word is digit
        if (!(Utilities::validateNumStr(num))) {
           return nullptr;
        }
        else{
            v.push_back(stod(num));
        }
    }
    LabeledVector *lPtr= new LabeledVector(v,classification);
    return lPtr;
}
/**
* returns the path string member
* @return string
*/
string LoadData::getPath() {
    return this->path;
}
