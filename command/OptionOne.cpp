#include "OptionOne.h"
#include "Utilities.h"
/**
 *  optionOne constructor initial the parameters
 *
 * @param (DefaultIO * dio,KNN* knn)
 */
OptionOne::OptionOne(DefaultIO * dio,KNN* knn) {
    this->dio = dio;
    this->knn= knn;
    this->description = "1. upload an unclassified csv data file";
}
/**
 *  default constructor
 */
OptionOne ::OptionOne(){}
/**
 *  execute option one recived the vectors data and test files
 */
void OptionOne::execute() {
    string labeled_line, unlabeled_line,labeled_str,unlabeled_str;
    list<LabeledVector> Labeled_vectors;
    list<UnlabeledVector> unlabeled_vectors;
    //asks for a csv path of the classified vectors
    this->dio->write(UPLOAD_CSV_TRAIN);
    //gets the csv content as a string line by line
    labeled_line = this->dio->read();
    //while there is content
    while(!labeled_line.empty()){
        //create a big string made by all the vectors
        labeled_str.append(labeled_line+"\n");
        labeled_line = this->dio->read();
    }
    //insert the vectors content into a labeled vectors list
    Labeled_vectors=Utilities::createLabeled(labeled_str,this->knn);
    //if one of the vectors is invalid
    if(Labeled_vectors.empty()){
        this->dio->write(ERROR);
        return;

    }
    //asks for a csv path of the unclassified vectors
    this->dio->write(UPLOAD_CSV_TEST);
    //gets the csv content as a string
    unlabeled_line = this->dio->read();
    //while there is content
    while(!unlabeled_line.empty()){
        //create a big string made by all the vectors
        unlabeled_str.append(unlabeled_line+"\n");
        unlabeled_line = this->dio->read();
    }
    unlabeled_vectors=Utilities::createUnLabeled(unlabeled_str,this->knn);
    //if one of the vectors is invalid
    if(unlabeled_vectors.empty()){
        this->dio->write(ERROR);
        return;
    }
    else{
        //sets the new Unlabeled and labeled vectors list
        this->knn->setUnLabeledList(unlabeled_vectors);
        this->knn->setLabeledList(Labeled_vectors);
    }
    //updates validData flag
    this->knn->setValidData(true);
}
