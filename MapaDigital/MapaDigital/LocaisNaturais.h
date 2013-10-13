#ifndef LocaisNaturais_
#define LocaisNaturais_



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
		void escrever(ostream &out) const;


};


LocaisNaturais::LocaisNaturais()
{
	area = 0;
}


LocaisNaturais::LocaisNaturais(string desc,double a) : Locais(desc)//desc=descrição - variavel da superclasse Locais
{
	area = a;
}

LocaisNaturais::~LocaisNaturais(){}


LocaisNaturais::LocaisNaturais(const LocaisNaturais &locNat)
{
	setArea(locNat.area);
}


Locais * LocaisNaturais::clone() const{
	return new LocaisNaturais(*this);
}



void LocaisNaturais::setArea(double a)
{
	area = a;
}

double LocaisNaturais::getArea()const
{
	return area;
}





#endif
