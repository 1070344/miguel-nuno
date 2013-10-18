#include "ViasLigacao.h"
#include "EstradasNacionais.h"
#include "AutoEstradas.h"


ViasLigacao::ViasLigacao(){
		codigo = "";
		totalKilometrosVia = 0;
		tempMedioPercurso = 0;
		origem = "vazio";
		destino = "vazio";
		actual = 0;
		tamanho = 0;
}

ViasLigacao::ViasLigacao(string cod,double totalVia,double tempMedio,string orig,string dest)
{
	codigo = cod;
	totalKilometrosVia = totalVia;
	tempMedioPercurso = tempMedio;
	origem = orig;
	destino = dest;
}


ViasLigacao::ViasLigacao(const ViasLigacao &vias)
{
	setCodigoVia(vias.codigo);
	setTotalKilometrosVia(vias.totalKilometrosVia);
	setTempoMedioPercurso(vias.tempMedioPercurso);
	setOrigem(vias.origem);
	setDestino(vias.destino);
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

void ViasLigacao::setTotalKilometrosVia(double totalVia)
{
	totalKilometrosVia = totalVia;
}

void ViasLigacao::setTempoMedioPercurso(double tempMedio)
{
	tempMedioPercurso = tempMedio;
}


void ViasLigacao::setOrigem(string orig)
{
	origem = orig;
}


void ViasLigacao::setDestino(string dest)
{
	destino = dest;
}



string ViasLigacao::getCodigoVia() const
{
	return codigo;
}

double ViasLigacao::getTotalKilometrosVia() const
{
	return totalKilometrosVia;
}

double ViasLigacao::getTempoMedioPercurso() const
{
	return tempMedioPercurso;
}


string ViasLigacao::getOrigem() const
{
	return origem;
}


string ViasLigacao::getDestino() const
{
	return destino;
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

void ViasLigacao::inserirViaLigacao(ViasLigacao *v)
{

	if (actual == tamanho)
	{
		tamanho = 2* tamanho;
		ViasLigacao * * vec_tmp = new ViasLigacao * [tamanho];
		for (int i=0; i<actual; i++)
			vec_tmp[i] = vec[i];
		delete [] vec;
		vec = vec_tmp;
	}

	vec[actual] = v->clone();
	actual++;
}
	
void ViasLigacao::contarVias() const
{
	int autoestradas = 0;
	int estradasnacionais = 0;

	/*for (int i=0; i<actual; i++)
	{
		if (typeid(*vec[i]) == typeid(AutoEstradas)) autoestradas++;
		if (typeid(*vec[i]) == typeid(EstradasNacionais)) estradasnacionais++;
	}
	cout << "Total de Vias de Ligacao" << endl;
	cout << "::::::::::Auto-Estradas: " << autoestradas << " vias." << endl;
	cout << "::::::::::Estradas-Nacionais: " << estradasnacionais << " vias." << endl;
	*/
}



void ViasLigacao::escrever(ostream & out) const
{  
	cout << "Origem: " << origem << endl;
	cout << "Destino: " << destino << endl;
	cout << "Codigo Estrada: " << codigo << endl;
	cout << "Distancia: " << totalKilometrosVia << endl;
	cout << "Tempo Medio: " << tempMedioPercurso << endl;
}


