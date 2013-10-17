#ifndef LocaisNaturais_
#define LocaisNaturais_
#include "Locais.h"


class LocaisNaturais : public Locais
{
	private:
		double area;//em km2
	public:
		LocaisNaturais();
		LocaisNaturais(const LocaisNaturais &locNat);
		LocaisNaturais(string desc,double a);
		~LocaisNaturais();
		virtual Locais * clone() const;

		//SET's e GET's
		void setArea(double a);
		double getArea() const;

		//Sobrecarga de operadores
		LocaisNaturais & operator =(const LocaisNaturais &locNat);
		bool operator >(const LocaisNaturais &locNat);
		bool operator <(const LocaisNaturais &locNat);
		bool operator ==(const LocaisNaturais &locNat);
		void escreve(ostream &out) const;


};
#endif
