/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorales <emorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:29:22 by emorales          #+#    #+#             */
/*   Updated: 2024/01/13 18:35:18 by emorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*create_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = '\0';
	list->next = 0;
	return (list);
}

void	populate_list(t_list **list, char *buffer)
{
	t_list	*last;

	if (!*list)
		*list = create_list();
	last = ft_lstlast(*list);
	while (*buffer != '\0')
	{
		if (!last->content)
			last->content = *buffer++;
	if (*buffer) //aqui copio o buffer inteiro, mesmo que tenha um \n no meio
		{
			ft_lstadd_back(list, create_list());
			last = last->next;
		}
	}
}

char	*create_line(t_list *list)
{
	char	*line;
	int		len;
	int		i;

	if (list->content == 0)
		return (NULL);
	len = ft_line_size(list);
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i++] = list->content;
		list = list->next;
	}
	line[len] = '\0';
	return (line);
}

char	*read_line(t_list **list, int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int		chars_read;
	char	*line;

	chars_read = read (fd, buffer, BUFFER_SIZE);
	if (chars_read <= 0)
		return (create_line(*list));
	buffer[chars_read] = '\0';
	populate_list(list, buffer);
	while (!ft_strchr(buffer, '\n'))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (NULL);
		if (chars_read == 0)
			break;
		buffer[chars_read] = '\0';
		populate_list(list, buffer);
	}
	if (chars_read != BUFFER_SIZE)
		ft_lstadd_back(list, create_list());
	line = create_line(*list);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!list)
		list = create_list();
	next_line = read_line(&list, fd);
		free_list(&list);
	return (next_line);
}
