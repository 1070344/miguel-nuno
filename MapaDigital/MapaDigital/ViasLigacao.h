#ifndef ViasLigacao_
#define ViasLigacao_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

class ViasLigacao
{
	private:
		string codigo; //código da via
		string origem;
		string destino;
		int totalKilometrosVia; //total de KM's da Via
		int tempMedioPercurso;//tempo médio do percurso em minutos entre um local origem e um local destino	
	public:
		ViasLigacao();
		ViasLigacao(const ViasLigacao &vias);
		ViasLigacao(string orig,string dest,string cod,int totalVia,int tempMedio);
		virtual ViasLigacao * clone() const;
		virtual ~ViasLigacao();

		//SET's e GET's
		void setCodigoVia(string cod);
		void setTotalKilometrosVia(int totalVia);
		void setTempoMedioPercurso(int tempMedio);
		void setOrigem(string orig);
		void setDestino(string dest);

		string getOrigem()const;
		string getDestino()const;
		string getCodigoVia()const;
		int getTotalKilometrosVia()const;
		int getTempoMedioPercurso()const;

		virtual void escrever (ostream & out) const;
};
#endif