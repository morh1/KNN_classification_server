//
// Created by mor on 1/13/23.
//

#ifndef KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H
#define KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H


class OptionEight: public Command {
private:
    Light *light;

public:
    OptionEight(Operation  *light) : light(light) {}

    void execute() {
        light->optionEight();
    }
};

#endif //KNN_CLASSIFICATION_SERVER_OPTIONEIGHT_H
