/**
 *
 * \file   : ClasseEditable.cpp
 *
 * \author :
 *
 * \date   :
 *
**/

#include <iostream>
#include <exception>

#include "CstCodErr.h"
#include "CException.h"

#include "ca.h"
#include "cb.h"

#include <editable.hpp>

using namespace std;
using namespace nsUtil;

namespace
{

class CExcFille : public CException {
public:
    CExcFille(const std::string &str, const unsigned &k) : CException (str, k) {}
    virtual ~CExcFille() {}
    void display(std::ostream &os) const {
        os << "Bonjour je suis la fille !";
    }
};

void contenu(const Editable &e) {
    cout << e << endl;
}

} // namespace

int main (int argc, char * argv [])
{
    if (argc != 1) return 0;

    try
    {
        CA ca;
        CB cb;

        contenu(ca);
        contenu(cb);

        throw CExcFille("Hello", 10);

        return KNoExc;
    }
    catch (const CException & e)
    {
        cerr << e << endl;
        return e.getCodErr();
    }
    catch (const exception & e)
    {
        cerr << "Exception standard : " << e.what () << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()
