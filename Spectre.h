#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <complex>
#include <valarray>
#include <math.h>

#define PI 3.141592653589793238460

// ��������� ������������ ���� ����� �� ������ ��� ��� ������ ������/���� 
using namespace std;
using namespace sf;

// ������� ���� ���� ������ ��� ��������� ����
typedef complex<double> Complex;
// valarray ��� ��� ������, ��������� �������� ��������, � ������� ����� ������ ����� �������������� �������� 
typedef valarray<Complex> CArray;

class Spectre
{
public:
	Spectre(Sound* sound, const SoundBuffer& _buffer, int _bufferSize);

	// ��������������� ������� ������ ��� ����������� ������� � �����
	void update();

	// ��������� ������� ����� �� ����
	void draw(RenderWindow& window);

	// ������� �����
	void hamming();

	// ������� ������ ��� ��������� �������
	void bars();

	// ������� �����
	float ghaus(float value);

	VertexArray VA1;
	VertexArray VA2;

private:
	// ���������� ��� ������ �� ������
	SoundBuffer buffer;
	int bufferSize;

	CArray bin;

	int sampleRate;
	int sampleCount;

	vector<Complex> sample;

	// ��������� �� ����
	Sound* pSound;
};

