/*
 * CelulaManager.cpp
 *
 *  Created on: 16 dic. 2020
 *      Author: Facu
 */

#include "CelulaManager.h"
using namespace std;

void CelulaManager::setDimensiones(unsigned int filas, unsigned int columnas)	{
	this->columnasMaximas = columnas;
	this->filasMaximas = filas;
}

bool CelulaManager::cargarCelula(unsigned int fila, unsigned int columna) {
	if (posicionValida(fila, columna))	{
		if (!agregarCelula(fila, columna))	{
			return false;
		}	else	setUltimaCelulaCargada(fila, columna);
	}
	return true;
}

bool CelulaManager::posicionValida(unsigned int fila,unsigned int columna)	{
	return fila <= getFilas() && columna <= getColumnas();
}

unsigned int CelulaManager::getFilas()	{
	return this->filasMaximas;
}
unsigned int CelulaManager::getColumnas()	{
	return this->columnasMaximas;
}

bool CelulaManager::agregarCelula(unsigned int fila, unsigned int  columna) {
	return agregarCelula(this->filas, fila, columna);
}

bool CelulaManager::agregarCelula(Lista<Fila*> *filas, unsigned int fila, unsigned int  columna) {
	bool posicionado = false;
	unsigned int numeroNodoApuntado = 0;
	unsigned int numeroDeFilaApuntado = 0;
	Fila *filaAuxiliar;
	filas->iniciarCursor();

	while (filas->avanzarCursor() && !posicionado)	{
		numeroNodoApuntado++;
		filaAuxiliar = filas->obtenerCursor();
		numeroDeFilaApuntado = filaAuxiliar->getNumeroDeFila();

		if (fila == numeroDeFilaApuntado) {
			if (filaAuxiliar->agregarCelula(columna))
				posicionado = true;
		}	else if (fila < numeroDeFilaApuntado)	{

			Fila *nuevaFila = new Fila(fila);
			filas->agregar(nuevaFila, numeroNodoApuntado);

			posicionado = agregarCelula(filas, fila, columna);
		}
	}
	if (!posicionado)	{
		Fila *nuevaFila = new Fila(fila);
		filas->agregar(nuevaFila);

		posicionado = agregarCelula(filas, fila, columna);
	}
	return posicionado;
}
bool CelulaManager::getCelulaViva(unsigned int fila, unsigned int columna) {
	bool encontrado = false;
	unsigned int numeroDeFilaApuntado = 0;
	Fila *filaAuxiliar;
	this->filas->iniciarCursor();

	while (this->filas->avanzarCursor() && !encontrado && numeroDeFilaApuntado<=fila)	{
		filaAuxiliar = this->filas->obtenerCursor();
		numeroDeFilaApuntado = filaAuxiliar->getNumeroDeFila();

		if (fila == numeroDeFilaApuntado) {
			encontrado = filaAuxiliar->getCelulaViva(columna);
		}
	}

	return encontrado;
}

void CelulaManager::setUltimaCelulaCargada(unsigned int fila, unsigned int columna)	{
	this->ultimaCelulaCargada[0] = fila;
	this->ultimaCelulaCargada[1] = columna;
}

bool CelulaManager::cargarGenEnUltimaCelula(string infoGenetica, short intensidad)	{
	bool posicionado = false;
	unsigned int numeroNodoApuntado = 0;
	unsigned int numeroDeFilaApuntado = 0;
	Fila *filaAuxiliar;
	this->filas->iniciarCursor();

	while (this->filas->avanzarCursor() && !posicionado && this->ultimaCelulaCargada[0] >= numeroDeFilaApuntado)	{
		numeroNodoApuntado++;
		filaAuxiliar = this->filas->obtenerCursor();
		numeroDeFilaApuntado = filaAuxiliar->getNumeroDeFila();

		if (this->ultimaCelulaCargada[0] == numeroDeFilaApuntado) {
			if (filaAuxiliar->agregarGen(this->ultimaCelulaCargada[1], infoGenetica, intensidad))
				posicionado = true;
		}
	}

	return posicionado;
}
unsigned int getNumeroDeCelulasVivas()	{

}
void CelulaManager::siguienteTurno() {
	Lista<Fila*> *nuevasFilas = new Lista<Fila*>();
	Lista<Fila*> *filasABorrar;
	int celulasVecinas = 0;

	for (unsigned int fila = 1;fila<=getFilas();fila++)	{
		for (unsigned int columna = 1;columna<=getColumnas();columna++)	{
			celulasVecinas = calcularCelulasVecinas(fila, columna, filasMaximas, columnasMaximas);
			setCelulaSiguienteEstado(nuevasFilas, fila, columna, celulasVecinas);
		}
	}
	filasABorrar = this->filas;
	this->filas = nuevasFilas;
	borrarFilas(filasABorrar);
}
void CelulaManager::borrarFilas(Lista<Fila*>* filasABorrar)	{
	filasABorrar->iniciarCursor();
    while (filasABorrar->avanzarCursor()){
        Fila* aEliminar=filasABorrar->obtenerCursor();
        delete aEliminar;
    }

    delete filasABorrar;
}

