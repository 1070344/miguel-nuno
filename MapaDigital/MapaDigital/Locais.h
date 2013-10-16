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
		int actual;
		int dimensao;
		Locais* *vec;


	public:
		Locais(int d=10);
		Locais(const Locais &loc);
		Locais(string desc);
		virtual Locais * clone() const;	
		virtual ~Locais();

		//set's e get´s
		void setDescricao(string d);
		string getDescricao()const;

		//metodos da classe
		virtual void contarLocais(Locais *v);
		virtual void inserirLocal(Locais *v);
		virtual void listar()const;


		/*Sobrecarga de operadores
		Locais & operator =(const Locais &loc);
		bool operator >(const Locais &loc);
		bool operator <(const Locais &loc);
		bool operator ==(const Locais &loc);*/
		virtual void escrever(ostream & out);
};

Locais::Locais(int d)
{
	desc = "nenhuma";
	actual = 0;
	dimensao = d;
	vec = new Locais* [dimensao];

}

Locais::Locais(const Locais &loc)
{
	setDescricao(loc.desc);
}


Locais::Locais(string d)
{
	desc = d;
}

Locais::~Locais()
{
	for (int i=0;i<actual;i++)
		delete vec[i]; 
	delete [] vec;
}

Locais * Locais::clone() const
{
	Locais * l = new Locais(*this);
	return l;
}

void Locais::setDescricao(string d){
	desc = d;
}



void Locais::contarLocais(Locais *v)
{
	int cont = 0;
	for (int i=0; i<actual; i++)
	{
		cont++;
	}
	cout << "Total de Locais: " << cont << endl;//para comparar letras: strcoll(string 1,string 2);
}


void Locais::inserirLocal(Locais *v)
{
	if(actual == dimensao)
	{
		Locais **locTemp = new Locais *[dimensao * 2];
		for(int i=0 ; i<actual ; i++)
		{
			locTemp[i] = vec[i];
			dimensao = 2 * dimensao;
			delete [] vec;
			vec = locTemp;
		}
	}
	cout << "A inserir local........" << endl;
	vec[actual] = v->clone();
	actual++;
}



void Locais::listar()const
{
	cout << "_______________ Listar ________________" << endl;
	for(int i=0 ; i<actual ; ++i)
	{
		vec[i]->listar();
	}
}


void Locais::escrever(ostream & out)
{  
	cout << "escrever..." << endl;
	
}





#endif
