/**
 *
 * \file    Duree.cpp
 *
 * \authors M. Laporte
 *
 * \date    02/04/2018
 *
 * \version V2.0
 *
 * \brief  définitions de la classe Duree
 *
 **/
#include <iostream>
#include <iomanip>   // setw()
#include "Duree.h"
#include "CException.h"

using namespace nsUtil;
using namespace std;

#define DUREE nsUtil::Duree

DUREE::Duree  (const ULLong_t duree /* = ULLong_t (0) */)
    : myDuree (duree) 
{ 
	normaliser ();
	
} // Duree()

DUREE::Duree  (const Duree & duree)
    : myDuree (duree.getDuree ()) 
{ 
	normaliser ();
	
} // Duree()

DUREE::~Duree  (void) 
{ 
	
} // Duree()

void DUREE::normaliser (void)
{
	myDays    =  myDuree / 86400;
	myHours   = (myDuree % 86400) / 3600;
    myMinutes  = (myDuree % 3600) / 60;
	mySeconds =  myDuree % 60;
	
} // normaliser()

ULLong_t DUREE::getDuree (void) const { return myDuree; }

void DUREE::display (std::ostream &os) const
{
    os << '['
	     << setw (10) << myDays    << ':' 
	     << setfill ('0')
         << setw (2)  << myHours   << " heure(s)"
         << setw (2)  << myMinutes << " minute(s)"
         << setw (2)  << mySeconds << " seconde(s)"
		 << setfill (' ')
		 << ']';
		 
} // display()


Duree & DUREE::operator ++ (void) noexcept {
    myDuree += 1;
    normaliser ();
    return *this;
}

Duree   DUREE::operator ++ (int)  noexcept {
    myDuree += 1;
    normaliser ();
    return *this;
}


Duree & DUREE::operator -- (void) noexcept {
    myDuree -= (1 > myDuree) ? myDuree : 1;
    return *this;
}

Duree   DUREE::operator -- (int)  noexcept {
    myDuree -= (1 > myDuree) ? myDuree : 1;
    return *this;
}

Duree & DUREE::operator += (Duree & d) noexcept {
    this->myDuree = myDuree + d.myDuree;

    return *this;
}

Duree & DUREE::operator -= (Duree & d) noexcept {
    this->myDuree = d.myDuree > myDuree ? 0 : myDuree - d.myDuree;

    return *this;
}

Duree & DUREE::operator += (int & l) noexcept {
    this->myDuree = myDuree + l;

    return *this;
}

Duree & DUREE::operator -= (int & l) noexcept {
    this->myDuree = l > myDuree ? 0 : myDuree - l;

    return *this;
}

DUREE DUREE::operator + (const Duree & d) const
{
    return Duree(myDuree + d.myDuree);
	
} // operator +()

DUREE DUREE::operator - (const Duree & d) const
{
    return Duree(myDuree - (myDuree < d.myDuree ? myDuree : d.myDuree));
	
} // operator -()

bool DUREE::operator > (const Duree & d) const
{
	return myDuree > d.myDuree;
	
} // operator >()

bool DUREE::operator < (const Duree & d) const
{
	return myDuree < d.myDuree;
	
} // operator <()

bool DUREE::operator != (const Duree & d) const
{
	return myDuree != d.myDuree;
	
} // operator !=()

bool DUREE::operator == (const Duree & d) const
{
	return myDuree == d.myDuree;
	
} // operator ==()

#undef DUREE

