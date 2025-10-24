/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:11:25 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/23 20:46:26 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
void	*ft_memset(void *src, int value, size_t len);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *src, size_t len);
char	*ft_strdup(const char *src);
int		ft_tolower(int C);
int		ft_toupper(int c);
int		ft_isalnum(int x);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strrchr(const char *string, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *s, ...);
void	ft_strrev(char *str);
int		ft_intlen(unsigned int n);
char	*ft_utoa(unsigned int n);
long	ft_ltoi(const char *nptr);
char	*get_next_line(int fd);
t_list	*ft_lstget_index(t_list *lst, size_t index);
int		ft_abs(int value);
void	ft_sort_int_tab(int *tab, int size);

#endif
