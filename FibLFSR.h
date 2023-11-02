#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <iostream>
#include <string>

using namespace std;

class FibLFSR
{
public:
	// Constructor that creates a linear feedback shift register
	// using the given initial seed string of 0s and 1s.
	// Initializes private variable, register_bits, of type string
	// with the type string argument, seed.
	FibLFSR(string seed);
	
	// Simulates only one step of a linear feedback shift register
	// Will shift the register_bits one position to the left and replace 
	// the bit at the end of the register with a value that is the Boolean
	// exclusive OR of the bit at the front, and the bits of tap positions:
	// 13, 12, and 10. Returns the result of the Boolean exclusive OR.
	int step(void);

	// Simulates k steps of the linear feedback shift register.
	// What is returned is the value of the k extracted bits.
	int generate(int k);
	
	// Overloading of the insertion operator so that the FibLFSR object can 
	// be printed easier to see what the register_bits
	friend ostream& operator<<(ostream& outStream, const FibLFSR& pFibLFSRObject);

private:
	string register_bits;
	int register_length;

};

#endif