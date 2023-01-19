#include "OptionOne.h"

OptionOne::OptionOne(DefaultIO * dio,KNN &knn) {
    this->dio = dio;
    this->knn= knn;
    this->description = "1. upload an unclassified csv data file";
}
OptionOne ::OptionOne(){

}

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
    Labeled_vectors=this->knn.getLoadData().createLabeled(labeled_str);
    if(Labeled_vectors.empty()){
        this->dio->write(ERROR);
        return;
        //what next????????????? ask again?
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
    unlabeled_vectors=this->knn.getLoadData().createUnLabeled(unlabeled_str);
    if(unlabeled_vectors.empty()){
        this->dio->write(ERROR);
        return;
        //what next????????????? ask again?
    }
    else{
        //sets the new Unlabeled and labeled vectors list
        this->knn.getLoadData().setUnLabeledList(unlabeled_vectors);
        this->knn.getLoadData().setLabeledList(Labeled_vectors);
    }
    this->knn.validData=true;
}
