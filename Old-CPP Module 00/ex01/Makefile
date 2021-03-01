UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	SHELL				=	/bin/zsh
endif

# Executable name
NAME				=	PhoneBook

# Compilation mode
WALL				=	yes
WEXTRA				=	yes
WERROR				=	yes

FSANITIZE			=	no
DEBUG				=	no
O2					=	no

ifeq ($(UNAME), Linux)
	CC					:=	clang++ -std=c++98
else
	CC					:=	clang++ -std=c++98
endif
GEN					:=	"Generation in mode"

ifeq ($(WALL), yes)
	CC				:=	$(CC) -Wall
	GEN				:=	$(GEN) all
endif

ifeq ($(WEXTRA), yes)
	CC				:=	$(CC) -Wextra
	GEN				:=	$(GEN) extra
endif

ifeq ($(WERROR), yes)
	CC				:=	$(CC) -Werror
	GEN				:=	$(GEN) error
endif

ifeq ($(WEVERYTHING), yes)
	CC				:=	$(CC) -Weverything
	GEN				:=	$(GEN) all
endif

ifeq ($(FSANITIZE), yes)
	CC				:=	$(CC) -fsanitize=address
	GEN				:=	$(GEN) sanitize
endif

ifeq ($(DEBUG), yes)
	CC				:=	$(CC) -g3
	GEN				:=	$(GEN) debug
endif

ifeq ($(O2),yes)
	CC				:=	$(CC) -O2
	GEN				:=	$(GEN) O2
endif

ifeq ($(GEN), "Generation in mode")
	GEN				:=	$(GEN) no flags
endif

# Text format
_DEF				=	$'\033[0m
_END				=	$'\033[0m
_GRAS				=	$'\033[1m
_SOUL				=	$'\033[4m
_CLIG				=	$'\033[5m
_SURL				=	$'\033[7m

# Colors
_BLACK				=	$'\033[30m
_RED				=	$'\033[31m
_GREEN				=	$'\033[32m
_YELLOW				=	$'\033[33m
_BLUE				=	$'\033[34m
_PURPLE				=	$'\033[35m
_CYAN				=	$'\033[36m
_GREY				=	$'\033[37m

# Background
_IBLACK				=	$'\033[40m
_IRED				=	$'\033[41m
_IGREEN				=	$'\033[42m
_IYELLOW			=	$'\033[43m
_IBLUE				=	$'\033[44m
_IPURPLE			=	$'\033[45m
_ICYAN				=	$'\033[46m
_IGREY				=	$'\033[47m

SRC_NAME =			main.cpp   \
					contact.cpp\


SRC_PATH =			./

OBJ_PATH =			./obj/

INC_PATH =			./

INC_NAME =			contact.hpp	\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(patsubst $(SRC_PATH)%.cpp, $(OBJ_PATH)%.o, $(SRC))

.PHONY :	all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ)
		@mkdir -p $(OBJ_PATH)
		@echo "\n$(_WHITE)====================================================$(_END)"
		@echo "$(_YELLOW)		COMPILING $(NAME)$(_END)"
		@echo "$(_WHITE)====================================================$(_END)"
		@$(CC) -o $(NAME) $(OBJ)
		@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t"	\
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

clean:
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(OBJ_PATH)"$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME)

re : fclean all