<h1>Strings</h1>
<br>


Strings are defined as an array of characters. The difference between a character array and a string is the string is terminated with a special character ‘\0’ known as Charater strings as we have studied in C.<br>

Declaration of strings: Declaring a string is as simple as declaring a one-dimensional array. Below is the basic syntax for declaring a string.<br>

char str_name[size];<br>
In the above syntax str_name is any name given to the string variable and size is used to define the length of the string, i.e the number of characters strings will store. Please keep in mind that there is an extra terminating character which is the Null character (‘\0’) used to indicate the termination of string which differs strings from normal character arrays.<br>

<h2>std::string class in C++</h2>

C++ has in its definition a way to represent sequence of characters as an object of class. This class is called std:: string. String class stores the characters as a sequence of bytes with a functionality of allowing access to single byte character. <br>
 

std:: string vs Character Array<br>

 

A character array is simply an array of characters can terminated by a null character. A string is a class which defines objects that be represented as stream of characters.<br>
  
 ![image](https://user-images.githubusercontent.com/91491296/135718570-94752590-ab2e-46b3-bc6b-b23d682cd770.png)


Size of the character array has to allocated statically, more memory cannot be allocated at run time if required. Unused allocated memory is wasted in case of character array. In case of strings, memory is allocated dynamically. More memory can be allocated at run time on demand. As no memory is preallocated, no memory is wasted.<br>
  
 



There is a threat of array decay in case of character array. As strings are represented as objects, no array decay occurs.<br>
  
 

Implementation of character array is faster than std:: string. Strings are slower when compared to implementation than character array.<br>
  
 

Character array do not offer much inbuilt functions to manipulate strings. String class defines a number of functionalities which allow manifold operations on strings.<br>
  
 

Operations on strings<br>

Input Functions<br>
<br>
1. getline() :- This function is used to store a stream of characters as entered by the user in the object memory.<br>
2. push_back() :- This function is used to input a character at the end of the string.<br>
3. pop_back() :- Introduced from C++11(for strings), this function is used to delete the last character from the string.<br><br><br>
 Capacity Functions <br>
4. capacity() :- This function returns the capacity allocated to the string, which can be equal to or more than the size of the string. Additional space is allocated so that when the new characters are added to the string, the operations can be done efficiently.<br>
5. resize() :- This function changes the size of string, the size can be increased or decreased.<br>
6.length():-This function finds the length of the string<br>
7.shrink_to_fit() :- This function decreases the capacity of the string and makes it equal to the minimum capacity of the string. This operation is useful to save additional memory if we are sure that no further addition of characters have to be made.<br>
<br><br><br>
Iterator Functions<br>
8. begin() :- This function returns an iterator to beginning of the string.<br>
9. end() :- This function returns an iterator to end of the string.<br>
10. rbegin() :- This function returns a reverse iterator pointing at the end of string.<br>
11. rend() :- This function returns a reverse iterator pointing at beginning of string.<br>
<br><br>
Manipulating Functions<br>
12. copy(“char array”, len, pos) :- This function copies the substring in target character array mentioned in its arguments. It takes 3 arguments, target char array, length to be copied and starting position in string to start copying.<br>
13. swap() :- This function swaps one string with other.<br>
