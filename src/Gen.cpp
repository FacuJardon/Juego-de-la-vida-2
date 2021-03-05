/*
 * Gen.cpp
 *
 *  Created on: 19 dic. 2020
 *      Author: Facu
 */


#include "Gen.h"

using namespace std;

void Gen::aumentarEdad()	{
	this->edad++;
}

Gen::~Gen()	{
	delete this->informacionGenetica;
}

Gen::Gen(string informacionGenetica, short intensidad) {
	this->edad = 0;
	this->informacionGenetica = new InformacionGenetica(informacionGenetica);
	this->intensidad = intensidad;
}

InformacionGenetica* Gen::getCargaGenetica()	{
	return this->informacionGenetica;
}

string Gen::getInformacionGenetica()	{
	return this->informacionGenetica->obtenerInfoGenetica();
}

int Gen::getIntensidad()	{
	return this->intensidad;
}

int Gen::getEdad()	{
	return this->edad;
}
