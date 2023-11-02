#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.h"

using namespace std;

/*
Transform function that takes an Image and a FibLFSR object.
What it does is that it will go through the image pixel by pixel and change
the colors by XORing the red, green, and blues with an eight bit integer
generated by the FibLFSR class generate function on the FibLFSR object.
*/
void transform(sf::Image& anImage, FibLFSR* aRegister);

int main(int argc, char* argv[])
{
	// declare string type variables using the command-line arguments
	string InputFile = argv[1];
	string OutputFile = argv[2];
	string seed = argv[3];
	// creating a FibLFSR object using the seed that came from a command-line argument
	FibLFSR register1(seed);

	// Setting up of the decoded png image using the InputFile
	sf::Image image1;
	if (!image1.loadFromFile(InputFile))
	{
		return -1;
	}

	sf::Vector2u size1 = image1.getSize();
	sf::RenderWindow window1(sf::VideoMode(size1.x, size1.y), "decode.png");
	
	sf::Texture texture1;
	texture1.loadFromImage(image1);
	
	sf::Sprite sprite1;
	sprite1.setTexture(texture1);

	// Setting up the encoded png image using the InputFile as well, but it will later go through the transform function
	sf::Image image2;
	if (!image2.loadFromFile(InputFile))
	{
		return -1;
	}

	transform(image2, &register1);

	sf::Vector2u size2 = image2.getSize();
	sf::RenderWindow window2(sf::VideoMode(size2.x, size2.y), "encode.png");

	sf::Texture texture2;
	texture2.loadFromImage(image2);

	sf::Sprite sprite2;
	sprite2.setTexture(texture2);


	// Opens two windows, one for the untouched image, and the other for the transformed image
	// Window will stay opened until one of the windows close
	while (window1.isOpen() && window2.isOpen())
	{
		sf::Event event;
		
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window1.close();
			}
		}
		
		
		while (window2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window2.close();
			}
		}
		

		window1.clear();
		window1.draw(sprite1);
		window1.display();

		
		window2.clear();
		window2.draw(sprite2);
		window2.display();
		
	}

	// Saves the transformed image into the OutputFile, output-file.png
	if (!image2.saveToFile(OutputFile))
	{
		return -1;
	}

	return 0;
}


void transform(sf::Image& anImage, FibLFSR* aRegister)
{
	// p is a pixel
	sf::Color p;
	// temp_size is used to get the size of the png image that is used in the transform function
	sf::Vector2u temp_size = anImage.getSize();
	int x, y;
	int x_length = temp_size.x;
	int y_length = temp_size.y;
	// declared eightBit_integer here because it would later be set to an eight bit integer later by the generate function with a register seed
	int eightBit_integer;

	// goes through pixel by pixel in every row and column of the image to change the colors by XORing the pixels red, green, and blue
	// with an eightBit_integer created by the FibLFSR class generate function
	for (x = 0; x < x_length; x++)
	{
		for (y = 0; y < y_length; y++)
		{
			p = anImage.getPixel(x, y);
			
			eightBit_integer = aRegister->generate(8);
			p.r ^= eightBit_integer;

			eightBit_integer = aRegister->generate(8);
			p.g ^= eightBit_integer;

			eightBit_integer = aRegister->generate(8);
			p.b ^= eightBit_integer;

			anImage.setPixel(x, y, p);
		}
	}
}

