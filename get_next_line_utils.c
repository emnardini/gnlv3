/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorales <emorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:33:06 by emorales          #+#    #+#             */
/*   Updated: 2024/01/13 18:38:20 by emorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

int	ft_line_size(t_list *list)
{
	int	len;

	if (!list || list->content == 0)
		return (0);
	len = 0;
	while (list->content)
	{
		len++;
		if (list->content == '\n')
			return (len);
		if (list->next == NULL)
			return (len);
		list = list->next;
	}
	return (len);
}

void	free_list(t_list **list)
{
	int		sizedelete;
	t_list	*temp;

	sizedelete = ft_line_size(*list);
	while (sizedelete > 0)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp);
		sizedelete--;
	}
	if (*list && (*list)->content == 0)
	{
		free(*list);
		*list = NULL;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
