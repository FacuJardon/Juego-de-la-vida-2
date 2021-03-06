/*
 * CelulaManager.h
 *
 *  Created on: 16 dic. 2020
 *      Author: Facu
 */

#ifndef CELULAMANAGER_H_
#define CELULAMANAGER_H_


#include "Lista.h"
#include "Fila.h"

//#include <iostream>	//BORRAR

class CelulaManager {
private:
	unsigned int  ultimaCelulaCargada[2];
	Lista<Fila*>* filas;
	unsigned int  filasMaximas;
	unsigned int  columnasMaximas;
	unsigned int  celulasRecienNacidas;
	std::string genEnSeguimiento;

	int calcularCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int filas, unsigned int columnas);

	void setCelulaSiguienteEstado(Lista<Fila*> *nuevasFilas, unsigned int fila, unsigned int columna, int celulasVecinas);

	bool agregarCelula(Lista<Fila*> *filas, unsigned int fila, unsigned int  columna);

	void actualizarGenes(Lista<Fila*> *nuevasFilas, unsigned int fila, unsigned int columna);

	Lista<Gen*>* getGenesVecinos(unsigned int fila, unsigned int columna);

	Lista<Gen*>* getGenes(unsigned int fila, unsigned int columna);

	bool agregarCelula(unsigned int fila, unsigned int  columna);
	Centoya
    unsigned int getColumnas();

    unsigned int getFilas();

	bool posicionValida(unsigned int fila,unsigned int columna);

	Lista<Gen*>* getGenesFinal(Lista<Gen*>* genes);

	Gen* getGenTransferencia(Lista<Gen*>* genesComparando);

	int getIntensidadDosGenesVecinos(int *intensidades, int *edades);

	int getIntensidadTresGenesVecinos(int *intensidades, int *edades);

	void agregarGenesEnNuevaFila(unsigned int columna, Lista<Gen*>* genes, Fila* fila);

	void borrarFilas(Lista<Fila*>* filasABorrar);

	void aumentarCelulasRecienNacidas();

	void reiniciarEstadisticas();

	void generarNuevasFilas();
public:
	unsigned int getNumeroDeCelulasRecienNacidas();

	unsigned int getNumeroDeCelulasVivas();

	bool hayGenEnSeguimiento();

	void setGenEnSeguimiento(std::string gen);

	void setDimensiones(unsigned int filas, unsigned int columnas);

	bool cargarCelula(unsigned int fila, unsigned int columna);

	bool getCelulaViva(unsigned int fila, unsigned int columna);

	bool cargarGenEnUltimaCelula(std::string infoGenetica, short intensidad);

	void setUltimaCelulaCargada(unsigned int fila, unsigned int columna);

	std::string getUltimaCelulaString();

	void siguienteTurno();

	~CelulaManager();

	CelulaManager();
};



#endif /* CELULAMANAGER_H_ */
