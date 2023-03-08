NAME			= minishell
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
DN				= > /dev/null
RM				= rm -rf
SRC_DIR			= src/
OBJ_DIR			= obj/
LIBFT			= libft/libft.a
OS				= $(shell uname)

MAIN			= main/minishell \
				  main/shell_loop \
				  main/prompt \
				  main/main_utils \

BUILTINS		= builtins/env/env_utils \
				  builtins/env/env \
				  builtins/pwd/pwd \
				  builtins/exit/exit \
				  builtins/export/export \
				  builtins/export/export_utils \
				  builtins/unset/unset \
				  builtins/cd/cd \
				  builtins/cd/cd_utils \
#   builtins/echo/

INIT 			= init/init \

LEXER			= lexer/lexer \

PARSER			= 

EXECUTOR		= 

CLEANUP_TOOLS	= cleanup_tools/free_at_error/free_at_error \
				  cleanup_tools/free/free \

GENERAL_UTILS	= general_utils/error \

SOURCE			= $(MAIN) $(INIT) $(BUILTINS) $(LEXER) $(GENERAL_UTILS) $(CLEANUP_TOOLS)

SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))

ifeq ($(OS), Linux)
INCL_RDL_HEADER	= -I /home/linuxbrew/.linuxbrew/opt/readline/include/readline
INCL_RDL_LIB	= -lreadline -L /home/linuxbrew/.linuxbrew/opt/readline/lib
else
INCL_RDL_HEADER	= -I /Users/zstenger/.brew/opt/readline/include
INCL_RDL_LIB	= -lreadline -L /Users/zstenger/.brew/opt/readline/lib
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo ""
	@echo "$(YELLOW)  Compiling: $(DEF_COLOR)$(PURPLE)$(NAME) Mandatory Part By:$(DEF_COLOR) $(RED)Mr. Minishell Community$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(CC) $(OBJ) $(INCL_RDL_LIB) $(LIBFT) -lreadline -o minishell $(DN)
	@cd obj/general_utils && touch user.txt && echo $$USER > user.txt
	@echo "$(PURPLE)                       $(NAME) $(DEF_COLOR)$(GREEN)Compiling done.$(DEF_COLOR)"
	@echo ""
	@echo "$(RED) ████▒░▒████▒░██▒░███▒░  █▒░██▒░ ████▒░ ██▒░░▒██▒░██████▒░██▒░    ██▒░"
	@echo " ██▒██▒██▒██▒░██▒░█▒██▒░ █▒░██▒░█▒░ ██▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo " ██▒░███▒░██▒░██▒░█▒░██▒░█▒░██▒░  ██▒░  ████████▒░████▒░  ██▒░    ██▒░"
	@echo " ██▒░░█▒░ ██▒░██▒░█▒░ ██▒█▒░██▒░██▒░ █▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo " ██▒░░░   ██▒░██▒░█▒░  ███▒░██▒░ ████▒░ ██▒░░▒██▒░██████▒░██████▒░██████▒░"
	@echo " ▓▓▒░░     ▓░▒▓▓▒░    ░▒▓▓▒░▓▒░ ░▒▓▓▒░   ▓▒░░▒▓▒░░▒▓▓▒░░░░░░▒▓▓▒░░░▒▓▓▒░"
	@echo " ▓▒░░       ░▒▓▒░     ░▒▓▒░      ░▒▓     ▒░   ▒░  ░▒▓▒░   ░░▒▓▒░  ░░▒▓▒░"
	@echo " ▒░░          ▒░        ▒░        ░░     ░    ░    ░▒░     ░▒▒░    ░▒▒░"
	@echo " ░░           ░         ░          ░                ░       ░░      ░░"
	@echo " ░                                                           ░       ░ $(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(INCL_RDL_HEADER) -c $< -o $@ $(DN)

$(LIBFT):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)LIBFT. $(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@git submodule update --init --recursive --remote $(DN)
	@make -C ./libft $(DN)
	@echo "$(PURPLE)LIBFT $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

clean:
	@echo "$(CYAN)CLEAN$(DEF_COLOR)"
	@echo "$(RED)Deleting objects.$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(RM) $(OBJ_DIR) $(DN)
	@make clean -C ./libft $(DN)
	@echo "$(RED)Object files have been successfully removed!$(DEF_COLOR)"

fclean:
	@make clean $(DN)
	@echo "$(CYAN)FCLEAN$(DEF_COLOR)"
	@echo "$(RED)Deleting objects, executables.$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(RM) $(NAME) $(DN)
	@make fclean -C ./libft $(DN)
	@$(RM) minishell.dSYM $(DN)
	@echo "$(RED)Executable and object files have been successfully removed.$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

run: all
	clear
	@./$(NAME)

v:
	valgrind --read-var-info=yes --leak-check=full --track-origins=yes ./minishell

DEF_COLOR = \033[0;39m
RED = \033[1;4;91m
GREEN = \033[4;92m
CYAN = \033[1;96m
CYAN3 = \033[1;4;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
CYAN2 = \x1B[1;36m

.PHONY: all clean fclean re run v
