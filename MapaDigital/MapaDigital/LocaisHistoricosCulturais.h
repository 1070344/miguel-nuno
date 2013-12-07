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

		void mostrarHora(int t,string tipo) const;
		void escrever(ostream & out) const;	

		virtual LocaisHistoricosCulturais& operator=(const LocaisHistoricosCulturais &hclocHist);
		virtual bool operator==(const LocaisHistoricosCulturais &hlocHistc) const;

		friend ostream & operator << (ostream & out, const LocaisHistoricosCulturais * locHist);
		friend ostream & operator << (ostream & out, const LocaisHistoricosCulturais  & locHist);

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


void LocaisHistoricosCulturais::mostrarHora(int t,string tipo)const
{
	int horas = t / 60;
	int minutos = t % 60;

	if(tipo == "abertura")
	{
		if(minutos == 0)
		{
			cout << "HORARIO DE ABERTURA: " << horas << ":" << minutos << "0h" << endl;
		}
		else
		{
			cout << "HORARIO DE ABERTURA: " << horas << ":" << minutos << "h" << endl;
		}
	}
	else
	{
		if(minutos == 0)
		{
			cout << "HORARIO DE ENCERRAMENTO: " << horas << ":" << minutos << "0h" << endl << endl;
		}
		else
		{
			cout << "HORARIO DE ENCERRAMENTO: " << horas << ":" << minutos << "h" << endl << endl;
		}
	}
}


void LocaisHistoricosCulturais::escrever(ostream & out) const
{  
	cout << "TIPO DE LOCAL: " << "Historico Cultural" << endl;
	Locais::escrever(cout);
	cout << "TEMPO MEDIO DE VISITA: " << tempoVisita << " minutos" << endl;
	LocaisHistoricosCulturais::mostrarHora(horarioAbertura,"abertura");
	LocaisHistoricosCulturais::mostrarHora(horarioEncerramento,"encerramento");
}


LocaisHistoricosCulturais& LocaisHistoricosCulturais::operator=(const LocaisHistoricosCulturais &locHist){
	
	tempoVisita = locHist.tempoVisita;
	horarioAbertura = locHist.horarioAbertura;
	horarioEncerramento = locHist.horarioEncerramento;
	
	return *this;
}

bool LocaisHistoricosCulturais::operator==(const LocaisHistoricosCulturais &locHist) const{

	return  (tempoVisita == locHist.tempoVisita &&
			horarioAbertura == locHist.horarioAbertura &&
			horarioEncerramento == locHist.horarioEncerramento);
}


ostream & operator << (ostream & out, const LocaisHistoricosCulturais * locHist){
	locHist->escrever(out);
	return out;
}

ostream & operator << (ostream & out, const LocaisHistoricosCulturais & locHist){
	locHist.escrever(out);
	return out;
}



#endif