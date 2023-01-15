#include "KNN.h"
/**
 * This class stands for the absolute distance of a vector, from checked vector ,and his name(label).
 * comparison between two tag dist object will be made according to the distance between them.
 */
class TagDist{
    double dist;
    string name;
public:
    TagDist(double dist,string name){
        this->dist =dist;
        this->name = name;
    }
    double getDist(){
        return this->dist;
    };
    string getName(){
        return this->name;
    }
    bool operator < (const TagDist& tagDist) const  {
        return this->dist < tagDist.dist;
    }
    bool operator > (const TagDist& tagDist) const  {
        return this->dist > tagDist.dist;
    }double operator- (const TagDist& tagDist) const  {
        return this->dist - tagDist.dist;
    }

};

using namespace std;
KNN :: KNN(LoadData loadData) {
    this->loadData = loadData;
}

void KNN::setK(int k) {
    this->k = k;
}

void KNN::setMat(string mat) {
    this->mat = mat;
}
/**
 *  the function get vector and return it's classification by implements the KNN algorithm
 *
 * @param (vector<double>)
 * @return (string)
 */
string KNN::findClassification(const vector<double>& vector) {
    //gets the classified vectors list
    list<LabeledVector> lst = this->loadData.getVecList();
    list<LabeledVector>::iterator it;
    list<TagDist> calcDistList;
//create the distance list between the param vector and the vectors in the list
    for (it = lst.begin(); it != lst.end(); ++it){
       calcDistList.emplace_back(stringBasedMetricCalc(vector,it->getVector()),it->getLabel());
    }
//sorting the list
    calcDistList.sort();

    map <string,int> showTimes;
    list<TagDist> ::iterator ite;
    int counter = 0;
    //calcDistList.pop_back();
    //insert the first k neighbors
    for (ite = calcDistList.begin();counter < this->k;counter++){
        //count the recurrence
        if(showTimes[ite->getName()]){
            showTimes[ite->getName()]++;
        }
        else{
            showTimes[ite->getName()] = 1;
        }
        ite++;
    }
    map<string, int>::iterator iter;
    int currMax=0;
    string maxString;
    for (iter = showTimes.begin(); iter != showTimes.end(); iter++)
    {
        if(iter->second >= currMax){
            currMax =iter->second;
            maxString = iter->first;
        }
    }

    return maxString;
}
/**
 * the function gets 2 vectors and calculate the distance between them according
 * to the distance algorithm name the in the member mat
 *
 * @param (vector<double>,vector<double>)
 * @return (double)
 */
double KNN::stringBasedMetricCalc(vector<double> v1, vector<double> v2) {
    if (this->mat == "AUC"){
        return euclidean(v1,v2);
    }if (this->mat == "MAN"){
        return taxiCab(v1,v2);
    }if (this->mat == "CHB"){
        return chebyshev(v1,v2);
    }if (this->mat == "CAN"){
        return canberra(v1,v2);
    }if (this->mat == "MIN"){
        return minkowski(v1,v2,2);
    }
    // not should get in here (validate before)
    cout << "metric error"<<endl;
    return 0;

}
void KNN::loadVectorsList(string labeled_str,string unlabeled_str){
    this.validData=false;
    if(this->loadData.createLabeled(labeled_str) && this->loadData.createUnLabeled(unlabeled_str)){
        validData=true;
    }
}






