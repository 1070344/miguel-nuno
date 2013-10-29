#ifndef ViasLigacao_
#define ViasLigacao_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "Locais.h"

using namespace std;

class ViasLigacao : public Locais
{
	private:
		string codigo; //código da via
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
		
		string getCodigoVia()const;
		int getTotalKilometrosVia()const;
		int getTempoMedioPercurso()const;

		virtual void escrever (ostream & out) const;

		//Sobrecarga de operadores
		ViasLigacao & operator =(const ViasLigacao &vias);
		bool operator >(const ViasLigacao &vias);
		bool operator <(const ViasLigacao &vias);
		bool operator == (const ViasLigacao &vias) const;
};

ViasLigacao::ViasLigacao()
{
		codigo = "vazio";
		totalKilometrosVia = 0;
		tempMedioPercurso = 0;
}

ViasLigacao::ViasLigacao(string orig,string dest,string cod,int totalVia,int tempMedio) : Locais(orig,dest)
{
	codigo = cod;
	totalKilometrosVia = totalVia;
	tempMedioPercurso = tempMedio;
}


ViasLigacao::ViasLigacao(const ViasLigacao &vias) : Locais(vias)
{
	setCodigoVia(vias.codigo);
	setTotalKilometrosVia(vias.totalKilometrosVia);
	setTempoMedioPercurso(vias.tempMedioPercurso);
}


ViasLigacao::~ViasLigacao()
{

}


ViasLigacao * ViasLigacao::clone() const
{
	return new ViasLigacao(*this);
}




void ViasLigacao::setCodigoVia(string cod)
{
	codigo = cod;
}

void ViasLigacao::setTotalKilometrosVia(int totalVia)
{
	totalKilometrosVia = totalVia;
}


void ViasLigacao::setTempoMedioPercurso(int tempMedio)
{
	tempMedioPercurso = tempMedio;
}




string ViasLigacao::getCodigoVia() const
{
	return codigo;
}

int ViasLigacao::getTotalKilometrosVia() const
{
	return totalKilometrosVia;
}

int ViasLigacao::getTempoMedioPercurso() const
{
	return tempMedioPercurso;
}





ViasLigacao & ViasLigacao::operator=(const ViasLigacao &vias)
{
	if(this != &vias){
		codigo = vias.getCodigoVia();
		totalKilometrosVia = vias.getTotalKilometrosVia();
		tempMedioPercurso = vias.getTempoMedioPercurso();
	}
	return *this;
}

bool ViasLigacao::operator < (const ViasLigacao & vias)
{
	if (codigo < vias.codigo) return true; else return false;
}

bool ViasLigacao::operator > (const ViasLigacao & vias)
{
	if (codigo > vias.codigo) return true; else return false;
}

bool ViasLigacao::operator == (const ViasLigacao & vias) const
{
	if (codigo == vias.codigo && totalKilometrosVia == vias.totalKilometrosVia && tempMedioPercurso == vias.tempMedioPercurso)
		return true;
	else
		return false;
}



void ViasLigacao::escrever(ostream & out) const
{  
	Locais::escrever2(cout);
	cout << "CODIGO DA VIA: " << codigo << endl;
	cout << "TOTAL DE QUILOMETROS: " << totalKilometrosVia << " km" << endl;
	cout << "TEMPO MEDIO: " << tempMedioPercurso << " minutos" << endl;
}




#endif