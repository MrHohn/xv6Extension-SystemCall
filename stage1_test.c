#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

void handle_signal(int signum)
{
	printf(1, "Caught signal %d...\n", signum);
	if (signum == SIGFPE)
		printf(1, "TEST PASSED\n");
	else
		printf(1, "TEST FAILED: wrong signal sent.\n");
	exit();
}

int main(int argc, char *argv[])
{

	int x = 5;
	int y = 0;


	signal(SIGFPE, handle_signal);

	x = x / y;

	printf(1, "TEST FAILED: no signal sent.\n");
	
	exit();
}