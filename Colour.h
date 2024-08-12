#pragma once
#include <cstdint>
class Colour
{
public:

	Colour();
	Colour(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

public:

	bool operator==(const Colour& rhs);
	bool operator!=(const Colour& rhs);

	unsigned char GetRed() const;
	unsigned char GetGreen() const;
	unsigned char GetBlue() const;
	unsigned char GetAlpha() const;
	
	void SetRed(unsigned char red);
	void SetGreen(unsigned char green);
	void SetBlue(unsigned char blue);
	void SetAlpha(unsigned char alpha);


public:

	std::uint32_t colour = 0;

	enum RGBA {
		RED = 24,
		GREEN = 16,
		BLUE = 8,
		ALPHA = 0
	};

};

