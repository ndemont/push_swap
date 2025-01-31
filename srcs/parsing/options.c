/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:35:48 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/28 01:48:03 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dst(char **av, t_piles *piles, long i)
{
	if ((!ft_strcmp(av[i], "--dst")) && (!piles->dst) && (!piles->src))
	{
		piles->fd = open(av[i + 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (piles->fd < 0)
			print_errors(piles, 0);
		piles->dst = 1;
		return (1);
	}
	return (0);
}

int		check_src(char **av, t_piles *piles, long i)
{
	if ((!ft_strcmp(av[i], "--src")) && (!piles->src) && (!piles->dst))
	{
		piles->fd = open(av[i + 1], O_RDONLY);
		if (piles->fd < 0)
			print_errors(piles, 0);
		piles->src = 1;
		return (1);
	}
	return (0);
}

int		check_vcs(char **av, t_piles *piles, long i)
{
	long j;

	if (av[i][0] != '-')
		return (0);
	j = 1;
	while (av[i][j])
	{
		if (av[i][j] == 'v' && (!piles->v))
			piles->v = 1;
		else if (av[i][j] == 'c' && (!piles->c))
			piles->c = 1;
		else if (av[i][j] == 's' && (!piles->s))
			piles->s = 1;
		else
			return (0);
		j++;
	}
	return (1);
}

int		check_dash(char **av, t_piles *piles, long i)
{
	(void)piles;
	if (av[i][0] != '-')
		return (i);
	if (!av[i][1])
		return (0);
	if (av[i][1] >= '0' && av[i][1] <= '9')
		return (i);
	return (-1);
}

int		check_options(char **av, int ac, t_piles *piles)
{
	long	i;

	i = 1;
	while (i < ac)
	{
		if (piles->s && !piles->v)
			return (0);
		if (check_dash(av, piles, i) != -1)
			return (check_dash(av, piles, i));
		if (check_dst(av, piles, i))
			i += 2;
		else if (check_src(av, piles, i))
			i += 2;
		else if (check_vcs(av, piles, i))
			i++;
		else
			return (0);
	}
	if (piles->s && !piles->v)
		return (0);
	return (i);
}
