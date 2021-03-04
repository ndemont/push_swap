/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 12:36:12 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_piles(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = *piles->a;
	pile_b = *piles->b;
	while (pile_a || pile_b)
	{
		if (pile_a)
		{
			ft_putnbr_fd(*(long *)pile_a->content, 1);
			pile_a = pile_a->next;
		}
		if (pile_b)
		{
			write(1, "\t\t", 1);
			ft_putnbr_fd(*(long *)pile_b->content, 1);
			pile_b = pile_b->next;
		}
		write(1, "\n", 1);
	}
	write(1, "\na\t\tb\n\n", 7);
}
