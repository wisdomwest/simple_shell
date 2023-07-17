steps to shell:

Initialize: 

In this step, a typical shell would read and execute its configuration files. These change aspects of the shell’s behavior.

Interpret: 

Next, the shell reads commands from stdin (which could be interactive, or a file) and executes them.


Terminate: 

After its commands are executed, the shell executes any shutdown commands, frees up any memory, and terminates.


steps for looping shell:

Read: Read the command from standard input.(using getline)
Parse: Separate the command string into a program and arguments.(using strtok)
Execute: Run the parsed command.