Provide real world examples

1 Syntax explanation:
Describe what the following line of C++ code does: int* ptr = &var;

It declares a integer pointer variable called ptr and assigns the memory address of reference integer var to it.
	int x = 6;
	int* ptr = &x;
	cout << ptr << endl;  prints 6
	
Дава адрес на референция за стойноста на var
Real life example: someones address(pointer) is the house with the big red door(reference). 



2 Concept Clarification: 
Explain the difference between a while loop and a do-while loop in C++.

A while loops checks the condition stated before running its code block, which might not initiate at all. A do-while loop has the code block run at least once before checking the condition. It then checks condition whether to continue running that same code block.

int x = 6;
while (x > 10){
	(run thiscode block)
}
do {
	(run this code block at least once)
} (while x > 10);
In this case the first example will not enter the loop. Lets say we need to perform an action 
while(leaving the house) {}


do while усигорява че кода ще тича поне веднъш.

real life example: do clean while (dirty)
while (dirty) clean   
the first example makes cleaning easier since we clean even if its not dirty because once it gets dirty, the cleaning is tougher. bad example, I am overthinking this.

3 Code Analysis:
Given a snippet of C++ code containing a for loop, explain what the loop does, including how many times it iterates and why.
int arr[20];
for (int i=0; i < 20; i++){
	arr[i] = i*i;
}
This loop assigns the squares from integer 0-19.
It iterates 20 times since we start from i = 0, and it stops when it meets the condition of i < 20, while being incremented by 1. (0,1,2...19)

Дава квадрат на цифри от 0-19. итирира с едно(i++)

Real life example: a timer decrements its seconds by one. When it reaches 0, it stops.

4 Function Usage:
Write about how functions prevent code duplication and give an example of a simple C++ function that calculates the square of a number

Once a large piece of code block is needed more than once(even if just once, for clarity's sake) it can be put inside a function which can then be called as many times with just a single statement: function(). this way your 40 line code that needs to be reused can be stated only once inside the function and help the code in the main be more legible.

...
int squared(int){
	return int*int;
}

int main(){
	int n;
	cout << "Enter integer to square: ";
	cin >> n;   //get integer from usr
	cout << squared(n);  // func is called and printed to console
	return 0;
}

Помага за четливост на кода, като се наложи да се повтара или е много дълаг.

Real life example: The process of walking. 
Lift right foot, 
shift momentum forward, 
lower right foot until touching ground, 
lift left foot, 
keep forward momentum, 
lower left foot until touching ground. 
can be replaced as
stepForward(right)
stepForward(left)
and further replaced as
walk();  //if under/above certain speed

5. Memory Management:
Discuss the importance of memory management in C++ and explain the difference between stack and heap memory allocation.

Memory management is important for creating efficient, optimal programs. If done properly, it helps the program run smoother. RAM is somewhat limited and using up too much memory space will cause the computer to run slower.

A stack memory allocation is temporary, data in stack is only available in the function call stack. Once the function is complete, the memory gets deallocated(free'd up) for further use in the program. 
A heap memory allocation is used for objects. This memory space needs to be cleaned after use by the programmer (if needed) while the stack gets automatically cleaned by compiler. The heap memory space is dynamic while the stack size allotted cannot be changed.[1]

Важно е за оптимизация на програми. Стек е по временен и сам се чисти след като функцията преключи. Хийп аксес е по бавен от стек и участва до като не му се даде код да се почисти.

Real life example: Blowing bubbles. The solution container is like the heap. It contains the solution to be put on the circular tool to blow the bubbles. The solution goes on the tool and once blown, bubbles appear (stack) and disappear once their function is complete(probably the air reacts/dries the sphere made of the solution and makes it burst). We need to manually get rid of the solution container once done having fun.

[1] https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/

6. Object oriented Programming:
Explain the concept of encapsulation in C++ and how it is achieved using classes.

Encapsulation allow classes to keep data members to itself. It stays within the scope of the class. public, private and protected allow protection of its private data from external code. To manipulate the classes data, we can only rely on its public functions.[2]

Real life example: A refrigerator. Keeps its data members inside, until we use a public method openDoor() which will let us peak inside to manipulate stored things and functions (temperature change, light switch, getEggCount();). 

Разрешава маниполация на членови даани. Улеснява създаване на обекти.

[2]https://www.geeksforgeeks.org/encapsulation-in-cpp/

7. Error Handling:
Describe how exceptions are used in C++ for error handling, with an example of a try-catch block.

An exception allows an error to pass through the program without  crashing the program due to the error. Knowing where to expect an error, a try-catch block captures the error(exception) and allows us to record it for debugging purposes, to know where the program went wrong and help with details of why WHILE still allowing the program continue executing (if even possible after certain error).

 Catch-all handler, which is activated for any exception[7]:

try { /* */ } catch (...) { /* */ }

Разрешава някой грешки да се случват без да прекъсва програмата и даже ни казва грешката.

Real life example: Safety nets around tall buildings. When someone/something slips off the edge and falls, the net catches that and doesnt damage people/property. We can then see what fell, from where, and we can provide fixes to those problems.

[7]https://en.cppreference.com/w/cpp/language/try_catch

8. STL Containers:
Write about the purpose and use of the std::vector container in C++.

The purpose of the std::vector is to store similar data under one name so it can be grouped and accessed with less code. The vector is useful for its dynamic memory. We can add extra data to it once initialized. 
Data can be added to the front of the group and the back.

Вектор ни разрешава да групираме един вид данни за по лесна маниполация.

Real life example: Vector is a giant warehouse(dynamic memory but still has a limit to how much memory the computer its running on can use) with two entrances/exits. We can push data in from either door. 

9.Pointers and References:
Discuss the difference between pointers and references in C++ and provide scenarios where on might be preferred over the other.

A pointer is a variable that holds an address to a variables memory location. It needs to be dereferenced with * to return the value at that address. A reference is just an alias to a variable. It also holds the address of the data. It needs to be declared and initialized on the same line. A reference gets automatically dereferenced by the compiler.

References are preferred for function parameters and return types.
Pointers are preferred when pointer arithmetic is needed and to implement data structures. [3]

пойнтер показва кам адрес на стойност. референция е адрес на името на променливата.

Real life example: A street address is a pointer to a physical place. A reference holds that address memory in a different name. Say you live in a small town in the only house with a big red door. &"The house with the big red door" would be a reference to your address to your postman.

[3]https://www.geeksforgeeks.org/pointers-vs-references-cpp/

10. Advanced Features:
Explain the concept of templates in C++ and how they support generic programming. Include a simple example of a template function

Templates are similar to function overloading, where it allows us to use the same code and function name but push in different data-type parameters (in templates data type is declared when the template function is called where as in function overloading we need to declare the functions seperately giving which data type it will return before using the function).[4]

#include <iostream>
using namespace std;

template<typename T>
T myMin(T x, T y){
	if (x < y){
		return x;
	} else {
		return y;
	}
}
int main() {
	cout << myMin<double>(20.3,20.1) << endl;
	cout << myMin<int>(30,29) << endl;
	return 0;
}

[4]https://www.geeksforgeeks.org/templates-cpp/

Темплейт е подобно на function overloading като подаваме един и същ брой параметри (и вид данни) и разрешава да исползваме различни видове данни на същата функция написана само веднъж като темплейт.

Real life example - a cup is a container(template) that can hold liquids, solids, and gasses if closed. 






















