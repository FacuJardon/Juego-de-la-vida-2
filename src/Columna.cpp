/*
 * Columna.cpp
 *
 *  Created on: 16 dic. 2020
 *      Author: Facu
 */


#include "Columna.h"

using namespace std;

unsigned int Columna::getNumeroDeColumna() {
	return this->numeroDeColumna;
}

void Columna::agregarCelula() {
	this->celula->setCelulaViva(true);
}

unsigned int Columna::getCelulaVivas()	{
	return this->celula->celulaViva()? 1 : 0;
}

Columna::Columna(unsigned int numeroDeColumna, bool estadoDeCelula) {
	this->numeroDeColumna = numeroDeColumna;
	this->celula = new Celula(estadoDeCelula);
}

Columna::Columna() {
	this->numeroDeColumna = 0;
	this->celula = NULL;
}

void Columna::setGenEnCelula(string infoGenetica, short intensidad)	{
	this->celula->setGen(infoGenetica, intensidad);
}

Lista<Gen*>* Columna::obtenerGenesDeCelula()	{
	return this->celula->obtenerGenes();
}

void Columna::aumentarEdadDeGenes()	{
	this->celula->aumentarEdadDeGenes();
}
