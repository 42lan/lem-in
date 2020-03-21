/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:12:56 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/21 17:13:37 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdint.h>

size_t	ft_arraysize(char **array);
int		ft_count_words(char const *s, char c);
size_t	ft_silen(intmax_t number, int base);
size_t	ft_uilen(uintmax_t number, int base);
int		ft_isseparator(char c, char separator);
char	*ft_strtok(char *str, const char *sep);
size_t	ft_strspn(const char *s, const char *charset);
size_t	ft_strcspn(const char *s, const char *charset);

/*
** LIB_H
*/
#endif
