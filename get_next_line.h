/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorales <emorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:34:09 by emorales          #+#    #+#             */
/*   Updated: 2024/01/09 19:48:33 by emorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}	t_list;

t_list	*create_list(void);
void	populate_list(t_list **list, char *buffer);
char	*create_line(t_list *list);
char	*read_line(t_list **list, int fd);
char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_line_size(t_list *list);
void	free_list(t_list **list);
char	*ft_strchr(const char *s, int c);

#endif // GET_NEXT_LINE_H