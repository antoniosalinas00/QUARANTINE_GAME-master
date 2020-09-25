#pragma once
#include <time.h>
#include "Adversario.h"
#include "Jugador.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "Pantalla.h"
#include "Mensaje.h"

using namespace System::Windows::Forms;

class Juego {
private:
	int puntaje;
	int tiempo;
	clock_t start;
	bool dificultad;
	int mundo;
	int nivel;
	int nadversarios;
	int adversarios1golpeados;
	int adversarios2golpeados;

	Jugador* jugador;

	vector<Adversario*>* adversario1;
	vector<Adversario*>* adversario2;
	vector<Mensaje*>* municion;
	vector<Mensaje*>* virus;

	Policia* policia;
	Ambulancia* ambulancia;


	Pantalla* pantalla;
public:
	Juego(int, int, bool, int);
	void mostrarpantalla(Graphics^, Bitmap^);
	void moverjugador(Graphics^);
	void mostrarjugador(Graphics^, Bitmap^);
	void moveradversarios(Direccion, Graphics^);
	void mostrarayudantes(Graphics^ canvas, Bitmap^ sprite, Bitmap^ sprite2);
	void movimientoadversarios(Graphics^ );
	void mostraradversarios(Graphics^, Bitmap^, Bitmap^);
	bool disparar(Keys, int);
	void moverdisparo(Graphics^);
	void moverayudantes(Graphics^ canvas);
	void mostrardisparo(Graphics^, Bitmap^, Bitmap^);
	bool colisionadversario();
	bool colisionvirus();
	void colisionmensaje();
	void jugadorsetfila(int);
	void setdir(Direccion);
	void jugadorsetdx(int);
	void jugadorsetdy(int);
	int mostrarvidas();
	void agregaradversarios(int c);
	int getpuntaje() {
		return puntaje;
	}
	void setpuntaje() {
		puntaje += 10;
	}
	void eliminarmensajes(Graphics^);
	int Tiempo();
	int getnadversarios() {
		return nadversarios;
	}
	Policia* getpolicia() {
		return policia;
	}
	Jugador* getjugador() {
		return jugador;
	}
	int getnivel() {
		return nivel;
	}
};

//Constructor
Juego::Juego(int nvidas, int ntiempo, bool dificultad, int _nivel) {
	//inicializar la pantalla, el jugador y los adversarios.
	adversario1 = new vector<Adversario*>;
	adversario2 = new vector<Adversario*>;
	municion = new vector<Mensaje*>;
	virus = new vector<Mensaje*>;
	
	//Construimos nuestros objetos
	jugador = new Jugador(nvidas);
	policia = new Policia();
	ambulancia = new Ambulancia();
	pantalla = new Pantalla();
	Adversario* adv1 = new Adversario();
	Adversario* adv2 = new Adversario(1);
	Mensaje* men = new Mensaje(0, 0, Izquierda);

	//Agregamos un primer elemento a los vectores
	adversario1->push_back(adv1);
	adversario2->push_back(adv2);
	municion->push_back(men);
	virus->push_back(men);

	//Copiamos los valores de los parametros del constructor de nuestro Juego y declaramos el puntaje en 0
	this->tiempo = ntiempo * 60;
	nivel = _nivel;
	this->dificultad = dificultad;
	start = clock();
	puntaje = 0;
	//Inicializamos nuestras variables para la cantidad de adversarios y adversarios golpeados.
	Random r;
	System::Threading::Thread::Sleep(20);
	nadversarios = r.Next(5,9);
	adversarios1golpeados = 0;
	adversarios2golpeados = 0;
}
int Juego::Tiempo(){
	if (clock()-start >= (double)CLOCKS_PER_SEC) {
		tiempo--;
		start = clock();
	}
	return tiempo;
}
//Funciones que indican que se muestren los objetos necesarios para el juego.
void Juego::mostrarjugador(Graphics^ canvas, Bitmap^ sprite) {
	jugador->mostrar(canvas, sprite);
}
void Juego::mostraradversarios(Graphics^ canvas, Bitmap^ sprite, Bitmap^ sprite2) {
	for (int i = 0; i < adversario1->size(); i++) {
		if (i != 0)adversario1->at(i)->mostrar(canvas, sprite);
	}
	for (int i = 0; i < adversario2->size(); i++) {
		if (i != 0)adversario2->at(i)->mostrar(canvas, sprite2);
	}
}
void Juego::mostrarayudantes(Graphics^ canvas, Bitmap^ sprite, Bitmap^ sprite2) {
	if (policia->getrescatar() || policia->getescapar()) policia->mostrar(canvas, sprite);
	if (ambulancia->getrescatar() || ambulancia->getescapar()) ambulancia->mostrar(canvas, sprite2);
}
void Juego::mostrarpantalla(Graphics^ canvas, Bitmap^ sprite) {
	pantalla->mostrar(canvas, sprite, nivel);
}
void Juego::mostrardisparo(Graphics^ canvas, Bitmap^ spritedisparo, Bitmap^ spritevirus) {
	for (int i = 0; i < municion->size(); i++) {
		municion->at(i)->mostrar(canvas, spritedisparo);
	}
	if (dificultad) {
		for (int j = 0; j < virus->size(); j++) {
			virus->at(j)->mostrar(canvas, spritevirus);
		}
	}
}
int  Juego::mostrarvidas() {
	return jugador->getvidas();
}

