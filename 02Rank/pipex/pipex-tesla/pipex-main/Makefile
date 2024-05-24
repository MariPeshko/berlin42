#### MAIN SETTINGS ####

CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra -pedantic -O3
LIBS			:= -Llibft/ -Lft_printf/ -lft -lftprintf 
INCLUDES		:= -Iinclude/ -Ilibft/ -Ift_printf/includes

TARGET			:= pipex

SRC_DIR			:= src/
SRC_FILES		+= pipex.c					# Main
SRC_FILES		+= parsing/args.c			# Parsing
SRC_FILES		+= parsing/cmd.c			# #
SRC_FILES		+= parsing/parse_files.c	# #
SRC_FILES		+= execute.c				# Command execution
SRC_FILES		+= checks.c					# Input validation
SRC_FILES		+= utils.c					# Helper functions
SRC_FILES		+= error_handling.c			# Error management

OBJ_DIR			:= obj/
OBJ_FILES		:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))

DEP_DIR			:= dep/
DEPENDS			:= $(patsubst %.o, $(DEP_DIR)%.d, $(OBJ_FILES))
-include $(DEPENDS)

#### SHELL COMMANDS ####

RM				:= /bin/rm -f
MKDIR			:= /bin/mkdir -p
TOUCH			:= /bin/touch

define	PRINT
	@echo "$(strip $(1))[$(TARGET) -" \
	"$(shell printf '%6s' $(strip $(2)))]:$(strip $(5))" \
	"$(BOLD)$(strip $(3))$(RESET) $(strip $(5))$(strip $(4))$(RESET)"	
endef

#### LOCAL LIBRARIES ####

FT_PRINTF_PATH	:= ft_printf/
FT_PRINTF_LIB	:= $(FT_PRINTF_PATH)libftprintf.a

LIBFT_PATH		:= libft/
LIBFT_LIB		:= $(LIBFT_PATH)libft.a

LIB_DEPENDS: $(LIBFT_LIB) $(FT_PRINTF_LIB)

#### DEBUG SETTINGS ####

ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -O0
endif

#### TARGET COMPILATION ####

.DEFAULT_GOAL	:= all

all: $(TARGET) ## Build this project

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(@D)
	$(call PRINT, $(CYAN), "build", "compiling", "$@", $(CYAN))
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJ_FILES) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	$(call PRINT, $(GREEN), "build", "🔗 linking", "-- $(TARGET)", $(GREEN))
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) $(INCLUDES) $(LIBS)
	$(call PRINT, $(GREEN), "info", "✨ Build finished!")
	-@echo -n "🚀 $(MAGENTA)" && ls -lah $(TARGET) && echo -n "$(RESET)"

#### LOCAL LIBS COMPILATION ####

$(FT_PRINTF_LIB):
	@$(MAKE) -sC $(FT_PRINTF_PATH)

$(LIBFT_LIB):
	@$(MAKE) -sC $(LIBFT_PATH)

#### ADDITIONAL RULES ####

clean: ## Clean objects and dependencies
	@$(RM) $(OBJ_FILES)
	@$(RM) -r $(OBJ_DIR)
	$(call PRINT, $(YELLOW), "clean", "Remove objects", $(YELLOW))
	@$(RM) $(DEPENDS)
	@$(RM) -r $(DEP_DIR)
	$(call PRINT, $(YELLOW), "clean", "Remove dependencies", $(YELLOW))
	@(test -s $(FT_PRINTF_LIB) && $(MAKE) -sC $(FT_PRINTF_PATH) clean)
	@(test -s $(LIBFT_LIB) && $(MAKE) -sC $(LIBFT_PATH) clean)

fclean: clean ## Restore project to initial state
	@$(RM) $(TARGET)
	$(call PRINT, $(YELLOW), "fclean", "Remove \`$(TARGET)\`", $(YELLOW))
	@(test -s $(FT_PRINTF_LIB) && $(MAKE) -sC $(FT_PRINTF_PATH) fclean)
	@(test -s $(LIBFT_LIB) && $(MAKE) -sC $(LIBFT_PATH) fclean)

re: fclean all ## Rebuild project

help: ## Show help info
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

.PHONY: all re clean fclean help

#### COLORS ####
# Color codes
RESET		:= \033[0m
BOLD		:= \033[1m
UNDERLINE	:= \033[4m

# Regular colors
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
MAGENTA		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m

# Background colors
BG_BLACK	:= \033[40m
BG_RED		:= \033[41m
BG_GREEN	:= \033[42m
BG_YELLOW	:= \033[43m
BG_BLUE		:= \033[44m
BG_MAGENTA	:= \033[45m
BG_CYAN		:= \033[46m
BG_WHITE	:= \033[47m
