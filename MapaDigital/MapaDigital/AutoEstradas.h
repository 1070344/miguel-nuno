#ifndef AutoEstradas_
#define AutoEstradas_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "ViasLigacao.h"

class AutoEstradas : public ViasLigacao
{
	private:
		double precoPortagem;
	public:
		AutoEstradas();
		AutoEstradas(const AutoEstradas &ae);
		AutoEstradas(string orig,string dest,string cod,int totalVia,int tempMedio,double preco);
		~AutoEstradas();
		AutoEstradas * clone() const;

		//SET's e GET's
		void setPrecoPortagem(double preco);
		double getPrecoPortagem() const;
	
		
		//Sobrecarga de operadores
		AutoEstradas & operator =(const AutoEstradas &ae);
		bool operator >(const AutoEstradas &ae);
		bool operator <(const AutoEstradas &ae);
		bool operator ==(const AutoEstradas &ae);
		void escrever(ostream &out) const;
		

};
#endif