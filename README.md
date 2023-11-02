# photo-encryption-decryption

About:
- Implemented a simple encryption/decryption program for digital pictures using C++ SFML Library.
- Produced pseudo-random bits by simulating a linear feedback shift register, and used the shift register to alter each individual pixel of the image, creating the encryption/decryption effect. 
- This program will take three command line arguments: the input-file.png, the output-file.png, and the 16-bit seed “1011011000110110” and when ran, two display windows will pop up that displays the inputfile image before and after going through the transform function. The image after will be put into the output-file.png file and the 16-bit seed is used to create a FibLFSR object for the transform function. 
- An example encryption image is provided in the repository. The input-file.png file is the image before encryption and the output-file.png file is the image after encryption.

Note:
- I ran and executed the code on my Linux environment in a virtual machine. To run the code in VS Code, you would need to go through some tutorials online to set up C++ for VS Code because C++ is a compiled language. 
