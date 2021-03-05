/*
 * InformacionGenetica.h
 *
 *  Created on: 11 dic. 2020
 *      Author: Facu
 */

#ifndef INFORMACIONGENETICA_H_
#define INFORMACIONGENETICA_H_
#include <string>

/* La Informacion Genetica est� conformada por una
* secuencia de bits.
* Un bit es la m�nima expresi�n de informaci�n,
* que puede tomar dos �nicos valores posibles: 0/1,
* apagado/encendido o desactivado/activado.
*/
class InformacionGenetica {

private:
	std::string infoGenetica;

public:

	/* pre : 'bits' es una secuencia de 1 y 0.
	* post: la instancia creada representa la
	* informaci�n dada en 'bits'.
	*/
	InformacionGenetica(std::string bits);

	/* post: la instancia creada representa la
	* informaci�n dada por un bit: 0.
	*/
	InformacionGenetica();

	/* post : indica si la instancia y 'otra'
	* representan la misma secuencia de
	* bits, es decir si son iguales.
	*/
	bool esIgualA(InformacionGenetica* otra);

	/* post: combina la secuencia de bits de la
	* instancia con la secuencia bits de
	* 'otra', aplicando un OR bit a bit.
	*/
	void combinarCon(InformacionGenetica* otra);

	/* post: indica si el valor del 'i'-�simo bit
	* es 1, numer�ndolos de derecha a
	* izquierda a partir de 1.
	*/
	bool estaEncendidoBit(unsigned int i);

	/* post: devuelve cantidad de bits que tiene
	* la instancia.
	*/
	unsigned int contarBits();

	/*pre:
	 * post; devuelve un string que representa la informacion genetica
	 */
	std::string obtenerInfoGenetica();

private:

	/*
	 * pre:
	 * post: Aniade un 0 por izquierda en la informacion genetica, todos los otros
	 * digitos son desplazado a derecha.
	 */
	void anadirCeroPorderecha ();

	/*
	 * pre:
	 * post: Almacenado el 'digito' en la posicion 'posicion' de informacion genetica,
	 * contando de izquierda a derecha, siendo el rango valido [0..contarBits())
	 */
	void guardarDigitoEnlaPosicion (char digito, unsigned int posicion);

	/*
	 * pre:
	 * post: Devuelve el valor maximo entre dos numeros del tipo indicado.
	 */
	unsigned int hallarMaximo(unsigned int primerNumero, unsigned int segundoNumero);
};



#endif /* INFORMACIONGENETICA_H_ */
