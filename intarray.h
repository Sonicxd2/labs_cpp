//
// Created by yaroslav on 06.02.19.
//

#ifndef DEBUG_ARRAY_H
#define DEBUG_ARRAY_H

class Array {
private:
    int *array;
    int size;

public:
    Array(int size);

    int &operator[](int id);

    bool operator==(Array next);

    bool operator>(Array next);

    bool operator<(Array next);

    bool operator!=(Array next);

    Array operator+(Array next);
};
#endif //DEBUG_ARRAY_H
