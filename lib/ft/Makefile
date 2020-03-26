# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 11:54:38 by abaisago          #+#    #+#              #
#    Updated: 2020/03/26 18:06:21 by abaisago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################
#                             VARIABLES                              #
######################################################################

NAME       := libft.a
PROJECT    := libft

CC         := gcc
CFLAGS     := -Wall -Wextra -Werror
CPPFLAGS   := -Iinclude                          \
              -Iinclude/gnl                      \
              -Iinclude/ft_printf

AR         := /usr/bin/ar
ARFLAGS    := rc
MAKE       := /usr/bin/make
RANLIB     := /usr/bin/ranlib

NORMINETTE := /usr/bin/norminette
MKDIR      := /bin/mkdir
PRINTF     := /usr/bin/printf
RM         := /bin/rm

#------------------------------------------------#
#                    SOURCES                     |
#------------------------------------------------#

### FUNCTIONS

SRC_ARRAY2 := ft_array2_clear.c                                      \
              ft_array2_del.c                                        \
              ft_array2_init.c                                       \
              ft_array2_new.c                                        \
              ft_array2_insert.c                                     \
              ft_array2_pop.c                                        \
              ft_array2_push.c                                       \
              ft_array2_remove.c                                     \
              ft_array2_resize.c
SRC_ARRAY2 := $(addprefix array/,$(SRC_ARRAY2))

SRC_CHAR   := ft_isalnum.c         ft_isprint.c                      \
              ft_isalpha.c         ft_isset.c                        \
              ft_isascii.c         ft_isspace.c                      \
              ft_isblank.c         ft_isupper.c                      \
              ft_iscntrl.c         ft_iswhitespace.c                 \
              ft_isdigit.c         ft_isxdigit.c                     \
              ft_isgraph.c         ft_toupper.c                      \
              ft_islower.c         ft_tolower.c
SRC_CHAR   := $(addprefix char/,$(SRC_CHAR))

SRC_CONV   := ft_atoi.c            ft_list_to_arr.c                  \
              ft_atoi_base.c       ft_llitoa.c                       \
              ft_atoll.c           ft_llitoa_base.c                  \
              ft_count_digits.c    ft_llitosa_base.c                 \
              ft_count_udigits.c   ft_lluitoa.c                      \
              ft_getnbr_base.c     ft_lluitoa_base.c                 \
              ft_itoa.c            ft_lluitosa_base.c                \
              ft_itoa_base.c
SRC_CONV   := $(addprefix conversion/,$(SRC_CONV))

SRC_LIST   := ft_list_at.c                 \
              ft_list_behead.c             \
              ft_list_clear.c              \
              ft_list_del.c                \
              ft_list_del_unsafe.c         \
              ft_list_delone.c             \
              ft_list_delone_unsafe.c      \
              ft_list_find.c               \
              ft_list_find_pos.c           \
              ft_list_init.c               \
              ft_list_insert.c             \
              ft_list_iter.c               \
              ft_list_link_new.c           \
              ft_list_map.c                \
              ft_list_merge.c              \
              ft_list_new.c                \
              ft_list_pop.c                \
              ft_list_pop_front.c          \
              ft_list_print.c              \
              ft_list_printone.c           \
              ft_list_push.c               \
              ft_list_push_front.c         \
              ft_list_remove.c             \
              ft_list_remove_back.c        \
              ft_list_remove_front.c       \
              ft_list_rotate.c             \
              ft_list_sorted.c             \
              ft_list_sorted_insert.c      \
              ft_list_swap.c
SRC_LIST   := $(addprefix list/,$(SRC_LIST))

SRC_MATH   := ft_abs_is.c                                            \
              ft_imaxabs.c                                           \
              ft_power.c                                             \
              ft_sqrt.c                                              \
              ft_sqrt_floor.c
SRC_MATH   := $(addprefix math/,$(SRC_MATH))

SRC_MEM    := ft_bzero.c           ft_memdel.c                       \
              ft_memalloc.c        ft_memmove.c                      \
              ft_memccpy.c         ft_memset.c                       \
              ft_memchr.c          ft_memskip.c                      \
              ft_memcmp.c          ft_swap.c                         \
              ft_memcpy.c          ft_swap_float.c
SRC_MEM    := $(addprefix memory/,$(SRC_MEM))

SRC_PRINT  := ft_printerr.c        ft_puterr.c                       \
              ft_printerr_fd.c     ft_putnbr.c                       \
              ft_printerr_vfd.c    ft_putnbr_base.c                  \
              ft_putchar.c         ft_putnbr_fd.c                    \
              ft_putchar_fd.c      ft_putstr.c                       \
              ft_putendl.c         ft_putstr_fd.c                    \
			  ft_putendl_fd.c      ft_putunbr_base.c
SRC_PRINT  := $(addprefix print/,$(SRC_PRINT))

SRC_STR    := ft_make_printable.c  ft_strncat.c                      \
              ft_strdup.c          ft_strncpy.c                      \
              ft_strcapitalize.c   ft_strnequ.c                      \
              ft_strcat.c          ft_strnew.c                       \
              ft_strchr.c          ft_strnstr.c                      \
              ft_strclen.c         ft_strrchr.c                      \
              ft_strclr.c          ft_strsplit.c                     \
              ft_strcmp.c          ft_strstr.c                       \
              ft_strcpy.c          ft_strsub.c                       \
              ft_strdel.c          ft_strtrim.c                      \
              ft_strequ.c          ft_strskip.c                      \
              ft_striter.c         ft_strskip_set.c                  \
              ft_striteri.c        ft_utfecut.c                      \
              ft_strjoin.c         ft_utfecut_index.c                \
              ft_strjoin_free.c    ft_wchar_utfe.c                   \
              ft_strlcat.c         ft_wchar_utfelen.c                \
              ft_strlcpy.c         ft_wputchar.c                     \
              ft_strlen.c          ft_wputstr.c                      \
              ft_strmatch.c        ft_wstr_utfe.c                    \
              ft_strmap.c          ft_wstr_utfelen.c                 \
              ft_strmapi.c         ft_wstrlen.c                      \
              ft_strncmp.c
