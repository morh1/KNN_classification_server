#include "OptionOne.h"

/**
 *  optionOne constructor initial the parameters
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
 *  execute option one received the vectors train and test files
 */
void OptionOne::execute() {
    //neutralize the classification string
    this->knn->initialClassification();
    //set the number of vectors to zero
    this->knn->initialSize();
    string labeled_line, unlabeled_line,labeled_str,unlabeled_str;
    list<LabeledVector> Labeled_vectors;
    list<UnlabeledVector> unlabeled_vectors;
    //asks for a csv path of the classified vectors
    this->dio->write(UPLOAD_CSV_TRAIN);
    //gets the csv content as a string
    labeled_str = this->dio->read();
    //separate the string to vectors and insert them to labeled vectors list
    Labeled_vectors=Utilities::createLabeled(labeled_str,this->knn);
    //if one of the vectors is invalid
    if(Labeled_vectors.empty()){
        this->dio->write(ERROR);
        return;

    }
    this->dio->write(UPLOAD_COMPLETE);
    //asks for a csv path of the unclassified vectors
    this->dio->write(UPLOAD_CSV_TEST);
    //gets the csv content as a string
    unlabeled_str = this->dio->read();
    //separate the string to vectors and insert them to Unlabeled vectors list
    unlabeled_vectors=Utilities::createUnLabeled(unlabeled_str,this->knn);
    //if one of the vectors is invalid
    if(unlabeled_vectors.empty()){
        this->dio->write(ERROR);
        return;
    }
    this->dio->write(UPLOAD_COMPLETE);
    //sets the new Unlabeled and labeled vectors list
    this->knn->setUnLabeledList(unlabeled_vectors);
    this->knn->setLabeledList(Labeled_vectors);
    //sets the number of vectors
    this->knn->setVectNum(Labeled_vectors.size());
    //updates validData flag
    this->knn->setValidData(true);
}
