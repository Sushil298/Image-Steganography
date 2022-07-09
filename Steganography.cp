//**********************************************************************************//
// *** This program encrypts the secret message into a bmp image  ***************//
// *** and decodes the secret message encoded into the bmp image ****************//
// *** Sushil Bohara (sb7702, NYUAD) **//

#include <iostream>
#include "Bitmap.h"         // Header file for reading and writing
#include "Encoder.h"        // Header file for encoding the message
#include "Decoder.h"        // header file decoding the message
#include <string>
using namespace std;

int main()

{
	// Declaring some variables
	bool repeat = true;  // initialize repeat to true
	string choice;

	while (repeat)
	{    // display the main menu to the user
		cout << "\nSelect your choice.\n\tEnter 'a' for encryption:\n\tEnter 'b' for decryption:\n\tEnter 'x' to exit:" << endl;
		getline(cin, choice);
		// call the EncryptMessage function if user chooses encryption
		if (choice == "a") {
			cout << "You have chosen to encrypt." << endl;
			EncodeMessage();

		}
		// call the DecryptMessage function if user chooses decryption
		if (choice == "b") {
			cout << "You have chosen to decrypt." << endl;
			DecodeMessage();

		}
		// terminate the program if user enters x
		if (choice == "x") {
			cout << "Program Terminating...." << endl;
			repeat = false;

		}
		// Display invalid choice if user enters the invalid input.
		if (choice != "a" && choice != "b" && choice != "x")
			cout << "Invalid Choice. Please enter 'a' or 'b' or 'x'." << endl;
	}


	return(0);
}





