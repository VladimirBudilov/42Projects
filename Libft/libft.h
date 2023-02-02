/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:41:15 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/24 23:41:33 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}							t_list;

int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isxdigit(int c);
int				ft_ispunct(int c);
int				ft_islower(int c);
int				ft_isupper(int c);

int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *res, int ch, size_t max_len);
void			*ft_memcpy(void *dst, const void *src, size_t max_len);
void			*ft_memmove(void *s1, const void *s2, size_t max_len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t max_len);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *input_str, int ch);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t max_size);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t max_size);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t max_size);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t max_size);

char			*ft_substr(char const *string, unsigned int start,
					size_t len_for_new_string);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *str, char const *trim_char);
char			**ft_split(char const *s1, char separator);
char			*ft_strmapi(char const *string,
					char (*map_funk)(unsigned int, char));

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *input_str, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int input_nbr, int fd);

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
#endif
