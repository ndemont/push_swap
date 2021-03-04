/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:07:54 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/04 16:28:50 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	if (!del)
		return ;
	while (*lst)
	{
		(*del)((*lst)->content);
		temp = *lst;
		*lst = temp->next;
		free(temp);
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!*alst)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst->next)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	(*f)(lst->content);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int		ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_list	*ft_lstdup(t_list *lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*begin;

	if (!lst)
		return (0);
	begin = ft_lstnew(lst->content);
	if (!begin)
		return (0);
	lst = lst->next;
	while (lst)
	{
		elem = ft_lstnew(lst->content);
		if (!elem)
		{
			ft_lstclear(&elem, del);
			return (0);
		}
		ft_lstadd_back(&begin, elem);
		lst = lst->next;
	}
	return (begin);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*begin;

	if (!lst)
		return (0);
	map = ft_lstdup(lst, del);
	if (!map)
		return (0);
	begin = map;
	while (map)
	{
		map->content = (f)(map->content);
		map = map->next;
	}
	return (begin);
}

void	ft_putnbr_fd(long n, int fd)
{
	int		c;
	long	nb;

	nb = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	if ((nb / 10) > 0)
		ft_putnbr_fd((nb / 10), fd);
	c = (nb % 10) + 48;
	write(fd, &c, 1);
}
