//
// Created by roman on 11/02/2026.
//

#ifndef PRJC_2026_PUMPKIN_H
#define PRJC_2026_PUMPKIN_H
class Pumpkin {
    //implicit private
    int weight;
    static int total_weight;
    static int total_number;
public:
    Pumpkin(int _weight);
    ~Pumpkin();
    void display();
    static void total_display();
};

#endif //PRJC_2026_PUMPKIN_H
