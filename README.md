# Problem Statement

The objective is to develop a program that can insert a text message inside a bitmap image and also extract it.  The software presents the user with a main menu, with options to encode a message, decode a message, and exit the program. When the user selects the encode option, he/she is prompted to enter the secret message and the name of the bitmap file where the secret message must be encoded in. When the user selects the decode option, the program prompts the user for the bitmap image(with text encoded into it)’s name, extracts the secret text message, and displays it on the output screen. When the user selects the exit option, a message confirming exit is printed on the screen and the program is terminated. 

# Relevant Background Information

Steganography is a technique of hiding the data (file, text, image, etc.) within another data file (file, text, image, etc.). Assume an image is represented as a three-dimensional array (M-by-N-by-3 array) where M is the number of pixels in the vertical direction (rows) and N is the number of pixels in the horizontal direction(cols), while each 3-vector corresponds to the blue, green, and red intensities of each pixel. The pixel values are 1-byte characters and are between 0 and 255.. A bitmap image has the following structure.  

<img width="500" alt="BMP Image Structure" src="https://github.com/Sushil298/Image-Steganography/assets/80779647/15dc014c-099a-40cd-9d76-c4b701a5da3d">

In the bitmap image, each pixel is represented in 8 bits. The last bit in a pixel is called the Least Significant bit as its value will affect the pixel value only by “1”. So, this property is used to hide the data in the image. If anyone has considered the last two bits as LSB bits, they will affect the pixel value only by “3”. This helps in storing extra data. The Least Significant Bit (LSB) steganography is one such technique in which the least significant bit of the image is replaced with a bit of a secret message. This approach is very simple. In this method, the least important bits of some or all of the bytes inside an image are replaced with bits of the secret message. This then produces a stego image with all the bits of secret message encoded into it. If we want to decode the message from the stego image, we should again extract the least significant bits of the pixels encoded with the secret message, and then convert them to equivalent characters.  

<img width="472" alt="BMP_Pixels_Arrangement" src="https://github.com/Sushil298/Image-Steganography/assets/80779647/63ed0c66-a749-4924-8633-e67797d900f7">

The process of replacing the last bit of the pixel of the bitmap image with a bit of the secret message can be shown with the help of the following diagram.  

<img width="457" alt="Message Encoding" src="https://github.com/Sushil298/Image-Steganography/assets/80779647/484c95d1-0e84-4203-a988-0a887a508754">

# Input/output Description

<img width="449" alt="IO Diagram" src="https://github.com/Sushil298/Image-Steganography/assets/80779647/277fab6f-f8e5-4a58-9275-a9a91ee4b268">

# Hand Solved Test Cases

## Test case 1: Invalid Selection input
Enter your choice.  
        Enter 'a' for encryption:  
        Enter 'b' for decryption:  
        Enter 'x' to exit:  

s(invalid choice)  
(The program must display the error message)  
Invalid Choice. Please enter 'a' or 'b' or 'x'.    

## Test case 2: Encryption

The user enters the name of the BMP image and the secret message. First of all, the message is converted into its equivalent binary numbers. Each character of the message is converted to 8 8-bit binary numbers. Then, each bit of this character replaces the least significant bit of a pixel of the image. Hence, each character of the message requires 8 pixels of the bmp image for encryption This process is repeated until the whole message is encoded into the image. At last, the null terminating character ‘\n’ is also encoded into the image in order to signify the end of the secret message.  

Suppose we want to encrypt the message “New York University Abu Dhabi !!” into the bitmap image. Then we convert all the characters of this message into the 8-bit binary number to encode. For instance, the first charter N can be encoded as:  
The corresponding ASCII value of N is: 78  
The corresponding binary value of 78 can be obtained as : 01001110  
Then, each bit of this binary number replaces the least significant bit of the the pixel of the image as:  
Here, each box represents the position of LSB of a particular pixel of the BMP image.  

<img width="464" alt="Screen Shot 2023-10-29 at 5 12 08 PM" src="https://github.com/Sushil298/Image-Steganography/assets/80779647/14ec78bf-e0c8-4185-9b77-1bc00a5df5fc">

Similarly, other characters of the secret message are encoded. At last null terminating character ‘\n’  with binary equivalent 00000000 is added to mark the end of the secret message.  

The other messages like “HELLO WORLD (-_-). The secret number is 0123456789.”  
and “ The random symbols are : “ *&%@# ” ” can be encoded into the bmp image by replacing the LSB of each pixel of the image by bits of the secret message.  
 
## Test case 3: Decryption

The decryption is done character by character until the null terminating character is found. For this, the 8 least significant digits are taken from the consecutive eight pixels of the stego image. Then, these bits are combined to form a character. This process is repeated until the null terminating character is found to get all the characters of the secret message.   

Suppose we have the message “New York University Abu Dhabi !!” encoded into the BMP image. Then we can decode it by the following process.
The image must have contained the binary bits of all characters in the least significant position of each pixel. So, we take the 8 consecutive pixels of the image and extract the least significant bits. From the first 8 consecutive pixels of the image, we obtain:  01110010 (inverted binary number)  
The decimal equivalent of this number is: 0\*2^0 + 1\*2^1 + 1\*2^2 + 1\*2^3 + 0\*2^4 + 0\*2^5 + 1\*2^6 +  0\*2^7 
                                          = 78  
The equivalent character of 78 is: N  
Similarly, next 8 pixels are decoded to get the next character and so on until the null terminating character is found. In this way, the whole message“New York University Abu Dhabi !!” can be decoded.  

Other messages like “HELLO WORLD (-_-). The secret number is 0123456789.”  
and “ The random symbols are: “ *&%@# ” ” can also be decoded using the above procedure.   

## Test case 4: Exit the Program

Enter ‘x’ to exit the program.  
Print the message “Program Terminating….” and exit the program.  

## Test case 5: Failure to open the File

If the filename input by the user is not found in the project directory, the program must display the message “Failed to open the image file ” and repeat the main menu.  

# User’s Guide
The program will help you to encrypt the secret message into a bmp image and also decode the secret message encrypted into a BMP image. To run the program, compile the cpp file named “main.cpp”. Also make  sure that the provided header files “Bitmap.h”, “Encrypt.h” and “Decrypt.h” are also included. The user should also keep the BMP image file from which he/she wants to extract the secret message or into which he/she wants to encrypt the secret message in the project directory. 



