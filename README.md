# Problem Statement

The objective is to develop a program that can encrypt a text message inside a bitmap image and also decrypt that message.  The software presents the user with a main menu, with options to encode a message, decode a message, and exit the program. When the user selects the encode option, he/she is prompted to enter the secret message and the name of the bitmap file where the secret message must be encoded in. When the user selects the decode option, the program prompts the user for the bitmap image(with text encoded into it)’s name, extracts the secret text message, and displays it on the output screen. When the user selects the exit option, a message confirming exit is printed on the screen and the program is terminated. 

# Relevant Background Information

Steganography is a technique of hiding the data (file, text, image, etc.) within another data file (file, text, image, etc.). Assume an image is represented as a three-dimensional array (M-by-N-by-3 array) where M is the number of pixels in the vertical direction (rows) and N is the number of pixels in the horizontal direction(cols), while each 3-vector corresponds to the blue, green, and red intensities of each pixel. The pixel values are 1-byte characters and are between 0 and 255.. A bitmap image has the following structure. 

![Example Image](Sample_BMP_Image.pmg)


