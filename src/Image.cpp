#include "Image.h"
#include <cassert>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

Image::Image()
{
	dimx = 0;
	dimy = 0;
	tab = NULL;
}

Image::Image(const unsigned int dimensionX, const unsigned int dimensionY)
{
	dimx = dimensionX;
	dimy = dimensionY;
	tab = new Pixel[dimx*dimy];
}

Image::~Image() /// Destructeur
{
	if ( tab != NULL ) delete []tab;
	dimx = 0;
	dimy = 0;
}

Pixel & Image::getPix(const unsigned int x, const unsigned int y) const
{
	assert(dimx >= x && dimy >= y);
	return tab[y*dimx + x];
}

void Image::setPix(const unsigned int & x, const unsigned int & y, const Pixel & couleur) const
{
	assert(dimx >= x && dimy >= y);
	tab[y*dimx + x].setRouge(couleur.getRouge());
	tab[y*dimx + x].setVert(couleur.getVert());
	tab[y*dimx + x].setBleu(couleur.getBleu());
}

void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, Pixel couleur)
{
	assert(dimx >= Xmax && dimy >= Ymax);
	assert(Xmax > Xmin && Ymax > Ymin);
	for (unsigned int x = Xmin; x <= Xmax; ++x)
	{
		for (unsigned int y = Ymin; y <= Ymax; ++y) setPix(x, y, couleur);
	}
}

void Image::effacer(Pixel couleur)
{
	this->dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);
}

void Image::testRegression()
{
	// test 1 avec valeurs 0
    Image test1;
    assert(test1.dimx == 0 && test1.dimy == 0);
    assert(test1.tab == NULL);
    
	// test 2 avec valeurs (50,50)
    Image test2(50,50);
    Pixel pix(1, 1, 1);
	assert(test2.dimx == 50 && test2.dimy == 50);
    assert(test2.tab != NULL);
    test2.setPix(1, 1, pix);
    assert(test2.getPix(1, 1).getRouge() == 1);
    test2.dessinerRectangle(0, 0, 2, 2, pix);
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            pix = test2.getPix(x, y);
            assert(pix.getRouge() == 1);
        }
    }
    pix.setRouge(2);
    pix.setBleu(2);
    pix.setVert(2);
    test2.effacer(pix);
    assert(test2.tab[0].getRouge() == 2);
}


void Image::sauver(const string & filename)
{
	ofstream fichier(filename.c_str());
	assert(fichier.is_open());
	fichier << "P3" << endl;
	fichier << dimx << " " << dimy << endl;
	fichier << "255" << endl;
	for (unsigned int y = 0; y < dimy; ++y)
	{
		for (unsigned int x = 0; x < dimx; ++x)
		{
			Pixel pix = getPix(x, y);
			fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
		}
	}

	cout << "Sauvegarde de l'image " << filename << " ... OK\n";
	fichier.close();
}

void Image::ouvrir(const string & filename)
{
	ifstream fichier(filename.c_str());
	assert(fichier.is_open());
	unsigned int r, g, b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete[] tab;
	tab = new Pixel[dimx*dimy];
	for (unsigned int y = 0; y < dimy; ++y)
	{
		for (unsigned int x = 0; x < dimx; ++x)
		{
			fichier >> r >> g >> b;
			Pixel pix(r, g, b);
			setPix(x, y, pix);
		}
	}
	fichier.close();
	cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole()
{
	cout << dimx << " " << dimy << endl;
	for (unsigned int y = 0; y < dimy; ++y)
	{
		for (unsigned int x = 0; x < dimx; ++x)
		{
			Pixel pix = this->getPix(x, y);
			cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
		}
		cout << endl;
	}
}

void Image::afficher()
{
	// Création des variables SDL
	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;
	SDL_Surface * picture = NULL;
	SDL_Texture * texture = NULL;
	SDL_Rect * dest_rect = NULL;
	dest_rect = new SDL_Rect();
	dest_rect->x = 0;
	dest_rect->y = 0;
	dest_rect->w = 200;
	dest_rect->h = 200;

	// Initialisation SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
	}

	// Dimensions de la fenetre
    int x, y;
    x = 200;
    y = 200;

	// Initialisation fenetre SDL
    window = SDL_CreateWindow("ModuleImage", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, 0);
	if (window == NULL)
	{
		cout << "Erreur window: " << SDL_GetError() << endl; SDL_Quit(); exit(1);
	}
	
	// Initialisation renderer SDL
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
	if (renderer == NULL)
	{
		cout << "Erreur renderer: " << SDL_GetError() << endl; SDL_Quit(); exit(1);
	}

	// Initialisation surface SDL
	picture = IMG_Load("./data/image.ppm");
	if (picture == NULL)
	{
		cout << "Erreur picture: " << SDL_GetError() << endl; SDL_Quit(); exit(1);
	}

	// Initialisation couleur gris claire
	SDL_SetRenderDrawColor(renderer, 211, 211, 211, 211);
	
	// Initialisation texture SDL
	texture = SDL_CreateTextureFromSurface(renderer, picture);
	SDL_FreeSurface(picture);
	if (texture == NULL)
	{
		cout << "Erreur texture: " << SDL_GetError() << endl; SDL_Quit(); exit(1);
	}

	// Initialisation et ouverture de la fenetre SDL
	bool isOpen = true;
    SDL_Event events;
	while(isOpen)
	{
        while ( SDL_PollEvent(&events) ) // Ouverture de la fenetre
		{
            switch(events.type){
                case SDL_WINDOWEVENT:
                    if(events.window.event == SDL_WINDOWEVENT_CLOSE){
                        isOpen = false;
                    }
                    break;
				case SDL_KEYDOWN: // Un événement de type touche relâchée est effectué
					if (events.key.keysym.sym == SDLK_t) // zoom
					{
							dest_rect->x -= 5;
							dest_rect->y -= 5;
							dest_rect->w += 10;
							dest_rect->h += 10;
					}
					else if (events.key.keysym.sym == SDLK_g) // dezoom
					{
							dest_rect->x += 5;
							dest_rect->y += 5;
							dest_rect->w -= 10;
							dest_rect->h -= 10;
					}
					else if (events.key.keysym.sym == SDLK_ESCAPE) // fermeture de la fenetre
					{
						isOpen = false;
					}
					break;
                default:
                break;
            }
        }
		SDL_RenderClear(renderer); // Couleur gris au fond
		// Changement de la taille d'image dans la fenetre
		if ( SDL_RenderCopy(renderer, texture, NULL, dest_rect) != 0 ) 
		{
			cout << "Erreur SDL_RenderCopy: " << SDL_GetError() << endl; SDL_Quit(); exit(1);
		}
        SDL_RenderPresent(renderer); // Ouverture d'image
    }
}