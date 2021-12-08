SFML_PATH=../SFML-2.5.1/
CFLAGS=-I$(SFML_PATH)include

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

undertale1:player.o gb.o sanstete.o sanscorps.o fightmenu.o button.o undertale1.o cadre.o menuItem.o life.o menustart.o parole.o
	g++ parole.o player.o menustart.o life.o gb.o sanstete.o sanscorps.o button.o fightmenu.o cadre.o menuItem.o undertale1.o -o undertale1 -lsfml-graphics -lsfml-system -lsfml-window -L$(SFML_PATH)lib
	export LD_LIBRARY_PATH=$(SFML_PATH)lib && ./undertale1
