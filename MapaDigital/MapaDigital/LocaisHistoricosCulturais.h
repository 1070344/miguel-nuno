#ifndef LocaisHistoricosCulturais_
#define LocaisHistoricosCulturais_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "Locais.h"


class LocaisHistoricosCulturais : public Locais
{
	private:
		int tempoVisita;
		int horarioAbertura;
		int horarioEncerramento;
	public:
		LocaisHistoricosCulturais();
		LocaisHistoricosCulturais(const LocaisHistoricosCulturais &locHist);
		LocaisHistoricosCulturais(string desc,int tempoVisita,int horarioAbertura,int horarioEncerramento);
		~LocaisHistoricosCulturais();
		LocaisHistoricosCulturais * clone() const;

		//SET's e GET's
		void setTempoVisita(int tVisita);
		void setHorarioAbertura(int abertura);
		void setHorarioEncerramento(int encerramento);

		int getTempoVisita()const;
		int getHorarioAbertura()const;
		int getHorarioEncerramento()const;

		void escrever(ostream & out) const;	
};


LocaisHistoricosCulturais::LocaisHistoricosCulturais():Locais()
{
	tempoVisita = 0;
	horarioAbertura = 0;
	horarioEncerramento = 0;
}

LocaisHistoricosCulturais::LocaisHistoricosCulturais(string desc,int tVisita,int abertura,int encerramento) : Locais(desc)//desc=descrição - variavel da superclasse Locais
{
	tempoVisita = tVisita;
	horarioAbertura = abertura;
	horarioEncerramento = encerramento;
}


LocaisHistoricosCulturais::LocaisHistoricosCulturais(const LocaisHistoricosCulturais &locHist) : Locais(locHist)
{
	setTempoVisita(locHist.tempoVisita);
	setHorarioAbertura(locHist.horarioAbertura);
	setHorarioEncerramento(locHist.horarioEncerramento);
}

LocaisHistoricosCulturais::~LocaisHistoricosCulturais(){}

LocaisHistoricosCulturais * LocaisHistoricosCulturais::clone() const{
	return new LocaisHistoricosCulturais(*this);
}



void LocaisHistoricosCulturais::setTempoVisita(int tVisita)
{
	tempoVisita = tVisita;
}
				

void LocaisHistoricosCulturais::setHorarioAbertura(int abertura)
{
	horarioAbertura = abertura;
}

void LocaisHistoricosCulturais::setHorarioEncerramento(int encerramento)
{
	horarioEncerramento = encerramento;
}


int LocaisHistoricosCulturais::getTempoVisita()const
{
	return tempoVisita;
}

int LocaisHistoricosCulturais::getHorarioAbertura()const
{
	return horarioAbertura;
}

int LocaisHistoricosCulturais::getHorarioEncerramento()const
{
	return horarioEncerramento;
}

void LocaisHistoricosCulturais::escrever(ostream & out) const
{  
	cout << "TIPO DE LOCAL: " << "Historico Cultural" << endl;
	Locais::escrever(cout);
	cout << "TEMPO MEDIO DE VISITA: " << tempoVisita << " minutos" << endl;
	Locais::mostrarHora(horarioAbertura,"abertura");
	Locais::mostrarHora(horarioEncerramento,"encerramento");
}


#endif