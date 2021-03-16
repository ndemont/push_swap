/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:07:54 by ndemont           #+#    #+#             */
/*   Updated: 2021/03/16 13:50:42 by ndemont          ###   ########.fr       */
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

float		ft_atoi(const char *str)
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

static int    is_sep(char c, char d)
{
    if (c == d)
        return (1);
    else
        return (0);
}

static int    count_words(const char *s, char c)
{
    int    i;
    int    count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (!(is_sep(s[i], c)) && ((is_sep(s[i + 1], c)) || s[i + 1] == '\0'))
            count++;
        i++;
    }
    return (count);
}

static void    ft_fill_tab(char *tab, const char *str, int i, int j)
{
    int    r;

    r = 0;
    while (j < i)
    {
        tab[r] = str[j];
        j++;
        r++;
    }
    tab[r] = '\0';
}

char        *ft_split2(char const *s, char c, int *i, int *j)
{
    char    *tab;

    while (is_sep(s[*i], c) && s[*i])
        (*i)++;
    *j = *i;
    while ((!(is_sep(s[*i], c))) && s[*i])
        (*i)++;
    tab = malloc(sizeof(char) * ((*i - *j) + 1));
    if (!tab)
        return (NULL);
    return (tab);
}

char        **ft_split(char const *s, char c)
{
    int        i;
    int        j;
    int        k;
    char    **tab;

    i = 0;
    k = 0;
    if (!s)
        return (NULL);
    tab = malloc(sizeof(char*) * (count_words(s, c) + 1));
    if (!tab)
        return (NULL);
    while (s[i] && k < count_words(s, c))
    {
        tab[k] = ft_split2(s, c, &i, &j);
        if (!(tab[k]))
            return (NULL);
        ft_fill_tab(tab[k], s, i, j);
        k++;
    }
    tab[k] = 0;
    return (tab);
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

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = s1[i];
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	while (*(char*)s != '\0')
	{
		if (c == *(char*)s)
			return ((char*)s);
		s++;
	}
	if (c == *(char*)s)
		return ((char*)s);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	size = ft_strlen(s);
	while (i < len && (start + i) < size)
	{
		dup[i] = s[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	begin;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		begin = i;
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && i < len && \
					haystack[i] && needle[j])
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return (&((char*)haystack)[begin]);
		}
		i = begin + 1;
	}
	return (NULL);
}
