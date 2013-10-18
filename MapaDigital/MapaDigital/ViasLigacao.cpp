#include "ViasLigacao.h"


ViasLigacao::ViasLigacao(){
		origem = "vazio";
		destino = "vazio";
		codigo = "vazio";
		totalKilometrosVia = 0;
		tempMedioPercurso = 0;
}

ViasLigacao::ViasLigacao(string orig,string dest,string cod,int totalVia,int tempMedio)
{
	origem = orig;
	destino = dest;
	codigo = cod;
	totalKilometrosVia = totalVia;
	tempMedioPercurso = tempMedio;
}


ViasLigacao::ViasLigacao(const ViasLigacao &vias)
{
	setOrigem(vias.origem);
	setDestino(vias.destino);
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



void ViasLigacao::setOrigem(string orig)
{
	origem = orig;
}


void ViasLigacao::setDestino(string dest)
{
	destino = dest;
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



string ViasLigacao::getOrigem() const
{
	return origem;
}


string ViasLigacao::getDestino() const
{
	return destino;
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






/*ViasLigacao & ViasLigacao::operator=(const ViasLigacao &vias)
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
}*/



void ViasLigacao::escrever(ostream & out) const
{  
	cout << "ORIGEM: " << origem << endl;
	cout << "DESTINO: " << destino << endl;
	cout << "CODIGO DA VIA: " << codigo << endl;
	cout << "TOTAL DE QUILOMETROS: " << totalKilometrosVia << endl;
	cout << "TEMPO MEDIO: " << tempMedioPercurso << endl;
}


