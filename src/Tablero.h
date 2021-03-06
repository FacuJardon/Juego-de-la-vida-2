#ifndef TABLERO_H_
#define TABLERO_H_
#include <iostream>
#include <string>
#include <fstream>
#include "Lista.h"
#include "CelulaManager.h"

class Tablero {

private:
	enum idObjetos{
		TABLERO = 0,
		CELULA,
		GEN,
		FIN
	};
	std::string objetos[4] = {
			"tablero",
			"celula",
			"gen",
			"fin"
	};

	unsigned int filas;
	unsigned int columnas;
    unsigned int numeroDeTurno;
    std::string genEnSeguimiento;
	CelulaManager celulaManager;

    void obtenerDatos(std::string line, std::string *datos);

    void obtenerDatos(std::string line, int *datos);

    void recorrerArchivo(std::ifstream archivo);

    void cargarEstructuraDeArchivo(std::string linea);

    void cargarObjeto(std::string linea, idObjetos idObjeto);

    void setearDimensiones(unsigned int filas, unsigned int columnas);

    void cargarCelula(unsigned int filas, unsigned int columnas);

    void cargarGenEnUltimaCelula(std::string infoGenetica, short intensidad);

    bool hayGenEnSeguimiento();

    void setGenEnSeguimiento(std::string gen);

    void mostrarEstadisticas();

    unsigned int getNumeroDeTurno();

    void iniciarAtributosPrimitivos();

    unsigned int getPromedioDeCelulasNacidasPorTurno();

    unsigned int getPromedioDeCelulasFallecidasPorTurno();

    void procesarArchivo(std::string RutaDeArchivo);

public:

    /*
     *	Post:  Habilita/Desabilita el seguimiento de un gen indicado.
     */
    void seguimientoDeGen();
    /*
	 *	Post: Avanza un turno el tablero y con ello evoluciona la estructura interna.
	 */
    void siguienteTurno();
    /*
     *	Post: Muestra en consola el tablero.
     */
    void mostrarTablero();
    /*
     *	Postcondicion: Devuelve true si la fila y columna estan dentro de las dimensiones del tablero.
     */
    bool posicionValida(unsigned int fila,unsigned int columna);
    /*
     *	Postcondicion: Se crea un tablero de juego con las dimensiones pasadas por parametro.
     */
    Tablero(int filas, int columnas, int numeroDeTurno);

    /*
     *	Postcondicion: Se crea un tablero de juego segun el archivo de entrada especificado.
     */
    Tablero(std::string RutaDeArchivo);

    /*
     *	Postcondicion: Se crea un tablero de juego que debe inicializarse mas tarde.
     */
    Tablero();

	virtual ~Tablero();
};

#endif /* TABLERO_H_ */
