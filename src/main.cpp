#include <iostream>
#include <string.h>
#include "Tablero.h"


enum OPCIONES	{
	SiguienteTurno = 1,
	SeguimientoDeGen,
	ReiniciarJuego,
	TerminarJuego
};

OPCIONES seleccionarOpcion();
void realizarAccion(Tablero *tablero, OPCIONES opcion);

int main(int argc, char const *argv[])
{
	std::string rutaDeArchivo = "/home/facu/eclipse-workspace/Juego de la vida 2.0/input/input.txt";
/*
	std::cout<<"Ingresa la ruta al archivo de ingreso de datos: ";
	cin>>rutaDeArchivo;
*/
	Tablero *tablero = new Tablero(rutaDeArchivo);
	OPCIONES opcion;

	do {
		tablero->mostrarTablero();

		opcion = seleccionarOpcion();

		realizarAccion(tablero, opcion);

	}
	while (opcion == SiguienteTurno);

	return 0;
}


OPCIONES seleccionarOpcion()	{
	int opcion = 0;

	do {
		std::cout<<std::endl<<"Seleccione la proxima accion."<<std::endl;
		std::cout<<"1) Siguiente turno."<<std::endl;
		std::cout<<"2) Comenzar/Terminar seguimiento de Gen."<<std::endl;
		std::cout<<"3) Reiniciar el juego."<<std::endl;
		std::cout<<"4) Terminar juego."<<std::endl;

		std::cin>>opcion;
	}
	while(opcion < 1 || opcion > 4);

	return (OPCIONES)opcion;
}


void realizarAccion(Tablero* tablero, OPCIONES opcion)	{
	switch(opcion)	{
	case SiguienteTurno:
		tablero->siguienteTurno();
		break;
	case SeguimientoDeGen:
		tablero->seguimientoDeGen();
		break;
	default: return;
	}
}
