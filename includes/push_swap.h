/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:34:04 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/20 12:36:02 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define CLEAR "\e[H\e[2J"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_elem
{
	long	pos;
	long	moves;
	int		dir;
}					t_elem;

typedef struct		s_piles
{
	t_list			*a;
	t_list			*b;
	long			len_total;
	long			len_a;
	long			len_b;
	long			min;
	long			max;
	long			prev_min;
	long			*mediane;
	long			steps;
	int				src;
	int				dst;
	int				fd;
	int				c;
	int				v;
	int				s;
}					t_piles;

/*libft*/
size_t				ft_strlen(const char *s);
float				ft_atoi(const char *str);
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
int					swap_a(t_piles *piles, int print, int fd);
int					swap_b(t_piles *piles, int print, int fd);
int					swap_both(t_piles *piles, int print, int fd);
int					push_a(t_piles *piles, int print, int fd);
int					push_b(t_piles *piles, int print, int fd);
int					rotate_a(t_piles *piles, int print, int fd);
int					rotate_b(t_piles *piles, int print, int fd);
int					rotate_both(t_piles *piles, int print, int fd);
int					reverse_rotate_a(t_piles *piles, int print, int fd);
int					reverse_rotate_b(t_piles *piles, int print, int fd);
int					reverse_rotate_both(t_piles *piles, int print, int fd);

void				bubble_sort(t_piles *piles);
void				heap_sort(t_piles *piles);
void				heap_sort_magic(t_piles *piles);
void				three_sort(t_piles *piles);


void				thib_sort(t_piles *piles);
void				set_steps(t_piles *piles);
void				find_position(t_list *pile, long *pos_min, long *pos_max);
void				count_moves(t_elem *min, t_elem *max, int len);

int					ascending_order(t_list *pile_a);
int					descending_order(t_list *pile_a);
int					check_empty(t_list *list);

void				put_min_first(t_piles *piles);

int					print_piles(t_piles *piles);
int					print_colors_piles(t_piles *piles);
int					print_nocolors_piles(t_piles *piles);
int					print_sticks(t_piles *piles);


void				free_piles(t_piles *piles);

int					check_options(int i, char *av, t_piles *piles);
int					check_options2(char **av, int ac, t_piles *piles);
void				parsing(int ac, char **av, t_piles *piles);

#endif