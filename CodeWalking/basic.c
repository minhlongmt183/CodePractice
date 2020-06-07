#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
	char buffer[10] = {0};
	printf("what's your name?\n");
	read(STDIN_FILENO, buffer, 100);
	printf("Hello %s\n", buffer);
	return 0;	
}
