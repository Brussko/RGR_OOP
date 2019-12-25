#pragma once

#include "Spectre.h"

// ��������� ������������ ���� ����� �� ������ ��� ��� ������ ������/���� 
using namespace std;
using namespace sf;

// ����� FFTHandler ����� ��� ��������� �����
// ����� ��� ��������� ������� �����
class FFTHandler
{
public:
	// ����������� ������
	FFTHandler(const string& _path, int _bufferSize);

	// ����������� ������� �������� �������������� �����
	static void fft(CArray& x);

	Spectre* pSpectre;

private:
	SoundBuffer buffer;
	Sound sound;
};