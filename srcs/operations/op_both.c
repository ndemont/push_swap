/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:27:35 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:36 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_piles *piles)
{
	swap_a(piles);
	swap_b(piles);
}

void	rotate_both(t_piles *piles)
{
	rotate_a(piles);
	rotate_b(piles);
}