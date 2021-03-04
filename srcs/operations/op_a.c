/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 12:31:56 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:32 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *piles)
{
	t_list	*pile_a;
	long	*tmp;

	if (!piles)
		return ;
	pile_a = *(piles->a);
	if (!pile_a)
		return ;
	if (pile_a->next)
	{
		tmp = pile_a->content;
		pile_a->content = pile_a->next->content;
		pile_a->next->content = tmp;
	}
}

void	push_a(t_piles *piles)
{
	t_list	*pile_b1;
	t_list	*pile_b2;

	pile_b1 = *piles->b;
	pile_b2 = (*piles->b)->next;
	if (!piles)
		return ;
	if (!pile_b1)
		return ;
	ft_lstadd_front(piles->a, pile_b1);
	piles->b = &pile_b2;
}

void	rotate_a(t_piles *piles)
{
	t_list	*new;
	t_list	*pile_second;

	printf("add piles = %p\n", piles);
	printf("add begin a = %p\n", piles->a);
	printf("add begin b = %p\n", piles->b);
	printf("add first a = %p\n", *piles->a);
	printf("add first b = %p\n", *piles->b);
	if (!piles)
		return ;
	if (!*piles->a)
		return ;
	new = ft_lstnew((*piles->a)->content);
	pile_second = (*piles->a)->next;
	if (!pile_second)
		return ;
	ft_lstadd_back(piles->a, new);
	piles->a = &pile_second;
	printf("add piles = %p\n", piles);
	printf("add begin a = %p\n", piles->a);
	printf("add begin b = %p\n", piles->b);
	printf("add first a = %p\n", *piles->a);
	printf("add first b = %p\n", *piles->b);
}

//void	ft_lstremove_last(t_list *lst, void (*del)(void *))
//{
//	if (!lst)
//	while (lst->)
//}

void	reverse_rotate_a(t_piles *piles)
{
	t_list	*pile_new;
	t_list	*pile_last;

	if (!piles)
		return ;
	if (!*piles->a)
		return ;
	if (!(*piles->a)->next)
		return ;
	pile_last = ft_lstlast(*piles->a);
	pile_new = ft_lstdup(pile_last, &free);
	ft_lstadd_front(piles->a, pile_new);
	//pile_last = 0;
	//ft_lstdelone(pile_last, &free);
	//pile_last = 0;
}