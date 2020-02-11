/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:02:14 by jkarren           #+#    #+#             */
/*   Updated: 2019/12/04 18:27:43 by jkarren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Double Linked List
*/

typedef struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_alist	*prev;
	struct s_alist	*next;
}				t_dlist;

/*
** XOR Linked List
*/

typedef struct	s_xlist
{
	void			*content;
	size_t			content_size;
	struct s_xlist	*npx;
}				t_xlist;

/*
** Binary Tree
*/

typedef struct	s_btree
{
	void			*content;
	size_t			content_size;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;

/*
** MEMORY BLOCK
*/

void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memdup(void const *content, size_t content_size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t n);
void			*ft_realloc(void *ptr, size_t len, size_t new_len);

/*
** STRING BLOCK
*/

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strcdel(char *str, const char c);
void			ft_strsdel(char *str, const char *arr);
void			ft_strrepl(char *str, const char c, const char replacement);
void			ft_strsrepl(char *str, const char *arr, const char replacement);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			ft_strclr(char *s);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *big, const char *little, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));

/*
** LIST BLOCK
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdup(void const *content, size_t content_size);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstpush(t_list **root, void const *content,
		size_t content_size);
void			ft_lstinsert(t_list *prev_node, void const *content,
		size_t content_size);
void			ft_lstappend(t_list **root, void const *content,
		size_t content_size);
void			*ft_lstpop(t_list **root);

/*
** BINARY TREE BLOCK
*/

t_btree			*ft_btrnew(void const *content, size_t content_size);

/*
** SORTING BLOCK
*/

/*
** OUTPUT BLOCK
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);

/*
** ASCII BLOCK
*/

int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);

/*
** TYPES CONVERTATION BLOCK
*/

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

/*
** AUXILIARY BLOCK
*/

size_t			ft_intlen(int n);
int				ft_wordscount(char *str, const char lim_ch);
int				ft_wordlen(char *str, const char lim_ch);
int				ft_isspace(int c);
int				ft_isinarr(char c, char *arr);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_bzero(void *s, size_t n);

#endif