SRC_STR    := $(addprefix str/,$(SRC_STR))

SRC_STRING := ft_string_append.c                                     \
              ft_string_clear.c                                      \
              ft_string_del.c                                        \
              ft_string_empty.c                                      \
              ft_string_init.c                                       \
              ft_string_insert.c                                     \
              ft_string_remove.c                                     \
              ft_string_resize.c
SRC_STRING := $(addprefix string/,$(SRC_STRING))

### PROJECTS

# GNL
GNL        := get_next_line.c
GNL        := $(addprefix programs/gnl/,$(GNL))

# FT_PRINTF
PF_PERC    := percent.c            specifier.c        \
              type_base.c          type_int.c         \
              type_char.c          type_utils.c       \
              type_date.c          type_cast_utils.c  \
              type_deprecated.c    type_wchar.c       \
              type_floats.c
PF_PERC    := $(addprefix percent/,$(PF_PERC))

PF_CURLY   := curly.c              ctl_sgr.c          \
              ctl_colors.c         curly_utils.c
PF_CURLY   := $(addprefix curly/,$(PF_CURLY))

FT_PRINTF  := ft_printf.c          integers.c         \
              args.c               output.c           \
              floats.c             parsing.c          \
              $(PF_CURLY)          $(PF_PERC)
FT_PRINTF  := $(addprefix programs/ft_printf/,$(FT_PRINTF))

### ALL SOURCES
SRC_NAME   := $(SRC_ARRAY2)   \
              $(SRC_CHAR)     \
              $(SRC_CONV)     \
              $(SRC_LIST)     \
              $(SRC_MATH)     \
              $(SRC_MEM)      \
              $(SRC_PRINT)    \
              $(SRC_STR)      \
              $(SRC_STRING)   \
              \
              $(GNL)          \
              $(FT_PRINTF)
SRC_PATH   := src
SRC        := $(addprefix $(SRC_PATH)/,$(SRC_NAME))

INC_PATH   := include                            \
              include/programs/gnl

OBJ_PATH   := obj
OBJ_NAME   := $(SRC_NAME:.c=.o)
OBJ        := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#------------------------------------------------#
#                    RELEASE                     |
#------------------------------------------------#

REL_PATH   := release
NAME       := $(NAME)
REL_OBJ    := $(addprefix $(REL_PATH)/,$(OBJ))
REL_CFLAGS := $(CFLAGS)

#------------------------------------------------#
#                     DEBUG                      |
#------------------------------------------------#

DBG_PATH   := debug
DBG  	   := $(DBG_PATH)/$(NAME)
DBG_OBJ	   := $(addprefix $(DBG_PATH)/,$(OBJ))
DBG_CFLAGS := $(CFLAGS) -g -fsanitize=address -fsanitize=undefined

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
.PHONY: all clean fclean re debug libs libft
.SILENT:

#------------------------------------------------#
#                 RELEASE-RULES                  |
#------------------------------------------------#

all: $(NAME)

$(NAME): $(REL_OBJ)
	@$(PRINTF) $(CREAT)"[ $(PROJECT): All object files created ]"$(END)
	@$(AR) $(ARFLAGS) $(NAME) $(REL_OBJ)
	@$(RANLIB) $(NAME)
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

$(DBG): $(DBG_OBJ)
	@$(PRINTF) $(CREAT)"[ $(PROJECT): All debug object files created ]"$(END)
	@$(AR) $(ARFLAGS) $(DBG) $(DBG_OBJ)
	@$(RANLIB) $(DBG)
	@$(PRINTF) $(CREAT)"[ $(PROJECT): $@ created ]"$(END)

$(DBG_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(MKDIR) -p $(dir $@) 2>/dev/null || true
	@$(PRINTF) "[ $(PROJECT): %s ]"$(END) $@
	@$(CC) $(DBG_CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(PRINTF) $(UP)

#------------------------------------------------#
#                 LIBRARY-RULES                  |
#------------------------------------------------#

### Library Clean Rules

libclean:
libcleandbg:
libfclean:

#------------------------------------------------#
#                  CLEAN-RULES                   |
#------------------------------------------------#

thisclean:
	@if [ -d $(REL_PATH)/$(OBJ_PATH) ]; then \
		$(RM) -f $(REL_OBJ) \
		&& $(RM) -rf $(REL_PATH)/$(OBJ_PATH) \
		&& $(PRINTF) $(DEL)"[ $(PROJECT): All object files cleaned ]"$(END); \
	fi

thiscleandbg:
	@if [ -d $(DBG_PATH)/$(OBJ_PATH) ]; then \
		$(RM) -f $(DBG_OBJ) \
		&& $(RM) -rf $(DBG_PATH)/$(OBJ_PATH) \
		&& $(PRINTF) $(DEL)"[ $(PROJECT): All debug object files cleaned ]"$(END); \
	fi

clean: libclean thisclean
cleandbg: libcleandbg thiscleandbg

fclean: libfclean thisclean thiscleandbg
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
#                  EXTRA-RULES                   |
#------------------------------------------------#

soft: thisclean all
softdbg: thiscleandbg dbg
shallow: soft softdbg
re: fclean all
redbg: fclean dbg
full: fclean all dbg

neat: all clean
neatdbg: dbg cleandbg
pure: clear cleardbg
whole: all dbg

FORCE:

norme:
	$(NORMINETTE) $(SRC) $(INC_PATH)/*.h
