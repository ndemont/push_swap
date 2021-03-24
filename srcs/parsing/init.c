/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:24:11 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/23 21:21:57 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		*init_piles(void)
{
	t_piles	*piles;

	piles = (t_piles*)malloc(sizeof(t_piles));
	if (!piles)
		print_errors(piles, 0);
	piles->a = 0;
	piles->b = 0;
	piles->v = 0;
	piles->c = 0;
	piles->s = 0;
	piles->len_total = 0;
	piles->len_a = 0;
	piles->len_b = 0;
	piles->prev_min = 0;
	piles->min = 0;
	piles->max = 0;
	piles->src = 0;
	piles->dst = 0;
	piles->mediane = 0;
	return (piles);
}
