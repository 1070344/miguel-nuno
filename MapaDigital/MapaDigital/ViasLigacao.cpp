#include "ViasLigacao.h"
#include "EstradasNacionais.h"
#include "AutoEstradas.h"
#include "Locais.h"


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

bool ViasLigacao::operator == (const ViasLigacao & vias)
{
	if (codigo == vias.codigo) return true; else return false;
}



void ViasLigacao::escrever(ostream & out) const
{  
	Locais::escrever2(cout);
	cout << "CODIGO DA VIA: " << codigo << endl;
	cout << "TOTAL DE QUILOMETROS: " << totalKilometrosVia << endl;
	cout << "TEMPO MEDIO: " << tempMedioPercurso << endl;
}