int CelulaManager::calcularCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int filasMaximas, unsigned int columnasMaximas)	{
	int celulasVecinas = 0;
	for (int c = -1;c<=1;c++)	{
		for (int f = -1;f<=1;f++)	{

			if (f == c && c == 0)	{
				continue;
			}

			else if (fila+f>filasMaximas || columna+c>columnasMaximas)	{
				continue;
			}

			else if (fila+f<1 || columna+c<1){
				continue;
			}

			else if (getCelulaViva(fila+f, columna+c))	{
				celulasVecinas++;
			}
		}
	}
	return celulasVecinas;
}

void CelulaManager::setCelulaSiguienteEstado(Lista<Fila*> *nuevasFilas, unsigned int fila, unsigned int columna, int celulasVecinas)	{
	bool celulaViva = this->getCelulaViva(fila, columna);
	if ( celulasVecinas == 3 || (celulaViva && celulasVecinas == 2))	{
		agregarCelula(nuevasFilas, fila, columna);
		this->ultimaCelulaCargada[0] = fila;
		this->ultimaCelulaCargada[1] = columna;

		if (!celulaViva)
			actualizarGenes(nuevasFilas, fila, columna);
	}
}

void CelulaManager::actualizarGenes(Lista<Fila*> *nuevasFilas, unsigned int fila, unsigned int columna)	{
	unsigned int numeroDeFilaApuntado = 0;
	Fila *filaAuxiliar;
	Lista<Gen*>* genesVecinos;
	Lista<Gen*>* genesFinales;

	nuevasFilas->iniciarCursor();

	while (nuevasFilas->avanzarCursor() && this->ultimaCelulaCargada[0] >= numeroDeFilaApuntado)	{
		filaAuxiliar = nuevasFilas->obtenerCursor();
		numeroDeFilaApuntado = filaAuxiliar->getNumeroDeFila();

		if (this->ultimaCelulaCargada[0] == fila)	{
			genesVecinos = getGenesVecinos(fila, columna);
			genesFinales = getGenesFinal(genesVecinos);

			agregarGenesEnNuevaFila(columna, genesFinales, filaAuxiliar);

			delete genesFinales;
			delete genesVecinos;
		}
	}
}
void CelulaManager::agregarGenesEnNuevaFila(unsigned int columna, Lista<Gen*>* genes, Fila* fila)	{
	Gen* genActual;

	for (unsigned int i = 1;i <= genes->contarElementos();i++){
		genActual = genes->obtener(i);
		fila->agregarGen(columna, genActual->getInformacionGenetica(), genActual->getIntensidad());
	}
}

Lista<Gen*>* CelulaManager::getGenesFinal(Lista<Gen*>* genes)	{
	Lista<Gen*>* genesFinal = new Lista<Gen*>;
	Lista<Gen*>* genesComparando = new Lista<Gen*>;
	Gen *genAComparar, *genAux;
	InformacionGenetica *infoGeneticaAComparar, *infoGeneticaAux;

	for (unsigned int genIdAComparar = 1;genIdAComparar <= genes->contarElementos();genIdAComparar++)	{
		genAComparar = genes->obtener(genIdAComparar);
		infoGeneticaAComparar = genAComparar->getCargaGenetica();

		genes->iniciarCursor();

		while (genes->avanzarCursor())	{
				genAux = genes->obtenerCursor();
				infoGeneticaAux = genAux->getCargaGenetica();
				if (infoGeneticaAComparar->esIgualA(infoGeneticaAux))	{
					genesComparando->agregar(genAux);
			}
		}
		genesFinal->agregar(getGenTransferencia(genesComparando));
	}
	delete genesComparando;
	return genesFinal;
}

