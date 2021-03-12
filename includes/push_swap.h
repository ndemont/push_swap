/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:34:04 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/10 12:03:43 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_piles
{
	int			v;
	int			c;
	int			len_total;
	int			len_a;
	int			len_b;
	t_list		*a;
	t_list		*b;
}					t_piles;

/*libft*/
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstnew(void *content);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstdup(t_list *lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));
void				ft_putnbr_fd(long n, int fd);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*parsing*/

int					check_digit(char *str);
int					check_integer(long nb);
int					check_duplicate(t_piles *piles, long n2);
long				*check_errors(char *av, t_piles *piles);
void				print_errors(t_piles *piles);

t_piles 			*init_piles(void);

void				ft_lstremove_last(t_list *lst, void (*del)(void *));

void				push_swap(t_piles *piles, int print);
int					swap_a(t_piles *piles, int print);
int					swap_b(t_piles *piles, int print);
int					swap_both(t_piles *piles, int print);
int					push_a(t_piles *piles, int print);
int					push_b(t_piles *piles, int print);
int					rotate_a(t_piles *piles, int print);
int					rotate_b(t_piles *piles, int print);
int					rotate_both(t_piles *piles, int print);
int					reverse_rotate_a(t_piles *piles, int print);
int					reverse_rotate_b(t_piles *piles, int print);
int					reverse_rotate_both(t_piles *piles, int print);

void				bubble_sort(t_piles *piles);
void				heap_sort(t_piles *piles);
void				heap_sort_magic(t_piles *piles);

int					check_ascending_order(t_list *pile_a);
int					check_ascending_order(t_list *pile_a);

int					print_piles(t_piles *piles);

void				free_piles(t_piles *piles);

void				parsing(int ac, char **av, t_piles *piles);

#endif
