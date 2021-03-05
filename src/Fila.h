/*
 * Fila.h
 *
 *  Created on: 16 dic. 2020
 *      Author: Facu
 */

#ifndef FILA_H_
#define FILA_H_

#include "Lista.h"
#include "Columna.h"
#include "Celula.h"
#include "Gen.h"

class Fila {
private:
	Lista<Columna*> *columna;
	int numeroDeFila;
public:
	Fila();
	Fila(unsigned int numeroDeFila);

	unsigned int getNumeroDeFila();

	bool agregarCelula(unsigned int columna);

	bool getCelulaViva(unsigned int columna);

	bool agregarGen(unsigned int columna, std::string infoGenetica, short intensidad);

	Lista<Gen*>* obtenerGenesDeCelula(unsigned int columna);

	~Fila();
};



#endif /* FILA_H_ */
