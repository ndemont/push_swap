/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:36 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 22:07:18 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_b(t_piles *piles, int print, int fd)
{
	t_list	*pile_b;
	long	*tmp;

	if (print)
		write(fd, "sb\n", 3);
	if (!piles)
		return (print_piles(piles));
	pile_b = piles->b;
	if (!pile_b)
		return (print_piles(piles));
	if (pile_b->next)
	{
		tmp = pile_b->content;
		pile_b->content = pile_b->next->content;
		pile_b->next->content = tmp;
	}
	return (print_piles(piles));
}

int		push_b(t_piles *piles, int print, int fd)
{
	t_list	*pile_a1;
	t_list	*pile_a2;
	t_list	*new;
	long	*copy;

	if (print)
		write(fd, "pb\n", 3);
	pile_a1 = piles->a;
	if (!piles)
		return (print_piles(piles));
	if (!pile_a1)
		return (print_piles(piles));
	pile_a2 = piles->a->next;
	copy = malloc(sizeof(long*));
	*copy = *(long *)pile_a1->content;
	new = ft_lstnew(copy);
	ft_lstadd_front(&piles->b, new);
	ft_lstdelone(pile_a1, &free);
	pile_a1 = 0;
	piles->a = pile_a2;
	piles->len_b++;
	piles->len_a--;
	return (print_piles(piles));
}

int		rotate_b(t_piles *piles, int print, int fd)
{
	t_list	*new;
	t_list	*pile_first;
	t_list	*pile_second;
	long	*copy;

	if (print)
		write(fd, "rb\n", 3);
	if (!piles)
		return (print_piles(piles));
	if (!piles->b)
		return (print_piles(piles));
	pile_first = piles->b;
	copy = malloc(sizeof(long*));
	*copy = *(long *)pile_first->content;
	if (!copy)
		print_errors(piles);
	new = ft_lstnew(copy);
	pile_second = pile_first->next;
	if (!pile_second)
		return (print_piles(piles));
	ft_lstadd_back(&piles->b, new);
	piles->b = pile_second;
	ft_lstdelone(pile_first, &free);
	pile_first = 0;
	return (print_piles(piles));
}

int		reverse_rotate_b(t_piles *piles, int print, int fd)
{
	t_list	*pile_new;
	t_list	*pile_last;
	long	*copy;

	if (print)
		write(fd, "rrb\n", 4);
	if (!piles)
		return (print_piles(piles));
	if (!piles->b)
		return (print_piles(piles));
	if (!piles->b->next)
		return (print_piles(piles));
	pile_last = ft_lstlast(piles->b);
	copy = malloc(sizeof(long*));
	if (!copy)
		print_errors(piles);
	*copy = *(long *)pile_last->content;
	pile_new = ft_lstnew(copy);
	ft_lstadd_front(&piles->b, pile_new);
	ft_lstremove_last(piles->b, &free);
	return (print_piles(piles));
}
