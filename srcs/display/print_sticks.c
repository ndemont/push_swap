/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sticks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/18 23:01:04 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_sticks(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;
	int		i;
	long	nb;

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
			printf(CYAN);
			i = piles->max;
			if (pile_a)
			{
				i = piles->max;
				nb = *(long *)pile_a->content;
				while (nb > 0)
				{
					printf("-");
					i--;
					nb--;
				}
				pile_a = pile_a->next;
			}
			while (i > 0)
			{
				printf(" ");
				i--;
			}
			i = piles->max;
			printf(WHITE);
			printf(" | ");
			printf(PURPLE);
			if (pile_b)
			{
				nb = *(long *)pile_b->content;
				while (nb > 0)
				{
					printf("-");
					i--;
					nb--;
				}
				pile_b = pile_b->next;
			}
			while (i > 0)
			{
				printf(" ");
				i--;
			}
			printf("\n");
			printf(WHITE);
		}
	}
	usleep(100000);
	return (1);
}
