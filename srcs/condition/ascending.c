/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:47:03 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/19 15:10:26 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ascending_order(t_list *pile)
{
	t_list	*list;

	list = pile;
	if (!list)
		return (1);
	while (list->next)
	{
		if (*(long *)list->content > *(long *)list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}