Gen* CelulaManager::getGenTransferencia(Lista<Gen*>* genesComparando)	{
	Gen* genAux;
	int intensidad = 0;
	int intensidades[3];
	int edades[3];
	string infoGenetica;
	unsigned int cantidad = genesComparando->contarElementos();

	genAux = genesComparando->obtener(1);
	infoGenetica = genAux->getInformacionGenetica();

	for (unsigned int i = 1;i <= cantidad;i++)	{
		genAux = genesComparando->obtener(i);
		intensidades[i-1] = genAux->getIntensidad();
		edades[i-1] = genAux->getEdad();
	}

	switch(cantidad)	{
		case 1: intensidad = 0;
		break;
		case 2:	intensidad = getIntensidadDosGenesVecinos(intensidades, edades);
		break;
		case 3:	intensidad = getIntensidadTresGenesVecinos(intensidades, edades);
	}

	Gen* asd = new Gen(infoGenetica, intensidad);
	return asd;
}
int CelulaManager::getIntensidadDosGenesVecinos(int *intensidades, int *edades)	{
	int intensidad = 0;

	if (intensidades[0] == 0 && intensidades[1] == 0)
		intensidad = ((edades[0]+edades[1])/2)+1;
	else if(intensidades[0] > 0 && intensidades[1] > 0)
		intensidad = (intensidades[0]+intensidades[1])/2;
	else intensidad = intensidades[0]+intensidades[1];

	return intensidad;
}

int CelulaManager::getIntensidadTresGenesVecinos(int *intensidades, int *edades)	{
	int intensidad = 0;

	if (intensidades[0] == 0 && intensidades[1] == 0 && intensidades[2] == 0)
		intensidad = ((edades[0]+edades[1])/2)+1;
	else {
		intensidad = max(intensidades[0], intensidades[1]);
		intensidad = max(intensidad, intensidades[2]);
	}

	return intensidad;
}

Lista<Gen*>* CelulaManager::getGenesVecinos(unsigned int fila, unsigned int columna)	{
	Lista<Gen*>* genesVecinos = new Lista<Gen*>;

	for (int c = -1;c<=1;c++)	{
		for (int f = -1;f<=1;f++)	{
			if (f == c && c == 0)	{
				continue;
			}
			else if (fila+f>getFilas() || columna+c>getColumnas())	{
				continue;
			}
			else if (fila+f<1 || columna+c<1){
				continue;
			}
			else if (getCelulaViva(fila+f, columna+c))	{
				genesVecinos->agregar(*(getGenes(fila+f,columna+c)));
			}
		}
	}
	return genesVecinos;
}
Lista<Gen*>* CelulaManager::getGenes(unsigned int fila, unsigned int columna)	{
	unsigned int numeroDeFilaApuntado = 0;
	Fila *filaAuxiliar;

	filas->iniciarCursor();
	while (filas->avanzarCursor() && fila >= numeroDeFilaApuntado)	{
		filaAuxiliar = filas->obtenerCursor();
		numeroDeFilaApuntado = filaAuxiliar->getNumeroDeFila();

		if (numeroDeFilaApuntado == fila)	{
			return filaAuxiliar->obtenerGenesDeCelula(columna);
		}
	}
	return NULL;
}
void CelulaManager::setGenEnSeguimiento(string gen)	{
	this->genEnSeguimiento = gen;
}
bool CelulaManager::hayGenEnSeguimiento()	{
	return this->genEnSeguimiento.length() != 0;
}

string CelulaManager::getUltimaCelulaString()	{
	string str = "[" + to_string(this->ultimaCelulaCargada[0]) + "," + to_string(this->ultimaCelulaCargada[1])+ "]";
	return str;
}
CelulaManager::CelulaManager() {
	this->filas = new Lista<Fila*>();
	this->ultimaCelulaCargada[0] = 0;
	this->ultimaCelulaCargada[1] = 0;
	this->columnasMaximas = 0;
	this->filasMaximas = 0;
	this->genEnSeguimiento = "";
}

CelulaManager::~CelulaManager()	{
    this->filas->iniciarCursor();
    while (this->filas->avanzarCursor()){
        Fila* aEliminar=this->filas->obtenerCursor();
        delete aEliminar;
    }

    delete this->filas;
}
