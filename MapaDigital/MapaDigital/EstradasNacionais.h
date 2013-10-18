#ifndef EstradasNacionais_
#define EstradasNacionais_


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>


#include "ViasLigacao.h"

class EstradasNacionais : public ViasLigacao
{
	private:
		string tipoPavimento;//asfalto, paralelo, terra batida, etc.
	public:
		EstradasNacionais();
		EstradasNacionais(const EstradasNacionais &en);
		EstradasNacionais(string orig,string dest,string cod,int totalVia,int tempMedio,string tipoPav);
		~EstradasNacionais();
		virtual ViasLigacao * clone() const;

		//SET's e GET's
		void setTipoPavimento(string tipoPav);
		string getTipoPavimento()const;
	
		//Sobrecarga de operadores
		EstradasNacionais & operator =(const EstradasNacionais &en);
		bool operator >(const EstradasNacionais &en);
		bool operator <(const EstradasNacionais &en);
		bool operator ==(const EstradasNacionais &en);
		void escrever(ostream &out)const;
		

};
#endif