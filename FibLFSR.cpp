#include "FibLFSR.h"
#include <iostream>
#include <string>

using namespace std;

FibLFSR::FibLFSR(string seed)
{
	register_bits = seed; 			// Initializes the private variable with a given seed string
	register_length = seed.length();	// Initializes the private variable with the given seed length (should be 16)
}

int FibLFSR::step(void)
{
	int exclusiveOR_result_bit;

	// Makes sure to check if the register_length is 16 bits because we are suppose
	// to simulate a register with 16 bits
	if (register_length != 16)
	{
		cout << "Incorrect Length. Make sure the length of the seed is 16 bits!" << endl;
		return -1;
	}
	
	// Result of the XORing of the first bit and bits of the tap positions: 13, 12, and 10
	// Used 0, 2, and 3 in the string 'at' functions because in the register, position 0 
	// is at the end and position 15 is at the front
	exclusiveOR_result_bit = register_bits.at(0) ^ register_bits.at(2) ^ register_bits.at(3) ^ register_bits.at(5);

	// If the result is 0, appends a string of 0 to the end of the register, otherwise appends
	// a string of 1
	if (exclusiveOR_result_bit == 0)
	{
		register_bits.append("0");
	}
	else
	{
		register_bits.append("1");
	}

	// Removes the first bit in the register
	register_bits.erase(0, 1);

	return exclusiveOR_result_bit;
}

int FibLFSR::generate(int k)
{
	// Makes sure to check if the register_length is 16 bits because we are suppose
	// to simulate a register with 16 bits
	if (register_length != 16)
	{
		cout << "Incorrect Length. Make sure the length of the seed is 16 bits!" << endl;
		return -1;
	}

	int result_of_extracted_bits = 0;
	int i;

	for (i = 0; i < k; i++)
	{
		result_of_extracted_bits = (result_of_extracted_bits * 2) + step();
	}

	// Below is the code that I wrote before rereading the description
	// of the provided arithmetic in the generate function part of
	// the assignment document and understanding it.
	// The below code will result in the same answer as the code above,
	// it is just a bit more work for the computer to do with an extra 
	// for loop and having more unnecessary variables.

	/*
	int count;
	int result = 0;
	int bit_position = k - 1;
	int bit_position_value = 1;

	for (count = 0; count < k; count++)
	{
		if (step() == 1)
		{
			for (int i = 0; i < bit_position; i++)
			{
				bit_position_value *= 2;
			}

			result += bit_position_value;	
		}
		
		bit_position_value = 1;
		bit_position--;
	}
	*/

	return result_of_extracted_bits;
}

ostream& operator<<(ostream& outStream, const FibLFSR& pFibLFSRObject)
{
	outStream << pFibLFSRObject.register_bits;

	return outStream;
}