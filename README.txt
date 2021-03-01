# Module image pour LIFAP4

Module image permet de générer 2 images et d'ouvrir une fenetre avec une image qu'on peut zoomer/dezoomer avec les touches T/G 
et fermer avec ESC

## Le code et l'organisation des fichiers
Ce code est construit de manière à avoir les fonctionalités de base regroupées dans des classes noyau; 
puis d'avoir une surcouche pour l'affichage : texte/console et SDL2.

L'organistion des fichiers est la suivante.

- ** src/ **    : les classes du module image et 3 fichiers d'exécutions
- ** data/ **   : les images générées
- ** doc/ **    : le fichier doxygen qui permet de générer la documentation du code
- ** bin/ **    : répertoire où les executables seront compilés
- ** obj/ **    : répertoire comportant les compilations intermédiaires (.o)
- ** makefile **    : ce fichier permet de compiler et générer les fichiers .o et les executables à partir du dossier src/



## Pour compiler

### Préambule : si vous voulez un Linux sous Windows, installez WSL !
### Préambule : pour faire installation sous MacOS il faut installer brew!

### Pour installer WSL sous Windows
    Voir la page de l'UE : https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4#wsl_pour_faire_tourner_un_linux_ultra_leger_sous_windows

### Pour installer brew
    ``` /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" ```

### Pour installer SDL2
    - sous Linux ou avec WSL/Windows
        ``` sudo apt install python3 valgrind doxygen libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev imagemagick ```
    - sous MacOS
        ``` brew install sdl ```
        ``` brew install sdl_image ```

### Pour installer doxygen
    - sous Linux ou avec WSL/Windows
        ``` sudo apt install doxygen ```
    - sous MacOS
        ``` brew install doxygen ```

### Pour installer valgrind
    - sous Linux ou avec WSL/Windows
        ``` sudo apt install valgrind ```
    - sous MacOS
        ``` brew tap LouisBrunner/valgrind ```
        ``` brew install --HEAD LouisBrunner/valgrind/valgrind ```