#include "FFTHandler.h"

FFTHandler::FFTHandler(const string& path, int _bufferSize)
{
	// Загрузка и воспроизведение файла
	if (!buffer.loadFromFile(path)) cout << "Unable to load file" << endl;

	sound.setBuffer(buffer);
	sound.setLoop(true);
	sound.play();

	// Создаем класс спектра для дальнейшего его отображения
	pSpectre = new Spectre(&sound, buffer, _bufferSize);
}

void FFTHandler::fft(CArray& x)
{
	const int N = x.size();
	if (N <= 1) return;

	CArray even = x[slice(0, N / 2, 2)];
	CArray odd = x[slice(1, N / 2, 2)];

	fft(even);
	fft(odd);

	for (int k = 0; k < N / 2; k++)
	{
		Complex t = polar(1.0, -2 * PI * k / N) * odd[k];
		x[k] = even[k] + t;
		x[k + N / 2] = even[k] - t;
	}
}