/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:46:37 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/06 19:07:03 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_piles(t_piles *piles)
{
	if (piles)
	{
		ft_lstclear(&piles->a, &free);
		ft_lstclear(&piles->b, &free);
		free(piles);
	}
}
