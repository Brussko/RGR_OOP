#include "FFTHandler.h"
#define BUFFER_SIZE_TREATED_FFT 10000//48000//16384

using namespace std;
using namespace sf;

int main()
{
	string path = "WAVES/";
	string filename;
	cout << "File name: ";
	cin >> filename;
	RenderWindow window(VideoMode(800, 800), filename);
	path += filename;
	FFTHandler fft(path, BUFFER_SIZE_TREATED_FFT);

	Event event;

	while (window.isOpen())
	{
		// Нужно чтобы мы могли взаимодейст с окном
		while (window.pollEvent(event)) {}

		// Отрисовка на окне
		window.clear();
		fft.pSpectre->draw(window);
		window.display();
	}
}
