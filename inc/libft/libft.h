/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:41:03 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/12 21:59:01 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>    // for malloc
# include <unistd.h>    // for read
# include <fcntl.h>     // for open txt file
# include <stdarg.h>
# include <stddef.h>
# include <signal.h> // minitalk

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// FT_PRINTF FUNCTIONS
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printint(int n);
int		ft_printhex(unsigned long n, char format);
int		ft_printptr(void *p);
int		ft_makehex(size_t p);
int		ft_printunsignedint(unsigned int n);
int		ft_printf(const char *string, ...);

// FT_GET_NEXT_LINE FUNCTIONS
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
// get_next_line.c
char	*get_next_line(int fd);
// get_next_line_utils.c
size_t	ft_strlen2(char *s);
char	*ft_strchr2(char *content, int c);
char	*ft_strjoin2(char *c, char *b);
char	*ft_strdup2(char *s1);

#endif
