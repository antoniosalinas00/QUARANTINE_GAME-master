#pragma once
#include "Ayudante.h"


class Policia : public Ayudante {
private:
	bool rescatar;
	bool eliminaradversario;
	bool escapar;
public:
	Policia();
	~Policia();

	void mostrar(Graphics^ canvas, Bitmap^ sprite);
	void mover(Direccion dir);
	void perseguir(vector <Adversario*>*, estadomovimiento);
	void seteliminaradversario();
	void setrescatar();
	void setescapar();


	bool getrescatar();
	bool geteliminaradversario();
	bool getescapar();
	Adversario* getadversario();
};

Policia::Policia() {
	x = 400;
	y = 720;
	dx = dy = 8;
	columna = fila = 0;
	rescatar = escapar = eliminaradversario = false;
}

void Policia::mover(Direccion dir) {
	switch (dir)
	{
	case Arriba:
		y -= dy;
		fila = 1;
		break;
	case Abajo:
		y += dy;
		fila = 0;
		break;
	case Izquierda:
		x -= dx;
		fila = 3;
		break;
	case Derecha:
		x += dx;
		fila = 2;
		break;
	}

}
void Policia::perseguir(vector <Adversario*>* _adversarios, estadomovimiento estado) {
	for (int i = 0; i < _adversarios->size(); i++) {
		if (_adversarios->at(i)->getestadogolpe()) {
			adversario = _adversarios->at(i);
			break;
		}
	}

	switch (estado) {
	case Perseguir:
		if (adversario->gety() < y) {
			if (y - adversario->gety() > 4) mover(Arriba);
		}
		else if (adversario->gety() > y) {
			if (adversario->gety() - y > 4) mover(Abajo);
		}

		if (adversario->getx() < x) {
			if (x - adversario->getx() > 4) mover(Izquierda);
		}
		else if (adversario->getx() > x) {
			if (adversario->getx() - x > 4) mover(Derecha);
		}
		break;
	case Rescatar:
		if (adversario->getx() - 6 <= x && adversario->getx() + 6 >= x) {
			if (adversario->gety() - 6 <= y && adversario->gety() + 6 >= y) {
				eliminaradversario = true;
			}
		}
		break;
	case Escapar:
		if (x + dx < 380) {
			mover(Derecha);
			mover(Derecha);
			mover(Derecha);
		} else if (x+dx >=380 && y < 680) {
			mover(Abajo);
			mover(Abajo);
			if (y >= 680) {
				escapar = false;
			}
		}
		break;
	}
}
void Policia::mostrar(Graphics^ canvas, Bitmap^ sprite) {
	alto = sprite->Height / 4;
	ancho = sprite->Width / 4;
	Rectangle molde = Rectangle(columna*ancho, fila*alto, ancho, alto);
	canvas->DrawImage(sprite, x, y, molde, GraphicsUnit::Pixel);
	columna++;
	if (columna == 4) {
		columna = 0;
	}
}

void Policia::seteliminaradversario() {
	eliminaradversario = !eliminaradversario;
}
void Policia::setrescatar() {
	rescatar = true;
}
void Policia::setescapar() {
	escapar = true;
	rescatar = false;
	eliminaradversario = false;
}
bool Policia::getrescatar() {
	return rescatar;
}
bool Policia::geteliminaradversario() {
	return eliminaradversario;
}
bool Policia::getescapar() {
	return escapar;
}


Adversario* Policia::getadversario() {
	return adversario;
}

Policia::~Policia() {

}