#include "Spectre.h"
#include "FFTHandler.h"


Spectre::Spectre(Sound* sound, const SoundBuffer& _buffer, int _bufferSize)
// «адаем переменные класса
	: buffer(_buffer)
	, bufferSize(_bufferSize)
	, pSound(sound)
{
	sampleRate = buffer.getSampleRate() * buffer.getChannelCount();
	sampleCount = buffer.getSampleCount();
	if (bufferSize < sampleCount) bufferSize = _bufferSize;
	else bufferSize = sampleCount;

	sample.resize(bufferSize);

	VA1.setPrimitiveType(LineStrip);
	VA2.setPrimitiveType(Lines);

	VA1.resize(bufferSize);
}

void Spectre::draw(RenderWindow& window)
{
	update();

	// «десь происходит отрисовка
	window.draw(VA1);
	window.draw(VA2);
}

void Spectre::bars()
{
	float accuracyOfSpectrre = 20000.f; // „ем больше это значение, тем больше будет 
	float accuracy = min(bufferSize / 2.f, accuracyOfSpectrre);
	float maxHeight = 1e5; // тоже самое что 10^8
	const Vector2f position(0, 700); // место на окне где будет отрисовыватьс€ спектр
	for (float i = 1; i < min(accuracyOfSpectrre, bufferSize / 2.f); i *= 1.01)
	{
		Vector2f samplePosition(log(i) / log(min(bufferSize / 2.f, accuracyOfSpectrre)), abs(bin[(int)i]));
		VA2.append(Vertex(position + Vector2f(samplePosition.x * 800, -samplePosition.y / maxHeight), Color::Magenta));
		VA2.append(Vertex(position + Vector2f(samplePosition.x * 800, 0), Color::White));
	}
}

float Spectre::ghaus(float value)
{
	return 0.5 - 0.5 * cos(2 * PI * value / (float)bufferSize);
}

void Spectre::hamming()
{
	float mark = pSound->getPlayingOffset().asSeconds() * sampleRate;
	if (mark + bufferSize < sampleCount)
	{
		for (int i = mark; i < bufferSize + mark; i++)
		{
			sample[i - mark] = Complex(buffer.getSamples()[i] * ghaus(i - mark), 0);
			// ћассив дл€ отрисовки звука
			VA1[i - mark] = Vertex(Vector2f(20, 250) + Vector2f((i - mark) / (float)bufferSize * 800, sample[i - mark].real() * 0.005), Color::Blue);
		}
	}
}

void Spectre::update()
{
	hamming();

	VA2.clear();

	bin = CArray(sample.data(), bufferSize);
	// ѕересчитываем массив через быстрое преобразование фурье
	FFTHandler::fft(bin);

	bars();
}