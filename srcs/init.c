/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:24:11 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/12 16:06:46 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		*init_piles(void)
{
	t_piles	*piles;
	t_list	*pile_a;
	t_list	*pile_b;

	piles = malloc(sizeof(t_piles*));
	if (!piles)
		print_errors(piles);
	pile_a = malloc(sizeof(t_list *));
	if (!pile_a)
		print_errors(piles);
	pile_b = malloc(sizeof(t_list *));
	if (!pile_b)
		print_errors(piles);
	pile_b = 0;
	pile_a = 0;
	piles->b = pile_b;
	piles->a = pile_a;
	piles->v = 0;
	piles->c = 0;
	piles->len_total = 0;
	piles->len_a = 0;
	piles->len_b = 0;
	piles->min = 0;
	piles->max = 0;
	return (piles);
}
