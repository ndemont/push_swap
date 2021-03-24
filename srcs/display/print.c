/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/24 11:33:05 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_numbers_a(t_piles *piles, t_list *pile_a)
{
	if (pile_a)
	{
		if (piles->c)
		{
			printf(CYAN);
			printf("%11ld", *(long *)pile_a->content);
			printf(RESET);
		}
		else
			printf("%11ld", *(long *)pile_a->content);
	}
	else
		printf("%11c", ' ');
}

void	print_numbers_b(t_piles *piles, t_list *pile_b)
{
	if (pile_b)
	{
		if (piles->c)
		{
			printf(PURPLE);
			printf("%ld", *(long *)pile_b->content);
			printf(RESET);
		}
		else
			printf("%ld", *(long *)pile_b->content);
	}
}

int		print_numbers(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (piles)
	{
		printf(CLEAR);
		printf("%11c", 'A');
		printf("%4c", 'B');
		printf("\n%9c--------\n", '-');
		pile_a = piles->a;
		pile_b = piles->b;
		while (pile_a || pile_b)
		{
			print_numbers_a(piles, pile_a);
			if (pile_a)
				pile_a = pile_a->next;
			printf(" | ");
			print_numbers_b(piles, pile_b);
			if (pile_b)
				pile_b = pile_b->next;
			printf("\n");
		}
	}
	usleep(100000);
	return (1);
}

int		print_piles(t_piles *piles)
{
	if (!piles)
		return (0);
	if (!piles->v)
		return (0);
	if (piles->s)
	{
		if (piles->min > 0 && piles->max < 60)
			print_sticks(piles);
		else
			print_numbers(piles);
	}
	else
		print_numbers(piles);
	return (1);
}
