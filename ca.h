#ifndef CA_H
#define CA_H

#include "editable.hpp"
#include <ostream>

class CA : public Editable
{
public:
    virtual void display(std::ostream &os) const override;
    virtual ~CA();
};

#endif // CA_H
