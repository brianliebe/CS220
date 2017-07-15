Question 1 - 

First, it iterates through dst and makes all the values '\0'. Then, it'll copy num_bytes characters in src to dst or until it finds a '\0' in src. After, it'll ensure the the remaining chars in dst will be '\0'. 

Question 2 -

Saves temp as the value saved at *num1, then I made *num2 to be *num2, and *num2 to be temp. Simple.

Question 3 -

I stored the value for *num1 at the address of num2 + 1. I then set *num1 as *num2, and *num2 as the value at num2 + 1.
