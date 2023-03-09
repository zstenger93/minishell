
#include "../../includes/minishell.h"

void clear_screen(void)
{
    printf("\033[2J"); // clear screen
    printf("\033[1;1H"); // move cursor to top left corner
}
