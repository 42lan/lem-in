# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 11:54:38 by abaisago          #+#    #+#              #
#    Updated: 2020/04/16 17:40:27 by abosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################
#                            DEFINITIONS                             #
######################################################################

#------------------------------------------------#
#                     PROJECT                    |
#------------------------------------------------#

NAME           := lem-in
PROJECT        := lem-in

#------------------------------------------------#
#                   LIBRARIES                    |
#------------------------------------------------#

LIB_PATH       := lib

LIB_FT_DIR     := $(LIB_PATH)/ft
LIB_FT_NAME    := libft.a
LIB_FT         := $(LIB_FT_DIR)/$(LIB_FT_NAME)
LIB_FT_FLAGS   := -lft

LIB            := $(LIB_FT)

LDFLAGS        := -L$(LIB_FT_DIR)
LDLIBS         := $(LIB_FT_FLAGS)

#------------------------------------------------#
#                   BINARIES                     |
#------------------------------------------------#

CC             := gcc
CFLAGS         := -Wall -Wextra -Werror          \
                  -Wno-unused-parameter          \
                  -Wno-unused-but-set-variable
CPPFLAGS       := -Iincludes                     \
                  -Ilib/ft/include

AR             := /usr/bin/ar
ARFLAGS        := rc
MAKE           := /usr/bin/make
RANLIB         := /usr/bin/ranlib

CP             := /bin/cp
NORMINETTE     := /usr/bin/norminette
MKDIR          := /bin/mkdir
PRINTF         := /usr/bin/printf
RM             := /bin/rm

#------------------------------------------------#
#                    SOURCES                     |
#------------------------------------------------#

SRC_PATH       := sources

SRC_DBG        := print.c
SRC_DBG        := $(addprefix debug/, $(SRC_DBG))

SRC_LIB        := ft_arraysize.c \
	              ft_count_words.c \
	              ft_isseparator.c \
                  ft_silen.c \
                  ft_strcspn.c \
                  ft_strspn.c \
                  ft_strtok.c \
                  ft_uilen.c
SRC_LIB        := $(addprefix lib/, $(SRC_LIB))

SRC_PARSE      := ant.c         \
                  hmap.c        \
                  link.c        \
                  parsing.c     \
                  room.c
SRC_PARSE      := $(addprefix parsing/, $(SRC_PARSE))

SRC_TOOLS      := tools.c \
                  predicates.c \
                  print_help.c \
				  reset_info.c
SRC_TOOLS      := $(addprefix tools/, $(SRC_TOOLS))

SRC_ALGO       := dfs.c \
                  orientation.c \
				  utils.c
SRC_ALGO       := $(addprefix algo/, $(SRC_ALGO))

SRC_NAME       := main.c \
                  lemin.c \
                  $(SRC_DBG) \
                  $(SRC_LIB) \
                  $(SRC_PARSE) \
                  $(SRC_TOOLS) \
				  $(SRC_ALGO)
SRC            := $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH       := obj
OBJ_NAME       := $(SRC_NAME:.c=.o)
OBJ            := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#------------------------------------------------#
#                    RELEASE                     |
#------------------------------------------------#

REL_PATH       := release
NAME           := $(NAME)
REL_OBJ        := $(addprefix $(REL_PATH)/,$(OBJ))
REL_CFLAGS     := $(CFLAGS)

#------------------------------------------------#
#                     DEBUG                      |
#------------------------------------------------#

DBG_PATH       := debug
DBG  	       := $(DBG_PATH)/$(NAME)
DBG_OBJ	       := $(addprefix $(DBG_PATH)/,$(OBJ))
DBG_CFLAGS     := $(CFLAGS) -g -fsanitize=address,undefined

#------------------------------------------------#
#                     EXTRA                      |
#------------------------------------------------#

EOC         := "\033[0;0m"
RED         := "\033[0;31m"
GREEN       := "\033[0;32m"

BASENAME    := `basename $(PWD)`
CREAT       := $(CR)$(GREEN)
DEL         := $(CR)$(RED)
END         := $(EOC)"\033[0K\n"
UP          := "\033[0F"



######################################################################
#                               RULES                                #
######################################################################
.PHONY: all clean fclean re release dbg
.SILENT:

all: release

#------------------------------------------------#
#                 RELEASE-RULES                  |
#------------------------------------------------#

