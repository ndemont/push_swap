/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descending.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:30:31 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 15:09:51 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_descending_order(t_list *pile_a)
{
	t_list	*list;

	list = pile_a;
	if (!list)
		return (1);
	while (list->next)
	{
		if (*(long *)list->content < *(long *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
