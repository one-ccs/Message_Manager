#include "MessageManager.h"

int main(int argc, char *argv[])
{
    BOOL state = FALSE;

	while(!state) {
		state = main_loop(argc, argv);
	}
	CL_SetPosition(0, IP_RAW + 1);

	return 0;
}
