/**
 *
 * \file    Duree.h
 *
 * \authors M. Laporte
 *
 * \date    02/04/2018
 *
 * \version V2.0
 *
 * \brief  déclarations de la classe Duree (avec constructeurs et 
 *         destructeur)
 *
 **/
 
 #ifndef __DUREE_H__
 #define __DUREE_H__
 
#include "editable.hpp"

namespace nsUtil
{
    typedef unsigned long long ULLong_t;

    class Duree : public Editable
	{
	  private :
        ULLong_t       myDuree;
		short unsigned mySeconds;
		short unsigned myMinutes;
		short unsigned myHours;
        ULLong_t       myDays;

		void normaliser (void);

	  public :
        explicit Duree  (const ULLong_t duree = ULLong_t (0));
        Duree  (const Duree & duree);
		~Duree (void);

        ULLong_t getDuree (void) const;

        virtual void display(std::ostream &os) const;

        Duree & operator ++ (void) noexcept;
        Duree   operator ++ (int)  noexcept;

        Duree & operator -- (void) noexcept;
        Duree   operator -- (int)  noexcept;

        Duree & operator += (Duree &) noexcept;
        Duree & operator -= (Duree &) noexcept;

        Duree & operator += (int &) noexcept;
        Duree & operator -= (int &) noexcept;
		
		Duree operator +  (const Duree & d) const;
		Duree operator -  (const Duree & d) const;
		
		bool  operator >  (const Duree & d) const;
		bool  operator <  (const Duree & d) const;
		bool  operator != (const Duree & d) const;
		bool  operator == (const Duree & d) const;

	}; // Duree

} // nsUtil

#endif /* __DUREE_H__ */

