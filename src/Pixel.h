#ifndef Pixel_h
#define Pixel_h

#include <stdio.h>
#include <iostream>

/** 
	@brief La classe Pixel contient les couleurs rouge, vert et bleue
*/
class Pixel
{
private:
	/** @brief Déclaration de variables rouge, vert et bleu */
	unsigned char r, g, b; 

public:
	/** @brief Constructeur avec des valeurs par défaut  */
	Pixel(); 
	/** 
	@brief  Constructeur avec de valeurs données 
	@param nr : couleur rouge à changer
	@param ng : couleur verte à changer
	@param nb : couleur bleue à changer
	*/
	Pixel(unsigned char nr, unsigned char ng, unsigned char nb); 
	/** @brief Return de pixel Rouge */
	const unsigned char getRouge() const; 
	/** @brief Return de pixel Vert */
	const unsigned char getVert() const; 
	/** @brief Return de pixel Rouge */
	const unsigned char getBleu() const; 
	/** 
	@brief Changement de pixel Rouge 
	@param nr : couleur rouge à change
	*/
	void setRouge(const unsigned char nr); 
	/** 
	@brief Changement de pixel Vert 
	@param ng : couleur verte à changer
	*/
	void setVert(const unsigned char ng); 
	/**
	@brief Changement de pixel Bleu 
	@param nb : couleur bleue à changer
	*/
	void setBleu(const unsigned char nb); 
};

#endif


