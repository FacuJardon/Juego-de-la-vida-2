#include "InformacionGenetica.h"

InformacionGenetica::InformacionGenetica(std::string bits){

	this->infoGenetica = bits;
}

InformacionGenetica:: InformacionGenetica(){

	this->infoGenetica = '0';
}

bool InformacionGenetica::esIgualA(InformacionGenetica* otra){

	return (this->infoGenetica == otra->infoGenetica);

}

void InformacionGenetica::combinarCon(InformacionGenetica* otra){

	unsigned int longitudCadena = this->contarBits();
	unsigned int longitudCadenaOtra = otra->contarBits();


	if (longitudCadena > longitudCadenaOtra){
		for (unsigned int i = 0; i < (longitudCadena - longitudCadenaOtra); ++i ){
			otra->anadirCeroPorderecha();
		}
	}
	else if (longitudCadena < longitudCadenaOtra){
		for (unsigned int i = 0; i < (longitudCadenaOtra - longitudCadena); ++i ){
			this->anadirCeroPorderecha();
		}
	}

	longitudCadena = this->obtenerInfoGenetica().length();

	for (unsigned int i = 0; i < longitudCadena; ++i){
		if ((this->obtenerInfoGenetica()[i] == '1' && otra->obtenerInfoGenetica()[i] == '0')
			|| (this->obtenerInfoGenetica()[i] == '0' && otra->obtenerInfoGenetica()[i] == '1')){
			this->guardarDigitoEnlaPosicion('1',i);
		}
		else{
			this->guardarDigitoEnlaPosicion('0',i);
		}
	}
}

bool InformacionGenetica::estaEncendidoBit(unsigned int i){
	return (this->obtenerInfoGenetica()[this->contarBits()-i] == '1');
}

unsigned int InformacionGenetica::contarBits(){
	return (this->infoGenetica.size());
}

std::string InformacionGenetica::obtenerInfoGenetica(){
	return this->infoGenetica;
}

void InformacionGenetica::anadirCeroPorderecha (){
	this->infoGenetica.insert(0,"0");
}

void InformacionGenetica::guardarDigitoEnlaPosicion
						(char digito, unsigned int posicion){
	this->infoGenetica[posicion] = digito;
}

unsigned int InformacionGenetica::hallarMaximo
					(unsigned int primerNumero, unsigned int segundoNumero){
	return (primerNumero >= segundoNumero) ? primerNumero : segundoNumero;
}
