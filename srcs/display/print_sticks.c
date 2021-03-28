/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sticks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/27 21:19:39 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_sticks_a(t_piles *piles, t_list *pile_a, int i)
{
	long	nb;

	if (pile_a)
	{
		nb = *(long *)pile_a->content;
		if (piles->max / 51 > 0)
			nb = nb / (piles->max / 51);
		while (nb > 0)
		{
			if (piles->c)
				printf("\e[46m");
			else
				printf("\e[47m");
			printf(" ");
			printf(RESET);
			i--;
			nb--;
		}
	}
	while (i > 0)
	{
		printf(" ");
		i--;
	}
}

static void	print_sticks_b(t_piles *piles, t_list *pile_b)
{
	long	nb;

	if (pile_b)
	{
		nb = *(long *)pile_b->content;
		if (piles->max / 51 > 0)
			nb = nb / (piles->max / 51);
		while (nb > 0)
		{
			if (piles->c)
				printf("\e[45m");
			else
				printf("\e[47m");
			printf(" ");
			printf(RESET);
			nb--;
		}
	}
}

int			print_sticks(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (piles)
	{
		printf(CLEAR);
		printf("%*c", (int)(piles->max - 3), ' ');
		printf("%c", 'A');
		printf("%8c\n", 'B');
		pile_a = piles->a;
		pile_b = piles->b;
		while (pile_a || pile_b)
		{
			print_sticks_a(piles, pile_a, piles->max);
			if (pile_a)
				pile_a = pile_a->next;
			printf("  ");
			print_sticks_b(piles, pile_b);
			if (pile_b)
				pile_b = pile_b->next;
			printf("\n");
		}
	}
	usleep(10000);
	return (1);
}
