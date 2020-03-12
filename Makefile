# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 08:39:15 by amalsago          #+#    #+#              #
#    Updated: 2020/03/12 09:57:03 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

PROJECT_NAME   = lem-in
LIBNAME        = libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC            = gcc
WOPT           = -Wall -Wextra -Werror# -g3 -fsanitize=address
OOPT           = -O2
IOPT           = -I $(INCDIR) -I $(LIBDIR)/$(INCDIR)

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

SRCNAME        = main.c

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
		$(RM) $(OBJDIR) \
		&& printf $(CR)$(RED)"✗ The objects files of $(PROJECT_NAME) are cleaned"$(EOC)\
		&& $(MAKE) $(LIBDIR) clean; \
	fi

fclean: clean
	@if [ -e $(PROJECT_NAME) ]; then \
		$(RM) $(PROJECT_NAME) \
		&& printf $(CR)$(RED)"✗ $(PROJECT_NAME) is cleaned\n"$(EOC); \
	fi

re: fclean all

norm:
	@$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources $(LIBDIR)/includes

.PHONY: all clean fclean re norm

FORCE:
