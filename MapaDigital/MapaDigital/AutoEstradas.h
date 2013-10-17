#ifndef AutoEstradas_
#define AutoEstradas_

#include "ViasLigacao.h"

class AutoEstradas : public ViasLigacao
{
	private:
		double precoPortagem;
	public:
		AutoEstradas();
		AutoEstradas(const AutoEstradas &ae);
		AutoEstradas(string cod,double totalVia,double tempMedio,double preco);
		~AutoEstradas();
		virtual ViasLigacao * clone() const;

		//SET's e GET's
		void setPrecoPortagem(double preco);
		double getPrecoPortagem() const;
	
		
		//Sobrecarga de operadores
		AutoEstradas & operator =(const AutoEstradas &ae);
		bool operator >(const AutoEstradas &ae);
		bool operator <(const AutoEstradas &ae);
		bool operator ==(const AutoEstradas &ae);
		void escreve(ostream &out) const;
		

};
#endif