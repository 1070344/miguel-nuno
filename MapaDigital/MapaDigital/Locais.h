#ifndef Locais_
#define Locais_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

class Locais
{
	private:
		string desc;
		

	public:
		Locais();
		Locais(const Locais &loc);
		Locais(string desc);
		virtual Locais * clone() const;	
		virtual ~Locais();

		//set's e get´s
		void setDescricao(string desc);
		string getDescricao()const;
		
		//Sobrecarga
		void Locais :: operator = (const Locais &loc);
		bool operator == (const Locais &loc) const;

		friend ostream & operator << (ostream & out, const Locais * loc);
		friend ostream & operator << (ostream & out, const Locais  & loc);

		virtual void escrever (ostream & out) const;

};


Locais::Locais()
{
	desc = "vazio";
}

Locais::Locais(string d)
{
	desc = d;
}



Locais::Locais(const Locais &loc)
{
	setDescricao(loc.desc);
}


Locais::~Locais()
{
}

Locais * Locais::clone() const
{
	return new Locais (*this);
}

void Locais::setDescricao(const string d)
{
	desc = d;
}


string Locais::getDescricao()const
{
	return desc;
}


void Locais::escrever(ostream & out) const
{  
	cout << "DESCRICAO: " << desc << endl;
}

ostream & operator << (ostream & out, const Locais * loc){
	loc->escrever(out);
	return out;
}

ostream & operator << (ostream & out, const Locais & loc){
	loc.escrever(out);
	return out;
}









#endif
