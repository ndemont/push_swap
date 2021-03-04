/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:34:04 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:52 by ndemont          ###   ########.fr       */
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
	t_list		**a;
	t_list		**b;
}					t_piles;

/*libft*/
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


/*parsing*/

int					check_digit(char *str);
int					check_integer(long nb);
int					check_duplicate(t_list **begin, long n2);
long				*check_errors(char *av, t_piles *piles);
void				print_errors(t_piles *piles);

t_piles 			*init_piles(void);


void				push_swap(t_piles *piles);
void				swap_a(t_piles *piles);
void				swap_b(t_piles *piles);
void				swap_both(t_piles *piles);
void				push_a(t_piles *piles);
void				push_b(t_piles *piles);
void				rotate_a(t_piles *piles);
void				rotate_b(t_piles *piles);
void				rotate_both(t_piles *piles);
void				reverse_rotate_a(t_piles *piles);

void				print_piles(t_piles *piles);

void				free_piles(t_piles *piles);

void				parsing(int ac, char **av, t_piles *piles);

#endif
