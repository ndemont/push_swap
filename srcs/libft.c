/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:07:54 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/08 11:22:51 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

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
		temp = *lst;
		*lst = (*lst)->next;
		(*del)(temp->content);
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	c;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;
	c = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
	return (c);
}

int			ft_count_strlen(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	return (count);
}

int			ft_count_splitlen(const char *s, char c)
{
	int	count;

	count = 0;
	s++;
	while (*(s - 1) && *s)
	{
		if (*s == c && *(s - 1) != c)
			count++;
		s++;
	}
	if (*(s - 1) && *(s - 1) != c)
		count++;
	return (count);
}

const char	*ft_dup_split(char **split, int i, const char *s, char c)
{
	int j;

	if (!(split[i] = malloc(sizeof(char) * (ft_count_strlen(s, c) + 1))))
		return (0);
	j = 0;
	while (*s != c && *s)
	{
		split[i][j] = *s;
		j++;
		s++;
	}
	split[i][j] = '\0';
	return (s);
}

char				**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = ft_count_splitlen((char*)s, c);
	if (!(split = malloc(sizeof(char*) * (count + 1))))
		return (0);
	split[count] = 0;
	i = 0;
	while (i < count && *s)
	{
		if (*s != c)
		{
			if (!(s = ft_dup_split(split, i, s, c)))
				return (NULL);
			i++;
		}
		else
			s++;
	}
	return (split);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(cat = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		cat[i] = *s2;
		i++;
		s2++;
	}
	cat[i] = '\0';
	return (cat);
}