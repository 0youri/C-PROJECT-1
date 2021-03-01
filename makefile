SDL = -lSDL2 -lSDL2_image
GPP_EXECUT = g++ -L/usr/local/lib
GPP_O = g++ -Wall -c
lib = -I/usr/local/include/SDL2

all: bin/test bin/exemple bin/affichage

bin/test: obj/mainTest.o obj/Pixel.o obj/Image.o
	${GPP_EXECUT} $^ -o $@  ${SDL}

bin/exemple: obj/mainExemple.o obj/Pixel.o obj/Image.o
	${GPP_EXECUT} $^ -o $@ ${SDL}

bin/affichage: obj/mainAffichage.o obj/Pixel.o obj/Image.o
	${GPP_EXECUT} $^ -o $@ ${SDL}

obj/mainTest.o: src/mainTest.cpp src/Image.h
	${GPP_O} $< -o $@

obj/mainExemple.o: src/mainExemple.cpp src/Image.h
	${GPP_O} $< -o $@
	
obj/mainAffichage.o: src/mainAffichage.cpp src/Image.h
	${GPP_O} $< -o $@

obj/Image.o: src/Image.cpp src/Image.h src/Pixel.h
	${GPP_O} ${lib} $< -o $@

obj/Pixel.o: src/Pixel.cpp src/Pixel.h
	${GPP_O} $< -o $@

clean:
	rm obj/*.o bin/*