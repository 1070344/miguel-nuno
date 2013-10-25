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


AutoEstradas::AutoEstradas()
{
	precoPortagem = 0;
}

AutoEstradas::AutoEstradas(string orig,string dest,string cod,int totalVia,int tempMedio,double preco) : ViasLigacao(orig,dest,cod,totalVia,tempMedio)
{
	precoPortagem = preco;
}

AutoEstradas::~AutoEstradas(){}


AutoEstradas * AutoEstradas::clone() const{
	return new AutoEstradas(*this);
}


AutoEstradas::AutoEstradas(const AutoEstradas &ae) : ViasLigacao(ae)
{
	setPrecoPortagem(ae.precoPortagem);
}

void AutoEstradas::setPrecoPortagem(double preco)
{
	precoPortagem = preco;
}

double AutoEstradas::getPrecoPortagem() const
{
	return precoPortagem;
}

void AutoEstradas::escrever(ostream &out)const
{
	cout << "TIPO DE VIA: " << "Auto Estrada" << endl;
	ViasLigacao::escrever(cout);
	cout << "PRECO DA PORTAGEM: " << "EUR "<< precoPortagem << endl << endl;
}



#endif