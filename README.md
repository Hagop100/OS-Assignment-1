# OS-Assignment-1
Program Description

The purpose of this assignment was to implement the functions fork(), exec(), and wait()
to create parent/child processes where the parent can communicate information to its children.
We will be giving gender-name pairs (e.g. boy Nick) to our parent through the command line,
and we will create an equal number of child processes as the number of gender-name pairs. For
example, if we say “boy Nick girl Natalie girl Jill” there will be 3 child processes. Once the child
processes are created, they will simply print to the command line which child number they are,
what gender they are, and what name they were given. We create the child processes through
the fork() function, and execute them with the exec() function. Finally we will use the wait()
function to make sure the parent does not complete its execution until all the child processes
are done executing.

The parent program is responsible for creating the child processes. We can do this with
a for loop. We will run a for loop starting from i = 1 and ending when i <= (argc - 1). Remember
that argc is an integer that represents the number of arguments passed in through the
command line upon executing the parent. Since the first index is the executable (filename), we
subtract one so that we are left with the gender-name pairs. Finally, i is incremented by 2 so that
we can walk through each element as a pair and fork() will only execute as many times as there
are pairs. We will fork() immediately after. This creates our first child process. We increment our
childIndex from 0 to 1, which tells us we are on child #1. Then we create a char* array called
childArgs. This will simply be passed into exec() for our child process. The first index will contain
the filename. The rest of the indices will contain information about that specific child; the child
number, the gender, and the name. The array is NULL terminated as well. Then we will use
if-statements to check if we are in a parent or child process. If the process id returned by fork()
is 0, then we are in the child process. We will call exec() here to execute that specific child
process. If the process id is greater than 0, we are in the parent. We will then call wait(NULL) to
make sure that the parent waits for the children to finish executing. If we do not call wait(NULL)
the parent will terminate and the child processes will never finish completing themselves. If the
process id is less than 0, that is a fork failure, and we print an error message.
The child program has a very simple task, and that is to display its components passed
in through its second parameter, char* argv[]. Because of the way we pass in the values in the
parent process, the index at which the child number, child gender, and child name are stored will
always be 1, 2, and 3 respectively. Remember that the 0th index contains the filename. We will
simply print these statements to the console using std::cout and we are done.
