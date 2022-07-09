//*******  This header  file decodes the message stored into the stego image   *************//
// ****** It asks for stego image name as the input and displays the decoded message *****//
// ***************************************************************************************//


#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void DecodeMessage();   // function signature

void DecodeMessage()

{   // declare and initialize some variables
	string filename;
	char character = ' ', ch;
	int num(0), counter = 0, Lastbit, number(0);
	// Declare the pointer
	unsigned char*** imageData;
	// declare variables for image height and width
	int imageWidth(0), imageHeight(0);
	// Ask for the stego image to reveal the secret message
	cout << "Enter the name of the bitmap image (from which you want to decrypt the message) along with its extension:" << endl;
	getline(cin, filename);
	// Read the necessary info from the image
	ReadBitmapImage(&filename[0], imageData, imageWidth, imageHeight);
	if (ReadBitmapImage(&filename[0], imageData, imageWidth, imageHeight)) {

		cout << "The following message is decrypted." << endl << endl;


		for (int rows = 0; rows < imageHeight; rows++)      // runs imageHeight number of times
		{
			for (int columns = 0; columns < imageWidth; columns++)  // rums imageWidth number of times
			{
				for (int i = 0; i <= 2; i++)      // runs channel number of times

				{
					ch = imageData[rows][columns][i];   // store the character value of the pixel
					num = int(ch);   // Convert the character value to ASCII value
					Lastbit = num % 2;  // store the least significant bit of the pixel
					number = number + (Lastbit * pow(2, counter));   // store the equivalent ASCII value of 8 consecutive least significant bits.

					// convert the consecutive 8 least significant bits into a character
					if (counter == 7)
					{
						character = char(number);
						if (int(character) == 0)  // exit the scope if null terminating character is found
							break;
						cout << character;  // Display the character




					}
					counter++;
					if (counter == 8) // reset the counter and number value to zero after character is obtained 
					{
						counter = 0;
						number = 0;

					}
					if (int(character) == 0)     // exit the loop if null terminating character is found
						break;

				}
				if (int(character) == 0)   // exit the loop if null terminating character is found
					break;
			}
			if (int(character) == 0)    // exit the loop if null terminating character is found
				break;
		}
		ReleaseMemory(imageData, imageHeight, imageWidth);  // deallocate the heap memory
	}
}
