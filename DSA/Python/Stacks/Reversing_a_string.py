# This is a program to reverse a string using stack
# Example - 
# input string -  define
# output string - enifed

# Reverse a string using stack 
def createStack(): 
    stack = []
    # Creates a new list 
    return stack

def size(stack): 
    return len(stack)

def isEmpty(stack) :
    # checking is the stack is empty 
    if size(stack)==0: 
        return True
 
def push(stack , item) : 
    # appends/pushes the item in the stack
    # and increases the stack size by 1 
    stack.append(item)

def pop(stack ): 
    if isEmpty(stack): 
        return 
    return stack.pop()  # removes an item from the back of the stack

# Reverse function 
def reverse(string): 
    n = len(string )

    stack = createStack()   # create a new empty stack

    #push all the characters of string to stack
    for i in range(0 , n , 1): 
        push(stack , string[i])
    
    # making the string empty since all
    # characters are saved to string 
    string = ""
    for i in range(0 , n , 1): 
        string = string + pop(stack)
    
    return string 

# main function 
def main():
    string = input("Enter string : ").strip(' ')
    string= reverse(string)
    print("Reversed string :" , string)
    
main()
