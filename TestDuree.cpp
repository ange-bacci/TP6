
/**
 *
 * @file    TestDuree.cpp
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    17/03/2010
 *
 * @version V1.0
 *
 * @brief   Test de la classe CDuree complete
 *
 **/
#include <iostream>
#include <utility>         // operateurs < et == generiques
#include <cassert>
#include <sstream>

#include "CException.h"    // de l'exercice précédent
#include "CstCodErr.h"
#include "Duree.h"

using namespace std;
using namespace rel_ops;
using namespace nsUtil;    // CException

namespace
{
    void testDuree_01 (void)
    {
        DureeEditable d1 (3661);
        DureeEditable d2 (2661);
        DureeEditable d3 (3661);

        assert (! (d1 < d2));
        assert (  (d2 < d1));

        assert (   d1 > d2);
        assert (! (d2 > d1));

        assert (! (d1 <= d2));
        assert (   d2 <= d1);

        assert (   d1 >= d2);
        assert (! (d2 >= d1));

        assert (! (d1 == d2));
        assert (! (d2 == d1));
        assert (   d1 == d3);

        assert (   d1 != d2);
        assert (   d2 != d1);

    } // testDuree_01()

    void TestCDuree_02 (void)
    {
        CDureeEditable D1 (3661);
        {
            ostringstream oss;
            oss << D1;
            assert (oss.str() == "[     0:01:01:01]");
        }
        {
            ostringstream oss;
            oss << D1--;
            assert (oss.str() == "[     0:01:01:01]");
        }
        {
            ostringstream oss;
            oss << D1--;
            assert (oss.str() == "[     0:01:01:00]");
        }
        {
            ostringstream oss;
            oss << --D1;
            assert (oss.str() == "[     0:01:00:58]");
        }
        {
            ostringstream oss;
            oss << D1;
            assert (oss.str() == "[     0:01:00:58]");
        }
        {
            ostringstream oss;
            oss << D1++;
            assert (oss.str() == "[     0:01:00:58]");
        }
        {
            ostringstream oss;
            oss << D1++;
            assert (oss.str() == "[     0:01:00:59]");
        }
        {
            ostringstream oss;
            oss << ++D1;
            assert (oss.str() == "[     0:01:01:01]");
        }
        {
            ostringstream oss;
            oss << ++D1;
            assert (oss.str() == "[     0:01:01:02]");
        }
        {
            ostringstream oss;
            oss << ++D1;
            assert (oss.str() == "[     0:01:01:03]");
        }
        {
            ostringstream oss;
            oss << (D1 -= 3);
            assert (oss.str() == "[     0:01:01:00]");
        }
        {
            ostringstream oss;
            oss << (D1 += 3);
            assert (oss.str() == "[     0:01:01:03]");
        }
        {
            ostringstream oss;
            oss << (D1 += CDuree (3));
            assert (oss.str() == "[     0:01:01:06]");
        }
        {
            D1.SetDuree (0);
            ostringstream oss;
            oss << D1;
            assert (oss.str() == "[     0:00:00:00]");
        }

    } // TestCDuree_02)

    void TestCDuree_03 (void)
    {
        CDureeEditable D1;
        bool IsCaught = false;

        try { D1--; }
        catch (const CException & E) { IsCaught = true; }
        assert (IsCaught);

        IsCaught = false;
        try { --D1; }
        catch (const CException & E) { IsCaught = true; }
        assert (IsCaught);

        IsCaught = false;
        try { D1 -= 1; }
        catch (const CException & E) { IsCaught = true; }
        assert (IsCaught);

        IsCaught = false;
        try { D1 -= CDuree (3); }
        catch (const CException & E) { IsCaught = true; }
        assert (IsCaught);

    } // TestCDuree_03()

} // namespace anonyme

int main (int argc, char * argv [])
{
    if (argc != 1)
    {
        cerr << "Nombre d'arguments invalide\n"
                "Usage : TestCDuree\n";
        return KErrArg;
    }
    try
    {
        TestCDuree_01 ();
        TestCDuree_02 ();
        TestCDuree_03 ();
        cout << "Fin normale\n";

        return KNoExc;
    }
    catch (const CException & E)
    {
        cerr << E << '\n';
        return E.GetCodErr();
    }
    catch (const exception & E)
    {
        cerr << "Exception standard : " << E.what() << '\n';
        return KExcStd;
    }
    catch (...)
    {
        cerr << "Exception inconnue\n";
        return KExcInconnue;
    }

} // main()


