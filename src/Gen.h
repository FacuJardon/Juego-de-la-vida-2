/*
 * Gen.h
 *
 *  Created on: 11 dic. 2020
 *      Author: Facu
 */

#ifndef GEN_H_
#define GEN_H_

#include <string>
#include "InformacionGenetica.h"

class Gen {
private:
	int edad;
	int intensidad;
	InformacionGenetica* informacionGenetica;
public:
	Gen(std::string informacionGenetica, short intensidad);

	~Gen();

	void aumentarEdad();

	int getIntensidad();

	int getEdad();

	InformacionGenetica *getCargaGenetica();

	std::string getInformacionGenetica();
};


#endif /* GEN_H_ */
