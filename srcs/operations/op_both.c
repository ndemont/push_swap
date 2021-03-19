/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:27:35 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 22:12:52 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_both(t_piles *piles, int print, int fd)
{
	swap_a(piles, 0, piles->fd);
	swap_b(piles, 0, piles->fd);
	if (print)
		write(fd, "ss\n", 3);
	return (print_piles(piles));
}

int		rotate_both(t_piles *piles, int print, int fd)
{
	rotate_a(piles, 0, piles->fd);
	rotate_b(piles, 0, piles->fd);
	if (print)
		write(fd, "rr\n", 3);
	return (print_piles(piles));
}

int		reverse_rotate_both(t_piles *piles, int print, int fd)
{
	rotate_a(piles, 0, piles->fd);
	rotate_b(piles, 0, piles->fd);
	if (print)
		write(fd, "rrr\n", 4);
	return (print_piles(piles));
}