//Funciones que permiten a los objetos moverse en pantalla.
void Juego::moverjugador(Graphics^ canvas) {
	jugador->mover(canvas);
}
void Juego::jugadorsetfila(int _fila) {
	jugador->setfila(_fila);
}

void Juego::setdir(Direccion _dir) {
	jugador->setdir(_dir);
}
void Juego::jugadorsetdx(int _dx) {
	jugador->setdx(_dx);
}
void Juego::jugadorsetdy(int _dy) {
	jugador->setdy(_dy);
}

void Juego::moveradversarios(Direccion direccion, Graphics^ canvas) {
	for (int i = 0; i < adversario1->size(); i++) {
		adversario1->at(i)->mover(direccion, canvas);
	}
	for (int i = 0; i < adversario2->size(); i++) {
		adversario2->at(i)->mover(direccion, canvas);
	}
}
void Juego::movimientoadversarios(Graphics^ canvas) {
	switch (nivel) {
	case 1:
		for (int i = 0; i < adversario1->size(); i++) {
			adversario1->at(i)->moveradversario1(canvas);
		}
		for (int i = 0; i < adversario2->size(); i++) {
			adversario2->at(i)->moveradversario2(canvas);
		}
		break;
	case 2:
		for (int i = 0; i < adversario1->size(); i++) {
			adversario1->at(i)->moveradversario1(canvas);
		}
		for (int i = 0; i < adversario2->size(); i++) {
			adversario2->at(i)->moveradversario2(canvas);
		}
		break;
	case 3:
		//Funcion adicional los Adversarios Asintomaticos persiguen al Jugador.
		for (int i = 0; i < adversario1->size(); i++) {
			adversario1->at(i)->moveradversario1(canvas);
		}
		for (int i = 0; i < adversario2->size(); i++) {

			if (jugador->getx() > adversario2->at(i)->getx()) {
				if (jugador->getx() - adversario2->at(i)->getx() > 5) adversario2->at(i)->mover(Direccion::Derecha, canvas);
			}
			else if (jugador->getx() < adversario2->at(i)->getx()) {
				if (adversario2->at(i)->getx() - jugador->getx() > 5) adversario2->at(i)->mover(Direccion::Izquierda, canvas);
			}

			if (jugador->gety() < adversario2->at(i)->gety()) {
				if (adversario2->at(i)->gety() - jugador->gety() > 5)adversario2->at(i)->mover(Direccion::Arriba, canvas);
			}
			else if (jugador->gety() > adversario2->at(i)->gety()) {
				if (jugador->gety() - adversario2->at(i)->gety() > 5)adversario2->at(i)->mover(Direccion::Abajo, canvas);
			}
		}

		break;
	case 4:
		break;
	}

}
void Juego::moverdisparo(Graphics^ canvas) {
	for (int i = 0; i < municion->size(); i++) {
		municion->at(i)->mover(canvas);
	}
	if (dificultad) {
		for (int j = 0; j < virus->size(); j++) {
			virus->at(j)->mover(canvas);
		}
	}
}
void Juego::moverayudantes(Graphics^ canvas) {
	adversarios1golpeados = 0;
	adversarios2golpeados = 0;
	//Cuento mis adversarios golpeados
	for (int i = 0; i < adversario1->size(); i++) {
		if (adversario1->at(i)->getestadogolpe()) adversarios1golpeados++;
	}
	for (int i = 0; i < adversario2->size(); i++) {
		if (adversario2->at(i)->getestadogolpe()) adversarios2golpeados++;
	}


	if (policia->getrescatar() && adversarios1golpeados>=1) { 
		policia->perseguir(adversario1,Perseguir);
		policia->perseguir(adversario1,Rescatar);
	}
	if (policia->geteliminaradversario()) {
		for (int i = 0; i < adversario1->size(); i++) {
			if (policia->getadversario() == adversario1->at(i)) {
				policia->seteliminaradversario();
				adversario1->erase(adversario1->begin() + i);
				adversarios1golpeados--;
				setpuntaje();
				i--;
				break;
			}
		}
	}
	if (adversarios1golpeados <= 0) policia->setescapar();
	if (policia->getescapar()) policia->perseguir(adversario1,Escapar);

	
	if (ambulancia->getrescatar() &&  adversarios2golpeados>=1) {
		ambulancia->perseguir(adversario2,Perseguir);
		ambulancia->perseguir(adversario2,Rescatar);
	}
	if (ambulancia->geteliminaradversario()) {
		for (int j = 0; j < adversario2->size(); j++) {
			if (ambulancia->getadversario() == adversario2->at(j)) {
				ambulancia->seteliminaradversario();
				adversario2->erase(adversario2->begin() + j);
				setpuntaje();
				adversarios2golpeados--;
				j--;
				break;
			}
		}
		
	}
	if (adversarios2golpeados <= 0) ambulancia->setescapar();
	if (ambulancia->getescapar()) ambulancia->perseguir(adversario2,Escapar);

}

