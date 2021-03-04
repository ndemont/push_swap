/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:53:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:46 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_piles(t_piles *piles)
{
	t_list	*pile_a;
	t_list	*pile_b;

	if (piles)
	{	
		printf("add begin a = %p\n", piles->a);
		printf("add begin b = %p\n", piles->b);
		printf("add first a = %p\n", *piles->a);
		printf("add first b = %p\n", *piles->b);
		pile_a = *piles->a;
		pile_b = *piles->b;
		printf("pile_a = %p\n", pile_a);
		printf("pile_b = %p\n", pile_b);
		while (pile_a || pile_b)
		{
			if (pile_a)
			{
				printf("a content = %ld\n", *(long *)pile_a->content);
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
	}
	write(1, "\na\t\tb\n\n", 7);
}
