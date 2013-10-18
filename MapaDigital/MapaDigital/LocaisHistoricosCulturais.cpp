#include "LocaisHistoricosCulturais.h"
#include "Locais.h"

LocaisHistoricosCulturais::LocaisHistoricosCulturais():Locais()
{
	tempoVisita = 0;
	horarioAbertura = 0;
	horarioEncerramento = 0;
}

LocaisHistoricosCulturais::LocaisHistoricosCulturais(string d,int tVisita,int abertura,int encerramento) : Locais(d)//desc=descri��o - variavel da superclasse Locais
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
	cout << "TIPO LOCAL: " << "Historico Cultural" << endl;
	Locais::escrever(cout);
	cout << "TEMPO DE VISITA: " << tempoVisita << endl;
	cout << "HORARIO DE ABERTURA: " << horarioAbertura << endl;
	cout << "HORARIO DE ENCERRAMENTO: " << horarioEncerramento << endl << endl;
}