//
// Created by roman on 11/05/2026.
//

#ifndef PRJC_2026_RULE_OF_THREE_AND_FIVE_H
#define PRJC_2026_RULE_OF_THREE_AND_FIVE_H
#include <cstddef>

class my_string {
private:
    char *str;
    std::size_t len;
public:
    my_string(char *str = "");
    void print();
    ~my_string();



};


#endif //PRJC_2026_RULE_OF_THREE_AND_FIVE_H
