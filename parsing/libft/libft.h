/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:09 by qdo               #+#    #+#             */
/*   Updated: 2024/05/17 00:53:44 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

// there are 1.libft 2.get_next_line 3.ft_printf and 4.ft_printf_fd
// get_next_line -only 1 file descriptor. call get_next_line(-1) to emmty buffer
// ft_print_fd(int fd, const char *str_o, ...);
// ft_printf(const char *str_o, ...);
// ft_split(char *str, char *separator)

/**************************   BASIC C FUNCTIONS   ***************************/
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int a);
int		ft_isalpha(int a);
int		ft_isascii(int a);
int		ft_isdigit(int a);
int		ft_isprint(int a);
size_t	ft_strlen(const char *a);
char	*ft_strcpy(char *dest, char *src);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst,
			const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst,
			const char *src, size_t dstsize);
size_t	ft_strlen(const char *a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int a);
int		ft_toupper(int c);

/************************   Functions that i added   **************************/
int		ft_isempty(int c);
int		ft_isalnum_(int c);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup_middle_del(char *str, int start_del, int end_del);
char	*ft_trim_whitespace(char *str);
int		ft_is_valid_word(char *str, int i);
int		ft_cnt_valid_word(char *str);
int		ft_empty_cnt(char *str);
char	*ft_trim_whitespace(char *str);
char	*ft_strdup_middle_del(char *str, int start_del, int end_del);
int		ft_isalnum_(int a);
int		ft_cnt_valid_word(char *str);
int		ft_is_valid_word(char *str, int i);
int		ft_empty_cnt(char *str);
char	*ft_strnjoin(char *dest, char *src, int n);

//fnc i modified and it's shorter
char	*sdup(const char *s1);
char	*snjoin(char *dest, char *src, int n);
char	*sdup_md_del(char *str, int start_del, int end_del);
int		sncmp(const char *s1, const char *s2, size_t n);
size_t	slen(const char *a);
void	ft_strncpy(char *dest, char *src, int i);
char	*sadd(char *str, char c);

/************************   ADVANCED C FUNCTIONS   **************************/
//ft_split, we have an array of separators, not only a char
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
/*********************** FUNCTIONS THAT I MODIFIED **************************/
char	**ft_split(char const *s, char *separators);
/**********************   LINKED LISTS' FUNCTIONS   *************************/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));

/***************************   GET_NEXT_LINE   ******************************/
char	*get_next_line(int fd);
char	*sndup(char *str, int n);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif

/***************************   FT_PRINTF   **********************************/
int		ft_printf(const char *str_o, ...);
int		ft_putp(unsigned long n);
int		ft_putc(char c);
int		ft_putdi(int n);
int		ft_puts(char *s);
int		ft_putu(unsigned int n);
int		ft_putx(unsigned int n);
int		ft_putxx(unsigned int n);

/***************************   FT_PRINTF__FD *********************************/
int		print_fd(int fd, const char *str_o, ...);
int		ft_putp_fd(unsigned long n, int fd);
int		ft_putc_fd(char c, int fd);
int		ft_putdi_fd(int n, int fd);
int		ft_puts_fd(char *s, int fd);
int		ft_putu_fd(unsigned int n, int fd);
int		ft_putx_fd(unsigned int n, int fd);
int		ft_putxx_fd(unsigned int n, int fd);

#endif
