#pragma once

#include "Spectre.h"

// Добавляем пространство имен чтобы не писать его для каждой фунции/типа 
using namespace std;
using namespace sf;

// Класс FFTHandler нужен для обработки звука
// Нужен для получения спектра звука
class FFTHandler
{
public:
	// Конструктор класса
	FFTHandler(const string& _path, int _bufferSize);

	// Рекурсивная функция Быстрого преобразования Фурье
	static void fft(CArray& x);

	Spectre* pSpectre;

private:
	SoundBuffer buffer;
	Sound sound;
};