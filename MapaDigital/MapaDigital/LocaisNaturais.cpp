#include "LocaisNaturais.h"
#include "Locais.h"

LocaisNaturais::LocaisNaturais()
{
	area = 0;
}


LocaisNaturais::LocaisNaturais(string d,int a) : Locais(d)//desc=descrição - variavel da superclasse Locais
{
	area = a;
}

LocaisNaturais::~LocaisNaturais(){}


LocaisNaturais::LocaisNaturais(const LocaisNaturais &locNat) : Locais(locNat)
{
	setArea(locNat.area);
}


LocaisNaturais * LocaisNaturais::clone() const{
	return new LocaisNaturais(*this);
}



void LocaisNaturais::setArea(int a)
{
	area = a;
}

double LocaisNaturais::getArea()const
{
	return area;
}

void LocaisNaturais::escrever(ostream & out) const
{  
	cout << "TIPO DE LOCAL: " << "Natural" << endl;
	Locais::escrever(cout);
	cout << "AREA: " << area << " km2 " << endl << endl;
}



