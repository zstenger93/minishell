NAME			= minishell
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
DN				= > /dev/null

SRC_DIR			= src/
OBJ_DIR			= obj/

LIBFT			= libft/libft.a

MAIN			= main/minishell

ENV_PATH		= main/parser/env_path/ \
				  main/parser/env_path/ \

INPUT			= main/parser/input/ \
				  main/parser/input/ \

COMMANDS		= main/executor/commands/builtins \
				  main/executor/commands/builtins \

INIT			= main/executor/init/ \
				  main/executor/init/ \

SIGNALS			= main/executor/signals/ \
				  main/executor/signals/ \

EXECUTE			= main/executor/execute/ \
				  main/executor/execute/ \

SUBHSHELL		= main/subshell/ \

PARSER			= $(ENV_PATH) $(INPUT)

EXECUTOR		= $(COMMANDS) $(INIT) $(SIGNALS) $(EXECUTE)

CLEANUP_TOOLS	= cleanup_tools/free/ \
				  cleanup_tools/free_at_error/ \

UTILS			= utils/ \

SOURCE			= $(MAIN) $(PARSER) $(EXECUTOR) $(CLEANUP_TOOLS) $(UTILS)

SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))

#READLINE HEADER HERE
INCL_RDL_HEADER	=
#READLINE LIB HERE
INCL_RDL_LIB	=

all: $(NAME)

$(NAME):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(PURPLE)$(NAME) Bonus part By:$(DEF_COLOR) $(RED)The Mr. Minishell Community$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(CC) $(CFLAGS) $(LIBFT) $(DN)
	@echo "$(PURPLE)$(NAME) $(DEF_COLOR)$(GREEN)Compiling done.$(DEF_COLOR)"
	@echo "$(RED) ████▒░▒████▒░██▒░███▒░  █▒░██▒░ ████▒░ ██▒░░▒██▒░██████▒░██▒░    ██▒░"
	@echo " ██▒██▒██▒██▒░██▒░█▒██▒░ █▒░██▒░█▒░ ██▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo " ██▒░███▒░██▒░██▒░█▒░██▒░█▒░██▒░  ██▒░  ████████▒░████▒░  ██▒░    ██▒░"
	@echo " ██▒░░█▒░ ██▒░██▒░█▒░ ██▒█▒░██▒░██▒░ █▒░██▒░░▒██▒░██▒░    ██▒░    ██▒░"
	@echo " ██▒░░░   ██▒░██▒░█▒░  ███▒░██▒░ ████▒░ ██▒░░▒██▒░██████▒░██████▒░██████▒░"
	@echo " ▓▓▒░░     ▓░▒▓▓▒░    ░▒▓▓▒░▓▒░ ░▒▓▓▒░   ▓▒░░▒▓▒░░▒▓▓▒░░░░░░▒▓▓▒░░░▒▓▓▒░"
	@echo " ▓▒░░       ░▒▓▒░     ░▒▓▒░      ░▒▓     ▒░   ▒░  ░▒▓▒░   ░░▒▓▒░  ░░▒▓▒░"
	@echo " ▒░░          ▒░        ▒░        ░░     ░    ░    ░▒░     ░▒▒░    ░▒▒░"
	@echo " ░░           ░         ░          ░                ░       ░░      ░░"
	@echo " ░                                                           ░       ░"


#FILL THIS UP WITH THE DIRECTORIES
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/
	@$(CC) $(CFLAGS) -c $< -o $@ $(DN)

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
	@$(RM) $(OBJ_DIR) $(BONUS_OBJS) $(DN)
	@make clean -C ./libft $(DN)
	@echo "$(RED)Object files have been successfully removed!$(DEF_COLOR)"

fclean:
	@make clean $(DN)
	@echo "$(CYAN)FCLEAN$(DEF_COLOR)"
	@echo "$(RED)Deleting objects, executables.$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(RM) $(NAME) $(BONUS_NAME) $(DN)
	@make fclean -C ./libft $(DN)
	@$(RM) pipex.dSYM $(DN)
	@$(RM) pipex_bonus.dSYM $(DN)
	@echo "$(RED)Executable and object files have been successfully removed.$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

run: all
	clear
	@./$(NAME)

v: all
	valgrind --read-var-info=yes --leak-check=full --track-origins=yes ./$(NAME)

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
