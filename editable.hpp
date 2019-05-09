#ifndef EDITABLE_H
#define EDITABLE_H

#include <iostream>

class Editable
{
public:
    virtual void display(std::ostream &os) const = 0;

    virtual ~Editable() {}

    friend std::ostream& operator<<(std::ostream &os, const Editable &editable) {
        editable.display(os);
        return os;
    }
};



#endif // EDITABLE_H
