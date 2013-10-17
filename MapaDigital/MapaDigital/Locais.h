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
		string descricao;
		int actual,dimensao;
		Locais* *vec;


	public:
		Locais(int dimensao = 20);
		Locais(const Locais &loc);
		Locais(string desc);
		virtual Locais * clone() const;	
		virtual ~Locais();

		//set's e get´s
		void setDescricao(string desc);
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
		void escreve (ostream & out) const;
};
#endif
