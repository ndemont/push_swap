/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 21:23:20 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_piles(t_piles *piles)
{
	if (!piles)
		return (0);
	if (!piles->v)
		return (0);
//print_sticks(piles);
	if (piles->c)
		print_colors_piles(piles);
	else
		print_nocolors_piles(piles);
	return (1);
}

int	print_nocolors_piles(t_piles *piles)
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
			if (pile_a)
			{
				printf("%11ld", *(long *)pile_a->content);
				pile_a = pile_a->next;
			}
			else
				printf("%11c", ' ');
			printf(" | ");
			if (pile_b)
			{
				printf("%ld", *(long *)pile_b->content);
				pile_b = pile_b->next;
			}
			printf("\n");
		}
	}
	usleep(10000);
	return (1);
}
