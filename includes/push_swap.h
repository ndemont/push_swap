/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:34:04 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/22 00:41:03 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/errno.h>
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
# define RESET "\033[0;0m"
# define CLEAR "\e[H\e[2J"

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

int					check_digit(char *str);
int					check_integer(long nb);
int					check_duplicate(t_piles *piles, long n2);
long				*check_errors(char *av, t_piles *piles);
void				print_errors(t_piles *piles, char *error);

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
void				insertion_sort(t_piles *piles);
void				median_sort(t_piles *piles);
void				three_sort(t_piles *piles);
void				five_sort(t_piles *piles);


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

int					check_options(char **av, int ac, t_piles *piles);
void				parsing(int ac, char **av, t_piles *piles);

#endif
