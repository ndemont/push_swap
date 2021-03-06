/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:56 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/06 19:24:30 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_a(t_piles *piles, int print)
{
	t_list	*pile_a;
	long	*tmp;

	if (print)
		write(1, "sa\n", 3);
	if (!piles)
		return (print_piles(piles));
	pile_a = piles->a;
	if (!pile_a)
		return (print_piles(piles));
	if (pile_a->next)
	{
		tmp = pile_a->content;
		pile_a->content = pile_a->next->content;
		pile_a->next->content = tmp;
	}
	return (print_piles(piles));
}

int		push_a(t_piles *piles)
{
	t_list	*pile_b1;
	t_list	*pile_b2;
	t_list	*new;
	long	*copy;

	write(1, "pa\n", 3);
	pile_b1 = piles->b;
	if (!piles)
		return (print_piles(piles));
	if (!pile_b1)
		return (print_piles(piles));
	pile_b2 = piles->b->next;
	copy = malloc(sizeof(long*));
	*copy = *(long *)pile_b1->content;
	new = ft_lstnew(copy);
	ft_lstadd_front(&piles->a, new);
	ft_lstdelone(pile_b1, &free);
	pile_b1 = 0;
	piles->b = pile_b2;
	return (print_piles(piles));
}

int		rotate_a(t_piles *piles, int print)
{
	t_list	*new;
	t_list	*pile_first;
	t_list	*pile_second;
	long	*copy;

	if (print)
		write(1, "ra\n", 3);
	if (!piles)
		return (print_piles(piles));
	if (!piles->a)
		return (print_piles(piles));
	pile_first = piles->a;
	copy = malloc(sizeof(long*));
	*copy = *(long *)pile_first->content;
	if (!copy)
		print_errors(piles);
	new = ft_lstnew(copy);
	pile_second = pile_first->next;
	if (!pile_second)
		return (print_piles(piles));
	ft_lstadd_back(&piles->a, new);
	piles->a = pile_second;
	ft_lstdelone(pile_first, &free);
	pile_first = 0;
	return (print_piles(piles));
}

void	ft_lstremove_last(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	while (lst->next->next)
		lst = lst->next;
	ft_lstdelone(lst->next, del);
	lst->next = 0;
}

int		reverse_rotate_a(t_piles *piles, int print)
{
	t_list	*pile_new;
	t_list	*pile_last;
	long	*copy;

	if (print)
		write(1, "rra\n", 4);
	if (!piles)
		return (print_piles(piles));
	if (!piles->a)
		return (print_piles(piles));
	if (!piles->a->next)
		return (print_piles(piles));
	pile_last = ft_lstlast(piles->a);
	copy = malloc(sizeof(long*));
	if (!copy)
		print_errors(piles);
	*copy = *(long *)pile_last->content;
	pile_new = ft_lstnew(copy);
	ft_lstadd_front(&piles->a, pile_new);
	ft_lstremove_last(piles->a, &free);
	if (piles->v)
		print_piles(piles);
	return (print_piles(piles));
}
