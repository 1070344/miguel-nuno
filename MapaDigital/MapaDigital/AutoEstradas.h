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
		AutoEstradas(Locais* origem, Locais* destino,string cod,int totalVia,int tempMedio,double preco);
		~AutoEstradas();
		virtual ViasLigacao * clone() const;

		//SET's e GET's
		virtual void setPrecoPortagem(double preco);
		virtual double getPrecoPortagem() const;
	
		
		//Sobrecarga de operadores
		void escrever(ostream &out) const;
		

};


AutoEstradas::AutoEstradas()
{
	precoPortagem = 0;
}

AutoEstradas::AutoEstradas(Locais* origem, Locais* destino,string cod,int totalVia,int tempMedio,double preco) : ViasLigacao(origem,destino,cod,totalVia,tempMedio)
{
	precoPortagem = preco;
}

AutoEstradas::~AutoEstradas(){}


ViasLigacao * AutoEstradas::clone() const{
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
	cout << "PRECO DA PORTAGEM: " << "$" << precoPortagem << endl << endl;
}



#endif