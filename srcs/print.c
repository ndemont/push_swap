/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/17 17:27:07 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_piles(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;

	printf(CLEAR);
	printf(CYAN);
	printf("%11c", 'A');
	printf(PURPLE);
	printf("%3c", 'B');
	printf(WHITE);
	printf("\n%9c--------\n", '-');
	if (!piles)
		return (0);
	if (!piles->v)
		return (0);
	if (piles)
	{
		pile_a = piles->a;
		pile_b = piles->b;
		while (pile_a || pile_b)
		{
			printf(CYAN);
			if (pile_a)
			{
				printf("%11ld", *(long *)pile_a->content);
				pile_a = pile_a->next;
			}
			else
				printf("%11c", ' ');
			printf(WHITE);
			printf(" | ");
			printf(PURPLE);
			if (pile_b)
			{
				printf("%ld", *(long *)pile_b->content);
				pile_b = pile_b->next;
			}
			printf("\n");
			printf(WHITE);
		}
	}
	usleep(100000);
	return (1);
}
