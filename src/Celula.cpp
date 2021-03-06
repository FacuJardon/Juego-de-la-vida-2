/*
 * Celula.cpp
 *
 *  Created on: 16 dic. 2020
 *      Author: Facu
 */

#include "Celula.h"

using namespace std;

Celula::Celula(bool estado)	{
	this->estaViva = estado;
	this->genes = new Lista<Gen*>;
}

void Celula::setCelulaViva(bool estadoDeCelula) {
	this->estaViva = estadoDeCelula;
}

bool Celula::celulaViva()	{
	return this->estaViva;
}

Lista<Gen*>* Celula::obtenerGenes() {
	return this->genes;
}

void Celula::setGen(string infoGenetica, short intensidad)	{
	if (!existeGen(infoGenetica))	{
		Gen *gen = new Gen(infoGenetica, intensidad);
		this->genes->agregar(gen);
	}
}

bool Celula::existeGen(string infoGenetica)	{
	bool encontrado = false;
	string infoGeneticaApuntada;
	Gen *genApuntado;
	this->genes->iniciarCursor();

	while (this->genes->avanzarCursor() && !encontrado)	{
		genApuntado = this->genes->obtenerCursor();
		infoGeneticaApuntada = genApuntado->getInformacionGenetica();
		if (infoGeneticaApuntada == infoGenetica)
			encontrado = true;
	}
	return encontrado;
}

void Celula::aumentarEdadDeGenes()	{
	Gen *genApuntado;
	this->genes->iniciarCursor();

	while (this->genes->avanzarCursor())	{
		genApuntado = this->genes->obtenerCursor();
		genApuntado->aumentarEdad();
	}
}

Celula::~Celula() {
    this->genes->iniciarCursor();
    while (this->genes->avanzarCursor()){
        Gen* aEliminar=this->genes->obtenerCursor();
        delete aEliminar;
    }
}
