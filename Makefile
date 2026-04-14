NAME			= libft
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I includes -fPIC -MMD -MP
AR				= ar rcs
RM				= rm -f
MKDIR			= mkdir -p

GREEN			= \033[0;32m
RED				= \033[0;31m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
RESET			= \033[0m

UNAME_S			:= $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
SHARED_EXT		= dylib
SHARED_LDFLAGS	= -dynamiclib -Wl,-install_name,@rpath/$(NAME).$(SHARED_EXT)
else
SHARED_EXT		= so
SHARED_LDFLAGS	= -shared
endif

STATIC_NAME		= $(NAME).a
SHARED_NAME		= $(NAME).$(SHARED_EXT)

SRC_DIR		= src
OBJ_DIR		= objects

SRC_FILES	=	ft_atoi.c \
						ft_bzero.c \
						ft_calloc.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_itoa.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_split.c \
						ft_strchr.c \
						ft_strdup.c \
						ft_striteri.c \
						ft_strjoin.c \
						ft_strlcat.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strmapi.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_strtrim.c \
						ft_substr.c \
						ft_tolower.c \
						ft_toupper.c \
						ft_lstadd_back.c \
						ft_lstadd_front.c \
						ft_lstclear.c \
						ft_lstdelone.c \
						ft_lstiter.c \
						ft_lstlast.c \
						ft_lstmap.c \
						ft_lstnew.c \
						ft_lstsize.c

BONUS_FILES =	

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

BONUS_SRCS	= $(addprefix $(SRC_DIR)/, $(BONUS_FILES))
BONUS_OBJS	= $(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))
DEPS		= $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

all: $(STATIC_NAME) $(SHARED_NAME)
	@if [ -f "$(STATIC_NAME)" ] && [ -f "$(SHARED_NAME)" ]; then \
		printf "$(GREEN)[OK] all: %s + %s$(RESET)\n" "$(STATIC_NAME)" "$(SHARED_NAME)"; \
	else \
		printf "$(RED)[FAILED] all: missing output file$(RESET)\n"; \
		exit 1; \
	fi

$(STATIC_NAME): $(OBJS)
	@printf "$(BLUE)[BUILD] static: %s$(RESET)\n" "$(STATIC_NAME)"
	@$(AR) $(STATIC_NAME) $(OBJS)
	@if [ -f "$(STATIC_NAME)" ]; then \
		printf "$(GREEN)[OK] static built: %s$(RESET)\n" "$(STATIC_NAME)"; \
	else \
		printf "$(RED)[FAILED] static build: %s$(RESET)\n" "$(STATIC_NAME)"; \
		exit 1; \
	fi

$(SHARED_NAME): $(OBJS)
	@printf "$(BLUE)[BUILD] shared: %s$(RESET)\n" "$(SHARED_NAME)"
	@$(CC) $(SHARED_LDFLAGS) -o $(SHARED_NAME) $(OBJS)
	@if [ -f "$(SHARED_NAME)" ]; then \
		printf "$(GREEN)[OK] shared built: %s$(RESET)\n" "$(SHARED_NAME)"; \
	else \
		printf "$(RED)[FAILED] shared build: %s$(RESET)\n" "$(SHARED_NAME)"; \
		exit 1; \
	fi

shared: $(SHARED_NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@printf "$(BLUE)[BUILD] bonus$(RESET)\n"
	@$(AR) $(STATIC_NAME) $(OBJS) $(BONUS_OBJS)
	@$(CC) $(SHARED_LDFLAGS) -o $(SHARED_NAME) $(OBJS) $(BONUS_OBJS)
	@if [ -f "$(STATIC_NAME)" ] && [ -f "$(SHARED_NAME)" ]; then \
		printf "$(GREEN)[OK] bonus built$(RESET)\n"; \
	else \
		printf "$(RED)[FAILED] bonus build$(RESET)\n"; \
		exit 1; \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

clean:
	@printf "$(YELLOW)[CLEAN] removing %s$(RESET)\n" "$(OBJ_DIR)"
	@$(RM) -r $(OBJ_DIR)
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		printf "$(GREEN)[OK] clean$(RESET)\n"; \
	else \
		printf "$(RED)[FAILED] clean$(RESET)\n"; \
		exit 1; \
	fi

fclean: clean
	@printf "$(YELLOW)[FCLEAN] removing %s and %s$(RESET)\n" "$(STATIC_NAME)" "$(SHARED_NAME)"
	@$(RM) $(STATIC_NAME) $(SHARED_NAME)
	@if [ ! -f "$(STATIC_NAME)" ] && [ ! -f "$(SHARED_NAME)" ]; then \
		printf "$(GREEN)[OK] fclean$(RESET)\n"; \
	else \
		printf "$(RED)[FAILED] fclean$(RESET)\n"; \
		exit 1; \
	fi

re:
	@printf "$(YELLOW)[RE] full rebuild$(RESET)\n"
	@$(MAKE) fclean
	@$(MAKE) all
	@if [ -f "$(STATIC_NAME)" ] && [ -f "$(SHARED_NAME)" ]; then \
		printf "$(GREEN)[OK] re$(RESET)\n"; \
	else \
		printf "$(RED)[FAILED] re$(RESET)\n"; \
		exit 1; \
	fi

docs:
	@printf "$(BLUE)[DOCS] generating Doxygen documentation$(RESET)\n"
	@doxygen Doxyfile
	@if [ -f "docs/html/index.html" ]; then \
		printf "$(GREEN)[OK] docs generated: docs/html/index.html$(RESET)\n"; \
	else \
		printf "$(RED)[FAILED] docs generation$(RESET)\n"; \
		exit 1; \
	fi

-include $(DEPS)

.PHONY: all clean fclean re bonus shared docs