//Funcion para la colision del adversario y mensaje
bool Juego::colisionadversario() {
	if (adversario1->size() > 1) {
		for (int i = 1; i < adversario1->size(); i++) {
			if (adversario1->at(i)->getarea().IntersectsWith(jugador->getarea())) return true;
		}

		for (int j = 1; j < adversario2->size(); j++) {
			if (adversario2->at(j)->getarea().IntersectsWith(jugador->getarea())) return true;
		}
	}
	return false;
}
void Juego::colisionmensaje() {
		for (int i = 1; i < municion->size(); i++) {
			for (int j = 0; j < adversario1->size(); j++) {
				if (municion->at(i)->getarea().IntersectsWith(adversario1->at(j)->getarea())) {
					adversario1->at(j)->setestadogolpe();
					municion->erase(municion->begin() + i);
					i--;
					break;
				}
			}
			for (int k = 0; k < adversario2->size(); k++) {
				if (municion->at(i)->getarea().IntersectsWith(adversario2->at(k)->getarea())) {
					municion->erase(municion->begin() + i);
					adversario2->at(k)->setestadogolpe();
					i--;
					break;
				}
			}
			for (int z = 1; z < virus->size(); z++) {
				if (municion->at(i)->getarea().IntersectsWith(virus->at(z)->getarea())) {
					virus->erase(virus->begin() + z);
					municion->erase(municion->begin() + i);
					z--;
					i--;
					break;
				}
			}
		}
}
bool Juego::colisionvirus() {
	for (int j = 1; j < virus->size(); j++) {
		if (virus->at(j)->getarea().IntersectsWith(jugador->getarea())) {
			virus->erase(virus->begin() + j);
			jugador->setvidas(jugador->getvidas() - 1);
			j--;
			return true;
		}
	}
	return false;

}
//Funcion que agrega usuarios segun el tiempo (c) que pasa.
void Juego::agregaradversarios(int c) {
	int ad1, ad2, limite, limite2;
	//Asignacion correcta de numero de adversarios por nivel
	if (nivel == 1 && nadversarios >=7) nadversarios -= 2;
	else if (nivel == 2 && nadversarios <= 7) nadversarios += 2;

	//Asignacion de cantidad de adversarios por tipo segun el numero total de adversarios.
	if (nadversarios % 2 == 0) {
		ad1 = ad2 = nadversarios / 2;
	}
	else if (nadversarios % 2 != 0) {
		ad1 = nadversarios / 2;
		ad2 = nadversarios / 2 - 1;
	}
	//Asignacion de limites para recorrer en un bucle y agregar adversarios en el paso del tiempo segun contador c
	limite = ad1 * 60 + 60;
	limite2 = ad2 * 70 + 70;

	if (c <= limite && c > 0 && c % 60 == 0) {
		Adversario* adv1 = new Adversario();
		adversario1->push_back(adv1);
	}
	if (c <= limite2 &&  c > 0 && c % 70 == 0) {
		Adversario* adv2 = new Adversario(1);
		adversario2->push_back(adv2);
	}

	//Comando para que los ayudantes entren a la pantalla del juego (Solo si hay enemigos golpeados).
	if (c % 200 == 0) {
		if (adversarios1golpeados > 0)policia->setrescatar();
	}
	else if (c % 210 == 0) {
		if (adversarios2golpeados > 0)ambulancia->setrescatar();
	}

	//AGREGAR VIRUS segun dificultad  
	if (dificultad) {
		if (c > 90 && c % 17 == 0) {
			Random r;
			System::Threading::Thread::Sleep(10);
			//variable n que dictaminara que  tipo y cual adversario lanzara el virus
			int n;
			if (adversario1->size() <= adversario2->size()) n = r.Next(1, adversario1->size());
			if (adversario2->size() <= adversario1->size()) n = r.Next(1, adversario2->size());

			//condicional para dictaminar el tipo de adversario que lanzara el virus.
			if (n % 2 == 0) {
				//Condicionales para dictaminar la direccion de movimiento del virus 
				if (adversario1->at(n)->getx() < jugador->getx()) {
					Mensaje* nuevovirus = new Mensaje(Derecha, adversario1->at(n)->getx(), adversario1->at(n)->gety());
					virus->push_back(nuevovirus);
				}
				else if (adversario1->at(n)->getx() > jugador->getx()) {
					Mensaje* nuevovirus = new Mensaje(Izquierda, adversario1->at(n)->getx(), adversario1->at(n)->gety());
					virus->push_back(nuevovirus);
				}
			}
			else {
				if (adversario2->at(n)->getx() < jugador->getx()) {
					Mensaje* nuevovirus = new Mensaje(Derecha, adversario2->at(n)->getx(), adversario2->at(n)->gety());
					virus->push_back(nuevovirus);
				}
				else {
					Mensaje* nuevovirus = new Mensaje(Izquierda, adversario2->at(n)->getx(), adversario2->at(n)->gety());
					virus->push_back(nuevovirus);
				}
			}
		}
	}
}
//Funcion que agrega 'disaparos al apretar "Space"
bool Juego::disparar(Keys tecla, int countdown) {
	if (tecla == Keys::Space && countdown<=0) {
		Mensaje* mensaje = new Mensaje(jugador->getx(), jugador->gety(), jugador->getdir());
		municion->push_back(mensaje);
		return true;
	}
	else return false;
}
void Juego::eliminarmensajes(Graphics^ canvas) {
	//ELIMINAR MENSAJES VIRUS-MENSAJE
	for (int i = 1; i < municion->size(); i++) {
		if (municion->at(i)->getx() - municion->at(i)->getdx() < 0 || municion->at(i)->getx() + municion->at(i)->getdx() > canvas->VisibleClipBounds.Right) {
			municion->erase(municion->begin() + i);
			i--;
		}
		if (municion->at(i)->gety() - municion->at(i)->getdy() < 0 || municion->at(i)->gety() + municion->at(i)->getdy() > canvas->VisibleClipBounds.Bottom) {
			municion->erase(municion->begin() + i);
			i--;
		}
	}
	for (int j = 1; j < virus->size(); j++) {
		if (virus->at(j)->getx() - virus->at(j)->getdx() < 0 || virus->at(j)->getx() + virus->at(j)->getdx() > canvas->VisibleClipBounds.Right) {
			virus->erase(virus->begin() + j); 
			j--;
		}
	}
}
