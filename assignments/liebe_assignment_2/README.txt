Brian Liebe

Question 1 - 

First, the program checks for weird circumstances like num >= 1000000000 or num == 0. Then it passes it to the millions fuction, which splits the "millions" part of the number into a number 0<x<999 and passes it through the hundreds fuction to get the number of letters. It passes the rest of the number to thousands, so it'll be a number 0<x999999. Thousands does basically the same thing, but for the thousands. Hundreds will split the number into hundreds, and tens. It figures out hundreds first, then passes the number 0<x<99 to the Tens function. The tens function checks the first digit of the 2 digit number, and passes the second digit to the Ones function. All of this combines together to get the overall number.

Question 2 - 

First, it creates a array sized 32, and sets all values to 0. It creates a temp number to basically preserve the positive/negative value for later. n is then made positive. It then takes the number and uses the module fuction to pull the remainder; this will turn the decimal number into a binary number, in array form. Next, a for loop changes ever 1 to a 0 and a 0 to a 1. Another for loop will find the first 0 and make it a 1, and take the following 1 (it would have to be a 1) and makes it a 0. This is the equivalent of adding 1 to the binary. It then returns (after a for loop) the number of ones in the binary.

Question 3 - 

I created three variables, part1, 2, 3,and 4, which hold the first 1st, 2nd, 3rd, and 4th bytes respectively. I did this using '&' with n, so that it would only take the byte that I wanted (0x00FF0000 for example is the 2nd byte). After, I created another variable 'final' which consists of part2 shifted 8 bits left, part1 shifted 8 bits right, part3 8 bits right, and part4 8 bits left. This is how I switched the bytes to it would be 2143 instead of 1234. For whatever reason, when I run this the 6th test case fails. However when I try to do this manually using online hex<->decimal converters I can't seem to get either of the answers, expected or actual output. Not really sure why what I wrote wouldn't work on that last test case... It is something to do with signed ints? It did work once with a negative number for one test case. Not sure. 
