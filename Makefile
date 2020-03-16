# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 08:39:15 by amalsago          #+#    #+#              #
#    Updated: 2020/03/16 21:48:37 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

PROJECT_NAME   = lem-in
LIBNAME        = libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC            = gcc
WOPT           = -Wall -Wextra -Werror# -fsanitize=address# -g3
OOPT           = -O2
IOPT           = -I $(INCDIR) -I $(LIBDIR)/include

# **************************************************************************** #
# System commands

AR             = ar -rc
MAKE           = make -sC
RANLIB         = ranlib
NORMINETTE     = norminette
MKDIR          = mkdir -p
RM             = rm -rf

# **************************************************************************** #
# Directories of source and object files

LIBDIR         = libft
SRCDIR         = ./sources
OBJDIR         = ./objects
INCDIR         = ./includes

# **************************************************************************** #
# List of source files

PARSING        = parsing/save_raw_input.c\
                 parsing/parse_input.c

SRCNAME        = main.c\
                print_help.c\
                initialize_farm.c\
                tools.c\
				predicates.c\
                $(PARSING)

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files

SRC            = $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ            = $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT            = $(addprefix $(LIBDIR)/, $(LIBNAME))

# **************************************************************************** #
# Extra

CR             = "\r"$(CLEAR)
CLEAR          = "\\033[0K"
EOC            = "\033[0;0m"
RED            = "\033[0;31m"
GREEN          = "\033[0;32m"
BASENAME       = `basename $(PWD)`

# **************************************************************************** #
# Rules

all: $(LFT) $(PROJECT_NAME)

$(LFT): FORCE
	@$(MAKE) $(LIBDIR)

$(PROJECT_NAME): $(LFT) $(OBJ)
	@$(GCC) $(EMF) $(WOPT) $(OBJ) $(LFT) -o $(PROJECT_NAME)
	@printf $(CR)$(GREEN)"✓ $(PROJECT_NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(GCC) $(EMF) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	@printf $(CR)"[ $(BASENAME)/%s ]"$(CLEAR) $@

clean:
	@if [ -d $(OBJDIR) ]; then \
		$(MAKE) $(LIBDIR) clean \
		&& $(RM) $(OBJDIR) \
		&& printf $(CR)$(RED)"✗ The objects files of $(PROJECT_NAME) are cleaned\n"$(EOC); \
	fi

fclean: clean
	@if [ -e $(PROJECT_NAME) ]; then \
		$(MAKE) $(LIBDIR) fclean \
		&& $(RM) $(PROJECT_NAME) \
		&& printf $(CR)$(RED)"✗ $(PROJECT_NAME) is cleaned\n"$(EOC); \
	fi

re: fclean all

norm:
	@$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources $(LIBDIR)/includes

.PHONY: all clean fclean re norm

FORCE:
