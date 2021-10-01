/**
 * Contributor info : 
 * Name: Riya Bhandari
 * Github: https://github.com/RiyaBhandari-2811
 */

 
/**
*👉 Problem: Reverse a string 
*Description: Write a Program to reverse a string using recursion 
*/


class String_Reverse 
{ 
    //recursive method to reverse a given string
    void reverseString(String str) 
    { 
        //base condition; return if string is null or with 1 or less character 
        if ((str==null)||(str.length() <= 1)) 
           System.out.println(str); 
        else
        { 
            //recursively print each character in the string from the end 
            System.out.print(str.charAt(str.length()-1)); 
            reverseString(str.substring(0,str.length()-1)); 
        } 
    }
}
class Main{
    public static void main(String[] args)  
    { 
        String inputstr = "SoftwareTestingHelp";
        System.out.println("The given string: " + inputstr);
        String_Reverse obj = new String_Reverse(); 
        System.out.print("The reversed string: ");
        obj.reverseString(inputstr); 
          
    }     
}