#include "Tablero.h"

using namespace std;

Tablero::Tablero(int filas, int columnas, int numeroDeTurno)   {
	this->columnas = columnas;
	this->filas = filas;
	this->numeroDeTurno = numeroDeTurno;
	this->genEnSeguimiento = "2";
}
Tablero::Tablero(string RutaDeArchivo)   {
	string line;
	ifstream archivo(RutaDeArchivo);

	if (archivo.is_open())	{

		while ( getline(archivo,line) )
		{
			cargarEstructuraDeArchivo(line);
		}
		archivo.close();
	}
	else cout << "No se pudo acceder al archivo.";

	this->genEnSeguimiento = "2";
}

void Tablero::cargarEstructuraDeArchivo(string linea) {
	int contador = (sizeof(this->objetos)/sizeof(this->objetos[0]))-1;
	int objetoEncontrado;

	do {
		objetoEncontrado = linea.find(this->objetos[contador]);
		if (objetoEncontrado >= 0)	{
			cargarObjeto(linea, (idObjetos)contador);
		}
		contador--;
	} while (contador >= 0 && objetoEncontrado < 0);
}

void Tablero::seguimientoDeGen()	{
	string genEnSeguimiento;
	if (celulaManager.hayGenEnSeguimiento())	{
		celulaManager.setGenEnSeguimiento("");
		cout<<"Se ha cancelado el seguimiento del gen."<<endl;
	}
	else	{
		cout<<"Ingrese el gen a hacer seguimiento: ";
		cin>>genEnSeguimiento;
		celulaManager.setGenEnSeguimiento(genEnSeguimiento);
	}
}

void Tablero::cargarObjeto(string linea, idObjetos idObjeto){
	int datos[2];
	string strDatos[2];

	switch(idObjeto)	{
	case TABLERO:
		obtenerDatos(linea, datos);
		setearDimensiones(datos[0], datos[1]);
		break;
	case CELULA:
		obtenerDatos(linea, datos);
		cargarCelula(datos[0], datos[1]);
		break;
	case GEN:
		obtenerDatos(linea, strDatos);
		cargarGenEnUltimaCelula(strDatos[0], stoi(strDatos[1]));
		break;
	case FIN:
		break;
	default:

		break;
	}
}

void Tablero::siguienteTurno() {
	this->celulaManager.siguienteTurno();
	this->numeroDeTurno++;
}

void Tablero::cargarGenEnUltimaCelula(string infoGenetica, short intensidad) {
	if (!this->celulaManager.cargarGenEnUltimaCelula(infoGenetica, intensidad))
		cout<<"El gen no pudo ser insertado en la celula "<<this->celulaManager.getUltimaCelulaString()<<endl;
}

void Tablero::obtenerDatos(string line, int *datos)	{
	string strDato, strDato2, nums;
	int idEspacio;

	idEspacio = line.find(" ");

	nums = line.substr(idEspacio+1, line.length());

	idEspacio = nums.find(" ");

	strDato = nums.substr(0, idEspacio);
	strDato2 = nums.substr(idEspacio+1, nums.length());

	*datos = stoi(strDato2);
	*(datos+1) = stoi(strDato);
}

void Tablero::obtenerDatos(string line, string *datos)	{
	string nums;
	int idEspacio;

	idEspacio = line.find(" ");

	nums = line.substr(idEspacio+1, line.length());

	idEspacio = nums.find(" ");

	*datos = nums.substr(0, idEspacio);
	*(datos+1) = nums.substr(idEspacio+1, nums.length());
}

void Tablero::cargarCelula(unsigned int fila, unsigned int columna) {
	if (!this->celulaManager.cargarCelula(fila, columna)){
		cout<<"La celula ya existe en esta posicion ["<<fila<<", "<<columna<<"]";
	}
}

void Tablero::setearDimensiones(unsigned int filas, unsigned int columnas)	{
	this->columnas = columnas;
	this->filas = filas;

	celulaManager.setDimensiones(filas, columnas);
}

void Tablero::mostrarTablero()	{
	for (unsigned int columna=1;columna <= this->columnas;columna++)	{
		for (unsigned int fila=1;fila <= this->filas;fila++)	{
			if (this->celulaManager.getCelulaViva(fila, columna))
				cout<<"|O";
			else cout<<"|-";
		}
		cout<<endl;
	}
	mostrarEstadisticas();
}

int Tablero::getNumeroDeTurno()	{
	return this->numeroDeTurno;
}

void Tablero::mostrarEstadisticas()	{
	cout<<endl<<"Turno numero:"<<getNumeroDeTurno()<<endl;
	cout<<"Celulas vivas: "<<celulaManager.getNumeroDeCelulasVivas()<<endl;
	cout<<"Celulas recien nacidas: "<<celulaManager.getNumeroDeCelulasRecienNacidas()<<endl;
	//cout<<"Celulas recien fallecidas: "<<celulaManager.getNumeroDeCelulasVivas()<<endl;
}

Tablero::Tablero()   {
	setearDimensiones(0, 0);
	this->numeroDeTurno = 0;
}

Tablero::~Tablero() {

}
