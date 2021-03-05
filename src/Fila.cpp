/*
 * Fila.cpp
 *
 *  Created on: 16 dic. 2020
 *      Author: Facu
 */

#include "Fila.h"
using namespace std;

unsigned int Fila::getNumeroDeFila() {
	return this->numeroDeFila;
}


bool Fila::agregarCelula(unsigned int columna) {

	bool posicionado = false;
	unsigned int numeroNodoApuntado = 0;
	unsigned int numeroDeColumnaApuntada = 0;
	Columna *columnaAuxiliar;
	this->columna->iniciarCursor();

	while (this->columna->avanzarCursor() && !posicionado)	{
		numeroNodoApuntado++;
		columnaAuxiliar = this->columna->obtenerCursor();
		numeroDeColumnaApuntada = columnaAuxiliar->getNumeroDeColumna();

		if (columna == numeroDeColumnaApuntada) {

			columnaAuxiliar->agregarCelula();
			posicionado = true;

		}	else if (columna < numeroDeColumnaApuntada)	{

			Columna *nuevaColumna = new Columna(columna, true);
			this->columna->agregar(nuevaColumna, numeroNodoApuntado);
			posicionado = true;
		}
	}
	if (!posicionado)	{
		Columna *nuevaColumna = new Columna(columna, true);
		this->columna->agregar(nuevaColumna);
		posicionado = true;
	}
	return posicionado;
}

bool Fila::getCelulaViva(unsigned int columna)	{
	bool encontrado = false;
	unsigned int numeroDeColumnaApuntado = 0;
	Columna *columnaAuxiliar;
	this->columna->iniciarCursor();

	while (this->columna->avanzarCursor() && !encontrado && numeroDeColumnaApuntado<=columna)	{
		columnaAuxiliar = this->columna->obtenerCursor();
		numeroDeColumnaApuntado= columnaAuxiliar->getNumeroDeColumna();

		if (columna == numeroDeColumnaApuntado) {
			encontrado = true;
		}
	}

	return encontrado;
}
bool Fila::agregarGen(unsigned int columna, string infoGenetica, short intensidad)	{
	bool encontrado = false;
	unsigned int numeroDeColumnaApuntado = 0;
	Columna *columnaAuxiliar;
	this->columna->iniciarCursor();

	while (this->columna->avanzarCursor() && !encontrado && columna >= numeroDeColumnaApuntado)	{
		columnaAuxiliar = this->columna->obtenerCursor();
		numeroDeColumnaApuntado = columnaAuxiliar->getNumeroDeColumna();

		if (columna == numeroDeColumnaApuntado) {
			columnaAuxiliar->setGenEnCelula(infoGenetica, intensidad);
			encontrado = true;
		}
	}

	return encontrado;
}

Lista<Gen*>* Fila::obtenerGenesDeCelula(unsigned int columna)	{

	bool encontrado = false;
	unsigned int numeroDeColumnaApuntado = 0;
	Columna *columnaAuxiliar;
	this->columna->iniciarCursor();

	while (this->columna->avanzarCursor() && !encontrado && columna >= numeroDeColumnaApuntado)	{
		columnaAuxiliar = this->columna->obtenerCursor();
		numeroDeColumnaApuntado = columnaAuxiliar->getNumeroDeColumna();

		if (columna == numeroDeColumnaApuntado) {
			return columnaAuxiliar->obtenerGenesDeCelula();
		}
	}
	return NULL;
}

Fila::Fila(unsigned int numeroDeFila)	{
	this->numeroDeFila = numeroDeFila;
	this->columna = new Lista<Columna*>;
}

Fila::~Fila() {
    this->columna->iniciarCursor();
    while (this->columna->avanzarCursor()){
        Columna* aEliminar=this->columna->obtenerCursor();
        delete aEliminar;
    }

    delete this->columna;
}

















