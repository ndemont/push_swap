/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:00:17 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:56 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(int ac, char **av, t_piles *piles)
{
	long	i;
	long	*nb;
	t_list	*new;

	i = 1;
	while (i < ac)
	{
		nb = check_errors(av[i], piles);
		new = ft_lstnew(nb);
		if (!new)
		{
			free(nb);
			print_errors(piles);
		}
		ft_lstadd_back(piles->a, new);
		i++;
	}
}
