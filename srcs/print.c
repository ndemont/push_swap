/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/06 19:22:59 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_piles(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (!piles->v)
		return (0);
	if (piles)
	{
		pile_a = piles->a;
		pile_b = piles->b;
		while (pile_a || pile_b)
		{
			if (pile_a)
			{
				ft_putnbr_fd(*(long *)pile_a->content, 1);
				pile_a = pile_a->next;
			}
			write(1, "\t\t", 2);
			if (pile_b)
			{
				ft_putnbr_fd(*(long *)pile_b->content, 1);
				pile_b = pile_b->next;
			}
			write(1, "\n", 1);
		}
	}
	write(1, "______________________\na\t\tb\n\n\n", 30);
	return (1);
}
