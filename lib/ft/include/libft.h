/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:46:22 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/21 11:27:10 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H
# include <math.h>
# include <stdarg.h>
# include <stdint.h>
# include <string.h>
# include <wchar.h>

# define FT_ARRAY_SIZE	8
# define FT_ARRAY_INC	8
# define FT_STRING_SIZE 512
# define FT_STRING_INC	512

typedef	unsigned char	t_byte;
typedef	float_t	t_float;

typedef struct	s_array2 t_array2;
typedef struct	s_ivec2 t_ivec2;
typedef struct	s_ivec3 t_ivec3;
typedef struct	s_list_link t_list_link;
typedef struct	s_list t_list;
typedef struct	s_string t_string;

struct			s_array2
{
	void		**arr;
	size_t		len;
	size_t		size;
};

struct			s_ivec2
{
	int			x;
	int			y;
};

struct			s_ivec3
{
	int			x;
	int			y;
	int			z;
};

struct			s_list_link
{
	t_list_link	*prev;
	void		*content;
	size_t		content_size;
	t_list_link	*next;
};

struct			s_list
{
	t_list_link	*head;
	size_t		size;
};

struct			s_string
{
	char		*buf;
	size_t		len;
	size_t		size;
};

/*
** ARRAY FUNCTIONS
*/
void			ft_array2_clear(t_array2 *array);
void			ft_array2_del(t_array2 **address);
t_array2		*ft_array2_init(void);
void			ft_array2_insert(t_array2 *array, void *text, size_t index);
t_array2		*ft_array2_new(size_t size);
void			ft_array2_pop(t_array2 *array);
void			ft_array2_push(t_array2 *array, void *elem);
void			ft_array2_remove(t_array2 *array, size_t index);
t_array2		*ft_array2_resize(t_array2 *array, size_t size);

/*
** CHAR FUNCTIONS
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isset(int c, char *set);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_iswhitespace(int c);
int				ft_isxdigit(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** CONVERSION FUNCTIONS
*/
int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);
long long		ft_atoll(const char *str);
size_t			ft_count_digits(intmax_t n, uint8_t base);
size_t			ft_count_udigits(size_t n, uint8_t base);
void			ft_getnbr_base(size_t value, uint8_t base,
					char *res, size_t *index);
char			*ft_itoa(intmax_t n);
char			*ft_itoa_base(int n, uint8_t base);
char			*ft_llitoa(int64_t n);
char			*ft_llitoa_base(int64_t value, uint8_t base);
char			*ft_llitosa_base(int64_t value, int8_t base, char *tab);
char			*ft_lluitoa(uint64_t n);
char			*ft_lluitoa_base(uint64_t value, uint8_t base);
char			*ft_lluitosa_base(size_t value, int8_t base, char *tab);

/*
** LIST FUNCTIONS
*/
t_list_link		*ft_list_at(t_list *list, unsigned pos);
void			ft_list_behead(t_list **list);
void			ft_list_del(t_list **alist, void (*del)(void *, size_t));
void			ft_list_del_unsafe(t_list_link **alink,
					void (*del)(void *, size_t));
void			ft_list_delone(t_list *list, t_list_link *link,
					void (*del)(void*, size_t));
void			ft_list_delone_unsafe(t_list_link **alink,
					void (*del)(void*, size_t));
t_list_link		*ft_list_find(t_list *list, void *data, int (*cmp)());
unsigned		ft_list_find_pos(t_list *list, void *data, int (*cmp)());
t_list			*ft_list_init(void);
void			ft_list_insert(t_list *list,
					t_list_link *dst, t_list_link *src);
void			ft_list_iter(t_list *list, void (*f)(t_list_link *elem));
t_list_link		*ft_list_link_new(void const *content, size_t content_size);
t_list_link		*ft_list_map(t_list *list,
					t_list_link *(*f)(t_list_link *elem),
					void (*del)(void*, size_t));
void			ft_list_merge(t_list *a, t_list **b);
t_list			*ft_list_new(t_list_link *link);
int				ft_list_print(t_list *list,
					int (*print)(void *, size_t, unsigned));
int				ft_list_printone(t_list_link *link, unsigned pos,
					int (*print)(void *, size_t, unsigned));
t_list_link		*ft_list_pop(t_list *list);
t_list_link		*ft_list_pop_front(t_list *list);
void			ft_list_push(t_list *list, t_list_link *link);
void			ft_list_push_front(t_list *list, t_list_link *link);
void			ft_list_remove(t_list *list, t_list_link *link,
					void (*del)(void *, size_t));
void			ft_list_remove_back(t_list *list,
					void (*del)(void *, size_t));
void			ft_list_remove_front(t_list *list,
					void (*del)(void *, size_t));
void			ft_list_rotate(t_list *list, int rot);
int				ft_list_sorted(t_list *list, int (*cmp)());
void			ft_list_sorted_insert(t_list *list, t_list_link *link,
					int (*cmp)());
void			ft_list_swap(t_list_link *a, t_list_link *b);

/*
** MATHS FUNCTIONS
*/
int				ft_abs_is(intmax_t *n);
int				ft_imaxabs(intmax_t j);
int				ft_power(int nb, int power);
int				ft_sqrt(int nb);
int				ft_sqrt_floor(int nb);

/*
** MEMORY FUNCTIONS
*/
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_memskip(const char *s, int (*f)(int));
void			ft_swap(intmax_t *v1, intmax_t *v2);
void			ft_swap_float(t_float *v1, t_float *v2);

/*
** PRINT FUNCTIONS
*/
void			ft_printerr(const char *fmt, ...);
void			ft_printerr_fd(int fd, const char *fmt, ...);
void			ft_printerr_vfd(int fd, const char *fmt, va_list ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_puterr(const char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_base(int nbr, char *base);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(const char *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putunbr_base(unsigned int nbr, char *base);

/*
** STR FUNCTIONS
*/
char			*ft_make_printable(char *str);
char			*ft_strdup(const char *src);
char			*ft_strcapitalize(char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
size_t			ft_strclen(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
void			ft_strdel(char **as);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char const *s1, char const *s2, char c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
int8_t			ft_strmatch(char *match, char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
size_t			ft_strskip(const char *s, int (*f)(int));
size_t			ft_strskip_set(const char *s, char *set);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
void			ft_utfecut(char *str, size_t len);
size_t			ft_utfecut_index(char *str, size_t len);
char			*ft_wchar_utfe(wchar_t c);
int8_t			ft_wchar_utfelen(wchar_t c);
char			*ft_wstr_utfe(wchar_t *str);
size_t			ft_wstr_utfelen(wchar_t *str);
void			ft_wputchar(wchar_t c);
void			ft_wputstr(wchar_t *str);
size_t			ft_wstrlen(wchar_t *c);

/*
** STRING FUNCTIONS
*/
void			ft_string_append(t_string *string, const char *text);
void			ft_string_del(t_string **address);
void			ft_string_clear(t_string *string);
void			ft_string_empty(t_string *string);
t_string		*ft_string_init(void);
void			ft_string_insert(t_string *string, const char *text,
					size_t index);
void			ft_string_remove(t_string *string, size_t index,
					size_t size);
t_string		*ft_string_resize(t_string *string, size_t new_size);

/*
** PROGRAMS
*/
int				ft_dprintf(int fd, const char *fmt, ...);
int				ft_printf(const char *restrict fmt, ...);
int				ft_vdprintf(int fd, const char *fmt, va_list ap);
int				get_next_line(const int fd, char **line);

/*
*************
** LIBFT_H **
*************
*/
#endif
