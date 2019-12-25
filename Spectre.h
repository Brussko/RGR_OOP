#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <complex>
#include <valarray>
#include <math.h>

#define PI 3.141592653589793238460

// Добавляем пространство имен чтобы не писать его для каждой фунции/типа 
using namespace std;
using namespace sf;

// Создаем свои типы данных для упрощения кода
typedef complex<double> Complex;
// valarray это тип данных, являеться массивом значений, с которым можно делать любые арефметические действия 
typedef valarray<Complex> CArray;

class Spectre
{
public:
	Spectre(Sound* sound, const SoundBuffer& _buffer, int _bufferSize);

	// Перерасчитывает массиви нужные для отображения спектра и звука
	void update();

	// Отрисовка спектра звука на окно
	void draw(RenderWindow& window);

	// Расчёта звука
	void hamming();

	// Создает массив для отрисовки спектра
	void bars();

	// Функция гауса
	float ghaus(float value);

	VertexArray VA1;
	VertexArray VA2;

private:
	// Переменный для работы со звуком
	SoundBuffer buffer;
	int bufferSize;

	CArray bin;

	int sampleRate;
	int sampleCount;

	vector<Complex> sample;

	// Указатель на звук
	Sound* pSound;
};

