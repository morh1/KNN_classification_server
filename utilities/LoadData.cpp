#include <string>
#include <fstream>
#include <vector>
#include <list>
#include "LoadData.h"
#include "Utilities.h"

vector<double> vectorFromString(string basicString);

using namespace std;
/**
 * The default constructor.
 */
LoadData::LoadData() { }

/**
* update the LabeledVector list
*/
/*
list<LabeledVector> LoadData::createLabeled(string s){
    stringstream stream(s);
    list<LabeledVector> vecList;
    string token;
    //if the file isn't empty
    if (!s.empty())
    {
            //separate the file's string by new line, etch line is a labeled vector.
            while(getline(stream,token,'\n')){
                //looking for the classification word
                unsigned long i=token.size() -1;
                while(token[i]!=','){
                    i--;
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
                        this->vectorSize = l.size();
                    }
                    else
                    {
                        // the vectors isn't in the same size >> in valid
                        if(l.size()!=this->vectorSize){
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
        return vecList;
    }
*/
/**
* return a string as a LabeledVector
* @param (string)
* @return (vector*)
*/
vector<double> LoadData:: vectorFromString(string strVec) {
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
/**
* returns the labeled vector list member
* @return list (list<LabeledVector>)
*/
list<LabeledVector> LoadData::getLabeledList() {
    return this->Labeled_vectors;
}
/**
* returns the unlabeled vectors list member
* @return list (list<UnLabeledVector>)
*/
list<UnlabeledVector> LoadData::getUnLabeledList() {
    return this->unlabeled_vectors;
}
/**
* sets the labeled vector list member
* @param list (list<LabeledVector>)
*/
void LoadData::setLabeledList(list<LabeledVector> list) {
     this->Labeled_vectors=list;
}
/**
* sets the Unlabeled vector list member
* @param list (list<LabeledVector>)
*/
void LoadData::setUnLabeledList(list<UnlabeledVector> list) {
     this->unlabeled_vectors=list;
}




//Irrelevant
/**
 * The constructor updates the path member.
 *
 * @param assignment (string)
 */
 /*
  *

LoadData :: LoadData(string path){
    this->path = path;
    fromPath();
} */
/**
 * The function gets the classified vectors from the csv file
 * and updates the vectors list member.
 *
 */
 /*
  *

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

}  */
/*
list<LabeledVector> LoadData::getVecList() {
    return this->vectors;
}*/
/*
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
}*/
/**
* returns the path string member
* @return string
*/
string LoadData::getPath() {
    return this->path;
}
