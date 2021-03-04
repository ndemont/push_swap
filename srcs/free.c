/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:37 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 11:44:53 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_piles(t_piles *piles)
{
	if (piles)
	{
		ft_lstclear(piles->a, &free);
		if (piles->a)
			free(piles->a);
		ft_lstclear(piles->b, &free);
		if (piles->b)
			free(piles->b);
		free(piles);
	}
}
