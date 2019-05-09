#ifndef CB_H
#define CB_H

#include "editable.hpp"

class CB : public Editable
{
public:
    void display(std::ostream &os) const override;
    virtual ~CB();
};

#endif // CB_H
