/*
 * Celula.h
 *
 *  Created on: 11 dic. 2020
 *      Author: Facu
 */

#ifndef CELULA_H_
#define CELULA_H_

#include "Gen.h"
#include "Lista.h"


class Celula	{
private:
	Lista<Gen*>* genes;
	bool estaViva;
public:
	bool celulaViva();

	bool existeGen(std::string infoGenetica);

	void setCelulaViva(bool estadoDeCelula);

	bool getCelulaViva();

	Lista<Gen*>* obtenerGenes();

	void setGen(std::string infoGenetica, short intensidad);

	void aumentarEdadDeGenes();

	Celula(bool estado);

	~Celula();
};


#endif /* CELULA_H_ */
