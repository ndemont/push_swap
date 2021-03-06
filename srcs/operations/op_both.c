/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:27:35 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/06 19:06:18 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_both(t_piles *piles)
{
	swap_a(piles, 0);
	swap_b(piles, 0);
	write(1, "ss\n", 3);
	return (print_piles(piles));
}

int		rotate_both(t_piles *piles)
{
	rotate_a(piles, 0);
	rotate_b(piles, 0);
	write(1, "rr\n", 3);
	return (print_piles(piles));
}

int		reverse_rotate_both(t_piles *piles)
{
	rotate_a(piles, 0);
	rotate_b(piles, 0);
	write(1, "rrr\n", 4);
	return (print_piles(piles));
}
