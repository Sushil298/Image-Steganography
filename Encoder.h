// **************This header file encodes the secret message into the bmp image **************//
//**** It asks for filename of bmp image, secret message, and the filename for stego image **//
//***  It then encodes the message into bmp image and produces stego image      *********//
// ****************************************************************************************//


#pragma once
#include <iostream>
#include <string>
using namespace std;
void EncodeMessage();              // function signature
char Replace(char ch, int newbit);  // function signature
void EncodeMessage()
{  //  Declare the local variables
	string  message;  int len;
	char ch; // to store the character pixel of the image
	char nullCharacter = '\0';  // store null terminating character
	int number;    //   to store the ASCII value of the null character
	int count(0), num;
	string filename;  // variable to store the file name of the input bmp image
	string nfilename;     // variable to to store the filename of the stego image.
	// Declare the pointer
	unsigned char*** imageData;
	// declare and initialize variables for image height and image width
	int imageWidth(0), imageHeight(0);
	// ask for the name of bmp image to encode message
	cout << "Enter the bitmap image (in which you want to encrypt message) alongwith its extension: " << endl;
	getline(cin, filename);   // take the input
	ReadBitmapImage(&filename[0], imageData, imageWidth, imageHeight); // call the function to read necessary info from the image
	if (ReadBitmapImage(&filename[0], imageData, imageWidth, imageHeight)) {

		cout << "Enter the message you want to encode : " << endl;  // ask for the secret message to encode
		getline(cin, message);
		len = message.length();       // find the length of the message

		int pointersize = (len + 1) * 8;      // length of the all bits of message including the null terminating character
		int* messagePtr;                      // Declare the pointer
		messagePtr = new int[pointersize];    // Create a pointer array to store the addresses of the all bits of the secret message including null terminating character


		for (int j = 0; j < len; j++)
		{
			ch = message[j];       // a character of the message
			num = int(ch);         // convert character to ASCII value
			for (int k = 0; k < 8; k++)  // loop to convert the ASCII value into 8 bit binary number 
			{
				messagePtr[count] = num % 2;  // store each bit into as different element of the pointer array - messagePTR[count]
				num = num / 2;
				count++;
			}
		}

		number = int(nullCharacter);
		for (int m = 0; m < 8; m++) // loop to convert the ASCII value of null character into 8 bit binary number 
		{
			messagePtr[count] = number % 2;     // store each bit of null character as different element of the pointer array
			number = number / 2;
			count++;
		}
		// declare and initialize local variable counter
		int counter(0);
		for (int rows = 0; rows < imageHeight; rows++)  // runs imageHeight number of times
		{
			for (int columns = 0; columns < imageWidth; columns++)    // runs imageWidth number of times 
			{
				for (int i = 0; i <= 2; i++)        // runs channel number of times 
				{
					// Call the function to replace the last bit of a pixel of the image with a bit of a secret message

					imageData[rows][columns][i] = Replace(imageData[rows][columns][i], messagePtr[counter]);
					counter++;
					if (counter == pointersize)    // exit the loop when whole message in encoded
						break;
				}
				if (counter == pointersize)   // exit the loop when whole message in encoded
					break;
			}
			if (counter == pointersize)   // exit the loop when whole message in encoded
				break;
		}
		// write all the changes to the image.
		cout << "Enter the filename for the encrypted bitmap image along with its extension : " << endl;
		getline(cin, nfilename);
		WriteBitmapImage(&nfilename[0], imageData, imageWidth, imageHeight);

		cout << "\nYour message is successfully encrypted in the image: " << nfilename << endl;
		ReleaseMemory(imageData, imageHeight, imageWidth);     // Deallocate the heap memory
	}
}







// function to replace last bit of the character
char Replace(char ch, int newbit)

{   // declare the constant for array size
	const int size = 8;
	// Declare and initialize some variables

	int num;
	int remainder, result(0);
	num = int(ch);
	// Declare and initialize the array
	int binarydigit[size] = { 0 };

	// loop to convert character into 8 bits binary number

	for (int i = 7; i >= 0; i--)
	{
		if (num > 0)
		{
			remainder = num % 2;
			num = num / 2;
			binarydigit[i] = remainder;
		}
		else
			break;
	}
	// Replace the least significant bit with a bit of the secret message
	binarydigit[7] = newbit;
	// loop to convert the newly formed 8 bit number to ASCII value
	for (int j = 0; j <= 7; j++)
	{
		result = result + binarydigit[j] * pow(2, 7 - j);
	}
	return char(result);  // return the equivalent character of the previous ASCII value

}
