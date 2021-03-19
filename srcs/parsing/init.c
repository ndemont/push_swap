/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:24:11 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 15:20:40 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		*init_piles(void)
{
	t_piles	*piles;

	piles = (t_piles*)malloc(sizeof(t_piles));
	if (!piles)
		print_errors(piles);
	piles->a = (t_list*)malloc(sizeof(t_list));
	if (!piles->a)
		print_errors(piles);
	piles->b = (t_list*)malloc(sizeof(t_list));
	if (!piles->b)
		print_errors(piles);
	piles->a = 0;
	piles->b = 0;
	piles->v = 0;
	piles->c = 0;
	piles->len_total = 0;
	piles->len_a = 0;
	piles->len_b = 0;
	piles->prev_min = 0;
	piles->min = 0;
	piles->max = 0;
	return (piles);
}
