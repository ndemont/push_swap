/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:35:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 16:41:18 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_options(int i, char *av, t_piles *piles)
{
	if (i < 2)
	{
		if ((!ft_strcmp(av, "-v")) && (!piles->v))
			piles->v = 1;
		else if ((!ft_strcmp(av, "-c")) && (!piles->c))
			piles->c = 1;
		else if ((!ft_strcmp(av, "-vc")) && (!piles->c) && (!piles->v))
		{
			piles->v = 1;
			piles->c = 1;
		}
		else if ((!ft_strcmp(av, "-cv")) && (!piles->c) && (!piles->v))
		{
			piles->v = 1;
			piles->c = 1;
		}
		else
			return (0);
		return (1);
	}
	return (0);
}
