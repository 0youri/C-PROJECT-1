#ifndef Image_h
#define Image_h

#include "Pixel.h"
#include <fstream>
#include <stdlib.h>

using namespace std;


/** 
	@brief La classe Image contient un pointeur sur un tableau de Pixels, les dimensions X et Y de ce tableau
*/
class Image
{
private:
	/** @brief Définition du tableau de pointeur sur Pixel */
	Pixel * tab; 
	/** @brief Définition de dimension X et Y */
	unsigned int dimx, dimy; 
public:
	/** @brief Constructeur par d�faut */
	Image();
	/** 
	@brief Constructeur avec les valeurs données
	@param dimensionX : définition de la dimension X
	@param dimensionsY : définition de la dimension Y
	 */
	Image(const unsigned int dimensionX, const unsigned int dimensionY); 
	/** @brief Destructeur */
	~Image(); 
	/** 
	@brief Retourne le Pixel demandé 
	@param x : position de x
	@param y : position de y
	*/
	Pixel & getPix(const unsigned int x, const unsigned int y) const; 
	/**
	@brief Changement de couleur de Pixel demandé 
	@param x : position de x
	@param y : position de y
	@param couleur : la couleur de Pixel à changer
	*/
	void setPix(const unsigned int & x, const unsigned int & y, const Pixel & couleur) const; 
	/** 
	@brief Dessine un rectangle de couleur donn�e sur l'emplacement donné
	@param Xmin : minimum de X
	@param Ymin : minimum de Y
	@param Xmax : maximum de X
	@param Ymax : maximum de Y
	@param couleur : couleur de Pixel à dessiner
	*/
	void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, Pixel couleur);
	/** 
	@brief Remplace le tableau de Pixel par une couleur donné
	@param couleur : couleur remplaçante
	*/
	void effacer(Pixel couleur); 
	/** @brief Test de toutes les fonctions */
	void testRegression(); 
	/** 
	@brief Création du fichier 
	@param filename : nom du fichier à créer
	*/
	void sauver(const string & filename); 
	/**
	@brief Copie du fichier existant
	@param filename : nom du fichier à copier
	*/ 
	void ouvrir(const string & filename); 
	/** @brief Affichage du tableau de Pixel */
	void afficherConsole(); 
	/** @brief Affichage SDL */
	void afficher(); 
};

#endif 
