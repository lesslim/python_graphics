/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:00:48 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 20:40:53 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define BUFF_SIZE 1024

typedef struct		s_list
{
	void			*data;
	size_t			data_size;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isdigit_base(int c, int base);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_bzero(void *s, size_t n);
void				ft_swab(const void *src, void *dest, ssize_t nbytes);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strlwr(char *src);
char				*ft_strupr(char *src);
char				*ft_strrev(const char *str);

char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

char				*ft_strchr(const char *dst, int c);
char				*ft_strrchr(const char *dst, int c);
char				*ft_strcasechr(const char *dst, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strcasestr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
								size_t len);
size_t				ft_strspn(const char *s, const char *charset);
size_t				ft_strcspn(const char *s, const char *charset);
char				*ft_strpbrk(const char *s, const char *charset);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);

char				*ft_strtok(char *str, const char *sep);
char				*ft_strsep(char **stringp, const char *delim);

long				ft_pow(int base, int exp);
int					ft_atoi(const char *str);
double				ft_atoi_base(const char *str, int base);
char				*ft_itoa(int n);
char				*ft_itoa_base(double num, int base, int precision);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstfind(t_list *lst, void *trg);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddnum(t_list **alst, t_list *new, size_t n);
void				ft_lstaddlast(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelnum(t_list **alst, void (*del)(void *, size_t), \
								size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					get_next_line(const int fd, char **line);

#endif
