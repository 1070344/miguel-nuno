#ifndef ViasLigacao_
#define ViasLigacao_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "Locais.h"

using namespace std;

class ViasLigacao
{
	private:
		Locais* origem;
		Locais* destino;
		string codigo; //código da via
		int totalKilometrosVia; //total de KM's da Via
		int tempMedioPercurso;//tempo médio do percurso em minutos entre um local origem e um local destino	
	public:
		ViasLigacao();
		ViasLigacao(const ViasLigacao &vias);
		ViasLigacao(Locais* orig, Locais* dest,string cod,int totalVia,int tempMedio);
		virtual ViasLigacao * clone() const;
		virtual ~ViasLigacao();

		//SET's e GET's
		void setCodigoVia(string cod);
		void setTotalKilometrosVia(int totalVia);
		void setTempoMedioPercurso(int tempMedio);
		void setDestino(Locais* origem);
		void setOrigem(Locais* destino);

		string getCodigoVia()const;
		int getTotalKilometrosVia()const;
		int getTempoMedioPercurso()const;
		Locais* getDestino() const;
		Locais* getOrigem() const;
		string getOrigemdesc() const;
		string getDestinodesc() const;

		virtual double getPrecoPortagem() const;

		virtual void escrever (ostream & out) const;

		
		
		//Sobrecarga
		ViasLigacao & operator =(const ViasLigacao &vias);
		bool operator >(const ViasLigacao &vias);
		bool operator <(const ViasLigacao &vias);
		bool operator == (const ViasLigacao &vias) const;

		friend ostream & operator << (ostream & out, const ViasLigacao * vias);
		friend ostream & operator << (ostream & out, const ViasLigacao  & vias);
};

ViasLigacao::ViasLigacao()
{
		codigo = "vazio";
		totalKilometrosVia = 0;
		tempMedioPercurso = 0;
}

ViasLigacao::ViasLigacao(Locais* orig, Locais* dest,string cod,int totalVia,int tempMedio)
{
	setCodigoVia(cod);
	setTotalKilometrosVia(totalVia);
	setTempoMedioPercurso(tempMedio);
	setOrigem(orig);
	setDestino(dest);
}


ViasLigacao::ViasLigacao(const ViasLigacao &vias)
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

void ViasLigacao::setOrigem(Locais* orig)
{
	origem = orig;
}

void ViasLigacao::setDestino(Locais* dest)
{
	destino = dest;
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


string ViasLigacao::getOrigemdesc() const
{
	return origem->getDescricao();
}

string ViasLigacao::getDestinodesc() const
{
	return destino->getDescricao();
}

Locais* ViasLigacao::getOrigem() const
{
	return origem;
}

Locais* ViasLigacao::getDestino() const
{
	return destino;
}

ViasLigacao & ViasLigacao::operator=(const ViasLigacao &vias)
{
	codigo = vias.getCodigoVia();
	totalKilometrosVia = vias.getTotalKilometrosVia();
	tempMedioPercurso = vias.getTempoMedioPercurso();
	return *this;
}


double ViasLigacao::getPrecoPortagem() const {
	return 0;
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
	cout << "CODIGO DA VIA: " << codigo << endl;
	cout << "TOTAL DE QUILOMETROS: " << totalKilometrosVia << " km" << endl;
	cout << "TEMPO MEDIO: " << tempMedioPercurso << " minutos" << endl;
}


ostream & operator << (ostream & out, const ViasLigacao * vias){
	vias->escrever(out);
	return out;
}

ostream & operator << (ostream & out, const ViasLigacao & vias){
	vias.escrever(out);
	return out;
}




#endif