release: $(NAME)

$(NAME): $(LIB) $(REL_OBJ)
	@$(PRINTF) $(CREAT)"[ $(PROJECT): All object files created ]"$(END)
	@$(CC) $(REL_CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@$(PRINTF) $(CREAT)"[ $(PROJECT): $@ created ]"$(END)

$(REL_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(MKDIR) -p $(dir $@) 2>/dev/null || true
	@$(PRINTF) "[ $(PROJECT): %s ]"$(END) $@
	@$(CC) $(REL_CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(PRINTF) $(UP)

#------------------------------------------------#
#                  DEBUG-RULES                   |
#------------------------------------------------#

dbg: $(DBG)

$(DBG): $(LIB) $(DBG_OBJ)
	@$(PRINTF) $(CREAT)"[ $(PROJECT): All debug object files created ]"$(END)
	@$(CC) $(DBG_CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@$(PRINTF) $(CREAT)"[ $(PROJECT): $@ created ]"$(END)

$(DBG_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(MKDIR) -p $(dir $@) 2>/dev/null || true
	@$(PRINTF) "[ $(PROJECT): %s ]"$(END) $@
	@$(CC) $(DBG_CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(PRINTF) $(UP)

#------------------------------------------------#
#                 LIBRARY-RULES                  |
#------------------------------------------------#

### LIBFT

libft: $(LIB_FT)
$(LIB_FT): FORCE
	make -sC $(LIB_FT_DIR)

libft_clean:
	make -sC $(LIB_FT_DIR) clean

libft_dbgclean:
	make -sC $(LIB_FT_DIR) dbgclean

libft_fclean:
	make -sC $(LIB_FT_DIR) fclean

### Library Clean Rules

libclean: libft_clean
libdbgclean: libft_dbgclean
libfclean: libft_fclean

#------------------------------------------------#
#                  CLEAN-RULES                   |
#------------------------------------------------#

thisclean:
	@if [ -d $(REL_PATH)/$(OBJ_PATH) ]; then \
		$(RM) -f $(REL_OBJ) \
		&& $(RM) -rf $(REL_PATH)/$(OBJ_PATH) \
		&& $(PRINTF) $(DEL)"[ $(PROJECT): All object files cleaned ]"$(END); \
	fi

thisdbgclean:
	@if [ -d $(DBG_PATH)/$(OBJ_PATH) ]; then \
		$(RM) -f $(DBG_OBJ) \
		&& $(RM) -rf $(DBG_PATH)/$(OBJ_PATH) \
		&& $(PRINTF) $(DEL)"[ $(PROJECT): All debug object files cleaned ]"$(END); \
	fi

clean: libclean thisclean
dbgclean: libclean thisdbgclean

fclean: libfclean thisclean thisdbgclean
	@for TARGET in $(NAME) $(DBG); do \
		if [ -e "$$TARGET" ]; then \
			$(RM) -f $$TARGET \
			&& $(PRINTF) $(DEL)"[ $(PROJECT): $$TARGET cleaned ]"$(END); \
		fi; \
	done
ifneq '$(REL_PATH)' '.'
	@$(RM) -rf $(REL_PATH)
endif
ifneq '$(DBG_PATH)' '.'
	@$(RM) -rf $(DBG_PATH)
endif

#------------------------------------------------#
#                  OTHER-RULES                   |
#------------------------------------------------#

soft: thisclean all
softdbg: thisdbgclean dbg
shallow: soft softdbg
re: fclean all
redbg: fclean dbg
full: fclean all dbg

clear: all clean
cleardbg: dbg dbgclean
pure: clear cleardbg
whole: all dbg

FORCE:

norme:
	$(NORMINETTE) $(SRC) includes/*.h

update_libft:
	$(RM) -rf $(LIB_FT_DIR)
	git clone http://gitlab.com/abaisago/42_libft $(LIB_FT_DIR)
	$(RM) -rf $(LIB_FT_DIR)/.git* $(LIB_FT_DIR)/tags

update_libht:
	$(RM) -rf $(LIB_HT_DIR)
	git clone http://gitlab.com/abaisago/libht $(LIB_HT_DIR)
	$(RM) -rf $(LIB_HT_DIR)/.git* $(LIB_HT_DIR)/tags
