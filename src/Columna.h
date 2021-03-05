/*
 * Columna.h
 *
 *  Created on: 16 dic. 2020
 *      Author: Facu
 */

#ifndef COLUMNA_H_
#define COLUMNA_H_

#include "Lista.h"
#include "Celula.h"
#include "Gen.h"

class Columna {
private:
	int numeroDeColumna;
	Celula* celula;

public:
	void aumentarEdadDeGenes();

	unsigned int getNumeroDeColumna();

	void agregarCelula();

	void setGenEnCelula(std::string infoGenetica, short intensidad);

	Lista<Gen*>* obtenerGenesDeCelula();

	Columna(unsigned int numeroDeColumna, bool estadoDeCelula);

	Columna();
};


#endif /* COLUMNA_H_ */
