/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:44:35 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 17:08:53 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_piles *piles)
{
	long	n1;
	long	n2;
	long	n3;

	n1 = *(long *)piles->a->content;
	n2 = *(long *)piles->a->next->content;
	n3 = *(long *)piles->a->next->next->content;
	if (n1 > n2 && n1 < n3 && n2 < n3)
		swap_a(piles, 1);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		swap_a(piles, 1);
		reverse_rotate_a(piles, 1);
	}
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		rotate_a(piles, 1);
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		swap_a(piles, 1);
		rotate_a(piles, 1);
	}
	else
		reverse_rotate_a(piles, 1);
}
